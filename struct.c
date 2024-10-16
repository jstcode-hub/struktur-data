#include <stdio.h>
#include <string.h>

// Define the motor struct
struct motor {
    float volts;
    float amps;
    int phases;
    float rpm;
};
typedef struct motor motor;

// Define the vehicle struct, containing a motor
struct vehicle {
    char model[50];
    int year;
    motor engine; // Nested motor struct
};
typedef struct vehicle vehicle;

// Function to initialize a vehicle with error handling
int init_vehicle(vehicle *v, const char *model, int year, float volts, float amps, int phases, float rpm) {
    // Check for valid motor parameter ranges
    if (volts < 0 || volts > 500) {
        printf("Error: Invalid voltage value. Must be between 0 and 500.\n");
        return -1; // Return error code
    }
    if (amps < 0 || amps > 1000) {
        printf("Error: Invalid amperage value. Must be between 0 and 1000.\n");
        return -1;
    }
    if (phases < 1 || phases > 5) {
        printf("Error: Invalid number of phases. Must be between 1 and 5.\n");
        return -1;
    }
    if (rpm < 0 || rpm > 20000) {
        printf("Error: Invalid RPM value. Must be between 0 and 20000.\n");
        return -1;
    }

    // Initialize the vehicle fields
    snprintf(v->model, sizeof(v->model), "%s", model);
    v->year = year;
    v->engine.volts = volts;
    v->engine.amps = amps;
    v->engine.phases = phases;
    v->engine.rpm = rpm;

    return 0; // Success
}

// Function to print vehicle details
void print_vehicle(const vehicle *v) {
    printf("Vehicle Model: %s\n", v->model);
    printf("Year: %d\n", v->year);
    printf("Engine Details:\n");
    printf("  Volts: %f\n", v->engine.volts);
    printf("  Amps: %f\n", v->engine.amps);
    printf("  Phases: %d\n", v->engine.phases);
    printf("  RPM: %f\n", v->engine.rpm);
}

int main() {
    vehicle myCar;

    // Initialize the vehicle with motor details
    if (init_vehicle(&myCar, "Tesla Model S", 2024, 400.5, 500.0, 3, 18000.0) == 0) {
        // Print the vehicle and motor details if initialization was successful
        print_vehicle(&myCar);
    } else {
        printf("Failed to initialize vehicle due to invalid input.\n");
    }

    return 0;
}
