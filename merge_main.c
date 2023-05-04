#include <stdio.h>

void merge(int nums[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = nums[start+i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = nums[mid+1+j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int nums[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);

        merge(nums, start, mid, end);
    }
}

void sort_colors(int nums[], int n) {
    merge_sort(nums, 0, n-1);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort_colors(nums, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
