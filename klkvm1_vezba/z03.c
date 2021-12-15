#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prebroj(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) res++;
    }
    return res;
}

int main() {
    int br_slova = 0;

    char buffer[100] = {0};
    do {
        br_slova += prebroj(buffer);
        scanf("%s[^\n]", buffer);
    } while (strcmp(buffer, "stop") != 0);

    printf("br slova: %d\n", br_slova);

    return 0;
}
