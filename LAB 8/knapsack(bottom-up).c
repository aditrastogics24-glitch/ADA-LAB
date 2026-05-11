#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Bottom-Up Dynamic Programming approach
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // Base case
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            // If current item can be included
            else if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            }

            // Cannot include current item
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP table
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    // Input weights and values
    printf("\nEnter weight and value of each item:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d\n", i + 1);

        printf("Weight: ");
        scanf("%d", &weights[i]);

        printf("Value : ");
        scanf("%d", &values[i]);
    }

    // Input knapsack capacity
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Function call
    int maxProfit = knapsack(capacity, weights, values, n);

    // Output result
    printf("\nMaximum Profit = %d\n", maxProfit);

    return 0;
}
