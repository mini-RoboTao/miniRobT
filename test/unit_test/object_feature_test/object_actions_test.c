#include "unit_test.h"

t_environment			expected	=	(t_environment){ \
									.gravity = (t_obj){.w=0, .x=1, .y=2, .z=3}, \
									.wind = (t_obj){.w=0, .x=1, .y=2, .z=3}};

t_projectile			exp_res	=	(t_projectile){ \
									.position = (t_obj){.w=1, .x=1, .y=2, .z=3}, \
									.velocity = (t_obj){.w=0, .x=1, .y=2, .z=3}};

Test(object_actions, test_create_environment_should_be_sucess)
{
	t_environment		*result;
	t_obj				vector_g = (t_obj){.x=1, .y=2, .z=3, .w=0};
	t_obj				vector_w = (t_obj){.x=1, .y=2, .z=3, .w=0};

    result = create_env(vector_g, vector_w);
	cr_assert(cr_object_eq(result->gravity, expected.gravity));
	cr_assert(cr_object_eq(result->wind, expected.wind));
	if (result)
		free(result);
}

// Test(object_actions, test_create_environment_with_null_obj_should_be_NULL)
// {
// 	t_environment		*result;
// 	t_environment		*expected_null = NULL;
// 	t_obj				*null_vector = NULL;
// 	t_obj				valid_vector = (t_obj){.x=1, .y=2, .z=3, .w=0};

//     result = create_env(null_vector, &valid_vector);
// 	cr_assert(eq(result, expected_null));
// 	result = create_env(&valid_vector, null_vector);
// 	cr_assert(eq(result, expected_null));
// }

Test(object_actions, test_create_projectile_should_be_sucess)
{
	t_projectile		*result;
	t_obj				point_p 		= (t_obj){.x=1, .y=2, .z=3, .w=1};
	t_obj				vector_v 		= (t_obj){.x=1, .y=2, .z=3, .w=0};

    result = create_proj(point_p, object_normalize(vector_v));
	cr_assert(cr_object_eq(result->position, exp_res.position));
	cr_assert(cr_object_eq(result->velocity, object_normalize(exp_res.velocity)));
	if (result)
		free(result);
}

// Test(object_actions, test_create_projectile_item_null_should_be_NULL)
// {
// 	t_projectile		*result;
// 	t_projectile		*exp_null		= NULL;
// 	t_obj				obj_null 		= NULL;
// 	t_obj				valid_point 	= (t_obj){.x=1, .y=2, .z=3, .w=1};
// 	t_obj				valid_vector 	= (t_obj){.x=1, .y=2, .z=3, .w=0};

//     result = create_proj(obj_null, object_normalize(valid_vector));
// 	cr_assert(eq(result, exp_null));
// 	result = create_proj(valid_point, obj_null);
// 	cr_assert(eq(result, exp_null));
// }
