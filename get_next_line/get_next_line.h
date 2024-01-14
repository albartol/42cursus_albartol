/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:11 by albartol          #+#    #+#             */
/*   Updated: 2023/10/23 13:58:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//get_next_line
char	*get_next_line(int fd);

//get_next_line_utils
void	*ft_calloc(size_t len, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

#endif