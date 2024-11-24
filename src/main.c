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
                perform_scenario_analysis(&portfolio);
                break;
            case 3:
                view_portfolio_summary(&portfolio);
                break;
            case 4:
                save_portfolio(&portfolio);
                break;
            case 5:
                load_portfolio(&portfolio);
                break;
            case 6: {
                char identifier[50];
                printf("Enter Bond Identifier to delete: ");
                scanf("%s", identifier);
                delete_bond(&portfolio, identifier);
                break;
            }
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        wait_for_user();
    } while (choice != 7);

    free_portfolio(&portfolio);
    return 0;
}

// Function to display the main menu
void display_main_menu() {
    printf("Bond Portfolio Calculator\n");
    printf("1. Add New Bond to Portfolio\n");
    printf("2. Scenario Analysis\n");
    printf("3. View Portfolio Summary\n");
    printf("4. Save Portfolio to File\n");
    printf("5. Load Portfolio to File\n");
    printf("6. Delete Bond from Portfolio\n");
    printf("7. Exit\n");
}

// Function to get the user's menu choice
int get_user_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
