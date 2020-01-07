/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:29:51 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:47 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_t *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = (((double)x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	yy = (((double)y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
}

void		set_color(t_t *t, int color)
{
	t->index = (4 * (WIDTH + 300) * t->y_y) + (t->x_x * 4);
	t->ch[t->index] = ((t->itier * t->color) + 186) * color;
	t->ch[t->index + 1] = ((t->itier * t->color) + 139) * color;
	t->ch[t->index + 2] = ((t->itier * t->color) + 91) * color;
	t->ch[t->index + 3] = 0;
}

void		draw(t_t *t)
{
	if (str_cmp(t->name, "Julia") == 0)
		julia(t);
	else if (str_cmp(t->name, "Mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "BurningShip") == 0)
		burningship(t);
}

double		ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
