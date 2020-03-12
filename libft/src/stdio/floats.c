/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:22:36 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/23 16:19:26 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

#include "internal/floats.h"
#include <string.h>

size_t	count_decimal(long double nbr)
{
	size_t	size;
	char	whole;

	size = 0;
	while (nbr > 0)
	{
		nbr *= 10;
		whole = nbr;
		nbr -= whole;
		++size;
	}
	return (size);
}

char	*get_decimal(long double nbr, unsigned int precision, size_t size)
{
	char	*res;
	size_t	i;
	char	whole;

	if (precision > size)
		size = precision;
	if ((res = ft_strnew(size)) == NULL)
		ft_puterr("ERROR: get_decimal() ft_strnew", 2);
	i = 0;
	while (i < size)
	{
		nbr *= 10;
		whole = nbr;
		nbr -= whole;
		res[i] = '0' + whole;
		++i;
	}
	return (res);
}

void	round_cascade(char *str, intmax_t *i)
{
	while (str[*i] == '9')
	{
		str[*i] = '0';
		--(*i);
	}
	if (str[*i] == '.')
	{
		--(*i);
		while (str[*i] == '9' && *i >= 0)
		{
			str[*i] = '0';
			--(*i);
		}
	}
}

char	*round_float(char *str, unsigned int precision)
{
	intmax_t	i;
	char		next;

	i = 0;
	while (str[i] != '.')
		++i;
	i += precision;
	next = str[i + 1];
	str[i + 1] = 0;
	if (next >= '5')
	{
		round_cascade(str, &i);
		if (i < 0)
		{
			str[0] = '0';
			str = ft_strjoin_free_d("1", str, 'r');
		}
		else
			str[i] += 1;
	}
	return (str);
}

char	*ftoa(long double nbr, unsigned int precision)
{
	char		*res;
	intmax_t	whole;

	whole = nbr;
	nbr -= whole;
	res = ft_llitoa(whole);
	res = ft_strjoin_free_d(res, ".", 'l');
	res = ft_strjoin_free_d(res,
			get_decimal(nbr, precision, count_decimal(nbr)), 'l');
	res = round_float(res, precision);
	return (res);
}
