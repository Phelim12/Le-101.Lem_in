/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   work.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/05 19:45:49 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/05 19:45:49 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	print_anthill_01(t_room *anthill)
{
	int cur1;
	int cur2;

	cur1 = -1;
	while (anthill && anthill[++cur1].name)
	{
		printf("name = %s\t", anthill[cur1].name);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("DONE = %d\t", anthill[cur1].dijk.done);
		printf("LEN = %d\n\n", anthill[cur1].dijk.len);
		cur2 = 0;
		while (anthill[cur1].dijk.link && anthill[cur1].dijk.link[cur2])
		{
			printf("new_lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].dijk.link[cur2]))[0].name);
			cur2++;
		}
		printf("\n\n");
	}
	printf("END\n\n");
}

uintmax_t	*dup_tab_rev(uintmax_t *tab)
{
	uintmax_t	*result;
	uintmax_t	swap;
	int			var_1;
	int			var_2;

	var_1 = 0;
	var_2 = 0;
	while (tab[var_1])
		var_1++;
	result = ft_newumaxtab(var_1);
	while (tab[--var_1])
		result[var_2++] = tab[var_1];
	return (result);
}

int		road_already_found(t_way *roads, uintmax_t *tab)
{
	int var_1;
	int var_2;

	var_1 = -1;
	while (roads[++var_1].road)
	{
		var_2 = 0;
		while (roads[var_1].road[var_2] == tab[var_2])
			if (!(tab[var_2]) || !(roads[var_1].road[var_2]))
				break ;
			else
				var_2++;
		if (!(tab[var_2]) && !(roads[var_1].road[var_2]))
			return (1);
	}
	return (0);
}

void	add_new_road(t_way *roads, uintmax_t *tab, int len_tab)
{
	uintmax_t	*tmp;
	int			var_1;

	var_1 = 0;
	tmp = dup_tab_rev(tab);
	if (!(road_already_found(roads, tmp)))
	{
		while (roads[var_1].road)
			var_1++;
		roads[var_1].len = len_tab;
		roads[var_1].road = tmp;
	}
	else
		free(tmp);
}

void	recursive_search(t_room *ptr, t_way *roads, uintmax_t *road, int var_2)
{
	t_room	*ptr_1;
	int		var_1;

	var_1 = -1;
	if (ptr->start)
	{
		road[var_2] = (uintmax_t)(ptr);
		add_new_road(roads, road, var_2);
		road[var_2] = 0;
	}
	while (!(ptr->start) && ptr->dijk.link[++var_1])
	{
		road[var_2] = (uintmax_t)(ptr);
		ptr = (t_room*)(ptr->dijk.link[var_1]);
		recursive_search(ptr, roads, road, (var_2 + 1));
		ptr = (t_room*)(road[var_2]);
		road[var_2] = 0;
	}
}

void	reset_anthill_test(t_room *anthill)
{
	int var_1;
	int var_2;

	var_1 = 0;
	while (anthill[var_1].name)
	{
		var_2 = 0;
		while (anthill[var_1].dijk.link && anthill[var_1].dijk.link[var_2])
		{
			anthill[var_1].dijk.link[var_2] = 0;
			var_2++;	
		}
		anthill[var_1].dijk.done = 0;
		anthill[var_1].dijk.len = 0;
		var_1++;
	}
}

void	resolve_anthill(t_room *anthill)
{
	t_room 	*end;
	t_way	*roads;
	t_way	*best_way;
	uintmax_t *test;
	int		nbr_rooms;
	int		nbr_ants;
	int		var_1;

	var_1 = -1;
	roads = NULL;
	end = anthill;
	while (!(end->end))
		end++;
	nbr_rooms = size_anthill(anthill);
	test = ft_newumaxtab(nbr_rooms);
	roads = ft_newroads(nbr_rooms * 10);
	while (anthill[++var_1].name)
	{
		fill_new_link_anthill(anthill);
		recursive_search(end, roads, test, 0);
		reset_anthill_test(anthill);
		if (!(anthill[var_1].end) && !(anthill[var_1].start))
			anthill[var_1].dijk.done = 1;
	}
	if (!(roads[0].road))
		print_error_no_way(anthill, roads);
	best_way = find_best_way(roads, nbr_ants);
	check_nbr_turn(best_way, nbr_ants);
	print_way_multi_loops(best_way, nbr_ants);
	if (roads)
	{
		print_roads(best_way);
		print_roads(roads);
		free_roads(roads);
	}
}




