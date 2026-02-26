/* Author: Bohush Polina group 11a */

/*
 * This file implements the server side of the car module.
 * It contains the logic to read car records from a text file,
 * print them to the standard output, evaluate their age,
 * and save cars older than 2 years to a new text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "car.h"

/*
 * Evaluates if a given car is older than 2 years.
 * Returns 1 if true, 0 if false.
 */

static int is_car_old(
        const car_t     *car,
        int             current_year
);

static int is_car_old(
        const car_t     *car,
        int             current_year
)
{
        return (current_year - car->year_made) > 2;
}

/*
 * Reads data from the input file, displays all records,
 * and writes records of cars older than 2 years to the output file.
 */
void process_cars(
        const char      *in_file,
        const char      *out_file,
        int             current_year)
{
        FILE            *fin;
        FILE            *fout;
        car_t           tmp_car;

        fin = fopen(in_file, "r");
        if (!fin) {
                printf("Failed to open input file.\n");
                return;
        }

        fout = fopen(out_file, "w");
        if (!fout) {
                printf("Failed to open output file.\n");
                fclose(fin);
                return;
        }

        printf("--- All Cars in Database ---\n");

        while (fscanf(fin, "%63s %63s %63s %63s %d %d %lf",
                      tmp_car.brand,
                      tmp_car.color,
                      tmp_car.serial_num,
                      tmp_car.reg_num,
                      &tmp_car.year_made,
                      &tmp_car.year_inspect,
                      &tmp_car.price) == 7) {

                printf("%s | %s | %s | %s | %d | %d | %.2f\n",
                       tmp_car.brand,
                       tmp_car.color,
                       tmp_car.serial_num,
                       tmp_car.reg_num,
                       tmp_car.year_made,
                       tmp_car.year_inspect,
                       tmp_car.price);

                if (is_car_old(&tmp_car, current_year)) {
                        fprintf(fout, "%s %s %s %s %d %d %.2f\n",
                                tmp_car.brand,
                                tmp_car.color,
                                tmp_car.serial_num,
                                tmp_car.reg_num,
                                tmp_car.year_made,
                                tmp_car.year_inspect,
                                tmp_car.price);
                }
        }

        fclose(fin);
        fclose(fout);
}
