#include "minunit.h"
#include "../bitvector/bitvector.h"

char *test_set_bit()
{
	unsigned char *bv;
	mu_assert(allocate_vector(&bv, 32) == 1,"Failed to allocate memory");
	
	set_bit(bv, 0);
	mu_assert(bv[0] == 1, "Bucket not expected value");
	
	set_bit(bv, 7);
	mu_assert(bv[0] == 129, "Bucket not expected value");

	set_bit(bv, 8);
	mu_assert(bv[1] == 1, "Bucket not expected value");
	
	set_bit(bv, 15);
	mu_assert(bv[1] == 129, "Bucket not expected value");

	set_bit(bv, 24);
	mu_assert(bv[3] == 1, "Bucket not expected value");

	set_bit(bv, 31);
	mu_assert(bv[3] == 129, "Bucket not expected value");	
	
	return NULL;
}

char *test_clear_bit()
{
	unsigned char* bv;
	allocate_vector(&bv, 32);
	mu_assert(bv[0] == 0, "Bucket not expected value");

	set_bit(bv, 0);
	mu_assert(bv[0] == 1, "Bucket not expected value");

	clear_bit(bv, 0);
	mu_assert(bv[0] == 0, "Bucket not expected value");

	return NULL;
}

char *test_destroy_vector()
{
	unsigned char* bv;
	allocate_vector(&bv, 32);

	destroy_vector(&bv);
	mu_assert(bv == NULL, "Memory maybe free'd or bv not set to NULL");
	return NULL;
}

char *test_check_bit()
{
	unsigned char* bv;
	allocate_vector(&bv, 32);

	mu_assert(bv[0] == 0, "Bucket not expected value");
	set_bit(bv, 1);
	mu_assert(bv[0] == 2, "Bucket not expected value");

	int rv = check_bit(bv, 1);
	mu_assert(rv == 2, "Bucket not expected value");

	rv = check_bit(bv, 16);
	mu_assert(rv != 2, "Bucket not expected value");
	
	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_clear_bit);
	mu_run_test(test_set_bit);
	mu_run_test(test_destroy_vector);
	mu_run_test(test_check_bit);

	return NULL;
}

RUN_TESTS(all_tests);
