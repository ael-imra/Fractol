/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:27:03 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:46 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		map(t_t *t)
{
	t->x = ((t->x_x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	t->y = (((t->y_y) / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
}

void		itier_loop(t_t *t)
{
	while (t->itier < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		if (str_cmp(t->name, "BurningShip") == 0)
			t->ytmp = ft_abs(2 * t->x * t->y);
		else
			t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_o;
		t->y = t->ytmp + t->y_o;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->itier++;
	}
}

void		init(t_t *t, char *av)
{
	if (str_cmp(av, "Mandelbrot") == 0)
	{
		t->start_x = -2.5;
		t->end_x = 1;
		t->start_y = -2;
		t->end_y = 2;
	}
	else
	{
		t->start_x = -2;
		t->end_x = 2;
		t->start_y = -2;
		t->end_y = 2;
	}
	t->x_o = -0.8;
	t->y_o = 0.156;
	t->name = av;
	t->stop = 0;
	t->max = 50;
	t->color = 20;
	t->zoom = 0.03;
}

void		destroy(t_t *t)
{
	if (t->image)
		mlx_destroy_image(t->ptr, t->image);
	if (t->ptr && t->win)
	{
		mlx_destroy_window(t->ptr, t->win);
		free(t->ptr);
	}
}
