#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char* ime;
    char* prezime;
    char* broj_indeksa;

    struct student* next;
} student;

void insert(student** root, student* new) {
    if (*root == NULL || strcmp(new->prezime, (*root)->prezime) < 0) {
        new->next = *root;
        *root = new;
    } else {
        student* curr = *root;
        while (curr->next != NULL && strcmp(new->prezime, curr->next->prezime) > 0) {
            curr = curr->next;
        }

        new->next = curr->next;
        curr->next = new;
    }
}

student* ucitaj() {
    FILE* fp = fopen("studenti.dat", "r");

    student* root = NULL;

    int n = 0;
    fscanf(fp, "%d\n", &n);

    for (int i = 0; i < n; i++) {
        student* new = (student*) malloc(sizeof(student));
        new->ime = (char*) malloc(50 * sizeof(char));
        new->prezime = (char*) malloc(50 * sizeof(char));
        new->broj_indeksa = (char*) malloc(50 * sizeof(char));
        new->next = NULL;

        fscanf(fp, "%[^\n]\n", new->ime);
        fscanf(fp, "%[^\n]\n", new->prezime);
        fscanf(fp, "%[^\n]\n", new->broj_indeksa);

        insert(&root, new);
    }

    fclose(fp);

    return root;
}

void print(student* root) {
    if (root != NULL) {
        puts(root->ime);
        puts(root->prezime);
        puts(root->broj_indeksa);
        puts("\n");

        print(root->next);
    }
}

void oslobodi(student* root) {
    if (root != NULL) {
        oslobodi(root->next);
        free(root->ime);
        free(root->prezime);
        free(root->broj_indeksa);
        free(root);
    }
}

int main() {
    student* s = ucitaj();

    print(s);

    oslobodi(s);

    return 0;
}