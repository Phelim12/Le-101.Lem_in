/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_lem_in.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 16:19:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 16:19:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	init_params_main(t_room **p1, t_way **p2, t_way **p3, char ***p4)
{
	*(p1) = NULL;
	*(p2) = NULL;
	*(p3) = NULL;
	*(p4) = NULL;
}

void	free_params_main(t_room **p1, t_way **p2, t_way **p3)
{
	if (*(p1))
		free_anthill(*(p1));
	if (*(p2))
		free_roads(*(p2));
	if (*(p3))
		free(*(p3));
}

int		check_error_no_way(t_room *anthill)
{
	t_room	*start;
	t_room	*end;
	t_way	way;

	end = end_anthill(anthill);
	start = start_anthill(anthill);
	if (!(end->link) || !(start->link))
		return (1);
	way = best_way_dijkstra(anthill);
	reset_anthill_dijkstra(anthill);
	if (!(way.road))
		return (1);
	else
		free(way.road);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_room	*anthill;
	t_way	*outcome;
	t_way	*roads;
	char	**map;

	init_params_main(&anthill, &outcome, &roads, &map);
	if (argc > 1)
		return (print_error_argc(argv[0]));
	if ((map = parsing_anthill(&anthill, NULL, 0, -1)) && (anthill))
	{
		if (check_error_no_way(anthill))
			print_error_no_way(anthill, map);
		map = print_map(map);
		if (check_link_start_end(anthill))
			print_way_one_loop(anthill, find_nbr_ants(anthill));
		roads = find_ways_dijkstra(anthill);
		outcome = best_road_group(roads, (find_nbr_ants(anthill)));
		how_many_turn_solve(outcome, (find_nbr_ants(anthill)));
		print_way_multi_loops(outcome, (find_nbr_ants(anthill)));
	}
	print_error_empty_file(map);
	free_params_main(&anthill, &roads, &outcome);
	return (0);
}
