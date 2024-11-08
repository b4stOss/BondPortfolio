#include <stdio.h>
#include "main.h"
#include "bond.h"
#include "portfolio.h"
#include "scenario.h"
#include "file_handler.h"
#include "utils.h"

int main() {
    int choice;
    Portfolio portfolio = create_portfolio();

    do {
        clear_screen();
        display_main_menu();
        choice = get_user_choice();
        clear_screen();
        
        switch (choice) {
            case 1:
                add_new_bond_to_portfolio(&portfolio);
                break;
            case 2:
                calculate_portfolio_value(&portfolio);
                break;
            case 3:
                perform_scenario_analysis(&portfolio);
                break;
            case 4:
                view_portfolio_summary(&portfolio);
                break;
            case 5:
                save_portfolio(&portfolio);
                break;
            case 6:
                load_portfolio(&portfolio);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        wait_for_user();
    } while (choice != 7);

    return 0;
}

void display_main_menu() {
    printf("Bond Portfolio Calculator\n");
    printf("1. Add New Bond to Portfolio\n");
    printf("2. Calculate Portfolio Value\n");
    printf("3. Scenario Analysis\n");
    printf("4. View Portfolio Summary\n");
    printf("5. Save Portfolio\n");
    printf("6. Load Portfolio\n");
    printf("7. Exit\n");
}

// Function to get the user's menu choice
int get_user_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
