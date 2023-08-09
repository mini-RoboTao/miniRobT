#include "unit_test.h"


Test(Swap_double, swap_1_2)
{
	double	a = 1;
	double	b = 2;

	swap_double(&a, &b);

	cr_assert(eq(a, 2));
	cr_assert(eq(b, 1));
}

Test(Min_three, one_two_three)
{
	cr_assert(eq(min_three(1, 2, 3), 1));
}

Test(Min_three, two_one_three)
{
	cr_assert(eq(min_three(2, 1, 3), 1));
}

Test(Min_three, one_three_two)
{
	cr_assert(eq(min_three(1, 3, 2), 1));
}

Test(Min_three, three_one_two)
{
	cr_assert(eq(min_three(3, 1, 2), 1));
}

Test(Min_three, two_three_one)
{
	cr_assert(eq(min_three(2, 3, 1), 1));
}

Test(Min_three, three_two_one)
{
	cr_assert(eq(min_three(3, 2, 1), 1));
}

Test(Max_three, one_two_three)
{
	cr_assert(eq(max_three(1, 2, 3), 3));
}

Test(Max_three, two_one_three)
{
	cr_assert(eq(max_three(2, 1, 3), 3));
}

Test(Max_three, one_three_two)
{
	cr_assert(eq(max_three(1, 3, 2), 3));
}

Test(Max_three, three_one_two)
{
	cr_assert(eq(max_three(3, 1, 2), 3));
}

Test(Max_three, two_three_one)
{
	cr_assert(eq(max_three(2, 3, 1), 3));
}

Test(Max_three, three_two_one)
{
	cr_assert(eq(max_three(3, 2, 1), 3));
}
