/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:07:01 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/14 18:18:52 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *
 *return a pointer to the first occurence of the char c in the string
 *
 * */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
	{
		return (NULL);
	}
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s += 1;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str1;
//
// 	str1 = "";
// 	if (ft_strchr(str1, 'z') != NULL)
// 	{
// 		printf("%s", "YES");
// 	}
// 	else
// 	{
// 		printf("%s", "NO");
// 	}
// }
