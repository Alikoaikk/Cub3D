/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:06:58 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 00:45:04 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclength;

	srclength = 0;
	while (src[srclength])
		srclength++;
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (srclength);
}

// int	main(void)
// {
// 	char	src[] = "Hello, 42!";
// 	char	dst[20];
// 	size_t	length;
// 	length = ft_strlcpy(dst, src, 6);
// 	printf("Copied string: %s\n", dst);
// 	printf("Length of src: %ld\n", length);
// }