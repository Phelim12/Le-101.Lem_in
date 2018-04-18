/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_anthill.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/16 21:56:15 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 21:56:15 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char	*check_number_of_ants(char **params, int *stage)
{
	if (P0 && P1)
		return ("- Too many arguments.");
	if (!(ft_str_is_number(P0)))
		return ("- The number is incorrect.");
	if ((ft_strlen(P0) > 7) || (ft_atoi(P0) > 2000000))
		return ("- The maximum number of ants is two million.");
	if (ft_atoi(P0) < 0)
		return ("- The number is negative.");
	if (ft_atoi(P0) == 0)
		return ("- Dude ! Their are no ants.");
	(*stage)++;
	return (NULL);
}

char	*check_coordinate_of_the_room(t_room *anthill, char **params)
{
	int cur;

	cur = -1;
	if (P0 && P1 && P2 && P3)
		return ("- Too many arguments.");
	if (!(P0) || !(P1) || !(P2))
		return ("- Need tree arguments.");
	if (P0[0] == 'L')
		return ("- The room name must not start with an \"L\"");
	if (!(ft_str_is_number(P1)))
		return ("- The number of abscissas is incorrect.");
	if (!(ft_str_is_number(P2)))
		return ("- The number of ordered is incorrect.");
	if (ft_atoi(P1) < 0)
		return ("- The number of abscissas is negative.");
	if (ft_atoi(P2) < 0)
		return ("- The number of ordered is negative.");
	while (anthill && anthill[++cur].name)
		if (!(ft_strcmp(anthill[cur].name, P0)))
			return ("- The name is already taken.");
		else if (anthill[cur].coord.x == ft_atoi(P1) &&\
			anthill[cur].coord.y == ft_atoi(P2))
			return ("- The coordinates are already taken.");
	return (NULL);
}

char	*check_links_between_rooms(t_room *anthill, char **params)
{
	int cur1;
	int cur2;

	cur1 = 0;
	cur2 = 0;
	if (P0 && P1)
		return ("- Too many arguments.");
	if (!(ft_strchr(P0, '-')))
		return ("- No separator.");
	while (anthill[cur1].name && (ft_strncmp(anthill[cur1].name, P0,\
		anthill[cur1].len) || P0[anthill[cur1].len] != '-'))
		cur1++;
	if (!(anthill[cur1].name))
		return ("- Name 1 dosen't found.");
	while (anthill[cur2].name && ft_strncmp(anthill[cur2].name, (P0 + \
		(anthill[cur1].len + 1)), ft_strlen(P0 + (anthill[cur1].len + 1))))
		cur2++;
	if (!(anthill[cur2].name))
		return ("- Name 2 dosen't found.");
	return (NULL);
}

char	*check_have_end_start(t_room *anthill, int start, int end)
{
	int		cur;

	cur = -1;
	while (anthill[++cur].name)
	{
		end += anthill[cur].end;
		start += anthill[cur].start;
	}
	if (end > 1 && start > 1)
		return ("- Multiple end and start.");
	if (end > 1 && !(start))
		return ("- Multiple end and no start.");
	if (start > 1 && !(end))
		return ("- Multiple start and no end.");
	if (!(start) && !(end))
		return ("- No start and no end.");
	if (!(start))
		return ("- No start.");
	if (start > 1)
		return ("- Multiple start.");
	if (!(end))
		return ("- No end.");
	if (end > 1)
		return ("- Multiple end.");
	return (NULL);
}

char	*check_error_anthill(t_room *anthill, char **params, int *stage)
{
	char *line;

	if (!(P0))
		return ("- The line is empty.");
	if (P0[0] == '#')
		return (NULL);
	if ((*stage == 1) && (ft_strchr(P0, '-') && !(P1)))
	{
		if (!anthill)
			return ("- No rooms");
		if ((line = check_have_end_start(anthill, 0, 0)))
			return (line);
		else
			++(*stage);
	}
	if (*stage == 0)
		return (check_number_of_ants(params, stage));
	if (*stage == 1)
		return (check_coordinate_of_the_room(anthill, params));
	if (*stage == 2)
		return (check_links_between_rooms(anthill, params));
	return (NULL);
}
