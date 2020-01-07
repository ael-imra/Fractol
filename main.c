/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:18:08 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:47 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display(t_t *t)
{
	mlx_hook(t->win, 6, 1, mouse_move, t);
	mlx_hook(t->win, 2, 1, key_press, t);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_loop(t->ptr);
}

void	julia(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < HIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			t->x = ((t->x_x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
			t->y = (((t->y_y) / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	menu(t);
	display(t);
}

void	mandelbrot(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < HIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	menu(t);
	display(t);
}

void	burningship(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->index = 0;
	t->y_y = 0;
	while (t->y_y < HIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	menu(t);
	display(t);
}

int		main(int ac, char *av[])
{
	t_t	t;

	if (usage(av[1], ac) == 1)
	{
		t.ptr = mlx_init();
		t.win = mlx_new_window(t.ptr, WIDTH + 300, HIGHT, "Fractol");
		t.image = mlx_new_image(t.ptr, WIDTH + 300, HIGHT);
		t.ch = (unsigned char*)mlx_get_data_addr(t.image,
		&t.bpp, &t.size_l, &t.endian);
		init(&t, av[1]);
		draw(&t);
	}
	return (0);
}
