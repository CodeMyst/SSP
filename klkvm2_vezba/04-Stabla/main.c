#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct birb {
    int id;
    char* name;

    struct birb* left;
    struct birb* right;
} birb;

void dodaj(birb** root, birb* cvrle) {
    if (*root == NULL) {
        *root = cvrle;
        cvrle->left = NULL;
        cvrle->right = NULL;
    } else {
        if (cvrle->id > (*root)->id) {
            dodaj(&(*root)->right, cvrle);
        } else {
            dodaj(&(*root)->left, cvrle);
        }
    }
}

birb* ucitaj() {
    FILE* fp = fopen("ptice.txt", "r");

    birb* root = NULL;

    int n = 0;
    fscanf(fp, "%d\r\n", &n);

    for (int i = 0; i < n; i++) {
        birb* cvrle = (birb*) malloc(sizeof(birb));
        cvrle->name = (char*) malloc(50 * sizeof(char));

        fscanf(fp, "%d\r\n", &cvrle->id);
        fscanf(fp, "%[^\r\n]\r\n", cvrle->name);

        dodaj(&root, cvrle);
    }

    fclose(fp);

    return root;
}

void oslobodi_memoriju(birb* root) {
    if (root == NULL) return;

    oslobodi_memoriju(root->left);
    oslobodi_memoriju(root->right);

    free(root->name);
    free(root);
}

void ispisi_stablo(birb* root) {
    if (root == NULL) return;

    printf("%d %s\n", root->id, root->name);

    ispisi_stablo(root->left);
    ispisi_stablo(root->right);
}

void pp_odnos(birb* root, int* asc, int* desc) {
    if (root == NULL) return;

    if (root->left != NULL && root->right != NULL) {
        (*asc)++;
    } else {
        (*desc)++;
    }

    pp_odnos(root->left, asc, desc);
    pp_odnos(root->right, asc, desc);
}

void prebroj_golubove(birb* root, int* bogoviHleba) {
    if (root == NULL) return;

    if (strstr(root->name, "Columb") != NULL) {
        (*bogoviHleba)++;
    }

    prebroj_golubove(root->left, bogoviHleba);
    prebroj_golubove(root->right, bogoviHleba);
}

int main() {
    birb* birbs = ucitaj();

    ispisi_stablo(birbs);

    int asc = 0;
    int desc = 0;
    pp_odnos(birbs, &asc, &desc);

    printf("asc: %d, desc: %d\n", asc, desc);

    int bogoviHleba = 0;
    prebroj_golubove(birbs, &bogoviHleba);

    printf("bogova hleba: %d\n", bogoviHleba);

    oslobodi_memoriju(birbs);

    return 0;
}