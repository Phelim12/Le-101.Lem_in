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

void		block_road(t_room **anthill, t_way *tree, int start, int go)
{
	t_room	*ptr;
	int		cur1;

	cur1 = -1;
	while ((*anthill)[++cur1].name)
	{
		(*anthill)[cur1].save.len = 0;
		(*anthill)[cur1].save.done = 0;
		(*anthill)[cur1].save.after = 0;
	}
	while (start <= go)
	{
		if (((*anthill)[start].end) || ((*anthill)[start].start))
			start++;
		else
			(*anthill)[start++].save.done = 1;
	}
}

int			fast_search(t_way *dirty_tree)
{
	int		cur1;
	int		cur2;
	int		cur3;
	int		cur4;

	cur4 = 0;
	cur2 = -1;
	while (dirty_tree[++cur2].branch)
	{
		cur1 = 0;
		cur3 = 0;
		while (dirty_tree[cur2].branch[(++cur1 + 1)])
			if (((t_room *)(dirty_tree[cur2].branch[cur1]))->save.done)
				cur3++;
		if (cur3 > 0)
			cur4++;
	}
	if (cur4 == cur2)
		return (1);
	return (0);
}

t_way		*search_all_roads(t_room *anthill, int size)
{
	t_way	*ret;
	int		cur1;
	int		cur2;
	int		cur3;

	cur3 = 0;
	cur1 = -1;
	ret = ft_newtree(size - 2);
	while (anthill[++cur1].name)
	{
		cur2 = -1;
		while (anthill[++cur2].name)
		{
			if (fast_search(ret) || !(cur3))
			{
				ret[cur3] = search_new_road(anthill, ret);
				if (ret[cur3].len != -1)
					cur3++;
				else if (cur2)
					cur2 = size;
			}
			block_road(&anthill, ret, cur1, cur2);
		}
	}
	return (ret);
}
