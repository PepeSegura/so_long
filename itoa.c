/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:22:30 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/26 13:48:07 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

static int	ft_len(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	*ft_savenbr(char *c, size_t digit, int len)
{
	while (digit > 0)
	{
		c[len - 1] = (digit % 10) + '0';
		digit = digit / 10;
		len--;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			len;
	long long	n_long;

	n_long = (long long)n;
	len = ft_len(n_long);
	dst = malloc(sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	if (n_long == 0)
		dst[0] = '0';
	if (n_long < 0)
	{
		n_long = n_long * -1;
		dst[0] = '-';
	}
	dst = ft_savenbr(dst, n_long, len);
	return (dst);
}