#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// Function to validate input within a specified range
int validate_input(double value, double min, double max) {
    return value >= min && value <= max;
}

// Function to wait for user input before continuing
void wait_for_user() {
    printf("Press Enter to continue...");
    getchar();
    getchar(); // To consume the newline character left by scanf
}

// Function to clear the terminal screen
void clear_screen() {
    // Platform-specific clear screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
