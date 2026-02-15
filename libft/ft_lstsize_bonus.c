/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:37:12 by msafa             #+#    #+#             */
/*   Updated: 2025/06/03 19:37:34 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lst;
	if (!lst)
		return (0);
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
// int main(void)
// {
// 	t_list *lst1 = ft_lstnew("A");
// 	t_list *lst2 = ft_lstnew("B");

// 	printf("%d\n", ft_lstsize(lst1));
// 	ft_lstadd_front(&lst1,lst2);
// 	printf("%s\n",(char *)lst1->content);
// 	printf("%d\n",ft_lstsize(lst2));
// }