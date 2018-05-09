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

/*
void	print_roads(t_way *roads)
{
	t_room *test;
	int cur = 0;
	int cur1 = -1;

	printf("\n\n\n");
	while (roads[++cur1].road)
	{
		cur = 0;
		while (roads[cur1].road[cur])
		{
			test = (t_room *)roads[cur1].road[cur];
			printf("%s->", test->name);
			cur++;
		}
		
		printf("VAL = %d\tLEN = %d\tNB_ANTS = %d\n\n", roads[cur1].value, roads[cur1].len, roads[cur1].ants);
	}
}

void	print_anthill(t_room *anthill)
{
	int cur1;
	int cur2;

	cur1 = -1;
	while (anthill && anthill[++cur1].name)
	{
		printf("name = %s\t", anthill[cur1].name);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("NBr_ants = %d\t", anthill[cur1].nbr_ants);
		printf("Len = %d\t", anthill[cur1].len);
		if (anthill[cur1].dijk.room)
			printf("ROOM DIJK = %s\t", ((t_room *)(anthill[cur1].dijk.room))->name);
		cur2 = 0;
		while (anthill[cur1].link && anthill[cur1].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].link[cur2]))[0].name);
			cur2++;
		}
		printf("\n");
	}
	printf("\n\n");
}*/

int		main(int argc, char const *argv[])
{
	t_room	*anthill;
	t_way	*outcome;
	t_way	*roads;
	char	**map;

	map = NULL;
	roads = NULL;
	outcome = NULL;
	anthill = NULL;
	if (argc > 1)
		return (print_error_argc(argv[0]));
	if ((map = parsing_anthill(&anthill, NULL, 0, -1)))
	{
		if (check_link_start_end(anthill))
			print_way_one_loop(anthill, find_nbr_ants(anthill));
		else if (!(roads = find_ways_dijkstra(anthill)))
			print_error_no_way(anthill);
		print_map(map);
		outcome = best_road_group(roads, (find_nbr_ants(anthill)));
		how_many_turn_solve(outcome, (find_nbr_ants(anthill)));
		print_way_multi_loops(outcome, (find_nbr_ants(anthill)));
	}
	if (roads)
		free_roads(roads);
	if (outcome)
		free(outcome);
	if (anthill)
		free_anthill(anthill);
}
