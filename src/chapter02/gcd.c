/* gcd.c --- 
 * 
 * Filename: gcd.c
 * Description: Implementation of the greatest common divisor.
 * Author: Martin Homuth
 * Created: Thu Apr  9 18:43:49 2015 (+0200)
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

long gcd_sub(long u, long v)
{
	long t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

long gcd_mod(long u, long v)
{
	long t, mod = -1;
	if (u < v) {
		t = u;
		u = v;
		v = t;
	}
	while (mod) {
		mod = u % v;
		u = v;
		v = mod;
	}
	return u;
}

/* gcd.c ends here */
