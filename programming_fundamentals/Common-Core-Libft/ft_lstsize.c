/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:46:53 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/10 22:02:22 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int ft_lstsize(t_list *lst) {
  int cnt = 0;
  while (lst->next_node != NULL) {
    lst += 1;
    cnt += 1;
  }
  return cnt;
}

int main() {
  int x = 5;
  int y = 4;
  t_list *new_node = ft_lstnew((void *)&x);

  t_list *new_node2 = ft_lstnew((void *)&y);
  new_node2->next_node = NULL;
  new_node->next_node = new_node2;

  printf("%d", ft_lstsize(new_node));
}
