/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:08:47 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 14:47:11 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*fd_read(int fd, char *data);
char	*take_line(char *data);
char	*clean_data(char *data);

//Funciones de utils
//size_t	ft_strlen(const char *s);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//char	*ft_strchr(char *s, int c);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*malloc_null(int i);

#endif
