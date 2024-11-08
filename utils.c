#include "utils.h"

int validate_input(double value, double min, double max) {
    return (value >= min && value <= max);
}
