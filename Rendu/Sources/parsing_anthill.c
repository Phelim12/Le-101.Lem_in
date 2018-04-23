/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_anthill.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 18:07:47 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 18:07:47 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		add_room(t_room **old_anthill, char **params)
{
	static int	size = 20;
	int			cur;

	cur = 0;
	if ((size % 20) == 0)
		realloc_anthill(old_anthill, size);
	while ((*old_anthill) && (*old_anthill)[cur].name)
		cur++;
	(*old_anthill)[cur].end = 0;
	(*old_anthill)[cur].size = 20;
	(*old_anthill)[cur].start = 0;
	(*old_anthill)[cur].link = NULL;
	(*old_anthill)[cur].nb_ants = 0;
	(*old_anthill)[cur].len = ft_strlen(P0);
	(*old_anthill)[cur].name = ft_strdup(P0);
	(*old_anthill)[cur].coord.x = ft_atoi(P1);
	(*old_anthill)[cur].coord.y = ft_atoi(P2);
	(*old_anthill)[cur + 1].name = NULL;
	size++;
}

void		add_link(t_room *anthill, char **params)
{
	int	cur1;
	int	cur2;
	int	cur3;

	cur1 = 0;
	cur2 = 0;
	while (anthill[cur1].name && (ft_strncmp(anthill[cur1].name, P0,\
		anthill[cur1].len) || P0[anthill[cur1].len] != '-'))
		cur1++;
	while (anthill[cur2].name && ft_strncmp(anthill[cur2].name, (P0 + \
		anthill[cur1].len + 1), ft_strlen(P0 + anthill[cur1].len + 1)))
		cur2++;
	if ((anthill[cur1].size++ % 20) == 0)
		anthill[cur1].link = realloc_room((anthill + cur1));
	if ((anthill[cur2].size++ % 20) == 0)
		anthill[cur2].link = realloc_room((anthill + cur2));
	cur3 = 0;
	while (anthill[cur1].link && anthill[cur1].link[cur3])
		cur3++;
	anthill[cur1].link[cur3] = (intmax_t)(anthill + cur2);
	cur3 = 0;
	while (anthill[cur2].link && anthill[cur2].link[cur3])
		cur3++;
	anthill[cur2].link[cur3] = (intmax_t)(anthill + cur1);
}

void		fill_anthill(t_room **ptr, char **params, char *cmt, int stage)
{
	static int	save_nb_ants = 0;
	t_room		*new_anthill;

	if (!(save_nb_ants) && (save_nb_ants = ft_atoi(P0)))
		return ;
	if (stage == 1)
	{
		add_room(ptr, params);
		modif_anthill(*ptr, cmt, save_nb_ants);
	}
	if (stage == 2)
		add_link(*ptr, params);
}

t_room		*parsing_anthill(t_room *ret, char *cmt, int stage, int cur)
{
	char	**params;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		params = ft_strsplit(line, ' ');
		cmt = check_start_end(line, cmt);
		ft_strdel(&line);
		if ((line = check_error_anthill(ret, params, &stage)))
		{
			ft_tabdel(params);
			free_anthill(ret);
			get_next_line(-1, &line);
			return (print_error_anthill(line, cur, stage));
		}
		if (P0[0] != '#')
			fill_anthill(&ret, params, cmt, stage);
		ft_tabdel(params);
		cur++;
	}
	if (stage == 1)
		free_anthill(ret);
	if (stage == 1)
		return (print_error_anthill("- No links between the rooms.", cur, 2));
	return (ret);
}
