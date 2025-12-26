/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:00:28 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/26 23:03:53 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Output the char 'c' to the given file disc
 *
 * */
#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
