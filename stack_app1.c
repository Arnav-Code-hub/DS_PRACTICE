#include <stdio.h>

// 1. Pass the specific top pointer so the function knows WHICH stack to check
int isstackfull(int n, int current_top) {
    if (current_top == n - 1) {
        printf("stack is full\n");
        return 1;
    }
    return 0;
}

int isstackempty(int current_top) {
    if (current_top == -1) {
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}

// Use int *current_top so we can modify the original top_even or top_odd variable
void push(int arr[], int n, int *current_top, int x) {
    if (!isstackfull(n, *current_top)) {
        (*current_top)++;            // Increase the specific top
        arr[*current_top] = x;       // Insert at the new top
    }
}

void pop(int arr[], int n, int *current_top) {
    if (!isstackempty(*current_top)) {
        printf("popped item is:- %d\n", arr[*current_top]);
        (*current_top)--;            // Decrease the specific top
    }
}

// FIX: Spelled 'display' correctly
void display(int arr[], int current_top) {
    if (current_top == -1) {
        printf("stack is empty");
    }
    for (int i = current_top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void peek(int arr[], int current_top) {
    if (current_top == -1) {
        printf("stack is empty\n");
    } else {
        printf("peeked element is :- %d\n", arr[current_top]);
    }
}

int main() {
    int n;
    printf("enter max size of Stacks:- ");
    scanf("%d", &n);

    int arr_even[n];
    int arr_odd[n];
    
    // 2. Separate top variables for each stack
    int top_even = -1;
    int top_odd = -1;

    printf("\nenter 1 to push\n");
    printf("enter 2 to pop\n");
    printf("enter 3 to peek\n");
    printf("enter 4 to display\n");
    printf("enter 5 to exit\n");

    int choice;
    printf("enter your choice:- ");
    scanf("%d", &choice); // Get first choice before the loop

    while (choice != 5) {
        switch (choice) {
            case 1: {
                int x;
                printf("enter element to push:- ");
                scanf("%d", &x);

                if (x % 2 == 0) {
                    // Pass the memory address (&) of top_even
                    push(arr_even, n, &top_even, x);
                    printf("Pushed to EVEN stack.\n");
                } else {
                    // Pass the memory address (&) of top_odd
                    push(arr_odd, n, &top_odd, x);
                    printf("Pushed to ODD stack.\n");
                }
                break;
            }
            case 2: {
                int stackChoice;
                printf("Pop from which stack? (1 for Even, 2 for Odd): ");
                scanf("%d", &stackChoice);
                if (stackChoice == 1) pop(arr_even, n, &top_even);
                else if (stackChoice == 2) pop(arr_odd, n, &top_odd);
                break;
            }
            case 3: {
                int stackChoice;
                printf("Peek which stack? (1 for Even, 2 for Odd): ");
                scanf("%d", &stackChoice);
                if (stackChoice == 1) peek(arr_even, top_even);
                else if (stackChoice == 2) peek(arr_odd, top_odd);
                break;
            }
            case 4:
                printf("EVEN Stack: ");
                display(arr_even, top_even);
                printf("ODD Stack:  ");
                display(arr_odd, top_odd);
                break;
            default:
                printf("invalid choice\n");
        }
        printf("\nenter your choice (1-Push, 2-Pop, 3-Peek, 4-Display, 5-Exit):- ");
        scanf("%d", &choice);
    }

    return 0;
}