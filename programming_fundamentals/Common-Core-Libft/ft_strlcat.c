/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:35:01 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/11 21:25:44 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
						strlcat will concatenate to the des as much as the
   buffer can take from src
*/
size_t	ft_strlcat(char *des, const char *src, size_t size)
{
	while (*des)
	{
		des += 1;
	}
	while (size != 1)
	{
		*des++ = *src++;
		size -= 1;
	}
	*des = '\0';
	return (ft_strlen(src) + ft_strlen(des));
}
// int main() {
//
//   char *str = "ahmad";
//   char des[10] = "hey";
//   ft_strlcat(des, str, sizeof(des));
//   printf("%s", des);
// }
