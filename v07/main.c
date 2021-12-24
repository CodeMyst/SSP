#include <stdio.h>
#include <stdlib.h>

int brIzdvojenih = 0;

typedef struct Osoba {
    char ime[50];
    char prezime[100];
    unsigned int godine;
    unsigned int godine_iskustva;
} Osoba;

Osoba* ucitaj_osobe(int n) {
    Osoba* res = (Osoba*) malloc(n * sizeof(Osoba));

    for (int i = 0; i < n; i++) {
        printf("ime[50]: ");
        scanf("%50s", res[i].ime);

        printf("prezime[100]: ");
        scanf("%100s", res[i].prezime);

        printf("godine: ");
        scanf("%u", &res[i].godine);

        printf("godine iskustva: ");
        scanf("%u", &res[i].godine_iskustva);
    }

    return res;
}

double prosecna_starost(Osoba* osobe, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += osobe[i].godine;
    }

    return sum / n;
}

double prosecni_radni_staz(Osoba* osobe, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += osobe[i].godine_iskustva;
    }

    return sum / n;
}

Osoba* izdvoj(Osoba* osobe, int n) {
    brIzdvojenih = 0;
    for (int i = 0; i < n; i++) {
        if (osobe[i].godine > 50 && osobe[i].godine_iskustva > 20) {
            brIzdvojenih++;
        }
    }

    Osoba* res = (Osoba*) malloc(brIzdvojenih * sizeof(Osoba));

    int k = 0;
    for (int i = 0; i < brIzdvojenih; i++) {
        if (osobe[i].godine > 50 && osobe[i].godine_iskustva > 20) {
            res[k++] = osobe[i];
        }
    }

    return res;
}

void ispis(Osoba* osobe, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", osobe[i].ime, osobe[i].prezime, osobe[i].godine, osobe[i].godine_iskustva);
    }
}

int main() {
    int n;
    printf("unesi broj osoba: ");
    scanf("%d", &n);

    Osoba* osobe = ucitaj_osobe(n);

    double starost = prosecna_starost(osobe, n);
    double staz = prosecni_radni_staz(osobe, n);

    Osoba* izdvojeni = izdvoj(osobe, n);

    ispis(izdvojeni, brIzdvojenih);

    printf("prosecna staros: %.2f\n", starost);
    printf("prosecni radni staz: %.2f\n", staz);

    free(izdvojeni);
    free(osobe);

    return 0;
}