/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:08:19 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:41:44 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((unsigned char)c >= 65 && (unsigned char)c <= 90)
		c += 32;
	return (c);
}

// int main(void)
// {
//     char s[] = "WELCOME";
//     int i = 0;

//     while (s[i])
//     {
//         s[i] = ft_tolower(s[i]);
//         i++;
//     }
//     printf("after tolower: %s\n", s);
// }
