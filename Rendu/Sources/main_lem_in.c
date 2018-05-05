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

void	print_roads(t_way *roads)
{
	t_room *test;
	int cur = 0;
	int cur1 = -1;

	printf("\n\n\n");
	while (roads[++cur1].len != -1)
	{
		cur = 0;
		//printf("\nLEN = %d\t VALUE = %d \tATNS = %d\n\n", roads[cur1].len, roads[cur1].value, roads[cur1].ants);
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
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("NBr_ants = %d\t", anthill[cur1].nbr_ants);
		printf("Len = %d\t", anthill[cur1].len);
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
		roads[cur].value = (roads[cur].len + roads[cur].ants - 1);
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


int 	check_intersection(t_way *roads, t_way road_b)
{
	int var_1;
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

t_way	*find_best_way_02(t_way *ptr_1, t_way *ptr_2)
{
	t_way	*result;
	int		var_1;
	int		var_2;

	var_1 = -1;
	result = ft_newroads(find_nbr_roads(ptr_1));
	while (ptr_2[++var_1].road)
	{
		if (!(var_1))
			result[0] = ptr_1[0];
		if (!(check_intersection(result, ptr_2[var_1])))
			result[(var_1 + 1)] = ptr_2[var_1];
	}
	result[(var_1 + 1)] = ft_branch_null();
	return (result); 
}

t_way	*find_best_way(t_way *roads, int nbr_ants)
{
	t_way	*ret;
	t_way	*tmp;
	int		var;
	int		r1;
	int		r2;

	r1 = -1;
	ret = NULL;
	while (roads[++r1].road)
	{
		r2 = r1;
		while (roads[++r2].road)
		{
			tmp = find_best_way_02((roads + r1), (roads + r2));
			var = check_nbr_turn(tmp, nbr_ants);
			if (!(ret) || var < check_nbr_turn(ret, nbr_ants))
			{
				if (ret)
					free(ret);
				ret = find_best_way_02((roads + r1), (roads + r2));
			}
			free(tmp);
		}
	}
	return (ret);
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

void	print_way_one_loop(t_room *anthill, int nbr_ants)
{
	t_room	*end;
	int		cur;

	end = anthill;
	cur = nbr_ants;
	while (!(end->end))
		end++;
	while (--cur > 0)
		ft_printf("L%d-%s ", (nbr_ants - cur), end->name);
	ft_printf("L%d-%s\n", (nbr_ants - cur), end->name);
}

void	print_and_move(t_way *best_way, t_room *ptr_1, t_room *ptr_2, int nbr_ants)
{
	if (!(ptr_1->nbr_ants))
		return ;
	if (ptr_1->nbr_ants && best_way->value)
	{
		if (ptr_1->start)
		{
			if (!(best_way->ants))
				return ;
			ptr_2->name_ants = (nbr_ants - (--ptr_1->nbr_ants));
			best_way->ants--;
		}
		else
		{
			ptr_1->nbr_ants = 0;
			ptr_2->name_ants = ptr_1->name_ants;
			ptr_1->name_ants = 0;
		}
		if (ptr_2->end)
			ptr_2->nbr_ants = 0;
		else
			ptr_2->nbr_ants = 1;
		ft_printf("L%d-%s ", ptr_2->name_ants, ptr_2->name);
	}
}

int		check_end_print(t_way *best_way)
{
	int var;

	var = -1;
	while (best_way[++var].road)
		if (best_way[var].value != 0)
			return (1);
	return (0);
}

void	print_way_multi_loops(t_way *best_way, int nbr_ants)
{
	t_room	*ptr_1;
	t_room	*ptr_2;
	int		var_1;
	int		var_2;

	var_1 = -1;
	while (best_way[++var_1].road)
	{
		var_2 = best_way[var_1].len;
		while (--var_2 >= 0)
		{
			ptr_1 = ((t_room *)(best_way[var_1].road[var_2]));
			ptr_2 = ((t_room *)(best_way[var_1].road[var_2 + 1]));
			print_and_move((best_way + var_1), ptr_1, ptr_2, nbr_ants);
		}
		if (best_way[var_1].value)
			best_way[var_1].value--;
	}
	ft_printf("\n");
	if (check_end_print(best_way))
		print_way_multi_loops(best_way, nbr_ants);
}

int	main(int argc, char const *argv[])
{
	t_room	*anthill;

	if (argc > 1)
		return (print_error_argc());
	if ((anthill = parsing_anthill(NULL, NULL, 0, 1)))
	{
		if (check_link_start_end(anthill))
			print_way_one_loop(anthill, find_nbr_ants(anthill));
		else
			resolve_anthill(anthill);
		/*
		if (!(roads[0].road))
			print_error_no_way(anthill, roads);*/
	}
	if (anthill)
		free_anthill(anthill);
	return (0);
}
