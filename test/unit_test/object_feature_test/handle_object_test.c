#include "unit_test.h"

Test(handle_object, test_magnitude_of_a_vector_x1_y0_z0_should_be_1)
{
    double  result;
    double  expected    = 1;
    t_obj   vector      = (t_obj){.x=1, .y=0, .z=0, .w=0};

    result = object_magnitude(vector);
	cr_assert(eq(result, expected));
}

Test(handle_object, test_magnitude_of_a_vector_x0_y1_z0_should_be_1)
{
    double  result;
    double  expected    = 1;
    t_obj   vector      = (t_obj){.x=0, .y=1, .z=0, .w=0};

    result = object_magnitude(vector);
	cr_assert(eq(result, expected));
}

Test(handle_object, test_magnitude_of_a_vector_x0_y0_z1_should_be_1)
{
    double  result;
    double  expected    = 1;
    t_obj   vector      = (t_obj){.x=0, .y=0, .z=1, .w=0};

    result = object_magnitude(vector);
	cr_assert(eq(result, expected));
}

Test(handle_object, test_magnitude_of_a_vector_x1_y2_z3_should_be_1)
{
    double  result;
    double  expected    = sqrt(14);;
    t_obj   vector      = (t_obj){.x=1, .y=2, .z=3, .w=0};

    result = object_magnitude(vector);
	cr_assert(eq(result, expected));
}

Test(handle_object, test_magnitude_of_a_vector_x_minus_1_y_minus_2_z_minus_3_should_be_1)
{
    double  result;
    double  expected    = sqrt(14);;
    t_obj   vector      = (t_obj){.x=-1, .y=-2, .z=-3, .w=0};

    result = object_magnitude(vector);
	cr_assert(eq(result, expected));
}

// Test(handle_object, test_magnitude_of_a_object_NULL_should_be_0)
// {
//     double  result;
//     double  expected    = 0;
//     t_obj   vector      = NULL;

//     result = object_magnitude(vector);
// 	cr_assert(eq(result, expected));
// }

Test(handle_object, test_normalize_of_a_vector_x4_y0_z0_should_be_vector_x1_y0_z0)
{
    t_obj   vector      = (t_obj){.x=4, .y=0, .z=0, .w=0};
    t_obj   expected    = (t_obj){.x=1, .y=0, .z=0, .w=0};
    t_obj   result;

    result = object_normalize(vector);
	cr_assert(cr_object_eq(result, expected));
}

// Test(handle_object, test_normalize_of_a_vector_x1_y2_z3_should_be_vector_x1_bksl_sqrt14_y2_bksl_sqrt14_z3_bksl_sqrt14)
// {
//     t_obj   vector      = (t_obj){.x=1, .y=2, .z=3, .w=0};
//     t_obj   expected    = (t_obj){.x=0.26726, .y=0.53452, .z=0.80178, .w=0};
//     double  exp         = 1;
//     double  res;
//     t_obj   result;

//     result = object_normalize(vector);
// 	cr_assert(cr_object_eq(result, expected));
//     res = object_magnitude(vector);
//     printf("res: %f\n", res);
// 	cr_assert(res == exp);
// }

// Test(handle_object, test_normalize_of_a_vector_NULL_should_be_NULL)
// {
//     t_obj   *vector      = NULL;
//     t_obj   *expected    = NULL;
//     t_obj   *result;

//     result = object_normalize(vector);
// 	cr_assert(eq(result, expected));
// }

// Test(handle_object, test_dot_of_a_vector_x1_y2_z3_and_a_vector_x2_y3_z4_should_be_20)
// {
//     t_obj   vector_a        = (t_obj){.x=1, .y=2, .z=3, .w=0};
//     t_obj   vector_b        = (t_obj){.x=2, .y=3, .z=4, .w=0};
//     double  expected        = 20;
//     double  result;

//     result = object_dot(&vector_a, &vector_b);
// 	cr_assert(eq(result, expected));
// }

// Test(handle_object, test_dot_of_a_vector_NULL_and_a_vector_x2_y3_z4_should_be_0)
// {
//     t_obj   *vector_a        = NULL;
//     t_obj   vector_b        = (t_obj){.x=2, .y=3, .z=4, .w=0};
//     double  expected        = 0;
//     double  result;

//     result = object_dot(vector_a, &vector_b);
// 	cr_assert(eq(result, expected));
//     result = object_dot(&vector_b, vector_a);
// 	cr_assert(eq(result, expected));
// }

// Test(handle_object, test_cross_product_of_a_vector_a_x1_y2_z3_and_a_vector_b_x2_y3_z4)
// {
//     t_obj   vector_a        = (t_obj){.x=1, .y=2, .z=3, .w=0};
//     t_obj   vector_b        = (t_obj){.x=2, .y=3, .z=4, .w=0};
//     t_obj   expected_a_b    = (t_obj){.x=-1, .y=2, .z=-1, .w=0};
//     t_obj   expected_b_a    = (t_obj){.x=1, .y=-2, .z=1, .w=0};
//     t_obj   *result;

//     result = object_cross_product(&vector_a, &vector_b);
// 	cr_assert(cr_object_eq(result, &expected_a_b));
//     clean_obj(result);
//     result = object_cross_product(&vector_b, &vector_a);
// 	cr_assert(cr_object_eq(result, &expected_b_a));
//     clean_obj(result);
// }

// Test(handle_object, test_cross_product_of_a_vector_NULL_and_a_vector_x2_y3_z4_should_be_NULL)
// {
//     t_obj   *vector_a        = NULL;
//     t_obj   vector_b         = (t_obj){.x=2, .y=3, .z=4, .w=0};
//     t_obj   *expected        = NULL;
//     t_obj   *result;

//     result = object_cross_product(vector_a, &vector_b);
// 	cr_assert(eq(result, expected));
//     clean_obj(result);
//     result = object_cross_product(&vector_b, vector_a);
// 	cr_assert(eq(result, expected));
//     clean_obj(result);
// }
