/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:08:38 by abelqasm          #+#    #+#             */
/*   Updated: 2022/02/10 22:41:02 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	signe;
	int	i;

	nb = 0;
	signe = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\v')
		|| (str[i] == '\t') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int	ft_hexa(char *str)
{
	int	i;
	int	num;
	int	len;

	len = ft_strlen(str) - 1;
	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += (str[i] - 48) * pow(16, len - i);
		else if (str[i] >= 'a' && str[i] <= 'f')
			num += (str[i] - 87) * pow(16, len - i);
		i++;
	}
	return (num);
}

int	ft_check_fdf(char *str, char *check)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i] && check[j] && str[i] == check[j])
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
