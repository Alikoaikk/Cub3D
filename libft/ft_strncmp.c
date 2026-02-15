/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:55 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:41:51 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char)s1[i] == (unsigned char)s2[i]) && s1[i] && s2[i])
			i++;
		else
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	}
	return (0);
}

// int main(void)
// {
// 	char s1[] = "abc";
// 	char s2[] = "abc";
// 	printf("%d",ft_strncmp(s1, s2, 4));
// }