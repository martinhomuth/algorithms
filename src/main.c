/* main.c --- 
 * 
 * Filename: main.c
 * Description: 
 * Author: Martin Homuth
 * Maintainer: 
 * Created: Thu Apr  9 18:42:54 2015 (+0200)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
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
#include <stdio.h>
#include <time.h>

/* chapter 02 */
#include "chapter02/gcd.h"
void test_gcd()
{
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
}


int main()
{
	test_gcd();
}

/* main.c ends here */
