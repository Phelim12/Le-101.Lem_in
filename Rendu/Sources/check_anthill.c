/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_anthill.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/16 21:56:15 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 21:56:15 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char	*check_have_end_start(t_room *anthill)
{
	int	start;
	int	end;

	end = how_many_end(anthill);
	start = how_many_start(anthill);
	if (end > 1 && start > 1)
		return (MSG_19);
	if (end > 1 && !(start))
		return (MSG_20);
	if (start > 1 && !(end))
		return (MSG_21);
	if (!(start) && !(end))
		return (MSG_22);
	if (!(start))
		return (MSG_23);
	if (start > 1)
		return (MSG_24);
	if (!(end))
		return (MSG_25);
	if (end > 1)
		return (MSG_26);
	return (NULL);
}

char	*check_number_of_ants(char **params, int *stage)
{
	if (P0 && P1)
		return (MSG_01);
	if (!(ft_str_is_number(P0)))
		return (MSG_02);
	if (ft_strlen(P0) > 7)
		return (MSG_03);
	if (ft_atoi(P0) > 2000000)
		return (MSG_03);
	if (ft_atoi(P0) < 0)
		return (MSG_04);
	if (ft_atoi(P0) == 0)
		return (MSG_05);
	(*stage)++;
	return (NULL);
}

char	*check_coordinate_of_the_room(t_room *anthill, char **params)
{
	char *line;

	if (P0 && P1 && P2 && P3)
		return (MSG_06);
	if (!(P0) || !(P1) || !(P2))
		return (MSG_07);
	if (P0[0] == 'L')
		return (MSG_08);
	if (!(ft_str_is_number(P1)))
		return (MSG_09);
	if (!(ft_str_is_number(P2)))
		return (MSG_10);
	if (ft_atoi(P1) < 0)
		return (MSG_11);
	if (ft_atoi(P2) < 0)
		return (MSG_12);
	if ((line = have_same_params_on_rooms(anthill, params)))
		return (line);
	return (NULL);
}

char	*check_links_between_rooms(t_room *anthill, char **params)
{
	char	*str;
	int		var_1;
	int		var_2;

	var_1 = 0;
	var_2 = 0;
	if (P0 && P1)
		return (MSG_15);
	if (!(str = ft_strchr(P0, '-')))
		return (MSG_16);
	if (!(ft_strncmp(P0, (str + 1), ft_strlen(str + 1))) &&
		P0[ft_strlen(str + 1)] == '-')
		return (MSG_41);
	while (anthill[var_1].name && (ft_strncmp(anthill[var_1].name, P0,\
		anthill[var_1].len) || P0[anthill[var_1].len] != '-'))
		var_1++;
	if (!(anthill[var_1].name))
		return (MSG_17);
	while (anthill[var_2].name && ft_strncmp(anthill[var_2].name, (P0 + \
		(anthill[var_1].len + 1)), ft_strlen(P0 + (anthill[var_1].len + 1))))
		var_2++;
	if (!(anthill[var_2].name))
		return (MSG_18);
	return (NULL);
}

char	*check_error_anthill(t_room *anthill, char **params, int *stage)
{
	char *line;

	if (!(P0))
		return (MSG_27);
	if (P0[0] == '#')
		return (NULL);
	if ((*stage == 1) && (ft_strchr(P0, '-') && !(P1)))
	{
		if (!anthill)
			return (MSG_28);
		if ((line = check_have_end_start(anthill)))
			return (line);
		++(*stage);
	}
	if (*stage == 0)
		return (check_number_of_ants(params, stage));
	if (*stage == 1)
		return (check_coordinate_of_the_room(anthill, params));
	if (*stage == 2)
		return (check_links_between_rooms(anthill, params));
	return (NULL);
}