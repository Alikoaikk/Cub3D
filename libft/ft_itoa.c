/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:13:58 by msafa             #+#    #+#             */
/*   Updated: 2025/06/01 03:04:47 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_neg(long nb, int size)
{
	char	*strint;

	nb = -nb;
	strint = (char *)malloc(size + 2);
	if (!strint)
		return (NULL);
	strint[0] = '-';
	strint[size + 1] = '\0';
	while (nb != 0)
	{
		strint[size] = (nb % 10) + '0';
		size--;
		nb = nb / 10;
	}
	return (strint);
}

char	*ft_pos(long nb, int size)
{
	char	*strint;

	strint = (char *)malloc(size + 1);
	if (!strint)
		return (NULL);
	strint[size] = '\0';
	while (nb != 0)
	{	
		strint[size - 1] = (nb % 10) + '0';
		size--;
		nb = nb / 10;
	}
	return (strint);
}

char	*ft_itoa(int n)
{
	int		size;
	long	nb;
	char	*zero;

	nb = n;
	size = ft_size(nb);
	if (n == 0)
	{
		zero = (char *)malloc(2);
		if (!zero)
			return (0);
		zero[0] = '0';
		zero[1] = '\0';
		return (zero);
	}
	if (n < 0)
		return (ft_neg(nb, size));
	else
		return (ft_pos(nb, size));
}
