/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:00:11 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/16 20:18:36 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 *Turn string into int
 Important notes:
  1) Stop at first non-digit except leading whitespaces ('\t','
 ','\n','\r','\f','\v')
 2) Don't handle overflow (man atoi says:  No checks  for
 overflow  or underflow are done. )
 3) Handle (postitive / negative) sign
 It's just handle an initial sign not a consuctive ones (according to the doc ->
search on google)
atoi("++42")   → 0
after a sign it must be digit
atoi("+-42")→ 0
atoi("  + 42") → 0
atoi("-42   23") -> -42
atoi("42   23") -> 42 --> make active = 1 when a number is hit [ whitespace ] [
+ | - ] [ digits ] --> valid rule

 *
 * */

#include "libft.h"
int ft_atoi(const char *nptr) {
  int sign = 1;
  int active = 0;
  int number = 0;
  int i = 0;
  if (!nptr) {
    return 0;
  }

  while (nptr[i]) {

    if (active && !(nptr[i] >= '0' && nptr[i] <= '9')) {
      break;
    }
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ') {
      i += 1;
      continue;
    }
    if ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '+') {
      active = 1;
    }
    if (nptr[i] == '-') {
      sign = -1;
      active = 1;
    }
    if (nptr[i] >= '0' && nptr[i] <= '9' && active) {
      number = (number * 10) + (char)nptr[i] - '0';
    }

    i += 1;
  }
  return (number * sign);
}

// int main() {
//   printf("%d\n", ft_atoi("123-a"));
//   printf("%d\n", ft_atoi("123-a"));
//   printf("%d\n", ft_atoi("9-8"));
//   printf("%d\n", ft_atoi("12+3"));
//   printf("%d\n", ft_atoi("   +-42"));
//   printf("%d\n", ft_atoi("- +42"));
//   printf("%d\n", ft_atoi("12-3"));
//   printf("%d\n", ft_atoi("2-3"));
//   printf("%d\n", ft_atoi("+-24"));
//   printf("%d\n", ft_atoi("-24"));
//   printf("%d\n", ft_atoi("++123-a"));
//   printf("%d\n", ft_atoi("  + 42"));
//   printf("%d\n", ft_atoi("    +42"));
//   printf("%d\n", ft_atoi("42 23"));
//   printf("%d\n", ft_atoi("-42 23"));
//   printf("%d\n", ft_atoi("-0"));
//   printf("%d\n", ft_atoi("9-8"));
//   printf("%d\n", ft_atoi("12+3"));
//   printf("%d\n", ft_atoi("   +-42"));
//   printf("%d\n", ft_atoi("- +42"));
//   printf("%d\n", ft_atoi("12-3"));
//   printf("%d\n", ft_atoi("2-3"));
//   printf("%d\n", ft_atoi("+-24"));
//   printf("%d\n", ft_atoi("-24"));
//   printf("%d\n", ft_atoi("++123-a"));
//   printf("%d\n", ft_atoi("  + 42"));
//   printf("%d\n", ft_atoi("    +42"));
//   printf("%d\n", ft_atoi("42 23"));
//   printf("%d\n", ft_atoi("-42 23"));
//   printf("%d\n", ft_atoi("-0"));
// }
