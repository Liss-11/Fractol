/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:53:19 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 10:28:29 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../LIB/minilibx/mlx.h"
# include "../LIB/LIBFT_PRINTF/INC/ft_printf.h"
# include "../LIB/LIBFT_PRINTF/Libft/INC/libft.h"

# define M "mandelbrot"
# define J "julia"

# define HEIGHT 600
# define WIDTH 900
# define MAX_COLOR 16
# define MAX_ITER 256
# define MAX_SIZE 4
# define MLX_ERROR -1
# define K_RETURN 36

//MOVMENTS

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	SCROLL_IN = 4,
	SCROLL_OUT = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	PLUS = 24,
	MINUS = 27,
	SPACE = 49,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126,
};

typedef struct	s_points
{
	double	r;
	double	i;
}				t_points;

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef	struct	s_pixel
{
	int	x;
	int	y;
}				t_pixel;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	char		*name;
	void		*img;
	char		*buffer;
	t_pixel		px;
	int			bpp;
	int			llen;
	int			endian;
//	t_point		max;
//	t_point		min;
	t_point		center;
	t_points	c;
	t_point		z;
	t_point		tmp;
	double		zoom;
	double		x_new;
}				t_data;

//mandelbrot.c
void	init_mandelbrot(t_data *data);
void	mandelbrot(t_data *data);
int		mandelbrot_drawer(t_data *data, int i);

//julia.c
void	init_julia(t_data *data, char **argv);
void	julia(t_data *data);
int		julia_drawer(t_data *data, int i);

//drawer.c
void	drawer(t_data *data);
void	background(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//main.c
int		main(int argc, char **argv);
int		init_program(char **argv);
int		execute_program(t_data *data);
int		end_all(t_data *data);
void	view_options();

//errors.c
int		check_errors(int argc, char **argv);

//init.c
void	init_fractal (t_data *data, char **argv);
int		create_window(t_data *data);

//key.c

int		key_enter(int key, t_data *data);

//mouse.c

int		mouse_scroll(int key, int x, int y, t_data *data);

//logs.c
void	invalid_input(void);
void	invalid_julia_param_input(void);


#endif
