/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_one_road.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 22:22:47 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 22:22:47 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_way		follow_rooms(t_room *ptr)
{
	t_way	ret;
	int		cur;

	cur = ptr->save.len;
	ret.len = ptr->save.len;
	ret.branch = ft_newumaxtab(cur);
	ret.branch[cur--] = (uintmax_t)ptr;
	while (!(ptr->start))
	{
		ret.branch[cur--] = ptr->save.after;
		ptr = (t_room *)(ptr->save.after);
	}
	ret.branch[cur] = (uintmax_t)ptr;
	return (ret);
}

t_room		*refresh_anthill(t_room *anthill, t_room *ptr)
{
	int cur;
	int min;

	min = 0;
	cur = -1;
	ptr->save.done = 1;
	while (anthill[++cur].name)
		if (((min > anthill[cur].save.len && anthill[cur].save.len > 0) ||
			!(min)) && !(anthill[cur].save.done))
			min = anthill[cur].save.len;
	cur = -1;
	while ((min > 0) && anthill[++cur].name)
		if ((anthill[cur].save.len == min && !(anthill[cur].save.done)))
			break ;
	if (!(anthill[cur].name) || (min <= 0))
		return (NULL);
	return (anthill + cur);
}

t_way		search_new_road(t_room *anthill, t_way *tree)
{
	t_room	*ptr;
	int		cur;

	ptr = anthill;
	while (!(ptr->start))
		ptr++;
	while (ptr && !(ptr->end))
	{
		cur = -1;
		while (ptr->link[++cur])
			if (tree->len != 1 && !(((t_room *)(ptr->link[cur]))->start) &&
				((((t_room *)(ptr->link[cur]))->save.len > (ptr->save.len + 1)
				|| !(((t_room *)(ptr->link[cur]))->save.len)) &&
				!(((t_room *)(ptr->link[cur]))->save.done)))
			{
				((t_room *)(ptr->link[cur]))->save.len = (ptr->save.len + 1);
				((t_room *)(ptr->link[cur]))->save.after = (uintmax_t)(ptr);
			}
		ptr = refresh_anthill(anthill, ptr);
	}
	if (ptr && ptr->end && ptr->save.after)
		return (follow_rooms(ptr));
	return (ft_branch_null());
}
