/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_ways_dijkstra.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 16:06:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/07 16:06:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		block_road(t_way *roads, int *cursor)
{
	int		var_1;
	int		var_2;
	int		var_3;
	int		var_4;
	int		var_5;

	var_1 = -1;
	while (roads[++var_1].road && !(var_2 = 0))
		while (roads[var_1].road[(++var_2 + 1)] &&
								((var_3 = var_1) >= 0))
			while (roads[++var_3].road && !(var_4 = 0))
				while (roads[var_3].road[(++var_4 + 1)])
					if (roads[var_1].road[var_2] == roads[var_3].road[var_4])
						((t_room *)(roads[var_1].road[var_2]))->dijk.done = 1;
	if ((roads[(*cursor)].road))
	{
		var_5 = (roads[(*cursor)].len - 1);
		((t_room *)(roads[(*cursor)++].road[var_5]))->dijk.done = 1;
	}
}

t_room		*new_pointer_dijkstra(t_room *anthill, t_room *ptr)
{
	int var_1;
	int var_2;

	var_2 = 0;
	var_1 = -1;
	ptr->dijk.done = 1;
	while (anthill[++var_1].name)
		if (!(anthill[var_1].dijk.done) && ((var_2 > anthill[var_1].dijk.len
			&& anthill[var_1].dijk.len > 0) || !(var_2)))
			var_2 = anthill[var_1].dijk.len;
	var_1 = -1;
	while ((var_2 > 0) && anthill[++var_1].name)
		if ((anthill[var_1].dijk.len == var_2 && !(anthill[var_1].dijk.done)))
			return (anthill + var_1);
	return (NULL);
}

t_way		undesrstand_dijkstra(t_room *ptr)
{
	t_way	result;
	int		var;

	var = ptr->dijk.len;
	result.len = ptr->dijk.len;
	result.road = new_umax_tab(var);
	result.road[var--] = (uintmax_t)ptr;
	while (!(ptr->start))
	{
		result.road[var--] = ptr->dijk.room;
		ptr = (t_room *)(ptr->dijk.room);
	}
	return (result);
}

t_way		best_way_dijkstra(t_room *anthill)
{
	t_room	*ptr_1;
	t_room	*ptr_2;
	t_room	*end;
	int		var;

	end = end_anthill(anthill);
	ptr_1 = start_anthill(anthill);
	while (ptr_1 && !(end->dijk.room))
	{
		var = -1;
		while ((ptr_2 = (t_room *)(ptr_1->link[++var])))
			if (((ptr_2->dijk.len) > (ptr_1->dijk.len + 1) ||
				!(ptr_2->dijk.len)) && !(ptr_2->dijk.done))
			{
				ptr_2->dijk.room = (uintmax_t)(ptr_1);
				ptr_2->dijk.len = (ptr_1->dijk.len + 1);
			}
		ptr_1 = new_pointer_dijkstra(anthill, ptr_1);
	}
	if (end->dijk.room)
		return (undesrstand_dijkstra(end));
	return (empty_way());
}

t_way		*find_ways_dijkstra(t_room *anthill)
{
	t_way	*result;
	int		var_1;
	int		var_2;

	var_1 = 0;
	var_2 = 0;
	result = new_roads(find_nbr_ways(anthill));
	while (1)
	{
		result[var_1] = best_way_dijkstra(anthill);
		if (!(result[var_1].road))
			if (++var_2 > 1)
				break ;
		reset_anthill_dijkstra(anthill);
		block_road(result, &(var_1));
	}
	sort_ways_short_to_long(result);
	if (!(result->road))
		ft_memdel((void **)&result);
	return (result);
}
