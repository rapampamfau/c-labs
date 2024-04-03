#include <stdio.h>

int binary_search_recursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
            
        if (arr[mid] > x)
            return binary_search_recursive(arr, left, mid - 1, x);

        return binary_search_recursive(arr, mid + 1, right, x);
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binary_search_recursive(arr, 0, n - 1, x);
    (result == -1) ? printf("Element nie został znaleziony w tablicy.\n")
                   : printf("Element znajduje się pod indeksem %d.\n", result);
    return 0;
}
