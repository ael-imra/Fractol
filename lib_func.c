/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <ael-imra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:33:24 by ael-imra          #+#    #+#             */
/*   Updated: 2019/12/25 10:41:49 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_putstr(char const *s)
{
	int				i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int					str_cmp(char *s1, char *s2)
{
	int				i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
