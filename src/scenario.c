#include "scenario.h"
#include <stdio.h>

// Function to perform scenario analysis on the portfolio
void perform_scenario_analysis(const Portfolio *portfolio) {
    double rate_change;
    printf("Enter the percentage change in interest rates (e.g., 5 for +5%%, -3 for -3%%): ");
    scanf("%lf", &rate_change);

    double new_total_value = 0.0;
    for (int i = 0; i < portfolio->bond_count; i++) {
        Bond bond = portfolio->bonds[i];
        bond.discount_rate += rate_change;
        new_total_value += calculate_bond_price(&bond);
    }

    printf("New Total Portfolio Value after %.2f%% interest rate change: %.2f\n", rate_change, new_total_value);
}
