#include "unit_test.h"

t_shape	s1;
t_shape s2;
t_shape s3;

void	new_spheres()
{
	s1 = new_sphere();
	s2 = new_sphere();
	s3 = new_sphere();
}

Test(remove_shape_in_list, remove_the_first_item_in_the_list)
{
	t_lst	*lst;
	new_spheres();
	t_lst	*shape1 = ft_lstnew(s1);
	t_lst	*shape2 = ft_lstnew(s2);
	t_lst	*shape3 = ft_lstnew(s3);
	lst = shape1;
	lst->next = shape2;
	lst->next->next = shape3;

	ft_lstremove(&lst, shape1->shape);

	cr_assert(eq(lst, shape2));
	cr_assert(eq(lst->next, shape3));
	cr_assert(eq(lst->next->next, NULL));
	ft_lstclean(&lst, free);
	clean_shape(&s1);
}

Test(remove_shape_in_list, remove_the_middle_item_in_the_list)
{
	t_lst	*lst;
	new_spheres();
	t_lst	*shape1 = ft_lstnew(s1);
	t_lst	*shape2 = ft_lstnew(s2);
	t_lst	*shape3 = ft_lstnew(s3);
	lst = shape1;
	lst->next = shape2;
	lst->next->next = shape3;

	ft_lstremove(&lst, shape2->shape);

	cr_assert(eq(lst, shape1));
	cr_assert(eq(lst->next, shape3));
	cr_assert(eq(lst->next->next, NULL));
	ft_lstclean(&lst, free);
	clean_shape(&s2);
}

Test(remove_shape_in_list, remove_the_last_item_in_the_list)
{
	t_lst	*lst;
	new_spheres();
	t_lst	*shape1 = ft_lstnew(s1);
	t_lst	*shape2 = ft_lstnew(s2);
	t_lst	*shape3 = ft_lstnew(s3);
	lst = shape1;
	lst->next = shape2;
	lst->next->next = shape3;

	ft_lstremove(&lst, shape3->shape);

	cr_assert(eq(lst, shape1));
	cr_assert(eq(lst->next, shape2));
	cr_assert(eq(lst->next->next, NULL));
	ft_lstclean(&lst, free);
	clean_shape(&s3);
}

Test(remove_shape_in_list, remove_the_a_item_in_a_empty_list)
{
	new_spheres();
	t_lst	*lst = NULL;
	t_lst	*shape3 = ft_lstnew(s3);

	ft_lstremove(&lst, shape3->shape);

	cr_assert(eq(lst, NULL));
	ft_lstclean(&shape3, free);
}

Test(remove_shape_in_list, remove_the_non_existent_item_in_the_list)
{
	t_lst	*lst;
	new_spheres();
	t_lst	*shape1 = ft_lstnew(s1);
	t_lst	*shape2 = ft_lstnew(s2);
	t_lst	*shape3 = ft_lstnew(s3);
	lst = shape1;
	lst->next = shape2;

	ft_lstremove(&lst, shape3->shape);

	cr_assert(eq(lst, shape1));
	cr_assert(eq(lst->next, shape2));
	cr_assert(eq(lst->next->next, NULL));
	ft_lstclean(&lst, free);
	ft_lstclean(&shape3, free);
}
