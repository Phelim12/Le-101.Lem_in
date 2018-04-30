/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_all_roads.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 22:25:11 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 22:25:11 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		block_road_01(t_room **anthill, int start, int go)
{
	reset_anthill(anthill);
	while (start <= go)
	{
		if (((*anthill)[start].end) || ((*anthill)[start].start))
			start++;
		else
			(*anthill)[start++].save.done = 1;
	}
}

void		block_road_02(uintmax_t *ptr1, uintmax_t *ptr2, int go1, int go2)
{
	int		cur;

	cur = 0;
	while (++cur <= go1)
		((t_room *)(ptr1[cur]))->save.done = 1;
	cur = 0;
	while (++cur <= go2)
		((t_room *)(ptr2[cur]))->save.done = 1;
}

int			check_new_road(t_way *roads)
{
	int		check;
	int		r1;
	int		l1;

	r1 = -1;
	while (roads[++r1].road)
	{
		check = 0;
		l1 = -1;
		while (roads[r1].road[++l1])
			if (((t_room *)(roads[r1].road[l1]))->save.done &&
				!(((t_room *)(roads[r1].road[l1]))->end) &&
				!(((t_room *)(roads[r1].road[l1]))->start))
				check++;
		if (check == 0)
			return (0);
	}
	return (1);
}

t_way		*search_all_roads_02(t_room *anthill, t_way *ret, int cur)
{
	int		r1;
	int		r2;
	int		l1;
	int		l2;

	r1 = -1;
	while (ret[++r1].road && !(l1 = 0))
		while (ret[r1].road[++l1] && ((r2 = -1) == -1))
			while (ret[++r2].road && !(l2 = 0))
				while (ret[r2].road[++l2])
				{
					reset_anthill(&anthill);
					block_road_02(ret[r1].road, ret[r2].road, l1, l2);
					if (check_new_road(ret))
					{
						if ((ret[cur] = search_new_road(anthill, ret)).len > 0)
							cur++;
						else
							break ;
					}
				}
	ft_sort_time(ret);
	return (ret);
}

t_way		*search_all_roads_01(t_room *anthill, int nb_rooms)
{
	t_way	*ret;
	int		ant1;
	int		ant2;
	int		cur;

	cur = 0;
	ant1 = -1;
	ret = ft_newroads(nb_rooms);
	while (anthill[++ant1].name && (ant2 = -1))
		while (anthill[++ant2].name)
		{
			if (check_new_road(ret) || !(cur))
			{
				ret[cur] = search_new_road(anthill, ret);
				if (ret[cur].len != -1)
					cur++;
				else if (ant2)
					ant2 = nb_rooms;
			}
			block_road_01(&anthill, ant1, ant2);
		}
	return (search_all_roads_02(anthill, ret, cur));
}
