/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:38:22 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:50 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		new_image(t_t *t)
{
	int		i;
	int		j;

	j = 0;
	while (j < HIGHT)
	{
		i = 600;
		while (i < WIDTH + 300)
		{
			t->index = (j * (WIDTH + 300) * 4) + (i * 4);
			t->ch[t->index] = 255;
			t->ch[t->index + 1] = 255;
			t->ch[t->index + 2] = 255;
			t->ch[t->index + 3] = 0;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
}

void		menu(t_t *t)
{
	new_image(t);
	mlx_string_put(t->ptr, t->win, 610, 100, 0, "ZOOM :");
	mlx_string_put(t->ptr, t->win, 610, 140, 0, "            + | -          ");
	mlx_string_put(t->ptr, t->win, 610, 160, 0, "    Scroll UP | Scroll DOWN");
	mlx_string_put(t->ptr, t->win, 610, 200, 0, "MOVE :");
	mlx_string_put(t->ptr, t->win, 610, 240, 0, "  Arrow UP    | Arrow DOWN ");
	mlx_string_put(t->ptr, t->win, 610, 260, 0, "  Arrow RIGHT | Arrow LIFT ");
	mlx_string_put(t->ptr, t->win, 610, 300, 0, "FRACTAL :");
	mlx_string_put(t->ptr, t->win, 610, 340, 0, "   Mandelbrot");
	mlx_string_put(t->ptr, t->win, 610, 360, 0, "   Julia");
	mlx_string_put(t->ptr, t->win, 610, 380, 0, "   BurningShip");
	mlx_string_put(t->ptr, t->win, 610, 420, 0, "OTHER :");
	mlx_string_put(t->ptr, t->win, 610, 460, 0, " Exit         :   Esc");
	mlx_string_put(t->ptr, t->win, 610, 480, 0, " Iteration    :  1 - 2");
	mlx_string_put(t->ptr, t->win, 610, 500, 0, " Reset        :    0");
	mlx_string_put(t->ptr, t->win, 610, 520, 0, " Change color :  Enter");
	mlx_string_put(t->ptr, t->win, 610, 540, 0, " Stop Julia   :  Espace");
}

int			usage(char *av, int ac)
{
	if (ac != 2 || (str_cmp(av, "BurningShip") != 0 &&
	str_cmp(av, "Mandelbrot") != 0 && str_cmp(av, "Julia") != 0))
	{
		ft_putstr("\e[91m/************************************/\n");
		ft_putstr("\e[91m/    \e[91mUsage:  ./fractol <name>        \e[91m/\n");
		ft_putstr("\e[91m/     		                     \e[91m/\n");
		ft_putstr("\e[91m/    \e[91mName :                          \e[91m/\n");
		ft_putstr("\e[91m/             \e[91mMandelbrot             \e[91m/\n");
		ft_putstr("\e[91m/            \e[91mBurningShip             \e[91m/\n");
		ft_putstr("\e[91m/               \e[91mJulia                \e[91m/\n");
		ft_putstr("\e[91m/************************************/\n");
		return (0);
	}
	return (1);
}
