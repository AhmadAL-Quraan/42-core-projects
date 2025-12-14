/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:01:35 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/14 20:08:51 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Return the last node of the list
 The idea is to loop until you find the next_node of some node is NULL
 *
 * */
t_list *ft_lstlast(t_list *lst) {
  if (!lst) {
    return (NULL);
  }
  while (lst) {
    if (lst->next_node == NULL) {
      break;
    }
    lst = lst->next_node;
  }
  return (lst);
}

// int main() {
//   char *cont1 = "ahmad";
//   t_list *node1 = ft_lstnew(cont1);
//   t_list *node2 = ft_lstnew(cont1);
//   node1->next_node = node2;
//   if (ft_lstlast(node1)->next_node == NULL) {
//     printf("%s", "done");
//   } else {
//     printf("%s", "wrong");
//   }
// }
