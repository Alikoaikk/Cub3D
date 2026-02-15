/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:30:55 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 20:21:57 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newlst;
	t_list	*new_node;
	void	*applied;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		applied = f(lst->content);
		new_node = ft_lstnew(applied);
		if (!new_node)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new_node);
		lst = lst->next;
	}
	return (newlst);
}

// void *tolower_content(void *content)
// {
// 	char *str = (char *)content;
// 	char *lower = ft_strdup(str);
// 	if (!lower)
// 		return (NULL);
// 	for (int i = 0; lower[i]; i++)
// 		lower[i] = ft_tolower(lower[i]);
// 	return (lower);
// }

// void delete_content(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *lst = ft_lstnew((char *)ft_strdup("HELLO"));
// 	ft_lstadd_back(&lst, ft_lstnew((char *)ft_strdup("WORLD")));
// 	ft_lstadd_back(&lst, ft_lstnew((char *)ft_strdup("42")));
// 	t_list *new = ft_lstmap(lst, tolower_content, delete_content);
// 	while (new)
// 	{
// 		printf("%s\n", (char *)new->content);
// 		new = new->next;
// 	}
// }