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

int allocate_vector(unsigned char** bv, int bits);
void clear_bit(char** bv, int n);
int set_bit(unsigned char bv[], int n);
void destroy_vector(char** bv);
int check_bit(char bv[], int n);
