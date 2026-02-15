/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:51:50 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 19:29:13 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	if ((total / size) != nmemb)
		return (NULL);
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}
// int main(void)
// {
// 	int i = 0;
// 	unsigned char *test;
// 	test = ft_calloc(5,sizeof(int));
// 	while (i < 5 * sizeof(int))
// 	{
// 		printf("%d",test[i]);
// 		i++;
// 	}
// 	free(test);
// }