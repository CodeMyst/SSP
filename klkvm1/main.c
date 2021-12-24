#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CENA_MALA 4
#define CENA_VELIKA 5

int duzina = 0;

void ucitaj_matricu(int** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrica[i][j]);
        }
    }
}

int deljiv_sa_dva(int broj) {
    return broj % 2 == 0;
}

int deljiv_sa_tri(int broj) {
    return broj % 3 == 0;
}

int* izdvoj(int** mat, int n, int m, int (*cmp)(int)) {
    duzina = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cmp(mat[i][j])) {
                duzina++;
            }
        }
    }

    int* res = (int*) malloc(duzina * sizeof(int));

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cmp(mat[i][j])) {
                res[k++] = mat[i][j];
            }
        }
    }

    return res;
}

int ukupna_cena(int** mat, int n, int m,
    int* (*izdv_fun)(int**, int, int, int (*fun1)(int)),
    int (*cmp_fun)(int),
    int cena) {
    
    int* izdvojeni = izdv_fun(mat, n, m, cmp_fun);

    int res = 0;
    for (int i = 0; i < duzina; i++) {
        res += cena * izdvojeni[i];
    }

    free(izdvojeni);

    return res;
}

int main() {
    int n, m;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);

    int** mat = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*) malloc(m * sizeof(int));
    }

    ucitaj_matricu(mat, n, m);

    char buff[100];
    printf("manji/veci? ");
    scanf("%s", buff);

    int (*cmp)(int);
    int* (*izdv_ptr)(int** mat, int n, int m, int (*fun)(int)) = &izdvoj;
    int cena = 0;

    if (strcmp(buff, "manji") == 0) {
        cmp = &deljiv_sa_dva;
        cena = CENA_MALA;
    } else if (strcmp(buff, "veci") == 0) {
        cmp = &deljiv_sa_tri;
        cena = CENA_VELIKA;
    } else {
        return 1;
    }

    int ukupno = ukupna_cena(mat, n, m, izdv_ptr, cmp, cena);

    printf("ukupna cena: %d\n", ukupno);

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}