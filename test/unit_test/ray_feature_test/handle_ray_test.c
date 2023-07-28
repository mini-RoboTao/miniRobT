// #include "unit_test.h"

// Test(handle_ray, creating_and_querying_a_ray)
// {
// 	t_ray	*ray;
// 	t_obj	origin = (t_obj){.x=1, .y=2, .z=3, .w=1};
// 	t_obj	direction = (t_obj){.x=4, .y=5, .z=6, .w=0};

// 	ray = create_ray(&origin, &direction);
// 	cr_assert(cr_object_eq(ray->position, &origin));
// 	cr_assert(cr_object_eq(ray->direction, &direction));
// 	if (ray)
// 		free(ray);
// }

// Test(handle_ray, creating_and_a_ray_with_a_param_NULL_should_be_NULL)
// {
// 	t_ray	*ray;
// 	t_obj	*obj_null = NULL;
// 	t_obj	obj = (t_obj){.x=4, .y=5, .z=6, .w=0};

// 	ray = create_ray(obj_null, &obj);
// 	cr_assert(eq(ray, NULL));
// 	ray = create_ray(&obj, obj_null);
// 	cr_assert(eq(ray, NULL));
// }

// t_ray	*d_ray = &(t_ray){.position = &(t_obj){.x= 2, .y= 3, .z= 4, .w= 1}, \
// 						.direction = &(t_obj){.x= 1, .y= 0, .z= 0, .w= 0}};

// Test(handle_ray, computig_a_point_x2_y3_z4_w1_from_a_distance_0_should_be_a_point_x2_y3_z4_w1)
// {
// 	t_obj	*obj;
// 	t_obj	*point_expected	= &(t_obj){.x= 2, .y= 3, .z= 4, .w= 1};

// 	obj = cat_position(d_ray, 0);
// 	cr_assert(cr_object_eq(obj, point_expected));
// 	if (obj)
// 		free(obj);
// }

// Test(handle_ray, computig_a_point_x2_y3_z4_w1_from_a_distance_1_should_be_a_point_x3_y3_z4_w1)
// {
// 	t_obj	*obj;
// 	t_obj	*point_expected	= &(t_obj){.x= 3, .y= 3, .z= 4, .w= 1};

// 	obj = cat_position(d_ray, 1);
// 	cr_assert(cr_object_eq(obj, point_expected));
// 	if (obj)
// 		free(obj);
// }

// Test(handle_ray, computig_a_point_x2_y3_z4_w1_from_a_distance_minus_1_should_be_a_point_x1_y3_z4_w1)
// {
// 	t_obj	*obj;
// 	t_obj	*point_expected	= &(t_obj){.x= 1, .y= 3, .z= 4, .w= 1};

// 	obj = cat_position(d_ray, -1);
// 	cr_assert(cr_object_eq(obj, point_expected));
// 	if (obj)
// 		free(obj);
// }

// Test(handle_ray, computig_a_point_x2_y3_z4_w1_from_a_distance_minus_1_should_be_a_point_x4_dot_5_y3_z4_w1)
// {
// 	t_obj	*obj;
// 	t_obj	*point_expected	= &(t_obj){.x= 4.5, .y= 3, .z= 4, .w= 1};

// 	obj = cat_position(d_ray, 2.5);
// 	cr_assert(cr_object_eq(obj, point_expected));
// 	if (obj)
// 		free(obj);
// }
