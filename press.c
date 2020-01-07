/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:56:14 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/24 15:07:57 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press_3(int keycode, t_t *t)
{
	if (keycode == 36)
	{
		t->color = rand();
		draw(t);
	}
	else if (keycode == 83)
	{
		t->max += 20;
		draw(t);
	}
	else if (keycode == 84)
	{
		t->max -= 20;
		draw(t);
	}
	else if (keycode == 53)
	{
		destroy(t);
		exit(0);
	}
	else if (keycode == 82)
	{
		init(t, t->name);
		draw(t);
	}
}

void	key_press2(int keycode, t_t *t)
{
	if (keycode == 123)
	{
		t->start_x = t->start_x + t->zoom;
		t->end_x = t->end_x + t->zoom;
		draw(t);
	}
	else if (keycode == 126)
	{
		t->start_y = t->start_y + t->zoom;
		t->end_y = t->end_y + t->zoom;
		draw(t);
	}
	else if (keycode == 125)
	{
		t->start_y = t->start_y - t->zoom;
		t->end_y = t->end_y - t->zoom;
		draw(t);
	}
	else if (keycode == 49 && str_cmp(t->name, "Julia") == 0)
	{
		t->stop = ((t->stop == 0) ? 1 : 0);
		julia(t);
	}
	else
		key_press_3(keycode, t);
}

int		key_press(int keycode, t_t *t)
{
	if (keycode == 69)
	{
		t->start_x = t->start_x + t->zoom;
		t->start_y = t->start_y + t->zoom;
		t->end_x = t->end_x - t->zoom;
		t->end_y = t->end_y - t->zoom;
		draw(t);
	}
	else if (keycode == 78)
	{
		t->start_x = t->start_x - t->zoom;
		t->start_y = t->start_y - t->zoom;
		t->end_x = t->end_x + t->zoom;
		t->end_y = t->end_y + t->zoom;
		draw(t);
	}
	else if (keycode == 124)
	{
		t->start_x = t->start_x - t->zoom;
		t->end_x = t->end_x - t->zoom;
		draw(t);
	}
	else
		key_press2(keycode, t);
	return (1);
}

int		mouse_move(int x, int y, t_t *t)
{
	if (t->stop == 0 && str_cmp(t->name, "Julia") == 0)
	{
		t->x_o = (((double)x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
		t->y_o = (((double)y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
		julia(t);
	}
	return (1);
}
