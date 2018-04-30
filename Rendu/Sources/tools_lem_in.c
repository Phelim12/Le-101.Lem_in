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

int			print_error_argc(void)
{
	ft_putendl_fd("lem-in: take no argument", 2);
	ft_putendl_fd("usage: lem-in", 2);
	return (0);
}

t_way		ft_branch_null(void)
{
	t_way ret;

	ret.road = NULL;
	ret.len = -1;
	ret.ants = -1;
	ret.value = -1;
	return (ret);
}

void		free_roads(t_way *roads)
{
	int cur;

	cur = -1;
	while (roads[++cur].road)
		free(roads[cur].road);
	free(roads);
}

int 		size_anthill(t_room *anthill)
{
	int	ret;
	
	ret = 0;
	while (anthill[ret].name)
		ret++;
	return (ret);
}

t_way		*ft_newroads(int size)
{
	t_way	*ret;
	int		cur;

	cur = -1;
	ret = (t_way *)malloc(sizeof(t_way) * (size + 5));
	while (++cur < size)
		ret[cur] = ft_branch_null();
	return (ret);
}

uintmax_t	*ft_newumaxtab(int size)
{
	uintmax_t	*ret;
	int			cur;

	cur = -1;
	ret = (uintmax_t *)malloc(sizeof(uintmax_t) * (size + 5));
	while (++cur < (size + 5))
		ret[cur] = 0;
	return (ret);
}

void		reset_anthill(t_room **anthill)
{
	int		cur;

	cur = -1;
	while ((*anthill)[++cur].name)
	{
		(*anthill)[cur].save.len = 0;
		(*anthill)[cur].save.done = 0;
		(*anthill)[cur].save.after = 0;
	}
}

void		free_anthill(t_room *anthill)
{
	int cur;

	cur = -1;
	while (anthill && anthill[++cur].name)
	{
		if (anthill[cur].link)
			free(anthill[cur].link);
		free(anthill[cur].name);
	}
	if (anthill)
		free(anthill);
}

void		ft_sort_time(t_way *roads)
{
	t_way	save;
	int 	cur;
	int 	r1;
	
	r1 = -1;
	while (roads[++r1].road)
	{
		cur = (r1 + 1);
		save = roads[r1];
		while (--cur > 0 && roads[cur - 1].len > save.len)
			roads[cur] = roads[cur - 1];
		roads[cur] = save;
	}
}
