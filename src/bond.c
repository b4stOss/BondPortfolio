#include "bond.h"
#include <stdio.h>
#include <math.h>

// Function to create a new bond from user input
Bond create_bond() {
    Bond bond;
    // Prompt user for bond details, e.g., identifier, face value, etc.
    return bond;
}

// Function to calculate the price of a bond based on cash flows and discount rate
double calculate_bond_price(const Bond *bond) {
    double price = 0.0;
    double coupon_payment = bond->face_value * (bond->coupon_rate / 100.0) / bond->frequency_of_payments;
    double discount_rate = bond->discount_rate / 100.0 / bond->frequency_of_payments;
    int total_payments = bond->years_to_maturity * bond->frequency_of_payments;

    for (int i = 1; i <= total_payments; i++) {
        price += coupon_payment / pow(1 + discount_rate, i);
    }

    price += bond->face_value / pow(1 + discount_rate, total_payments);

    return price;
}

// Function to display bond details for summary view
void display_bond(const Bond *bond) {
    printf("Bond Identifier: %s\n", bond->identifier);
    printf("Face Value: %.2f\n", bond->face_value);
    // Continue with other bond details
}
