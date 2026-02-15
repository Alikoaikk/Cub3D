/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:33:46 by msafa             #+#    #+#             */
/*   Updated: 2025/06/02 19:37:37 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new;
	size_t			i;

	i = 0;
	new = (unsigned char *)s;
	while (i < n)
	{
		*(new + i) = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char buffer[] = "Hello, World!";
// 	int i;
// 	printf("Before: %s\n", buffer);
// 	ft_bzero(buffer + 7, 6);
// 	printf("After: %s\n", buffer);
// 	printf("Hex bytes:\n");
// 	for (i = 0; i < 13; i++)
// 		printf("%02x ", (unsigned char)buffer[i]);
// 	return (0);
// }
