/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:39:05 by msafa             #+#    #+#             */
/*   Updated: 2025/06/02 19:23:11 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			slen;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	result = (char *)malloc(slen + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
// char ft_upper(unsigned int i, char c)
// {
// 	if(i % 2 ==  0)
// 		return(c - 32);
// 	else
// 		return(c);
// }
// int main(void)
// {
// 	char *before = "hello world";
// 	char *after;

// 	after = ft_strmapi(before,ft_upper);
// 	if(after)
// 	{
// 		printf("%s",after);
// 		free(after);
// 	}
// 	else
// 	{
// 		printf("ft_strmapi returned NULL\n");	
// 	}
// }