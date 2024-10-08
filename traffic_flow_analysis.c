#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10  // Default maximum number of vehicles that the road can handle

typedef struct {
    int number;               // Vehicle number
    char type[20];           // Vehicle type (car, truck, bus, etc.)
    time_t entry_time;       // Entry time of the vehicle
} Vehicle;

typedef struct {
    Vehicle vehicles[MAX];
    int top;
    int max_capacity;        // Dynamic maximum capacity
} Stack;

// Initialize the stack
void init(Stack *s, int capacity) {
    s->top = -1;
    s->max_capacity = capacity;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == s->max_capacity - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Add a vehicle to the road (Push operation)
void push(Stack *s, int number, char *type) {
    if (isFull(s)) {
        printf("The road is full! Traffic congestion occurred.\n");
    } else {
        s->top++;
        s->vehicles[s->top].number = number;
        strcpy(s->vehicles[s->top].type, type);
        s->vehicles[s->top].entry_time = time(NULL);
        printf("Vehicle %d (%s) entered the road at %s", number, type, ctime(&s->vehicles[s->top].entry_time));
    }
}

// Remove a vehicle from the road (Pop operation)
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("The road is empty! No vehicles to leave.\n");
    } else {
        Vehicle vehicle = s->vehicles[s->top];
        time_t exit_time = time(NULL);
        printf("Vehicle %d (%s) has left the road at %s", vehicle.number, vehicle.type, ctime(&exit_time));
        s->top--;
    }
}

// Check the top vehicle on the road (Peek operation)
void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("No vehicles on the road.\n");
    } else {
        Vehicle vehicle = s->vehicles[s->top];
        printf("Vehicle %d (%s) is at the front of the road.\n", vehicle.number, vehicle.type);
    }
}

// Display current traffic (all vehicles on the road)
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("No vehicles on the road.\n");
    } else {
        printf("Vehicles on the road:\n");
        for (int i = 0; i <= s->top; i++) {
            Vehicle vehicle = s->vehicles[i];
            printf("  %d (%s) - Entered at: %s", vehicle.number, vehicle.type, ctime(&vehicle.entry_time));
        }
    }
}

// Function to display traffic level
void trafficLevel(Stack *s) {
    int vehiclesOnRoad = s->top + 1; // Number of vehicles on the road

    printf("Traffic Level: ");
    
    if (vehiclesOnRoad == 0) {
        printf("No traffic.\n");
    } else if (vehiclesOnRoad <= s->max_capacity / 3) {
        printf("Low Traffic (Smooth flow).\n");
    } else if (vehiclesOnRoad <= (2 * s->max_capacity) / 3) {
        printf("Medium Traffic (Moderate flow).\n");
    } else if (vehiclesOnRoad < s->max_capacity) {
        printf("High Traffic (Heavy flow).\n");
    } else {
        printf("Traffic Congestion (Road Full).\n");
    }
}

// Function to display average traffic level (simplified for demo)
void averageTrafficLevel(Stack *s) {
    int vehiclesOnRoad = s->top + 1;
    printf("Average Traffic Level during this session: ");
    
    if (vehiclesOnRoad == 0) {
        printf("No traffic.\n");
    } else if (vehiclesOnRoad <= s->max_capacity / 3) {
        printf("Low Traffic (Smooth flow).\n");
    } else if (vehiclesOnRoad <= (2 * s->max_capacity) / 3) {
        printf("Medium Traffic (Moderate flow).\n");
    } else if (vehiclesOnRoad < s->max_capacity) {
        printf("High Traffic (Heavy flow).\n");
    } else {
        printf("Traffic Congestion (Road Full).\n");
    }
}

int main() {
    Stack road;
    int custom_capacity;
    
    printf("Enter the maximum capacity of the road: ");
    scanf("%d", &custom_capacity);
    
    init(&road, custom_capacity);
    
    int choice, vehicle_number;
    char vehicle_type[20];
    
    while (1) {
        printf("\n--- Traffic Flow Analysis (Stack) ---\n");
        printf("1. Vehicle enters the road (Push)\n");
        printf("2. Vehicle leaves the road (Pop)\n");
        printf("3. Check the top vehicle (Peek)\n");
        printf("4. Display traffic on the road\n");
        printf("5. Show traffic level on the road\n");
        printf("6. Exit with session summary\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter vehicle number: ");
                scanf("%d", &vehicle_number);
                printf("Enter vehicle type (car, truck, bus, etc.): ");
                scanf("%s", vehicle_type);
                push(&road, vehicle_number, vehicle_type);
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
                printf("Exiting...\n");
                averageTrafficLevel(&road);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
