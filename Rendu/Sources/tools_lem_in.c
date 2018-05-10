/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_lem_in.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 18:04:40 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 18:04:40 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		stay_on_loops(t_way *best_way)
{
	int var;

	var = -1;
	while (best_way[++var].road)
		if (best_way[var].value != 0)
			return (1);
	return (0);
}

void	reset_anthill_dijkstra(t_room *anthill)
{
	int	var;

	var = -1;
	while (anthill[++var].name)
	{
		anthill[var].dijk.len = 0;
		anthill[var].dijk.done = 0;
		anthill[var].dijk.room = 0;
	}
}

int		check_link_start_end(t_room *anthill)
{
	t_room	*ptr1;
	t_room	*ptr2;
	int		var;

	var = -1;
	ptr1 = start_anthill(anthill);
	while (ptr1->name && ptr1->link[++var])
	{
		ptr2 = ((t_room *)(ptr1->link[var]));
		if (ptr2->end)
			return (1);
	}
	return (0);
}

void	sort_ways_short_to_long(t_way *roads)
{
	t_way	save;
	int		var_1;
	int		var_2;

	var_2 = -1;
	while (roads[++var_2].road)
	{
		var_1 = (var_2 + 1);
		save = roads[var_2];
		while (--var_1 > 0 && roads[var_1 - 1].len > save.len)
			roads[var_1] = roads[var_1 - 1];
		roads[var_1] = save;
	}
}
