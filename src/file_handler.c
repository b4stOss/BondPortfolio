#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

void save_portfolio(const Portfolio *portfolio) {
    FILE *file = fopen("portfolio.json", "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    json_object *jportfolio = json_object_new_object();
    json_object *jbonds = json_object_new_array();

    for (int i = 0; i < portfolio->bond_count; i++) {
        json_object *jbond = json_object_new_object();
        json_object_object_add(jbond, "identifier", json_object_new_string(portfolio->bonds[i].identifier));
        json_object_object_add(jbond, "face_value", json_object_new_double(portfolio->bonds[i].face_value));
        json_object_object_add(jbond, "coupon_rate", json_object_new_double(portfolio->bonds[i].coupon_rate));
        json_object_object_add(jbond, "years_to_maturity", json_object_new_int(portfolio->bonds[i].years_to_maturity));
        json_object_object_add(jbond, "frequency_of_payments", json_object_new_int(portfolio->bonds[i].frequency_of_payments));
        json_object_object_add(jbond, "discount_rate", json_object_new_double(portfolio->bonds[i].discount_rate));
        json_object_array_add(jbonds, jbond);
    }

    json_object_object_add(jportfolio, "bonds", jbonds);
    json_object_object_add(jportfolio, "bond_count", json_object_new_int(portfolio->bond_count));

    fprintf(file, "%s", json_object_to_json_string(jportfolio));
    fclose(file);
    json_object_put(jportfolio);
}

void load_portfolio(Portfolio *portfolio) {
    FILE *file = fopen("portfolio.json", "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);
    data[length] = '\0';

    json_object *jportfolio = json_tokener_parse(data);
    free(data);

    json_object *jbonds = json_object_object_get(jportfolio, "bonds");
    portfolio->bond_count = json_object_get_int(json_object_object_get(jportfolio, "bond_count"));

    for (int i = 0; i < portfolio->bond_count; i++) {
        json_object *jbond = json_object_array_get_idx(jbonds, i);
        strcpy(portfolio->bonds[i].identifier, json_object_get_string(json_object_object_get(jbond, "identifier")));
        portfolio->bonds[i].face_value = json_object_get_double(json_object_object_get(jbond, "face_value"));
        portfolio->bonds[i].coupon_rate = json_object_get_double(json_object_object_get(jbond, "coupon_rate"));
        portfolio->bonds[i].years_to_maturity = json_object_get_int(json_object_object_get(jbond, "years_to_maturity"));
        portfolio->bonds[i].frequency_of_payments = json_object_get_int(json_object_object_get(jbond, "frequency_of_payments"));
        portfolio->bonds[i].discount_rate = json_object_get_double(json_object_object_get(jbond, "discount_rate"));
    }

    json_object_put(jportfolio);
}
