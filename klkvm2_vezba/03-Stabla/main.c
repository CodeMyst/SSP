#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct student {
    char* ime;
    int indeks;
    int bodovi;

    struct student* left;
    struct student* right;
} student;

void dodaj(student** root, student* new) {
    if (*root == NULL) {
        *root = new;
        new->left = NULL;
        new->right = NULL;
    } else {
        if (new->indeks > (*root)->indeks) {
            dodaj(&(*root)->right, new);
        } else {
            dodaj(&(*root)->left, new);
        }
    }
}

student* ucitaj() {
    FILE* fp = fopen("studenti.dat", "r");

    student* root = NULL;

    int br = 0;
    fscanf(fp, "%d\r\n", &br);

    for (int i = 0; i < br; i++) {
        student* new = (student*) malloc(sizeof(student));
        new->ime = (char*) malloc(50 * sizeof(student));

        fscanf(fp, "%[^\r\n]\r\n", new->ime);
        fscanf(fp, "%d\r\n", &new->indeks);
        fscanf(fp, "%d\r\n", &new->bodovi);

        dodaj(&root, new);
    }

    fclose(fp);

    return root;
}

void oslobodi_memoriju(student* root) {
    if (root == NULL) return;

    oslobodi_memoriju(root->left);
    oslobodi_memoriju(root->right);

    free(root->ime);
    free(root);
}

void stampaj(student* root) {
    if (root == NULL) return;

    stampaj(root->left);

    printf("%s %d %d\n", root->ime, root->indeks, root->bodovi);

    stampaj(root->right);
}

student* pronadji_studenta(student* root, int idx) {
    if (root == NULL) return NULL;

    if (root->indeks == idx) return root;

    student* l = pronadji_studenta(root->left, idx);

    student* r = pronadji_studenta(root->right, idx);

    return l == NULL ? r : l;
}

student* nadji_najboljeg(student* root) {
    if (root == NULL) return NULL;

    int b = root->bodovi;
    student* lres = nadji_najboljeg(root->left);
    student* rres = nadji_najboljeg(root->right);

    if (lres != NULL && lres->bodovi > b) return lres;
    else if (rres != NULL && rres->bodovi > b) return rres;

    return root;
}

student* nti_upisani(student* root, int n) {
    static int count = 0;
    if (root == NULL) return NULL;

    if (count <= n) {
        student* l = nti_upisani(root->left, n);
        count++;

        if (l != NULL) return l;

        if (count == n) {
            return root;
        }

        return nti_upisani(root->right, n);
    }

    return NULL;
}

int main() {
    student* s = ucitaj();

    stampaj(s);

    student* nadji = pronadji_studenta(s, 1);
    if (nadji != NULL) printf("nadjen %s\n", nadji->ime);

    student* najbolji = nadji_najboljeg(s);
    if (najbolji != NULL) printf("najbolji %s\n", najbolji->ime);

    student* nti = nti_upisani(s, 3);
    if (nti != NULL) printf("nti: %s\n", nti->ime);

    oslobodi_memoriju(s);

    return 0;
}