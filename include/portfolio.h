#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "bond.h"

typedef struct {
    Bond bonds[100]; // Array to hold bonds
    int bond_count;  // Track number of bonds
} Portfolio;

// Function to initialize an empty portfolio
Portfolio create_portfolio();

// Function to add a new bond to the portfolio
void add_bond(Portfolio *portfolio, const Bond *bond);

// Function to add a new bond to the portfolio based on user input
void add_new_bond_to_portfolio(Portfolio *portfolio);

// Function to calculate total portfolio value
double calculate_portfolio_value(const Portfolio *portfolio);

// Function to display a summary of the portfolio
void view_portfolio_summary(const Portfolio *portfolio);

#endif
