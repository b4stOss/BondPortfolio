#include "utils.h"
#include <stdio.h>

int validate_input(double value, double min, double max) {
    return (value >= min && value <= max);
}

void wait_for_user() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for Enter key
}

void clear_screen() {
    // Clear the terminal
    printf("\033[H\033[J");
}
