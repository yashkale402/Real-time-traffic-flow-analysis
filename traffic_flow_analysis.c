#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum number of vehicles that the road can handle

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Add a vehicle to the road (Push operation)
void push(Stack *s, int vehicle) {
    if (isFull(s)) {
        printf("The road is full! Traffic congestion occurred.\n");
    } else {
        s->items[++(s->top)] = vehicle;
        printf("Vehicle %d entered the road.\n", vehicle);
    }
}

// Remove a vehicle from the road (Pop operation)
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("The road is empty! No vehicles to leave.\n");
    } else {
        int vehicle = s->items[(s->top)--];
        printf("Vehicle %d has left the road.\n", vehicle);
    }
}

// Check the top vehicle on the road (Peek operation)
void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("No vehicles on the road.\n");
    } else {
        printf("Vehicle %d is at the front of the road.\n", s->items[s->top]);
    }
}

// Display current traffic (all vehicles on the road)
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("No vehicles on the road.\n");
    } else {
        printf("Vehicles on the road: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

// Function to display traffic level
void trafficLevel(Stack *s) {
    int vehiclesOnRoad = s->top + 1; // Number of vehicles on the road

    printf("Traffic Level: ");
    
    if (vehiclesOnRoad == 0) {
        printf("No traffic.\n");
    } else if (vehiclesOnRoad <= MAX / 3) {
        printf("Low Traffic (Smooth flow).\n");
    } else if (vehiclesOnRoad <= (2 * MAX) / 3) {
        printf("Medium Traffic (Moderate flow).\n");
    } else if (vehiclesOnRoad < MAX) {
        printf("High Traffic (Heavy flow).\n");
    } else {
        printf("Traffic Congestion (Road Full).\n");
    }
}

int main() {
    Stack road;
    init(&road);
    
    int choice, vehicle;
    
    while (1) {
        printf("\n--- Traffic Flow Analysis (Stack) ---\n");
        printf("1. Vehicle enters the road (Push)\n");
        printf("2. Vehicle leaves the road (Pop)\n");
        printf("3. Check the top vehicle (Peek)\n");
        printf("4. Display traffic on the road\n");
        printf("5. Show traffic level on the road\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter vehicle number: ");
                scanf("%d", &vehicle);
                push(&road, vehicle);
                trafficLevel(&road);
                break;
            case 2:
                pop(&road);
                trafficLevel(&road);
                break;
            case 3:
                peek(&road);
                break;
            case 4:
                display(&road);
                break;
            case 5:
                trafficLevel(&road);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
