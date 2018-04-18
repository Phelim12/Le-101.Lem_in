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

int		print_error_argc(void)
{
	ft_putendl_fd("lem-in: take no argument", 2);
	ft_putendl_fd("usage: lem-in", 2);
	return (0);
}

void	free_anthill(t_room *anthill)
{
	int cur;

	cur = -1;
	while (anthill[++cur].name)
	{
		if (anthill[cur].link)
			free(anthill[cur].link);
		free(anthill[cur].name);
	}
	free(anthill);
}

void	*print_error_anthill(char *error, char *line_number, int stage)
{
	ft_putstr_fd("Error line ", 2);
	ft_putstr_fd(line_number, 2);
	if (stage == 0)
		ft_putendl_fd(" on the number of ants:", 2);
	if (stage == 1)
		ft_putendl_fd(" on the coordinate of the room:", 2);
	if (stage == 2)
		ft_putendl_fd(" on the links between rooms:", 2);
	ft_putendl_fd(error, 2);
	return (NULL);
}
