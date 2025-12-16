/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqoraan <aqoraan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:05:33 by aqoraan           #+#    #+#             */
/*   Updated: 2025/12/16 21:53:53 by aqoraan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
  void *content;
  struct node *next_node;
} t_list;
t_list *ft_lstnew(void *content);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *str);
void *ft_memmove(void *dest, const void *src, size_t len);
void *ft_memcpy(void *dest, const void *src, size_t len);
t_list *ft_lstnew(void *content);
void ft_bzero(void *arr, size_t size);
int ft_isalnum(int c);
int ft_isascii(int c);
char *ft_strdup(const char *s);

#endif
