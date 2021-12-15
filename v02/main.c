#include <stdio.h>
#include <math.h>
#include <string.h>

float vecDot(float a[3], float b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void vecCross(float a[3], float b[3], float res[3]) {
    float ax = a[0];
    float ay = a[1];
    float az = a[2];

    float bx = b[0];
    float by = b[1];
    float bz = b[2];

    res[0] = ay * bz - az * by;
    res[1] = az * bx - ax * bz;
    res[2] = ax * by - ay * bx;
}

// Napisati program koji od korisnika učitava dva vektora (niza) dužine 3 i
// vraća skalarni proizvod i vektorski proizvod unetih vektora.
void v01() {
    float a[3];
    float b[3];

    printf("unesi prvi vektor: ");
    scanf("%f %f %f", &a[0], &a[1], &a[2]);

    printf("unesi drugi vektor: ");
    scanf("%f %f %f", &b[0], &b[1], &b[2]);

    float dot = vecDot(a, b);
    printf("skalarni proizvod: %.2f\n", dot);

    float cross[3];
    vecCross(a, b, cross);
    printf("vektorski proizvod: x: %.2f, y: %.2f, z: %.2f\n", cross[0], cross[1], cross[2]);
}

// Napisati program koji od korisnika učitava brojeve n, m i p, a zatim i dve
// matrice dimenzija nxm i mxp i određuje proizvod unetih matrica.
void v02() {
    int n;
    int m;
    int p;

    int a[10][10];
    int b[10][10];
    int res[10][10];

    printf("unesi n: ");
    scanf("%d", &n);
    printf("unesi m: ");
    scanf("%d", &m);
    printf("unesi p: ");
    scanf("%d", &p);

    printf("prva matrica:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("druga matrica:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("proizvod:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

// Napisati program koji od korisnika učitava string, a zatim svaku pojavu
// simbola x zamenjuje slovima ks. Primer: extra -> ekstra.
void v03() {
    char input[20];
    char output[20];

    printf("unesi tekst: ");
    gets(input);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'x') {
            strcat(output, "ks");
        } else {
            strncat(output, &input[i], 1);
        }
    }

    printf("rezultat: %s\n", output);
}

int main() {
    // v01();
    // v02();
    // v03();

    return 0;
}