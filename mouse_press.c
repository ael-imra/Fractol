/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:42:27 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/24 16:06:53 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mouse_press_2(int button, int x, int y, t_t *t)
{
	if (button == 1)
	{
		if ((x >= 641 && x <= 737) && (y <= 356 && y >= 345))
		{
			t->name = "Mandelbrot";
			init(t, t->name);
		}
		else if ((x >= 642 && x <= 689) && (y <= 376 && y >= 367))
		{
			t->name = "Julia";
			init(t, t->name);
		}
		else if ((x >= 641 && x <= 747) && (y <= 395 && y >= 387))
		{
			t->name = "BurningShip";
			init(t, t->name);
		}
	}
}

int			mouse_press(int button, int x, int y, t_t *t)
{
	if (button == 5)
	{
		if (str_cmp(t->name, "Mandelbrot") == 0 ||
		str_cmp(t->name, "BurningShip") == 0)
			zoom(t, (double)x, (double)y, 1.3);
		else if (str_cmp(t->name, "Julia") == 0 && t->stop == 1)
			zoom(t, (double)x, (double)y, 1.3);
		t->zoom *= 1.3;
	}
	else if (button == 4)
	{
		if (str_cmp(t->name, "Mandelbrot") == 0 ||
		str_cmp(t->name, "BurningShip") == 0)
			zoom(t, (double)x, (double)y, 0.7);
		else if (str_cmp(t->name, "Julia") == 0 && t->stop == 1)
			zoom(t, (double)x, (double)y, 0.7);
		t->zoom *= 0.7;
	}
	else
		mouse_press_2(button, x, y, t);
	draw(t);
	return (1);
}
