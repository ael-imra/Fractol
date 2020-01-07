/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:27:51 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:48 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
#	define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#	define WIDTH 600
#	define HIGHT 600

typedef	struct			s_t
{
	unsigned char		*ch;
	double				x;
	double				y;
	double				x_x;
	double				y_y;
	void				*ptr;
	void				*win;
	double				x_o;
	double				y_o;
	int					itier;
	double				xtmp;
	double				ytmp;
	void				*image;
	int					size_l;
	int					bpp;
	int					endian;
	int					index;
	char				*name;
	double				start_y;
	double				end_y;
	double				start_x;
	double				end_x;
	int					stop;
	int					max;
	int					color;
	double				zoom;
}						t_t;

void					mandelbrot(t_t *t);
void					draw(t_t *t);
int						str_cmp(char *s1, char *s2);
int						mouse_move(int x, int y, t_t *t);
int						mouse_press(int button, int x, int y, t_t *t);
int						key_press(int keycode, t_t *t);
void					julia(t_t *t);
void					burningship(t_t *t);
void					zoom(t_t *t, double x, double y, double zoom);
void					set_color(t_t *t, int color);
double					ft_abs(double x);
void					menu(t_t *t);
void					ft_putstr(char const *s);
int						usage(char *av, int ac);
void					map(t_t *t);
void					itier_loop(t_t *t);
void					init(t_t *t, char *av);
void					destroy(t_t *t);

#	endif
