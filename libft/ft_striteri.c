/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:14:21 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:41:59 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}

// void ft_spcupper(unsigned int i, char *c)
// {
// 	if((*c >= 'a' && *c <= 'z') && *(c - 1) == ' ')
// 		*c = *c - ' ';
// }
// int main(void)
// {
// 	char test[] = "Hello world please make me upper";
// 	ft_striteri(test,ft_spcupper);
// 	printf("%s",test);
// }