/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:52:08 by msafa             #+#    #+#             */
/*   Updated: 2025/06/03 19:38:17 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// int main(void)
// {
// 	t_list* node = NULL;
// 	for(int i = 1 ; i <= 6 ; i++)
// 	{
// 		int *value = malloc(sizeof(int));
// 		*value = i;
// 		t_list *new = ft_lstnew(value);
// 		ft_lstadd_back(&node,new);
// 	}
// 	t_list *result = ft_lstlast(node);
// 	printf("%d",*(int *)result->content);
// }