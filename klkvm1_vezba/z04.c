#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ucitaj_knjige(char** knjige, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        getchar();
        scanf("%50[^\n]", knjige[i]);
    }
}

void sortiraj(char** knjige, int n) {
    char* key = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        key = knjige[i];
        j = i - 1;

        while (j >= 0 && strcmp(key, knjige[j]) < 0) {
            knjige[j+1] = knjige[j];
            j--;
        }

        knjige[j+1] = key;
    }
}

int main() {
    int n;
    printf("broj knjiga: ");
    scanf("%d", &n);

    char** knjige = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        knjige[i] = (char*) malloc(50 * sizeof(char));
    }

    ucitaj_knjige(knjige, n);

    sortiraj(knjige, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", knjige[i]);
    }

    for (int i = 0; i < n; i++) {
        free(knjige[i]);
    }
    free(knjige);

    return 0;
}
