/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:31:45 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:48:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	init_parsing(t_data *data)
{
	data->parsing = ft_calloc(sizeof(t_parsing), 7);
	if (data->parsing == NULL)
		return (perror("malloc"), FAILURE);
	data->parsing[0] = (t_parsing){"L", interpret_lightsource};
	return (SUCCESS);
}
