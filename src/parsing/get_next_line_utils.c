/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:11:52 by msafa             #+#    #+#             */
/*   Updated: 2026/01/05 22:16:35 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	check_read(ssize_t bytes_read, t_block **head)
{
	if (bytes_read < 0)
	{
		free_head(head);
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	return (1);
}

void	free_head(t_block **head)
{
	t_block	*temp;

	if (!head)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

int	find_new_line(t_block *head)
{
	while (head)
	{
		if (head->c == '\n')
			return (1);
		head = head->next;
	}
	return (0);
}

void	add_back(char c, t_block **head)
{
	t_block	*new;
	t_block	*temp;

	new = malloc(sizeof(t_block));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	length(t_block *head)
{
	int	i;

	i = 0;
	while (head && head->c != '\n')
	{
		i++;
		head = head->next;
	}
	if (head && head->c == '\n')
		return (i + 1);
	else
		return (i);
}
