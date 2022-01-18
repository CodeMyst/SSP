#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct knjiga {
    int sifra;
    char autor[100];
    char naziv[100];
    char zanr[100];
    int kolicina;

    struct knjiga* next;
} knjiga;

void nabavka(knjiga** root, knjiga* new) {
    if (*root == NULL || new->sifra < (*root)->sifra) {
        new->next = *root;
        *root = new;
    } else {
        knjiga* curr = *root;
        while (curr->next != NULL && new->sifra > curr->next->sifra) {
            curr = curr->next;
        }

        new->next = curr->next;
        curr->next = new;
    }
}

knjiga* ucitaj() {
    FILE* fp = fopen("knjizara.txt", "r");

    knjiga* root = NULL;

    int n = 0;
    fscanf(fp, "%d\n", &n);

    for (int i = 0; i < n; i++) {
        knjiga* new = (knjiga*) malloc(sizeof(knjiga));
        new->next = NULL;

        fscanf(fp, "%d\n", &new->sifra);
        fscanf(fp, "%[^\n]\n", new->autor);
        fscanf(fp, "%[^\n]\n", new->naziv);
        fscanf(fp, "%d\n", &new->kolicina);
        fscanf(fp, "%[^\n]\n", new->zanr);

        nabavka(&root, new);
    }

    fclose(fp);

    return root;
}

void oslobodi(knjiga* root) {
    if (root != NULL) {
        oslobodi(root->next);
        free(root);
    }
}

void stampaj(knjiga* root) {
    if (root != NULL) {
        printf("%d\n", root->sifra);
        puts(root->autor);
        puts(root->naziv);
        printf("%d\n", root->kolicina);
        puts(root->zanr);
        printf("\n");

        stampaj(root->next);
    }
}

int prodaj(knjiga** root, int sifra) {
    knjiga* t = *root;
    knjiga* prev = NULL;

    if (t != NULL && t->sifra == sifra) {
        t->kolicina -= 1;

        if (t->kolicina <= 0) {
            *root = t->next;
            free(t);
        }

        return 1;
    } else {
        while (t != NULL && t->sifra != sifra) {
            prev = t;
            t = t->next;
        }

        if (t == NULL) {
            return 0;
        }

        t->kolicina -= 1;

        if (t->kolicina <= 0) {
            prev->next = t->next;

            free(t);
        }

        return 1;
    }
}

void preporuci(knjiga* root, char* zanr) {
    if (root == NULL) return;

    if (strcmp(root->zanr, zanr) == 0) {
        printf("%s\n", root->naziv);
    }

    preporuci(root->next, zanr);
}

int main() {
    knjiga* k = ucitaj();

    prodaj(&k, 157);
    prodaj(&k, 157);
    prodaj(&k, 157);
    prodaj(&k, 157);
    prodaj(&k, 157);

    stampaj(k);

    preporuci(k, "fantastika\r");

    oslobodi(k);

    return 0;
}