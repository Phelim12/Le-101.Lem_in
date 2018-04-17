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
	if (params[0] && params[1])
		return ("- Too many arguments.");
	if (!(ft_str_is_number(params[0])))
		return ("- The number is incorrect.");
	if ((ft_strlen(params[0]) > 7) || (ft_atoi(params[0]) > 2000000))
		return ("- The maximum number of ants is two million.");
	if (ft_atoi(params[0]) < 0)
		return ("- The number is negative.");
	if (ft_atoi(params[0]) == 0)
		return ("- Dude ! Their are no ants.");
	(*stage)++;
	return (NULL);
}

char	*check_links_between_rooms(t_room *anthill, char **params)
{
	int cur1;
	int cur2;

	cur1 = 0;
	cur2 = 0;
	if (params[0] && params[1])
		return ("- Too many arguments.");
	if (!(ft_strchr(params[0], '-')))
		return ("- No separator.");
	while (anthill[cur1].name && (ft_strncmp(anthill[cur1].name, params[0],\
		 ft_strlen(anthill[cur1].name)) || params[0][ft_strlen(anthill[cur1].name)] != '-'))
		cur1++;
	if (!(anthill[cur1].name))
		return ("- Name 1 dosen't found.");
	while (anthill[cur2].name && ft_strncmp(anthill[cur2].name, \
		(params[0] + (ft_strlen(anthill[cur1].name) + 1)), \
		ft_strlen((params[0] + (ft_strlen(anthill[cur1].name) + 1)))))
		cur2++;
	if (!(anthill[cur2].name))
		return ("- Name 2 dosen't found.");
	return (NULL);
}

char	*check_coordinate_of_the_room(t_room *anthill, char **params)
{
	int cur;

	cur = -1;
	if (params[0] && params[1] && params[2] && params[3])
		return ("- Too many arguments.");
	if (params[0][0] == 'L')
		return ("- The room name must not start with an \"L\"");
	if (!(ft_str_is_number(params[1])))
		return ("- The number of abscissas is incorrect.");
	if (!(ft_str_is_number(params[2])))
		return ("- The number of ordered is incorrect.");
	if (ft_atoi(params[1]) < 0)
		return ("- The number of abscissas is negative.");
	if (ft_atoi(params[2]) < 0)
		return ("- The number of ordered is negative.");
	while (anthill && anthill[++cur].name)
		if (!(ft_strcmp(anthill[cur].name, params[0])))
			return ("- The name is already taken.");
	return (NULL);	
}

char	*check_error_anthill(t_room *anthill, char **params, int *stage)
{
	if (!(params[0]))
		return ("- The line is empty.");
	if (params[0][0] == '#')
		return (NULL);
	if ((*stage == 1) && (ft_strchr(params[0], '-') && !(params[1])))
		++(*stage);
	if (*stage == 0)
		return (check_number_of_ants(params, stage));
	if (*stage == 1)
		return (check_coordinate_of_the_room(anthill, params));
	if (*stage == 2)
		return (check_links_between_rooms(anthill, params));
	return (NULL);
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
