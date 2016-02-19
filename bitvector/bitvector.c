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
	/* release pid from vector if found else nothing */
	bv[n >> BITSHIFT] = bv[n >> BITSHIFT] & ~(1 << (n & BITMASK));
}

int set_bit(unsigned char bv[], int n)
{
	/*calculate bucket by dividing by size of char (8 bits per byte)
	  then we can set nth bit by shifting 1 n%BITMASK spaces and
	  performing a BITWISE OR
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
	/* figure out bucket with operations in index
	   then we AND that value with 1 shifted to the
	   spot we want to check. For example, test 3rd bit
	   001100 & 1 << 3 = 001100 & 000100 = 0001000 != 0
	*/
	return bv[n >> BITSHIFT] & 1 << (n & BITMASK);
}
