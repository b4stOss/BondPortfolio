#ifndef SCENARIO_H
#define SCENARIO_H

#include "portfolio.h"

// Function to perform scenario analysis on the portfolio
void perform_scenario_analysis(const Portfolio *portfolio);

// Function to perform interest rate scenario analysis on the portfolio
void perform_interest_rate_scenario_analysis(const Portfolio *portfolio, double interest_rate_change);

#endif
