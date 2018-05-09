/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   best_road_group.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 22:05:30 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 22:05:30 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	init_roads(t_way *roads, int nbr_ants)
{
	int var;

	var = -1;
	while (roads[++var].road)
	{
		if (!(var))
			roads[var].ants = nbr_ants;
		else
			roads[var].ants = 0;
		roads[var].value = (roads[var].len + roads[var].ants - 1);
	}
}

int		how_many_turn_solve(t_way *roads, int nbr_ants)
{
	int result;
	int var;

	var = -1;
	init_roads(roads, nbr_ants);
	result = roads[0].value;
	while (roads[(++var + 1)].road)
		if (roads[var].value > roads[(var + 1)].value)
		{
			while (roads[var].value > roads[(var + 1)].value)
			{
				roads[var].value--;
				roads[(var + 1)].value++;
				roads[var].ants--;
				roads[(var + 1)].ants++;
			}
			result = roads[(var + 1)].value;
			var = -1;
		}
	return (result);
}

int		have_junction(t_way *roads, t_way road_b)
{
	int	var_1;
	int	var_2;
	int	var_3;

	var_1 = -1;
	while (roads[++var_1].road)
	{
		var_2 = 0;
		while (roads[var_1].road[(++var_2 + 1)])
		{
			var_3 = 0;
			while (road_b.road[(++var_3 + 1)])
				if (roads[var_1].road[var_2] == road_b.road[var_3])
					return (1);
		}
	}
	return (0);
}

void	new_road_group(t_way **ptr_1, t_way *ptr_2, t_way *ptr_3)
{
	int		var_1;
	int		var_2;

	var_1 = -1;
	var_2 = -1;
	(*ptr_1) = new_roads(find_nbr_roads(ptr_2));
	while (ptr_3[++var_1].road)
	{
		if (!(var_1))
			(*ptr_1)[++var_2] = ptr_2[0];
		if (!(have_junction((*ptr_1), ptr_3[var_1])))
			(*ptr_1)[++var_2] = ptr_3[var_1];
	}
}

t_way	*best_road_group(t_way *roads, int nbr_ants)
{
	t_way	*result;
	t_way	*ptr_1;
	int		var_1;
	int		var_2;

	var_1 = -1;
	ptr_1 = NULL;
	result = NULL;
	new_road_group(&result, roads, roads);
	while (roads[++var_1].road)
	{
		var_2 = var_1;
		while (roads[++var_2].road)
		{
			new_road_group(&ptr_1, (roads + var_1), (roads + var_2));
			if ((how_many_turn_solve(ptr_1, nbr_ants)) <
				(how_many_turn_solve(result, nbr_ants)))
			{
				free(result);
				new_road_group(&result, (roads + var_1), (roads + var_2));
			}
			free(ptr_1);
		}
	}
	return (result);
}
