#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// za uneti broj dana (ceo broj) ispisuje koliko je to godina, nedelja, dana
void v01() {
    int brojDana;

    printf("unesi broj dana: ");

    scanf("%d", &brojDana);

    int godina = brojDana / 365;
    int nedelja = (brojDana % 365) / 7;
    int dana = (brojDana % 365) % 7;

    printf("godina: %d\nnedelja: %d\ndana: %d\n", godina, nedelja, dana);
}

// za unesen poluprecnik kruga (realan broj) racuna njegov obim
void v02() {
    float r;

    printf("unesi poluprecnik kruga: ");

    scanf("%f", &r);

    float obim = 2 * r * 3.14;

    printf("obim: %.2f\n", obim);
}

// za dve unesene tacke (koordinate su realni brojevi) racuna rastojanje izmedju njih
void v03() {
    float x1;
    float y1;
    float x2;
    float y2;

    printf("unesi prvu tacku: ");

    scanf("%f %f", &x1, &y1);

    printf("unesi drugu tacku: ");

    scanf("%f %f", &x2, &y2);

    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("rastojanje: %.2f\n", dist);
}

// za unesenu kolicinu novca (ceo broj) racuna na koji nacin je najpogodnije izvrsiti isplatu tako da se dobije najmanji broj novcanica
// novcanice postoje u apoenima od 100, 50, 20, 10, 5, 2 i 1
void v04() {
    int novac;
    printf("unesi kolicinu novca: ");
    scanf("%d", &novac);

    int n100 = novac / 100;
    int n50 = (novac % 100) / 50;
    int n20 = (novac % 100 % 50) / 20;
    int n10 = (novac % 100 % 50 % 20) / 10;
    int n5 = (novac % 100 % 50 % 20 % 10) / 5;
    int n2 = (novac % 100 % 50 % 20 % 10 % 5) / 2;
    int n1 = (novac % 100 % 50 % 20 % 10 % 5 % 1);

    printf("n100: %d\nn50: %d\nn20: %d\nn10: %d\nn5: %d\nn2: %d\nn1: %d\n", n100, n50, n20, n10, n5, n2, n1);
}

// ispisuje tabelu konverzije temperatura koje se nalaze u intervalu od 0F do 300F u C
// razlika izmedju dve susedne vrednosti u tabeli neka bude 50
void v05() {
    for (int f = 0; f <= 300; f += 20) {
        float c = (f - 32) * 5.0/9.0;

        printf("%df = %.2ff\n", f, c);
    }
}

// igra pogadjanja broja
// racunar zamislja broj od 0 do 50, a korisnik unosi brojeve sve dok ne pogodi zamisljeni broj
void v06() {
    int min = 0;
    int max = 50;

    srand(time(NULL));

    int r = rand() % (max - min) + min;

    int guess;
    int tries = 0;
    int pogodak = 0;
    while (!pogodak) {
        printf("broj: ");
        scanf("%d", &guess);

        tries++;

        if (guess == r) {
            pogodak = 1;
            printf("pogodjen broj u %d pokusaja\n", tries);
        } else if (r > guess) {
            printf("random broj je veci\n");
        } else {
            printf("random broj je manji\n");
        }
    }
}

// za uneti broj vraca broj koji se dobije obrtanjem redosleda cifara unetog broja
void v07() {
    int d;
    printf("unesi broj: ");
    scanf("%d", &d);

    int res = 0;
    int cif = 0;

    while (d > 0) {
        cif = d % 10;
        res = (res * 10) + cif;
        d /= 10;
    }

    printf("obrnuti broj: %d\n", res);
}

int main() {
    // v01();
    // v02();
    // v03();
    // v04();
    // v05();
    // v06();
    // v07();

    // printf("test\123");

    return 0;
}