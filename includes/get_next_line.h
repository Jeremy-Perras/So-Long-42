/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:18:30 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 09:18:34 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_read(int fd, char *buff, char *str, int res);
char    *ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
int 	ft_strchr(char *str, char c);

#endif
