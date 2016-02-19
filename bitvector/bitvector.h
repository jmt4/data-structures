#include <limits.h>
#ifndef WORDSIZE
#define WORDSIZE (sizeof(char)*CHAR_BIT)
#endif
#ifndef BITSHIFT
#define BITSHIFT 3
#endif
#ifndef BITMASK
#define BITMASK 0x7
#endif

/* Using an unsigned char* as the type for a bit vector. Seems to be the most "constant"
   sized type among possible choices (int, for example).
*/

/* bv is the bitvector and it can keep track of n bits. it might have an extra bucket in some cases */
int allocate_vector(unsigned char** bv, int bits);

/* sets a particular bit n to 0 */
void clear_bit(unsigned char bv[], int n);

/* sets bit n to 1 */
int set_bit(unsigned char bv[], int n);

/* frees memory used by bitvector and sets bv to NULL */
void destroy_vector(unsigned char** bv);

/* checks if bit at position n is set. returns nonzero value if bit is there */
int check_bit(unsigned char bv[], int n);
