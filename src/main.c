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
