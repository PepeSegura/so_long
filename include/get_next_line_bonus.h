/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:54:30 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/05 23:50:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//Includes
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

//Main function
char	*get_next_line(int fd);
char	*ft_clean_stash(char *stash);
char	*ft_get_line(char *stash);
char	*ft_get_stash(int fd, char *stash);

//Utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *stash, char *buffer);
int		ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);

#endif
