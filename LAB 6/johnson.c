#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print the current permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Find the largest mobile element index
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        int next = i + dir[i];

        if (next >= 0 && next < n && perm[i] > perm[next]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void johnsonTrotter(int n) {
    int perm[n];
    int dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print the first permutation
    printPermutation(perm, n);

    while (1) {
        int mobileIndex = getMobile(perm, dir, n);

        // No mobile element → done
        if (mobileIndex == -1)
            break;

        int swapWith = mobileIndex + dir[mobileIndex];

        // Swap elements
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapWith];
        perm[swapWith] = temp;

        // Swap directions
        int tempDir = dir[mobileIndex];
        dir[mobileIndex] = dir[swapWith];
        dir[swapWith] = tempDir;

        mobileIndex = swapWith;
        int mobileValue = perm[mobileIndex];

        // Reverse direction of elements greater than mobileValue
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobileValue)
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
