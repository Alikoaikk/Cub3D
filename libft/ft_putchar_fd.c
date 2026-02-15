/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:48:29 by msafa             #+#    #+#             */
/*   Updated: 2025/05/27 01:02:32 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// int main(void)
// {
// 	ft_putchar_fd('A',1);
// 	ft_putchar_fd('A', 2); 
// it wont appear if we redirect a.out to out.txt only
// 	return 0;
// }
