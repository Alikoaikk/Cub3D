/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:05:31 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 00:54:08 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlength;
	size_t	srclength;

	i = 0;
	dstlength = 0;
	srclength = 0;
	while (dst[dstlength] && dstlength < size)
		dstlength++;
	while (src[srclength])
		srclength++;
	if (dstlength == size)
		return (size + srclength);
	while (src[i] && i < size - dstlength - 1)
	{
		dst[dstlength + i] = src[i];
		i++;
	}
	if (dstlength + i < size)
		dst[dstlength + i] = '\0';
	return (dstlength + srclength);
}

// int main(void)
// {
//     char buffer[20] = "Hello worl";
//     const char *to_add = " World";
//     size_t result;

//     result = ft_strlcat(buffer, to_add, 20);

//     printf("Result: %ld\n", result);
//     printf("Buffer: %s\n", buffer);
// }