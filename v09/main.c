#include <stdlib.h>
#include <stdio.h>

typedef struct predmet {
    char naziv[50];
    char sifra[50];
    float prosek;

    struct predmet* levi;
    struct predmet* desni;
} predmet;

void dodaj(predmet* novi, predmet** root) {
    if (*root == NULL) {
        *root = novi;
        novi->levi = NULL;
        novi->desni = NULL;
    } else {
        if (novi->prosek < (*root)->prosek) {
            dodaj(novi, &(*root)->levi);
        } else {
            dodaj(novi, &(*root)->desni);
        }
    }
}

predmet* ucitaj() {
    FILE* fp = fopen("predmeti.txt", "r");

    int brPredmeta;
    fscanf(fp, "%d\n", &brPredmeta);

    predmet* root = NULL;

    for (int i = 0; i < brPredmeta; i++) {
        predmet* novi = (predmet*) malloc(sizeof(predmet));
        fgets(novi->naziv, 50, fp);
        fgets(novi->sifra, 50, fp);
        fscanf(fp, "%f\n", &novi->prosek);

        dodaj(novi, &root);
    }

    fclose(fp);

    return root;
}

void zbir_proseka(predmet* root, int* n, float* res) {
    if (root == NULL) return;

    (*n)++;

    float l = 0;
    float r = 0;

    zbir_proseka(root->levi, n, &l);
    zbir_proseka(root->desni, n, &r);

    *res = l + r + root->prosek;
}

void ukupan_prosek(predmet* root, float* res) {
    int n = 0;
    float zbir = 0;
    zbir_proseka(root, &n, &zbir);

    if (n == 0) {
        *res = 0;
    } else {
        *res = zbir / n;
    }
}

void print_predmet(predmet* p) {
    printf("%s %s %.2f\n", p->naziv, p->sifra, p->prosek);
}

void print(predmet* root) {
    if (root == NULL) return;

    print_predmet(root);

    print(root->levi);
    print(root->desni);
}

void iznad_proseka(predmet* root, float prosek) {
    if (root == NULL) return;

    if (root->prosek > prosek) {
        print_predmet(root);
        if (root->levi != NULL && root->levi->prosek > prosek) {
            iznad_proseka(root->levi, prosek);
        }
    }

    iznad_proseka(root->desni, prosek);
}

void oslobodi_memoriju(predmet* root) {
    if (root == NULL) return;

    oslobodi_memoriju(root->levi);
    oslobodi_memoriju(root->desni);

    free(root);
}

int main() {
    predmet* p = ucitaj();

    float prosek = 0;
    ukupan_prosek(p, &prosek);

    printf("prosek: %.2f\n", prosek);

    iznad_proseka(p, prosek);

    printf("----\n");

    print(p);

    oslobodi_memoriju(p);

    return 0;
}