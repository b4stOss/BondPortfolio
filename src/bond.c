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

    // Calculate the present value of coupon payments
    for (int i = 1; i <= total_payments; i++) {
        price += coupon_payment / pow(1 + discount_rate, i);
    }

    // Calculate the present value of the face value
    price += bond->face_value / pow(1 + discount_rate, total_payments);

    return price;
}

// Function to calculate the Yield to Maturity (YTM) of a bond
double calculate_bond_ytm(const Bond *bond) {
    double price = calculate_bond_price(bond);
    double coupon_payment = bond->face_value * (bond->coupon_rate / 100.0) / bond->frequency_of_payments;
    int total_payments = bond->years_to_maturity * bond->frequency_of_payments;
    double ytm = bond->coupon_rate / 100.0; // Initial guess for YTM

    // Newton-Raphson method to approximate YTM
    for (int i = 0; i < 100; i++) {
        double f = 0.0;
        double f_prime = 0.0;
        for (int j = 1; j <= total_payments; j++) {
            double discount_factor = pow(1 + ytm / bond->frequency_of_payments, j);
            f += coupon_payment / discount_factor;
            f_prime -= (j * coupon_payment) / (discount_factor * (1 + ytm / bond->frequency_of_payments));
        }
        f += bond->face_value / pow(1 + ytm / bond->frequency_of_payments, total_payments);
        f_prime -= (total_payments * bond->face_value) / (pow(1 + ytm / bond->frequency_of_payments, total_payments + 1));

        double diff = price - f;
        if (fabs(diff) < 0.0001) {
            break;
        }
        ytm -= diff / f_prime;
    }

    return ytm * bond->frequency_of_payments * 100; // Convert to annual percentage rate
}

// Function to display bond details for summary view
void display_bond(const Bond *bond) {
    printf("Bond Identifier: %s\n", bond->identifier);
    printf("Face Value: %.2f\n", bond->face_value);
    printf("Coupon Rate: %.2f%%\n", bond->coupon_rate);
    printf("Years to Maturity: %d\n", bond->years_to_maturity);
    printf("Frequency of Payments: %d\n", bond->frequency_of_payments);
    printf("Discount Rate: %.2f%%\n", bond->discount_rate);
}
