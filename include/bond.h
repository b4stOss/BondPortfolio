#ifndef BOND_H
#define BOND_H

// Structure to represent a bond
typedef struct {
    char identifier[50];       // Unique identifier for the bond
    double face_value;         // Face value of the bond
    double coupon_rate;        // Coupon rate of the bond (in percentage)
    int years_to_maturity;     // Years to maturity
    int frequency_of_payments; // Frequency of coupon payments (e.g., 1 for annual, 2 for semi-annual)
    double discount_rate;      // Discount rate (in percentage)
} Bond;

// Function to create a new bond from user input
Bond create_bond();

// Function to calculate the price of a bond
double calculate_bond_price(const Bond *bond);

// Function to display bond details
void display_bond(const Bond *bond);

// Function to calculate the Yield to Maturity (YTM) of a bond
double calculate_bond_ytm(const Bond *bond);

#endif
