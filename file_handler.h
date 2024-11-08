#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "portfolio.h"

// Function to save portfolio to file
void save_portfolio(const Portfolio *portfolio);

// Function to load portfolio from file
void load_portfolio(Portfolio *portfolio);

#endif
