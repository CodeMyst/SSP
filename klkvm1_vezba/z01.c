#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int n) {
    int key = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}
