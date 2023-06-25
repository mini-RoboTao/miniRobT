#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/new/assert.h"
#include <string.h>
// #include <criterion/new/criterion.h>
// #include <criterion/new/assert.h>

Test(sample, test)
{
    cr_expect(strlen("Test") == 4, "Expected \"Test\" to have a length of 4.");
    // cr_expect(strlen("Hello") == 4, "This will always fail, why did I add this?");
    cr_assert(strlen("") == 0);
}

Test(sample, test2)
{
	cr_expect(1 == 1, "2 is different than 1");
}

// to run

// gc -Icriterion-2.4.2/inclube/criterion -Lcriterion-2.4.2/lib -lcriterion main.c
// export LD_LIBRARY_PATH=${CRITERION_LIB_FOLDER}
// run