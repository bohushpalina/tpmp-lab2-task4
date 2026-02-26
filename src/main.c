/* Author: Bohush Polina group 11a */

/*
 * The main client program that utilizes the car processing module.
 * It defines the file names and the current year, then calls
 * the module's interface function to process the data.
 */

#include <car.h>

int main(void)
{
	const char      *in_txt = "cars.txt";
        const char      *out_txt = "filtered_cars.txt";
        int             curr_year = 2026;

        process_cars(
                in_txt,
                out_txt,
                curr_year
        );

        return 0;
}
