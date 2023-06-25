#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/new/assert.h"
#include <string.h>
// #include <criterion/new/criterion.h>
// #include <criterion/new/assert.h>

Test(sample, string_to_float)
{
	char	*str = "3.14159";
	float	result;
	float	expected;

	result = atof(str);
	expected = atof(str);

	cr_assert_float_eq(result, expected, 0.001);
}

// to run

// gc -Icriterion-2.4.2/inclube/criterion -Lcriterion-2.4.2/lib -lcriterion main.c
// export LD_LIBRARY_PATH=${CRITERION_LIB_FOLDER}
// run