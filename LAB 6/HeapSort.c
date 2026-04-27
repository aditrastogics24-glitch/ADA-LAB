#include <stdio.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (bottom-up)
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort using bottom-up approach
void heapSort(int arr[], int n) {

    // Step 1: Build max heap (bottom-up)
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap
    for (int i = n-1; i > 0; i--) {

        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;

    start = clock();  // Start time

    heapSort(arr, n);

    end = clock();    // End time

    printf("Sorted array:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %.20f seconds\n", time_taken);

    return 0;
}