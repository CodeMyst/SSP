#include <stdio.h>
#include <stdlib.h>

void z01() {
    int n;

    printf("unesi velicinu niza: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        printf("unesi %d. element niza: ", i);
        scanf("%d", &a[i]);
    }

    int* m = (int*) malloc(n*n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 0; j < n; j++) {
            m[i * n + j] = x * a[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i * n + j]);
        }
        printf("\n");
    }
}

void ucitaj(int n, float* m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%f", &m[i * n + j]);
        }
    }
}

float saberi(float a, float b) { return a + b; }
float oduzmi(float a, float b) { return a - b; }

float operacija(float* niz, int n, float (*ptr)(float, float)) {
    float x = 0.0;

    for (int i = 0; i < n; i++) {
        x += ptr(x, niz[i]);
    }

    return x;
}

float* izdvoj(int n, float* m) {
    int broj = 0;

    for (int i = 0; i < n*n; i++) {
        if (m[i] > 20.0) broj++;
    }

    float* res = (float*) malloc(broj * sizeof(float));

    int j = 0;
    for (int i = 0; i < n*n; i++) {
        if (m[i] > 20.0) res[j++] = m[i];
    }

    return res;
}

void z02() {
    int n;

    printf("unesi n: ");
    scanf("%d", &n);

    float* m = (float*) malloc(n * n * sizeof(float));

    ucitaj(n, m);

    float* izdvojeni = izdvoj(n, m);

    char op[10];
    printf("+/-?");
    scanf("%s", &op);

    float (*op_fun)(float, float);

    switch (op[0])
    {
        case '+': {
            op_fun = &saberi;
        } break;

        case '-': {
            op_fun = &oduzmi;
        } break;
    
        default: break;
    }

    float res = operacija(izdvojeni, n, op_fun);

    printf("res: %.2f\n", res);

    free(izdvojeni);

    free(m);
}

int main() {
    // z01();
    z02();

    return 0;
}
