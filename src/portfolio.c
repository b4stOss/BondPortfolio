#include "portfolio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize an empty portfolio
Portfolio create_portfolio() {
    Portfolio portfolio;
    portfolio.bond_count = 0;
    portfolio.capacity = 10; // Initial capacity
    portfolio.bonds = (Bond *)malloc(portfolio.capacity * sizeof(Bond));
    return portfolio;
}

// Function to add a new bond to the portfolio
void add_bond(Portfolio *portfolio, const Bond *bond) {
    if (portfolio->bond_count >= portfolio->capacity) {
        portfolio->capacity *= 2;
        portfolio->bonds = (Bond *)realloc(portfolio->bonds, portfolio->capacity * sizeof(Bond));
    }
    portfolio->bonds[portfolio->bond_count++] = *bond;
}

// Function to calculate total portfolio value
double calculate_portfolio_value(const Portfolio *portfolio) {
    double total_value = 0.0;
    for (int i = 0; i < portfolio->bond_count; i++) {
        total_value += calculate_bond_price(&portfolio->bonds[i]);
    }
    return total_value;
}

// Function to add a new bond to the portfolio based on user input
void add_new_bond_to_portfolio(Portfolio *portfolio) {
    if (portfolio->bond_count >= 100) {
        printf("Portfolio is full. Cannot add more bonds.\n");
        return;
    }

    Bond bond;

    // Gather bond information from user
    printf("Enter Bond Identifier: ");
    scanf("%s", bond.identifier);

    printf("Enter Face Value: ");
    scanf("%lf", &bond.face_value);

    printf("Enter Coupon Rate (%%): ");
    scanf("%lf", &bond.coupon_rate);

    printf("Enter Years to Maturity: ");
    scanf("%d", &bond.years_to_maturity);

    printf("Enter Payment Frequency (1 for Annual, 2 for Semi-Annual): ");
    scanf("%d", &bond.frequency_of_payments);

    printf("Enter Discount Rate (%%): ");
    scanf("%lf", &bond.discount_rate);

    // Add the bond to the portfolio
    add_bond(portfolio, &bond);

    // Confirmation message
    printf("Bond '%s' added to portfolio.\n", bond.identifier);
}

// Function to display a summary of all bonds in the portfolio
void view_portfolio_summary(const Portfolio *portfolio) {
    printf("\nPortfolio Summary:\n");
    printf("--------------------\n");

    if (portfolio->bond_count == 0) {
        printf("No bonds in the portfolio.\n");
        return;
    }

    for (int i = 0; i < portfolio->bond_count; i++) {
        printf("Bond %d:\n", i + 1);
        display_bond(&portfolio->bonds[i]);
        printf("Bond Price: %.2f\n", calculate_bond_price(&portfolio->bonds[i]));
        printf("Yield to Maturity (YTM): %.2f%%\n", calculate_bond_ytm(&portfolio->bonds[i]));
        printf("--------------------\n");
    }

    printf("Total Portfolio Value: %.2f\n", calculate_portfolio_value(portfolio));
}

// Function to free the portfolio
void free_portfolio(Portfolio *portfolio) {
    free(portfolio->bonds);
    portfolio->bonds = NULL;
    portfolio->bond_count = 0;
    portfolio->capacity = 0;
}

// Function to delete a bond from the portfolio
void delete_bond(Portfolio *portfolio, const char *identifier) {
    int found = 0;
    for (int i = 0; i < portfolio->bond_count; i++) {
        if (strcmp(portfolio->bonds[i].identifier, identifier) == 0) {
            found = 1;
            // Shift remaining bonds to fill the gap
            for (int j = i; j < portfolio->bond_count - 1; j++) {
                portfolio->bonds[j] = portfolio->bonds[j + 1];
            }
            portfolio->bond_count--;
            break;
        }
    }
    if (found) {
        printf("Bond '%s' deleted from portfolio.\n", identifier);
    } else {
        printf("Bond '%s' not found in portfolio.\n", identifier);
    }
}
