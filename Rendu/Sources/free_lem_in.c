/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_lem_in.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 22:51:51 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 22:51:51 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	free_roads(t_way *roads)
{
	int cur;

	cur = -1;
	while (roads[++cur].road)
		free(roads[cur].road);
	if (roads)
		free(roads);
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

void	parsing_free_all(char ***params, char ***result, t_room **anthill)
{
	if (params)
	{
		ft_tabdel(*(params));
		*(params) = NULL;
	}
	if (result)
	{
		ft_tabdel(*(result));
		*(result) = NULL;
	}
	if (anthill)
	{
		free_anthill(*(anthill));
		*(anthill) = NULL;
	}
	get_next_line(-1, NULL);
}
