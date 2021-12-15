#include <stdio.h>
#include <string.h>
#include "celi_brojevi.h"

#define PI 3.14

// Napisati funkciju koja kao parameter prima string i vraća broj
// pojavljivanja karaktera ‘a’ u stringu

int pojavaA(char str[]) {
    int res = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') res++;
    }

    return res;
}

// Napisati funkcije obim i površina koje kao argument primaju poluprečnik
// kruga a kao povratnu vrednost vraćaju redom obim i površinu kruga.
// Konstantu π u kodu definisati kao makro koji ima vrednost 3.14.

float obim(float r) {
    return 2 * PI * r;
}

float povrsina(float r) {
    return PI * r * r;
}

// Napisati funkciju koja kao parametar prima string i za njega proverava da
// li je palindrom.

int palindrom(char str[]) {
    for (int i = 0; i < strlen(str) / 2; i++) {
        if (str[i] != str[strlen(str) - 1 - i]) return 0;
    }

    return 1;
}

// Napisati funkciju koja kao parametar prima string i u prosleđenom stringu
// menja sva mala slova u velika (aLiBaba → ALIBABA). Funkcija nema
// povratnu vrednost.

void malaUVelika(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

// Napraviti header fajl koji definiše operacije nad celim brojevima i
// implementirati njegove funkcije. Definisati operacije +, -, *, / i % kao funkcije
// koje kao argumente primaju dva cela broja a kao rezultat vraćaju rezultat
// odgovarajuće operacije. U main-u testirati implementaciju header fajla.

int main() {
    printf("pojava a u \"alibaba\": %d\n", pojavaA("alibaba"));

    printf("obim kruga r=2 je %.2f\n", obim(2));
    printf("povrsina kruga r=2 je %.2f\n", povrsina(2));

    printf("abba je palindrom: %d\n", palindrom("abba"));
    printf("alibaba je palindrom: %d\n", palindrom("alibaba"));

    char str[] = "aLiBaba";
    malaUVelika(str);
    printf("aLiBaba -> %s\n", str);

    int a = 4;
    int b = 2;

    printf("saberi: %d\n", saberi(a, b));
    printf("oduzmi: %d\n", oduzmi(a, b));
    printf("pomnozi: %d\n", pomnozi(a, b));
    printf("podeli: %.2f\n", podeli(a, b));
    printf("moduo: %d\n", moduo(a, b));

    return 0;
}
