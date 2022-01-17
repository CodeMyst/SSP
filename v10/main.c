#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char dest[50];
    float dist;
    float price;

    struct node* left;
    struct node* right;
} node;

void dodaj(node** root, node* new) {
    if (*root == NULL) {
        *root = new;
        new->left = NULL;
        new->right = NULL;
    } else {
        if (new->dist > (*root)->dist) {
            dodaj(&(*root)->right, new);
        } else {
            dodaj(&(*root)->left, new);
        }
    }
}

node* ucitaj() {
    FILE* fp = fopen("agencija.txt", "r");

    int count = 0;
    fscanf(fp, "%d\n", &count);

    node* root = NULL;

    for (int i = 0; i < count; i++) {
        node* new = (node*) malloc(sizeof(node));
        fgets(new->dest, 50, fp);
        fscanf(fp, "%f\n", &new->dist);
        fscanf(fp, "%f\n", &new->price);

        dodaj(&root, new);
    }

    fclose(fp);

    return root;
}

void dodaj_lista_pom(node** curr, node** prev, node* new) {
    if (*curr) {
        if ((*curr)->price < new->price) {
            dodaj_lista_pom(&((*curr)->right), curr, new);
        } else if (*prev) {
            (*prev)->right = new;
            new->right = *curr;
        } else {
            new->right = (*curr)->right;
            *curr = new;
        }
    } else {
        if (*prev) {
            (*prev)->right = new;
            new->right = NULL;
        } else {
            *curr = new;
            new->right = NULL;
        }
    }
}

void dodaj_lista(node** root, node* n) {
    if (n == NULL) return;

    if (n->dist < 1000.0) {
        node* new = (node*) malloc(sizeof(node));
        strncpy(new->dest, n->dest, 50);
        new->dist = n->dist;
        new->price = n->price;
        new->left = NULL;

        node* prev = NULL;
        dodaj_lista_pom(root, &prev, new);
        dodaj_lista(root, n->left);
        dodaj_lista(root, n->right);
    } else {
        dodaj_lista(root, n->left);
        dodaj_lista(root, n->right);
    }
}

void ponuda(node* curr, float budget) {
    if (curr == NULL) return;

    if (curr->price <= budget) {
        printf("%s %f %f\n", curr->dest, curr->price, curr->dist);

        ponuda(curr->left, budget);
        ponuda(curr->right, budget);
    } else {
        ponuda(curr->left, budget);
        ponuda(curr->right, budget);
    }
}

node* povoljne_ponude(node* root) {
    node* res = NULL;
    dodaj_lista(&res, root);
    return res;
}

void stampaj(node* curr) {
    if (curr == NULL) return;

    stampaj(curr->left);

    printf("%s %f %f\n", curr->dest, curr->price, curr->dist);

    stampaj(curr->right);
}

void oslobodi_memoriju(node* curr) {
    if (curr == NULL) return;

    oslobodi_memoriju(curr->left);
    oslobodi_memoriju(curr->right);

    free(curr);
}

int main() {
    node* curr = ucitaj();

    stampaj(curr);

    printf("-----\n");

    node* list = povoljne_ponude(curr);

    stampaj(list);

    printf("-----\n");

    ponuda(curr, 200.0);

    printf("-----\n");

    ponuda(curr, 450.0);

    oslobodi_memoriju(list);
    oslobodi_memoriju(curr);

    return 0;
}