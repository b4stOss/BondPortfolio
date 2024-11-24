#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to save portfolio to a text file
void save_portfolio(const Portfolio *portfolio) {
    FILE *file = fopen("portfolio.txt", "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    // Write the number of bonds
    fprintf(file, "%d\n", portfolio->bond_count);
    for (int i = 0; i < portfolio->bond_count; i++) {
        // Write each bond's details
        fprintf(file, "%s\n", portfolio->bonds[i].identifier);
        fprintf(file, "%lf\n", portfolio->bonds[i].face_value);
        fprintf(file, "%lf\n", portfolio->bonds[i].coupon_rate);
        fprintf(file, "%d\n", portfolio->bonds[i].years_to_maturity);
        fprintf(file, "%d\n", portfolio->bonds[i].frequency_of_payments);
        fprintf(file, "%lf\n", portfolio->bonds[i].discount_rate);
    }

    fclose(file);
}

// Function to load portfolio from a text file
void load_portfolio(Portfolio *portfolio) {
    FILE *file = fopen("portfolio.txt", "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    // Read the number of bonds
    fscanf(file, "%d\n", &portfolio->bond_count);
    portfolio->capacity = portfolio->bond_count > 10 ? portfolio->bond_count : 10;
    portfolio->bonds = (Bond *)malloc(portfolio->capacity * sizeof(Bond));
    if (!portfolio->bonds) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    for (int i = 0; i < portfolio->bond_count; i++) {
        // Read each bond's details
        fscanf(file, "%s\n", portfolio->bonds[i].identifier);
        fscanf(file, "%lf\n", &portfolio->bonds[i].face_value);
        fscanf(file, "%lf\n", &portfolio->bonds[i].coupon_rate);
        fscanf(file, "%d\n", &portfolio->bonds[i].years_to_maturity);
        fscanf(file, "%d\n", &portfolio->bonds[i].frequency_of_payments);
        fscanf(file, "%lf\n", &portfolio->bonds[i].discount_rate);
    }

    fclose(file);
}
