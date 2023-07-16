/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:02:19 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/22 02:02:31 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_integerString(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int check_centerString(char *str)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(str, ",");
	if (split[3] != NULL)
		return (free_stringArray(split),FAILURE);
	while (split[i] != NULL)
	{
		if (double_checker(split[i]) == FAILURE)
			return (free_stringArray(split), FAILURE);
		i++;
	}
	free_stringArray(split);
	return (SUCCESS);
}

int check_rgbString(char *str)
{
	char **split;
	int i;
	int j;

	i = 0;
	split = ft_split(str, ",");
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0' && split[i][j] != '\n')
		{
			if (ft_isdigit(split[i][j]) == 0)
				return (free_stringArray(split), FAILURE);
			j++;
		}
		i++;
	}
	free_stringArray(split);
	return (SUCCESS);
}

int double_checker(char *str)
{
	int len;
	int i;
	int point_check;

	i = 0;
	point_check = 0;
	len = ft_strlen(str);
	if (str[0] == '-' || str[i] == '+')
		i++;
	if (str[0] == '.')
		return (FAILURE);
	if (str[len - 1] == '.')
		return (FAILURE);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '.')
		{
			printf("non digit character found\n");
			return (FAILURE);
		}
		if (str[i] == '.')
			point_check++;
		if (point_check > 1)
		{
			printf("too many dots for double variable\n");
			return (FAILURE);
		}
		i++;

	}
	return (SUCCESS);
}
