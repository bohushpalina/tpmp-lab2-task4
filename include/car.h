/* Author: Bohush Polina group 11a */
#ifndef CAR_H
#define CAR_H

/*
 * This header file acts as an interface for the car processing module.
 * It defines the data structures and provides function prototypes
 * required to read, display, and filter car data based on its age.
 */

#include <stdio.h>
#define MAX_STR_LEN	64

typedef struct{
	char		brand[MAX_STR_LEN];
	char		color[MAX_STR_LEN];
	char            serial_num[MAX_STR_LEN];
        char            reg_num[MAX_STR_LEN];
        int             year_made;
        int             year_inspect;
        double          price;
} car_t;

void process_cars(
        const char      *in_file,
        const char      *out_file,
        int             current_year
);

#endif

