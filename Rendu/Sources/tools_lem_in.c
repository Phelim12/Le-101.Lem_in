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
	while (anthill && anthill[++cur].name)
	{
		if (anthill[cur].link)
			free(anthill[cur].link);
		free(anthill[cur].name);
	}
	if (anthill)
		free(anthill);
}
