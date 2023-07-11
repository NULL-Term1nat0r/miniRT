/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_cylindner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:22:09 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/06 14:22:09 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector normal_cylindner(void *cylindner, t_line line, t_vector point)
{
	t_cylindner	*cy;
	t_vector q;
	t_vector surface_normal;
	double len_q;

    (void)point;
	cy = ((t_list*)cylindner)->content;
	if (top_cap_intersection(*cy, line.direction, line.base) == TRUE)
	{
		surface_normal = cy->axis_direction;
		return (surface_normal);
	}
	if (bottom_cap_intersection(*cy, line.direction, line.base) == TRUE)
	{
		surface_normal = _multiply(cy->axis_direction, -1);
		return (surface_normal);
	}
	len_q = sqrt(_len(cy->center) - pow(cy->diameter / 2, 2));
	q = _add(cy->center, _multiply(cy->axis_direction, len_q));
	surface_normal = _subtract(line.base, q);
	return (surface_normal);
}


//t_vector normal_plane(void *plane, t_vector point)
//{
//	t_plane	*pl;
//
//	(void)point;
//	pl = ((t_list*)plane)->content;
//	return (_cross(pl->v1, pl->v2));
//}
