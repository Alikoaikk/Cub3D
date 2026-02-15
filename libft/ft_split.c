/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:15:40 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 20:16:34 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	*ft_allocwords(char const *s, int start, int length, int end)
{
	int		i;
	char	*words;

	i = 0;
	words = (char *)malloc(length + 1);
	if (!words)
		return (NULL);
	while (start <= end)
	{
		words[i] = s[start];
		start++;
		i++;
	}
	words[i] = '\0';
	return (words);
}

void	ft_cpywords(const char *s, char c, char **words)
{
	int	i;
	int	start;
	int	end;
	int	length;
	int	word_index;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i - 1;
		length = i - start;
		if (length > 0)
		{
			words[word_index] = ft_allocwords(s, start, length, end);
			word_index++;
		}
	}
	words[word_index] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	ft_cpywords(s, c, words);
	return (words);
}

// int main(void)
// {
//     char *str = NULL;
//     char delim = ' ';
//     char **result = ft_split(str, delim);
//     int i = 0;

//     if (result)
//     {
// 		printf("Split result:\n");
// 		while (result[i])
// 		{
// 			printf("[%s]\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 		printf("ft_split returned NULL\n");
// }