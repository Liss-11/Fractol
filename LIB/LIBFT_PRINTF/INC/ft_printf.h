/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:52:20 by afrolova          #+#    #+#             */
/*   Updated: 2022/09/05 17:01:02 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define GREEN "\033[1;30m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define BLUE_ITALIC "\033[3;34m"
# define CYAN "\033[1;36m" 
# define CYAN_ITALIC "\033[3;36m" 
# define RESET "\033[1;0m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[4;33m"

//ft_printf.c
int		ft_printf(char const *str, ...);
int		return_value(va_list ptr, char const *str, int *we);
//ft_write.c
int		my_putchar(int c, int *we);
int		ft_write(int fd, char *c, int i, int *we);
int		ft_strlen_print(char *str, int *we);
//ft_numbers.c
int		ft_putnbr(int n, int *we);
int		ft_putnbr_unsigned(unsigned int n, int *we);
//ft_hexadecimals.c
int		to_hexadecimal(unsigned int n, char str, int *we);
int		to_hexadecimal_ptr(unsigned long long n, int *we);
int		ft_write_pointer(unsigned long long n, int *we);

#endif
