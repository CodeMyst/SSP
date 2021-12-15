#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int brIzdvojenih = 0;

float* izdvoj(float* arr, int n) {
    brIzdvojenih = 0;
    int nums = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > PI) nums++;
    }
    
    float* res = (float*) malloc(nums * sizeof(float));

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > PI) {
            res[k++] = arr[i];
            brIzdvojenih++;
        }
    }

    return res;
}

int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    float* arr = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        scanf("%f", &arr[i]);
    }

    float* izdvojeni = izdvoj(arr, n);

    for (int i = 0; i < brIzdvojenih; i++) {
        printf("%f\n", izdvojeni[i]);
    }

    free(izdvojeni);

    free(arr);

    return 0;
}
