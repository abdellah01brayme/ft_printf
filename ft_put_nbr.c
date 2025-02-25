/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:44 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 14:00:13 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int nbr, t_flags flag)
{
	t_infonbr	info;

	info.base = 10;
	info.x = 'a';
	info.nbr = nbr;
	info.sign = 0;
	info.count = 0;
	flag.c_hash = 0;
	if (nbr < 0)
	{
		info.nbr = -nbr;
		info.sign = 1;
		info.count = 1;
	}
	if ((flag.c_plus || flag.c_space) && !info.count)
		info.count = 1;
	if (flag.c_zero && !flag.c_dash && flag.n_zero > 0 && info.sign)
		flag.n_zero--;
	if (nbr)
		return (treat_flags(flag, info));
	return (treat_nbr_zero(flag, info));
}
