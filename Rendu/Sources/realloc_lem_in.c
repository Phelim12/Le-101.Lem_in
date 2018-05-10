/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc_lem_in.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 22:17:35 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 22:17:35 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char		**realloc_map_anthill(char **map, int size)
{
	char	**ret;
	int		var;

	var = -1;
	ret = new_tab(size + 100);
	while (map && map[++var])
	{
		ret[var] = ft_strdup(map[var]);
		free(map[var]);
	}
	if (map)
		free(map);
	return (ret);
}

uintmax_t	*realloc_links(t_room *src)
{
	uintmax_t	*ret;
	int			var;

	var = 0;
	ret = new_umax_tab(src->size + 10);
	while ((src->link) && src->link[var])
	{
		ret[var] = src->link[var];
		var++;
	}
	while (var < src->size + 9)
		ret[var++] = 0;
	if ((src->link))
		free(src->link);
	return (ret);
}

void		realloc_anthill(t_room **old_anthill, int size)
{
	t_room	*new_anthill;
	int		var;

	var = -1;
	new_anthill = (t_room *)malloc(sizeof(t_room) * (size + 20));
	while ((*old_anthill) && (*old_anthill)[++var].name)
	{
		new_anthill[var] = (*old_anthill)[var];
		new_anthill[var].link = NULL;
		new_anthill[var].name = ft_strdup((*old_anthill)[var].name);
		new_anthill[var + 1].name = NULL;
		ft_strdel(&(*old_anthill)[var].name);
	}
	if (size == 20)
		new_anthill[0].name = NULL;
	else
		new_anthill[var].name = NULL;
	if ((*old_anthill))
		free((*old_anthill));
	(*old_anthill) = new_anthill;
}
