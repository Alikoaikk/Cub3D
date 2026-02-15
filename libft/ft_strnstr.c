/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:46:14 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:41:53 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *) big);
	while (i < len && *(big + i))
	{
		j = 0;
		if (*(big + i) == *(little + j))
		{
			while ((i + j < len) && little[j] && *(big + i + j) == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char test1[] = "abc";
// 	char test2[] = "g";
// 	printf("%s",ft_strnstr(test1, test2,10));
// }