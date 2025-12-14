/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:46:53 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/11 22:00:58 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	if (!lst)
	{
		return (0);
	}
	cnt = 1;
	while (lst->next_node != NULL)
	{
		lst = lst->next_node;
		cnt += 1;
	}
	return (cnt);
}

// int main(void) {
//   int x;
//   int y;
//   t_list *new_node;
//   t_list *new_node2;
//
//   x = 5;
//   y = 4;
//   new_node = ft_lstnew((void *)&x);
//   new_node2 = ft_lstnew((void *)&y);
//   new_node2->next_node = NULL;
//   new_node->next_node = new_node2;
//   printf("%d", ft_lstsize(new_node));
// }
