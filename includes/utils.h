/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:38 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:22:12 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//slice_utils
int			float_checker(char *str);
long double	ft_atod(const char *str);
int			count_elements(char **str);
int			trgb(int t, int r, int g, int b);
int			get_center(char *str, t_pos *center);
int			get_singleFloat(char *str, float *variable);
int			get_singleInteger(char *str, int *variable);

int			check_integerString(char *str);
int			check_centerString(char *str);
int			check_floatString(char *str);
int			get_trgb(char *str, int *colour);
int			check_rgbString(char *str);
// inits
t_scene		*init_scene(t_scene *scene);
int			init_parsing(t_data *data);
int			init_data(int argc, char **argv, t_data *data);

// mlx s	tuff
void		loop_mlx(t_data *data);
void		put_pixel(int x, int y, int color, t_data *data);

int			free_stuff(t_data *data);
void		free_stringArray(char **str);

#endif
