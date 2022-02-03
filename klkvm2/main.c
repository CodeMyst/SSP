#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct kolac {
    char* vrsta;
    int cena;
    int kolicina;
    int br;

    struct kolac* left;
    struct kolac* right;
} kolac;

void dodaj(kolac** root, kolac* new) {
    if (*root == NULL) {
        *root = new;
        new->left = NULL;
        new->right = NULL;
    } else {
        if (new->cena > (*root)->cena) {
            dodaj(&(*root)->right, new);
        } else {
            dodaj(&(*root)->left, new);
        }
    }
}

kolac* ucitaj() {
    FILE* fp = fopen("kolaci.txt", "r");

    kolac* root = NULL;

    int n = 0;
    fscanf(fp, "%d\r\n", &n);

    for (int i = 0; i < n; i++) {
        kolac* new = (kolac*) malloc(sizeof(kolac));
        new->vrsta = (char*) malloc(50 * sizeof(char));

        fscanf(fp, "%[^\r\n]\r\n", new->vrsta);
        fscanf(fp, "%d\r\n", &new->cena);
        fscanf(fp, "%d\r\n", &new->kolicina);
        fscanf(fp, "%d\r\n", &new->br);

        dodaj(&root, new);
    }

    fclose(fp);

    return root;
}

void oslobodi_memoriju(kolac* root) {
    if (root == NULL) return;

    oslobodi_memoriju(root->left);
    oslobodi_memoriju(root->right);

    free(root->vrsta);
    free(root);
}

void ispisi_stablo(kolac* root) {
    if (root == NULL) return;

    ispisi_stablo(root->left);

    printf("%s %d %d %d\n", root->vrsta, root->cena, root->kolicina, root->br);
    
    ispisi_stablo(root->right);
}

void ukupna_cena(kolac* root, int* cena) {
    if (root == NULL) return;

    ukupna_cena(root->left, cena);

    (*cena) += root->kolicina * root->cena;

    ukupna_cena(root->right, cena);
}

void akcija(kolac* root) {
    if (root == NULL) return;

    if (root->cena < 54) {
        root->kolicina -= 5;
    }

    if (root->left != NULL) {
        akcija(root->left);
        return;
    }

    akcija(root->right);
}

int main() {
    kolac* k = ucitaj();

    ispisi_stablo(k);

    int pre = 0;
    ukupna_cena(k, &pre);
    printf("cena pre akcije: %d\n", pre);

    akcija(k);

    int posle = 0;
    ukupna_cena(k, &posle);
    printf("cena posle akcije: %d\n", posle);

    printf("razlika u ceni: %d\n", pre-posle);

    printf("-----\n");

    ispisi_stablo(k);

    oslobodi_memoriju(k);

    return 0;
}