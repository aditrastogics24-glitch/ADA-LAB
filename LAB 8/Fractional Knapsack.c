#include <stdio.h>

// Structure for an item
struct Item {
    int weight;
    int value;
    float ratio; // value / weight
};

// Function to sort items by ratio in descending order
void sortItems(struct Item items[], int n) {
    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            // Sort based on higher value/weight ratio
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Fractional Knapsack using Greedy Technique
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;

    // Sort items by ratio
    sortItems(items, n);

    printf("\nItems selected:\n");

    for (int i = 0; i < n; i++) {

        // If full item can be taken
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;

            printf("Took full item -> Weight: %d  Value: %d\n",
                   items[i].weight, items[i].value);
        }

        // Take fractional part
        else {
            float fraction = (float)capacity / items[i].weight;

            totalValue += items[i].value * fraction;

            printf("Took %.2f fraction of item -> Weight: %d  Value: %d\n",
                   fraction, items[i].weight, items[i].value);

            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input item details
    printf("\nEnter weight and value of each item:\n");

    for (int i = 0; i < n; i++) {
        printf("\nItem %d\n", i + 1);

        printf("Weight: ");
        scanf("%d", &items[i].weight);

        printf("Value : ");
        scanf("%d", &items[i].value);

        // Calculate value/weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Function call
    float maxValue = fractionalKnapsack(items, n, capacity);

    // Output
    printf("\nMaximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
