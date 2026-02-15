/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:31:01 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 00:37:52 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	i = 0;
	if (ndest < nsrc)
	{
		while (i < n)
		{
			ndest[i] = nsrc[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			ndest[n] = nsrc[n];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char test1[] = "ABCDEFG";
// 	ft_memmove(test1 + 2, test1, 4);
// 	write(1, test1, 7);
// }