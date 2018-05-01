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

void	print_roads(t_room *anthill, t_way *roads)
{
	t_room *test;
	int cur = 0;
	int cur1 = -1;
	int cur2 = 0;

	while (anthill[cur2].name)
		cur2++;
	while (roads[++cur1].len != -1)
	{
		cur = 0;
		printf("\nLEN = %d\t VALUE = %d \tATNS = %d\n\n", roads[cur1].len, roads[cur1].value, roads[cur1].ants);
		while (cur <= roads[cur1].len)
		{
			if (roads[cur1].road[cur])
			{
				test = (t_room *)roads[cur1].road[cur];
				printf("%s->", test->name);
			}
			cur++;
		}
		printf("\n");
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
		printf("x = %d  y = %d\t", anthill[cur1].coord.x, anthill[cur1].coord.y);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("NBr_ants = %d\t", anthill[cur1].nbr_ants);
		printf("Len = %d\t", anthill[cur1].len);
		printf("Done = %d\t", anthill[cur1].save.done);
		cur2 = 0;
		while (anthill[cur1].link && anthill[cur1].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].link[cur2]))[0].name);
			cur2++;
		}
		printf("\n");
	}
	printf("\n\n");
}

int		check_link_start_end(t_room *anthill)
{
	t_room *ptr1;
	t_room *ptr2;
	int		cur;

	cur = -1;
	ptr1 = anthill;
	while (!(ptr1->start))
		ptr1++;
	while (ptr1->link[++cur])
	{
		ptr2 = ((t_room *)(ptr1->link[cur]));
		if (ptr2->end)
			return (1);
	}
	return (0);
}

void	init_roads(t_way *roads, int nbr_ants)
{
	int cur;

	cur = -1;
	while (roads[++cur].road)
	{
		if (!(cur))
			roads[cur].ants = nbr_ants;
		else
			roads[cur].ants = 0;
		roads[cur].value = (roads[cur].len + roads[cur].ants);
	}
}

int		check_nbr_turn(t_way *roads, int nbr_ants)
{
	int cur;

	cur = -1;
	init_roads(roads, nbr_ants);
	while (roads[(++cur + 1)].road)
	{
		if (roads[cur].value > roads[(cur + 1)].value)
		{
			while (roads[cur].value > roads[(cur + 1)].value)
			{
				roads[cur].value--;
				roads[(cur + 1)].value++;
				roads[cur].ants--;
				roads[(cur + 1)].ants++;
			}
			cur = -1;
		}
	}
	cur = 0;
	while (roads[cur].road && roads[cur].ants)
		cur++;
	return (roads[(cur - 1)].value);
}

int		find_nbr_ants(t_room *anthill)
{
	t_room *ptr;

	ptr = anthill;
	while (!(ptr->start))
		ptr++;
	return (ptr->nbr_ants);
}

int		find_nbr_roads(t_way *roads)
{
	int ret;

	ret = 0;
	while (roads[ret].road)
		ret++;
	return (ret);
}

int 	check_intersection(t_way road_a, t_way road_b)
{
	int var_1;
	int	var_2;
	
	var_1 = 0;
	while (road_a.road[(++var_1 + 1)])
	{
		var_2 = 0;
		while (road_b.road[(++var_2 + 1)])
			if (road_b.road[var_2] == road_a.road[var_1])
				return (1);
	}
	return (0);
}

t_way	*find_best_way_02(t_way *ptr_1, t_way *ptr_2)
{
	t_way	*result;
	int		var_1;
	int		var_2;

	var_1 = -1;
	result = ft_newroads(find_nbr_roads(ptr1));
	while (ptr_2[++var_1].road)
	{

	}
}

t_way	**find_best_way(t_way *roads)
{
	int 	nbr_roads;
	t_way	*ret;
	int 	cur1;
	int		r1;
	int		r2;

	r1 = -1;
	nbr_roads = find_nbr_roads(roads);
	while (roads[++r1].road)
	{
		r2 = r1;
		while (roads[++r2].road)
		{
			
		}
	}
	return (ret);
}

void	print_way_one_shot(t_room *anthill, int nbr_ants)
{
	t_room	*start;
	t_room	*end;
	int		cur;

	end = anthill;
	cur = nbr_ants;
	start = anthill;
	while (!(end->end))
		end++;
	while (--cur > 0)
		ft_printf("L%d-%s ", (nbr_ants - cur), end->name);
	ft_printf("L%d-%s\n", (nbr_ants - cur), end->name);
}

int	main(int argc, char const *argv[])
{
	t_room	*anthill;
	t_way	*roads;
	int		nbr_rooms;
	int		nbr_ants;

	roads = NULL;
	if (argc > 1)
		return (print_error_argc());
	if ((anthill = parsing_anthill(NULL, NULL, 0, 1)))
	{
		nbr_ants = find_nbr_ants(anthill);
		nbr_rooms = size_anthill(anthill);
		if (check_link_start_end(anthill))
			print_way_one_shot(anthill, nbr_ants);
		else
		{
			roads = search_all_roads_01(anthill, nbr_rooms);
			if (!(roads[0].road))
				print_error_no_way(anthill, roads);
			if (check_intersection(roads[0], roads[1]))
				printf("INTER\n");
			printf("test %d\n", check_nbr_turn(roads, nbr_ants));
		}
		/*
		if (!(roads[0].road))
			print_error_no_way(anthill, roads);*/
	}
	if (roads)
	{
		print_roads(anthill, roads);
		free_roads(roads);
	}
	if (anthill)
		free_anthill(anthill);
	return (0);
}













































