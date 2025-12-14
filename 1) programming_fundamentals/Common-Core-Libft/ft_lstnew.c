/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:11:23 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/11 22:05:27 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *
 *Make a new node in Heap and attach the content to it and next_node to NULL
 * */
t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	ptr->content = content;
	ptr->next_node = NULL;
	return (ptr);
}
// int main() {
//
//   char arr[4] = {'a', 'b', 'm', '\0'};
//   t_list test = ft_lstnew((void *)arr);
//   printf("%s", (char *)test.content);
// }
