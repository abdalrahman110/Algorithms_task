#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int n) {
    if (n < 1 || n > 300) {
        return;
    }
    for (int j = 1; j < n; j++) {
        int key = A[j];
        if (key != 0 && key != 1 && key != 2) {
            return;
        }
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int main() {
    int A[] = {2, 1, 0, 2, 1, 0};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    insertionSort(A, n);
    printf("\n Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
