/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:11:17 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 20:31:02 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// void del_content(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
// 	t_list *node2 = ft_lstnew(ft_strdup("World"));
// 	t_list *node3 = ft_lstnew(ft_strdup("!"));
// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_lstclear(&node1, del_content);
// 	if (node1 == NULL)
// 		printf("Done");
// }