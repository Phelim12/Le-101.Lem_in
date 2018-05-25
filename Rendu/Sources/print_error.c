/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 20:45:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 20:45:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			print_error_argc(const char *name)
{
	ft_putendl_fd(MSG_30, 2);
	ft_putstr_fd(MSG_31, 2);
	ft_putendl_fd(name, 2);
	return (0);
}

void		print_error_empty_file(char **map)
{
	if (!(map))
		return ;
	ft_putendl_fd(MSG_42, 2);
	free(map);
}

void		print_error_no_way(t_room *anthill, char **map)
{
	t_room *start;
	t_room *end;

	end = end_anthill(anthill);
	start = start_anthill(anthill);
	ft_putendl_fd(MSG_32, 2);
	ft_putstr_fd(MSG_33, 2);
	ft_putstr_fd(start->name, 2);
	ft_putstr_fd(" to ", 2);
	ft_putstr_fd(end->name, 2);
	ft_putendl_fd(".", 2);
	if (anthill)
		free_anthill(anthill);
	if (map)
		ft_tabdel(map);
	exit(1);
}

void		*print_error_anthill(char *error, int line_number, int stage)
{
	char *tmp;

	tmp = ft_itoa((line_number + 1));
	ft_putstr_fd(MSG_34, 2);
	ft_putstr_fd(tmp, 2);
	if (stage == 0)
		ft_putendl_fd(MSG_35, 2);
	if (stage == 1)
		ft_putendl_fd(MSG_36, 2);
	if (stage == 2)
		ft_putendl_fd(MSG_37, 2);
	ft_putendl_fd(error, 2);
	ft_strdel(&tmp);
	return (NULL);
}
