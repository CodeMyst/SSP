#include <stdio.h>
#include <stdlib.h>

int brIzdvojenih = 0;

void ucitaj_cene(float** police, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%f", &police[i][j]);
        }
    }
}

int veci_od(float a, float b) { return a > b; }
int manji_od(float a, float b) { return a < b; }

float** izdvoji(float** police, int n, float cmp, int(*fun)(float, float)) {
    brIzdvojenih = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fun(police[i][j], cmp)) {
                brIzdvojenih++;
            }
        }
    }

    float** res = (float**) malloc(brIzdvojenih * sizeof(float*));

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fun(police[i][j], cmp)) {
                res[k++] = &police[i][j];
            }
        }
    }

    return res;
}

void uvecaj(float* val, float perc) {
    *val += *val * perc;
}

void umanji(float* val, float perc) {
    *val -= *val * perc;
}

void modifikuj_vrednosti(float** arr, int n, float perc, void (*fun)(float*, float)) {
    for (int i = 0; i < n; i++) {
        fun(arr[i], perc);
    }
}

int main() {
    int n;

    printf("unesi velicinu police: ");
    scanf("%d", &n);

    float** police = (float**) malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        police[i] = (float*) malloc(n * sizeof(float));
    }

    ucitaj_cene(police, n);

    char op;
    printf("+ / - ? ");
    scanf(" %c", &op);

    int(*cmp_fun)(float, float);
    void(*mod_fun)(float*, float);

    switch (op) {
        case '+': {
            cmp_fun = &veci_od;
            mod_fun = &uvecaj;
            printf("cena veca od: ");
        } break;

        case '-': {
            cmp_fun = &manji_od;
            mod_fun = &umanji;
            printf("cena manja od: ");
        } break;

        default: return 1;
    }

    float cmp;
    scanf("%f", &cmp);

    float** cene = izdvoji(police, n, cmp, cmp_fun);

    float perc;
    printf("postotak za koliko da se promeni cena [0, 1]: ");
    scanf("%f", &perc);

    modifikuj_vrednosti(cene, brIzdvojenih, perc, mod_fun);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]: %.2f\n", i, j, police[i][j]);
        }
    }

    free(cene);

    for (int i = 0; i < n; i++) {
        free(police[i]);
    }

    free(police);

    return 0;
}
