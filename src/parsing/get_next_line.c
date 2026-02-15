/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:06:26 by msafa             #+#    #+#             */
/*   Updated: 2026/01/05 22:16:33 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	create_head(t_block **head, int fd, char *buffer, t_fdblock *current_fd)
{
	ssize_t	bytes_read;
	int		i;

	while (!find_new_line(*head))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (check_read(bytes_read, head) == 0)
			break ;
		if (check_read(bytes_read, head) == -1)
		{
			current_fd->head = NULL;
			return (0);
		}
		i = 0;
		while (i < bytes_read)
			add_back(buffer[i++], head);
	}
	return (1);
}

char	*alloc_string(t_block **head)
{
	char	*str;
	int		i;
	t_block	*temp;

	i = 0;
	str = malloc(length(*head) + 1);
	if (!str)
		return (free_head(head), NULL);
	while (*head && (*head)->c != '\n')
	{
		str[i++] = (*head)->c;
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
	if ((*head) && (*head)->c == '\n')
	{
		str[i++] = '\n';
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
	str[i] = '\0';
	return (str);
}

t_fdblock	*find_current_fd(t_fdblock **lst, int fd)
{
	t_fdblock	*new;
	t_fdblock	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	new = malloc(sizeof(t_fdblock));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->head = NULL;
	new->next = *lst;
	*lst = new;
	return (new);
}

void	free_lst_fd(t_fdblock **lst, int fd)
{
	t_fdblock	*temp;
	t_fdblock	*aux;

	temp = *lst;
	aux = NULL;
	while (temp)
	{
		if (temp->fd == fd)
		{
			if (aux)
				aux->next = temp->next;
			else
				*lst = temp->next;
			free_head(&temp->head);
			free(temp);
			return ;
		}
		aux = temp;
		temp = temp->next;
	}
}

char	*get_next_line(int fd)
{
	char				*buffer;
	t_block				*head;
	t_fdblock			*current_fd;
	static t_fdblock	*lst;

	buffer = malloc(BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || !buffer)
		return (free(buffer), NULL);
	current_fd = find_current_fd(&lst, fd);
	if (!current_fd)
		return (free(buffer), NULL);
	head = current_fd->head;
	if (!(create_head(&head, fd, buffer, current_fd)))
	{
		if (!current_fd->head)
			free_lst_fd(&lst, fd);
		return (free(buffer), NULL);
	}
	current_fd->head = head;
	free(buffer);
	if (!head)
		return (free_lst_fd(&lst, fd), NULL);
	return (alloc_string(&(current_fd)->head));
}
