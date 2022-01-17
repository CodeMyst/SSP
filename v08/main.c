#include <stdlib.h>
#include <stdio.h>

typedef struct vocka {
    char naziv[50];
    int cena;
    int kolicina;

    struct vocka* next;
} vocka;

vocka* ucitaj() {
    FILE* fp = fopen("voce.txt", "r");

    int amnt;
    fscanf(fp, "%d\n", &amnt);

    vocka* root = NULL;

    for (int i = 0; i < amnt; i++) {
        vocka* v = (vocka*) malloc(sizeof(vocka));
        v->next = NULL;

        fscanf(fp, "%s ", v->naziv);
        fscanf(fp, "%d ", &(v->cena));
        fscanf(fp, "%d ", &(v->kolicina));

        int idx;
        fscanf(fp, "%d", &idx);

        if (idx <= 0 || root == NULL) {
            v->next = root;
            root = v;
        } else {
            vocka* n = root;
            while (n->next != NULL && idx > 1) {
                n = n->next;
                idx--;
            }

            v->next = n->next;
            n->next = v;
        }
    }

    fclose(fp);

    return root;
}

void oslobodi_memoriju(vocka* root) {
    if (root != NULL) {
        oslobodi_memoriju(root->next);
        free(root);
    }
}

void rasprodaja(vocka* root) {
    if (root != NULL) {
        rasprodaja(root->next);

        if (root->kolicina < 30) {
            root->cena *= 0.8;
        }
    }
}

void izracunaj_zaradu(vocka* root, int* res) {
    if (root != NULL) {
        izracunaj_zaradu(root->next, res);

        *res += root->cena * root->kolicina;
    }
}

void stampaj(vocka* root) {
    if (root != NULL) {
        stampaj(root->next);

        printf("%s %d %d\n", root->naziv, root->cena, root->kolicina);
    }
}

int main() {
    vocka* vocke = ucitaj();

    rasprodaja(vocke);

    int cena = 0;
    izracunaj_zaradu(vocke, &cena);

    printf("%d\n", cena);

    stampaj(vocke);

    oslobodi_memoriju(vocke);

    return 0;
}