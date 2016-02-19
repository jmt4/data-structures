#include "bitvector.h"
#include <stdio.h>
#include <stdlib.h>

int allocate_vector(unsigned char** bv, int bits)
{
	*bv = calloc(bits/WORDSIZE + 1, sizeof(char));
	if (*bv == NULL) return -1;
	else return 1;
}

void clear_bit(unsigned char bv[], int n)
{
	/* could add some more code here if we want to return a value that 
	   indicates whether a bit was actually cleared vs clearing a bit 
	   that is already zero'd
	*/
	bv[n >> BITSHIFT] = bv[n >> BITSHIFT] & ~(1 << (n & BITMASK));
}

int set_bit(unsigned char bv[], int n)
{
	/* ANDing with BITMASK is equivalent to modulo bucket size 
	 * Thus we can figure out which bit to set
	 */
	bv[n >> BITSHIFT] |= 1 << (n & BITMASK);
	return 1;
}

void destroy_vector(unsigned char** bv)
{
	free(*bv);
	*bv = NULL;
}

int check_bit(unsigned char bv[], int n)
{
	/* returns 1 if bit is present; 0 otherwise */
	return bv[n >> BITSHIFT] & 1 << (n & BITMASK);
}
