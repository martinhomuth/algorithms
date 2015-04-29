/* chapter02.c --- 
 * 
 * Filename: chapter02.c
 * Description: Chapter 02 testing functions.
 * Author: Martin Homuth
 * Created: Tue Apr 28 12:31:40 2015 (+0200)
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

#include "gcd.h"
#include "chapter02.h"

#include <stdio.h>
#include <time.h>

void test_chap02()
{
	int i, j;
	int denominator, numerator;
	clock_t start, stop;
	double diff;
	start = clock();
	printf("The gcd of %ld and %ld is %ld\n", 123L, 43L, gcd_sub(123, 43));
	printf("The gcd of %ld and %ld is %ld\n", 4L, 6L, gcd_sub(4, 6));
	printf("The gcd of %ld and %ld is %ld\n", 123124L, 26L, gcd_sub(123124, 26));
	printf("The gcd of %ld and %ld is %ld\n", 123394832931L, 43L, gcd_sub(123394832931, 43));
	printf("The gcd of %ld and %ld is %ld\n", 4L, 6L, gcd_sub(4, 6));
	printf("The gcd of %ld and %ld is %ld\n", 123124L, 26L, gcd_sub(123124, 26));
	stop = clock();
	diff = (stop - start) / CLOCKS_PER_SEC;
	printf("----------------------------------------------\n");
	printf("subtraction took %f seconds\n\n", diff);

	start = clock();
	printf("The gcd of %ld and %ld is %ld\n", 123L, 43L, gcd_mod(123, 43));
	printf("The gcd of %ld and %ld is %ld\n", 4L, 6L, gcd_mod(4, 6));
	printf("The gcd of %ld and %ld is %ld\n", 123124L, 26L, gcd_mod(123124, 26));
	printf("The gcd of %ld and %ld is %ld\n", 123394832931L, 43L, gcd_mod(123394832931, 43));
	printf("The gcd of %ld and %ld is %ld\n", 4L, 6L, gcd_mod(4, 6));
	printf("The gcd of %ld and %ld is %ld\n", 123124L, 26L, gcd_mod(123124, 26));
	stop = clock();
	diff = (stop - start) / CLOCKS_PER_SEC;
	printf("----------------------------------------------\n");
	printf("modulus took %f seconds\n\n", diff);

	/* Exercise 3: result for u % v if u and v are not positive */
	for (i = 3; i > -5; i -= 2) {
		for (j = 3; j > -5; j -= 2) {
			if (i != 0 && j != 0)
				printf("%d %% %d = %ld\n",
				       i, j, gcd_mod(i, j));
		}
	}
	printf("\n\n");

	/* Exercise 4: Reduce a fraction using a structure */
	struct fraction frac;
	numerator = 342;
	denominator = 34526;
        frac = create_shortened_fraction(numerator, denominator);
	printf("Shortened fraction %d / %d is %d / %d\n",
	       numerator, denominator,
	       frac.numerator, frac.denominator);
	numerator = 3123;
	denominator = 34526324;
	frac = create_shortened_fraction(numerator, denominator);
	printf("Shortened fraction %d / %d is %d / %d\n",
	       numerator, denominator,
	       frac.numerator, frac.denominator);
	numerator = 34;
	denominator = 3453426;
	frac = create_shortened_fraction(numerator, denominator);
	printf("Shortened fraction %d / %d is %d / %d\n",
	       numerator, denominator,
	       frac.numerator, frac.denominator);
	numerator = 342394082;
	denominator = 3452;
	frac = create_shortened_fraction(numerator, denominator);
	printf("Shortened fraction %d / %d is %d / %d\n",
	       numerator, denominator,
	       frac.numerator, frac.denominator);
	numerator = 24;
	denominator = 8;
	frac = create_shortened_fraction(numerator, denominator);
	printf("Shortened fraction %d / %d is %d / %d\n",
	       numerator, denominator,
	       frac.numerator, frac.denominator);
	printf("--------------------------------\n\n");

	/* Exercise 4: write function int convert() which reads a number
	 *             character by character and returns the value
	 */
	printf("Testing convert...\n");
	printf("The number you just entered was %d\n",
	       convert());
}

struct fraction create_shortened_fraction(int numerator, int denominator)
{
	int gcd;
	struct fraction frac = {
		.numerator = numerator,
		.denominator = denominator
	};
	gcd = gcd_mod(frac.numerator, frac.denominator);
	frac.numerator /= gcd;
	frac.denominator /= gcd;
	return frac;
}

/* 
int convert()
{
	int ch;
}

/* chapter02.c ends here */
