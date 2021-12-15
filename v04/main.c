#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void stat(int* niz, int n, int* min, int* max, int* avg) {
    *min = INT_MAX;
    *max = INT_MIN;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int el = niz[i];

        if (el > *max) *max = el;
        if (el < *min) *min = el;

        sum += el;
    }

    *avg = sum / n;
}

void ucitaj(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        int el;
        printf("unesi %d. element niza: ", (i+1));
        scanf("%d", &el);
        niz[i] = el;
    }
}

void ispisi_obrnuto(int* niz, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", niz[i]);
    }
}

void sort(int* niz, int n, int** res) {
    int i, j;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (*res[j] > *res[j+1]) {
                int* tmp = res[j];
                res[j] = res[j+1];
                res[j+1] = tmp;
            }
        }
    }
}

int main() {
    int n;

    printf("unesi velicinu niza: ");
    scanf("%d", &n);

    int niz[n];

    ucitaj(niz, n);

    int min;
    int max;
    int avg;

    stat(niz, n, &min, &max, &avg);

    printf("min: %d, max: %d, avg: %d\n", min, max, avg);

    ispisi_obrnuto(niz, n);

    int* niz_pok[n];

    for (int i = 0; i < n; i++) {
        niz_pok[i] = niz + i;
    }

    sort(niz, n, niz_pok);

    for (int i = 0; i < n; i++) {
        printf("%d\n", *niz_pok[i]);
    }

    return 0;
}
