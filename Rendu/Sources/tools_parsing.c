/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 16:07:32 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 16:07:32 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char		*check_start_end(char *line, char *cmt)
{
	static int	stop = 0;

	if (!(ft_strcmp(line, "##start")) && (stop = 1))
		return ("##start\0");
	if (!(ft_strcmp(line, "##end")) && (stop = 1))
		return ("##end\0");
	if (line[0] == '#')
		return (cmt);
	if (stop++ == 1)
		return (cmt);
	stop = 0;
	return ("");
}

void		modif_anthill(t_room *anthill, char *cmt, int nb_ants)
{
	int	cur;

	cur = -1;
	while (anthill[(cur + 1)].name)
		cur++;
	if (!(ft_strcmp(cmt, "##start")))
	{
		anthill[cur].start = 1;
		anthill[cur].nb_ants = nb_ants;
	}
	if (!(ft_strcmp(cmt, "##end")))
		anthill[cur].end = 1;
}

void		*print_error_anthill(char *error, int line_number, int stage)
{
	char *tmp;

	tmp = ft_itoa(line_number);
	ft_putstr_fd("Error line ", 1);
	ft_putstr_fd(tmp, 1);
	if (stage == 0)
		ft_putendl_fd(" on the number of ants:", 1);
	if (stage == 1)
		ft_putendl_fd(" on the coordinate of the room:", 1);
	if (stage == 2)
		ft_putendl_fd(" on the links between rooms:", 1);
	ft_putendl_fd(error, 1);
	ft_strdel(&tmp);
	return (NULL);
}

intmax_t	*realloc_room(t_room *src)
{
	intmax_t	*ret;
	int			cur;

	cur = 0;
	ret = (intmax_t *)malloc(sizeof(intmax_t) * (src->size + 10));
	while ((src->link) && src->link[cur])
	{
		ret[cur] = src->link[cur];
		cur++;
	}
	while (cur < src->size + 9)
		ret[cur++] = 0;
	if ((src->link))
		free(src->link);
	return (ret);
}

void		realloc_anthill(t_room **old_anthill, int size)
{
	t_room	*new_anthill;
	int		cur;

	cur = -1;
	new_anthill = (t_room *)malloc(sizeof(t_room) * (size + 20));
	while ((*old_anthill) && (*old_anthill)[++cur].name)
	{
		new_anthill[cur] = (*old_anthill)[cur];
		new_anthill[cur].link = NULL;
		new_anthill[cur].name = ft_strdup((*old_anthill)[cur].name);
		ft_strdel(&(*old_anthill)[cur].name);
	}
	if (size == 20)
		new_anthill[0].name = NULL;
	else
		new_anthill[cur].name = NULL;
	if ((*old_anthill))
		free((*old_anthill));
	(*old_anthill) = new_anthill;
}
