/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recover_value.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 22:55:16 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 22:55:16 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*end_anthill(t_room *anthill)
{
	t_room *result;

	result = anthill;
	while (result->name && !(result->end))
		result++;
	return (result);
}

t_room		*start_anthill(t_room *anthill)
{
	t_room *result;

	result = anthill;
	while (result->name && !(result->start))
		result++;
	return (result);
}

int			find_nbr_ways(t_room *anthill)
{
	int		result;
	t_room	*ptr;

	result = 0;
	ptr = end_anthill(anthill);
	while (ptr->link[result])
		result++;
	return ((result * 2));
}

int			find_nbr_ants(t_room *anthill)
{
	t_room *ptr;

	ptr = anthill;
	while (!(ptr->start))
		ptr++;
	return (ptr->nbr_ants);
}

int			find_nbr_roads(t_way *roads)
{
	int result;

	result = 0;
	while (roads[result].road)
		result++;
	return (result);
}
