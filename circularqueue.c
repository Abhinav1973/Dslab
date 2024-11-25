#include <stdio.h>
#include <stdlib.h>
int *a;
int front = 0, rear = 0, n, count = 0;

void display() {
    int i;

    if (count == 0) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

   // printf("\nTHE QUEUE IS:\n");
    for (i = 0; i < count; i++) {
        int index = (front + 1 + i) % n;
        printf("%d \n", a[index]);
    }
    printf("\n");
}

void insert() {
    if (count == n) {
        printf("QUEUE IS FULL\n");
    } else {
        rear = (rear + 1) % n;
        printf("\nEnter the element: ");
        scanf("%d", &a[rear]);
        count++;
        display();
    }
}

void delete() {
    if (count == 0) {
        printf("QUEUE EMPTY\n");
    } else {
        front = (front + 1) % n;
        printf("\nDELETED ELEMENT %d FROM QUEUE\n", a[front]);
        count--;
        display();
    }
}

void search() {
    int element, i, position = -1;

    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < count; i++) {
        int index = (front + 1 + i) % n;
        if (a[index] == element) {
            position = i + 1;
            break;
        }
    }

    if (position != -1) {
        printf("Element %d found at position %d .\n", element, position);
    } else {
        printf("Element %d not in the queue.\n", element);
    }
}

int main() {
    int choice;
    printf("ENTER THE SIZE OF THE CIRCULAR QUEUE : ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    /*if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }*/

    while (1) {
        printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. SEARCH\n5. EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: search();
                    break;
            case 5:
                   exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
