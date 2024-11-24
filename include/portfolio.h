#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "bond.h"

// Structure to represent a portfolio of bonds
typedef struct {
    Bond *bonds;    // Dynamic array to hold bonds
    int bond_count; // Track number of bonds
    int capacity;   // Capacity of the dynamic array
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

// Function to delete a bond from the portfolio
void delete_bond(Portfolio *portfolio, const char *identifier);

// Function to free the portfolio
void free_portfolio(Portfolio *portfolio);

#endif
