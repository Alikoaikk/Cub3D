/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:51:25 by msafa             #+#    #+#             */
/*   Updated: 2025/06/03 19:31:55 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*to_find;

	to_find = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(to_find + i) == (unsigned char)c)
			return (to_find + i);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	unsigned char test[] = "Where is a the first letter a here";
// 	unsigned char c = 'a';
// 	unsigned char *result;
// 	result = ft_memchr(test, c ,sizeof(test));
// 	int i = 0;
// 	while (i < sizeof(test))
// 	{
// 		write(1, &result[i], 1);
// 		i++;
// 	}
// }