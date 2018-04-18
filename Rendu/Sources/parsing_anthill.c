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

char	*check_start_end(char *line, char *cmt)
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

t_room	*parsing_anthill(t_room *ret, char *cmt, int stage, int cur)
{
	char	**params;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		params = ft_strsplit(line, ' ');
		cmt = check_start_end(line, cmt);
		ft_strdel(&line);
		if ((line = check_error_anthill(ret, params, &stage)))
			return (print_error_anthill(line, ft_itoa(cur), stage));
		if (P0[0] != '#')
			fill_anthill(&ret, params, cmt, stage);
		ft_tabdel(params);
		cur++;
	}
	if (stage == 1)
	{
		line = "- No links between the rooms.";
		return (print_error_anthill(line, ft_itoa(cur), 2));
	}
	return (ret);
}
