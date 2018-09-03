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

void		fill_anthill(t_room **ptr, char **params, char *cmt, int stage)
{
	static int	save_nb_ants = 0;

	if (!(save_nb_ants) && (save_nb_ants = ft_atoi(P0)))
		return ;
	if (stage == 1)
	{
		add_room(ptr, params);
		set_start_and_end(*ptr, cmt, save_nb_ants);
	}
	if (stage == 2)
		add_link(*ptr, params);
}

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
	(*old_anthill)[cur].nbr_ants = 0;
	(*old_anthill)[cur].len = ft_strlen(P0);
	(*old_anthill)[cur].name = ft_strdup(P0);
	(*old_anthill)[cur].coord.x = ft_atoi(P1);
	(*old_anthill)[cur].coord.y = ft_atoi(P2);
	(*old_anthill)[cur].dijk.len = 0;
	(*old_anthill)[cur].dijk.done = 0;
	(*old_anthill)[cur].dijk.room = 0;
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
		anthill[cur1].link = realloc_links((anthill + cur1));
	if ((anthill[cur2].size++ % 20) == 0)
		anthill[cur2].link = realloc_links((anthill + cur2));
	cur3 = 0;
	while (anthill[cur1].link && anthill[cur1].link[cur3])
		cur3++;
	anthill[cur1].link[cur3] = (uintmax_t)(anthill + cur2);
	cur3 = 0;
	while (anthill[cur2].link && anthill[cur2].link[cur3])
		cur3++;
	anthill[cur2].link[cur3] = (uintmax_t)(anthill + cur1);
}

char		**parsing_anthill(t_room **ret, char *cmt, int stage, int cur)
{
	char	**result;
	char	**params;
	char	*line;

	result = realloc_map_anthill(NULL, cur);
	while (get_next_line(0, &(result[++cur])) > 0)
	{
		if ((cur) && (cur % 100) == 0)
			result = realloc_map_anthill(result, cur);
		params = ft_strsplit(result[cur], ' ');
		cmt = next_end_or_start(result[cur], cmt);
		if ((line = check_error_anthill(*ret, params, &stage)))
		{
			parsing_free_all(&params, &result, ret);
			return (print_error_anthill(line, cur, stage));
		}
		if (P0[0] != '#')
			fill_anthill(ret, params, cmt, stage);
		ft_tabdel(params);
	}
	if (stage == 1)
		parsing_free_all(NULL, &result, ret);
	if (stage == 1)
		return (print_error_anthill(MSG_29, cur, 2));
	return (result);
}