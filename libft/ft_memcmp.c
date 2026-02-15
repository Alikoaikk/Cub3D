/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:38:02 by msafa             #+#    #+#             */
/*   Updated: 2025/06/04 19:51:52 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

// int main(void)
// {
// 	char a[] = {1, 2, 3, 4};
// 	char b[] = {1, 2, 0, 4};
// 	int result = ft_memcmp(a, b, 4);
// 	if (result == 0)
// 		printf("a == b\n");
// 	else if (result < 0)
// 		printf("a < b (%d)\n", result);
// 	else
// 		printf("a > b (%d)\n", result);
// 	return 0;
// }

// int main(void) {
//     int arr[] = {1, 2, 3, 4};
//     int arr1[] = {1, 2, -1, 4};
//     int i = 0;
//     while (i < 4) {
//         unsigned char *bytes = (unsigned char *)&arr[i];
//         int j = 0;
//         printf("Integer %d (%d): ", i, arr[i]);
//         while (j < sizeof(int)) {
//             printf("%02x ", bytes[j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// 	printf("\n");
//     i = 0;
//     while (i < 4) {
//         unsigned char *bytes = (unsigned char *)&arr1[i];
//         int j = 0;
//         printf("Integer %d (%d): ", i, arr1[i]);
//         while (j < sizeof(int)) {
//             printf("%02x ", bytes[j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
//     int result = ft_memcmp(arr, arr1, sizeof(arr));
//     if (result == 0)
//         printf("arr == arr1\n");
//     else if (result < 0)
//         printf("arr < arr1 (%d)\n", result);
//     else
//         printf("arr > arr1 (%d)\n", result);
// }
