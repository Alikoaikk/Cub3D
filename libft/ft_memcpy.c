/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:53:08 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 00:38:59 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	i = 0;
	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	while (i < n)
	{
		*(ndest + i) = *(nsrc + i);
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char src[] = "ABCDEFG";

// 	ft_memcpy(src + 2, src, 5);
// 	printf("Copied string: %s\n", src);

// 	return 0;
// }