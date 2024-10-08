#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100  // Maximum number of vehicles that the road can handle
#define FILENAME "traffic_data.txt"

// Structure for vehicle data
typedef struct {
    int number;              // Vehicle number
    char type[20];           // Vehicle type (car, truck, bus, etc.)
    time_t entry_time;       // Entry time of the vehicle
    int priority;            // Priority level of the vehicle (1: High, 2: Medium, 3: Low)
} Vehicle;

// Structure for the stack
typedef struct {
    Vehicle vehicles[MAX];
    int top;
    int max_capacity;       // Dynamic maximum capacity
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
void push(Stack *s, int number, char *type, int priority) {
    if (isFull(s)) {
        printf("The road is full! Traffic congestion occurred.\n");
    } else {
        // Insert vehicle based on priority
        int i = s->top;
        while (i >= 0 && s->vehicles[i].priority >= priority) {
            s->vehicles[i + 1] = s->vehicles[i]; // Shift vehicles to make space
            i--;
        }
        s->top++;
        s->vehicles[i + 1].number = number;
        strcpy(s->vehicles[i + 1].type, type);
        s->vehicles[i + 1].entry_time = time(NULL);
        s->vehicles[i + 1].priority = priority;

        // Save vehicle entry to file
        FILE *file = fopen(FILENAME, "a");
        if (file) {
            fprintf(file, "Vehicle %d (%s) entered at %s", number, type, ctime(&s->vehicles[i + 1].entry_time));
            fclose(file);
        } else {
            printf("Error opening file!\n");
        }

        printf("Vehicle %d (%s) with priority %d entered the road at %s", number, type, priority, ctime(&s->vehicles[i + 1].entry_time));
    }
}

// Remove a vehicle from the road (Pop operation)
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("The road is empty! No vehicles to leave.\n");
    } else {
        Vehicle vehicle = s->vehicles[s->top];
        time_t exit_time = time(NULL);

        // Save vehicle exit to file
        FILE *file = fopen(FILENAME, "a");
        if (file) {
            fprintf(file, "Vehicle %d (%s) left at %s", vehicle.number, vehicle.type, ctime(&exit_time));
            fclose(file);
        } else {
            printf("Error opening file!\n");
        }

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

// Display traffic level
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

// Change the road capacity
void changeCapacity(Stack *s) {
    int new_capacity;
    printf("Enter new maximum capacity for the road: ");
    scanf("%d", &new_capacity);

    if (new_capacity > MAX) {
        printf("Maximum capacity exceeded!\n");
        return;
    }

    s->max_capacity = new_capacity;
    printf("Road capacity updated to %d vehicles.\n", new_capacity);
}

// Average time spent on the road
void averageTimeOnRoad(Stack *s) {
    if (isEmpty(s)) {
        printf("No vehicles on the road to calculate average time.\n");
        return;
    }

    time_t total_time = 0;
    for (int i = 0; i <= s->top; i++) {
        total_time += difftime(time(NULL), s->vehicles[i].entry_time);
    }

    double average_time = total_time / (double)(s->top + 1);
    printf("Average time spent on the road: %.2f seconds.\n", average_time);
}

// Predict traffic level based on current pattern
void trafficPrediction(Stack *s) {
    int vehiclesOnRoad = s->top + 1;

    printf("\nTraffic Prediction:\n");
    if (vehiclesOnRoad > s->max_capacity * 0.9) {
        printf("Warning: Heavy congestion expected in the next 10 minutes!\n");
    } else if (vehiclesOnRoad > s->max_capacity * 0.5) {
        printf("Moderate traffic flow predicted for the next 10 minutes.\n");
    } else {
        printf("Traffic is expected to remain smooth.\n");
    }
}

// Traffic statistics by vehicle type
void displayStatistics(Stack *s) {
    if (isEmpty(s)) {
        printf("No traffic data available.\n");
        return;
    }

    int car_count = 0, truck_count = 0, bus_count = 0;
    for (int i = 0; i <= s->top; i++) {
        if (strcmp(s->vehicles[i].type, "car") == 0) car_count++;
        else if (strcmp(s->vehicles[i].type, "truck") == 0) truck_count++;
        else if (strcmp(s->vehicles[i].type, "bus") == 0) bus_count++;
    }

    printf("\nTraffic Statistics:\n");
    printf("Total Vehicles: %d\n", s->top + 1);
    printf("Cars: %d, Trucks: %d, Buses: %d\n", car_count, truck_count, bus_count);
}

// Login function for user authentication
void userLogin() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Username: yashh, Password: 0001
    if (strcmp(username, "yashh") == 0 && strcmp(password, "0001") == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed! Exiting program.\n");
        exit(1);
    }
}

int main() {
    Stack road;
    int custom_capacity;

    // User authentication
    userLogin();

    printf("Enter the maximum capacity of the road: ");
    scanf("%d", &custom_capacity);
    
    init(&road, custom_capacity);
    
    int choice, vehicle_number, priority;
    char vehicle_type[20];
    
    while (1) {
        printf("\n--- Traffic Flow Analysis (Advanced) ---\n");
        printf("1. Vehicle enters the road\n");
        printf("2. Vehicle leaves the road\n");
        printf("3. View top vehicle on road\n");
        printf("4. Display all vehicles on road\n");
        printf("5. Display current traffic level\n");
        printf("6. Change road capacity\n");
        printf("7. Display average time on road\n");
        printf("8. View traffic statistics\n");
        printf("9. Predict future traffic level\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter vehicle number: ");
                scanf("%d", &vehicle_number);
                printf("Enter vehicle type (car, truck, bus, etc.): ");
                scanf("%s", vehicle_type);
                printf("Enter vehicle priority (1: High, 2: Medium, 3: Low): ");
                scanf("%d", &priority);
                push(&road, vehicle_number, vehicle_type, priority);
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
                changeCapacity(&road);
                break;
            case 7:
                averageTimeOnRoad(&road);
                break;
            case 8:
                displayStatistics(&road);
                break;
            case 9:
                trafficPrediction(&road);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
