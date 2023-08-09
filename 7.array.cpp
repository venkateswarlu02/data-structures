#include <stdio.h>

// Function to insert an element at a specified position
int insert(int arr[], int size, int pos, int value) {
    if (pos < 0 || pos > size) {
        return -1; // Invalid position
    }
    
    // Shift elements to make space for the new element
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[pos] = value;
    return size + 1;
}

// Function to delete an element at a specified position
int deleteElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        return -1; // Invalid position
    }
    
    // Shift elements to fill the gap left by the deleted element
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;
}

// Function to display the elements of the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size = 0; // Current size of the array
    
    int choice, pos, value;
    
    do {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                size = insert(arr, size, pos, value);
                if (size != -1) {
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Invalid position.\n");
                }
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                size = deleteElement(arr, size, pos);
                if (size != -1) {
                    printf("Element deleted successfully.\n");
                } else {
                    printf("Invalid position.\n");
                }
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 4);
    
    return 0;
}
