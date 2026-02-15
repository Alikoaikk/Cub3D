/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:41:54 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:42:01 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	buff = (char *)malloc(i + 1);
	if (!buff)
		return (NULL);
	while (j < i)
	{
		buff[j] = s[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

// int main(void)
// {
// 	char *s = "";
// 	char *dup;
// 	dup = ft_strdup(s);
// 	printf("%s",ft_strdup(s));
// 	free(dup);
// }