/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:02:42 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/11 14:21:37 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n) {

  if (!dest && !src) {
    return NULL;
  }
  unsigned char *ptrDest = (unsigned char *)dest;
  unsigned char *ptrSrc = (unsigned char *)src;
  // move the data to a temp of n bytes array
  unsigned char temp[n];
  size_t copyN = n;
  int idx = 0;
  while (copyN) {
    copyN--;
    temp[idx++] = *ptrSrc++;
  }
  idx = 0;
  while (n--) {
    *ptrDest++ = temp[idx++];
  }
  return dest;
}
// int main() {
//
//   // overlap test
//   char arr[3] = {'1', '2', '3'};
//   // int arr2[2] = {3, 4};
//   ft_memmove(arr + 1, arr, sizeof(char) * 2);
//   for (int i = 0; i < 3; ++i) {
//     printf("%c", arr[i]);
//   }
// }
