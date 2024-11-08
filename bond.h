#ifndef BOND_H
#define BOND_H

typedef struct {
    char identifier[50];
    double face_value;
    double coupon_rate;
    int years_to_maturity;
    int frequency_of_payments;
    double discount_rate;
} Bond;

// Function to create a new bond from user input
Bond create_bond();

// Function to calculate the price of a bond
double calculate_bond_price(const Bond *bond);

// Function to display bond details
void display_bond(const Bond *bond);

#endif
