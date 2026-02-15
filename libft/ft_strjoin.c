/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:21:49 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 02:15:43 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *nstr, char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		nstr[i] = s2[j];
		j++;
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*nstr;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen((char *) s1);
	s2len = ft_strlen((char *) s2);
	nstr = (char *)malloc(s1len + s2len + 1);
	if (!nstr)
		return (NULL);
	return (ft_strcat(nstr, s1, s2));
}

// int main(void)
// {
//     printf("%s",ft_strjoin("",""));
// }