#include "push_swap.h"

void	print_stacks(t_stack *A, t_stack *B)
{
	t_stack *temp;

	temp = A;
	ft_putendl("Stack A:");
	while (temp)
	{
		ft_putnbr(temp->content);
		ft_putstr(", ");
		temp = temp->next;
	}
	ft_putendl("");
	temp = B;
	ft_putendl("Stack B:");
	while (temp)
	{
		ft_putnbr(temp->content);
		ft_putstr(", ");
		temp = temp->next;
	}
	ft_putendl("");
}