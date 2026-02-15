/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:11:38 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 02:36:12 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_found(const char *set, char c)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strcpy(char const *s1, char *strtrm, int begin, int end)
{
	int	i;

	i = 0;
	while (begin <= end)
	{
		strtrm[i] = s1[begin];
		i++;
		begin++;
	}
	strtrm[i] = '\0';
	return (strtrm);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		begin;
	int		end;
	char	*strtrm;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1)- 1;
	while (s1[i] && ft_found(set, s1[i]))
		i++;
	begin = i;
	while (j >= begin && ft_found(set, s1[j]))
		j--;
	end = j;
	strtrm = (char *)malloc((end - begin) + 2);
	if (!strtrm)
		return (NULL);
	return (ft_strcpy(s1, strtrm, begin, end));
}

// int main(void)
// {
//     printf("%s",ft_strtrim("", ""));
// }