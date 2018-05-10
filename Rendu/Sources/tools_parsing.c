/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 16:07:32 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 16:07:32 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		how_many_end(t_room *anthill)
{
	int result;
	int var;

	var = -1;
	result = 0;
	while (anthill[++var].name)
		result += anthill[var].end;
	return (result);
}

int		how_many_start(t_room *anthill)
{
	int result;
	int var;

	var = -1;
	result = 0;
	while (anthill[++var].name)
		result += anthill[var].start;
	return (result);
}

char	*next_end_or_start(char *line, char *cmt)
{
	static int	stop = 0;

	if (!(ft_strcmp(line, START)) && (stop = 1))
		return (START);
	if (!(ft_strcmp(line, END)) && (stop = 1))
		return (END);
	if (line[0] == '#')
		return (cmt);
	if (stop++ == 1)
		return (cmt);
	stop = 0;
	return (NULL);
}

void	set_start_and_end(t_room *anthill, char *cmt, int nb_ants)
{
	int	var;

	var = -1;
	if (!(cmt))
		return ;
	while (anthill[(var + 1)].name)
		var++;
	if (!(ft_strcmp(cmt, START)))
	{
		anthill[var].start = 1;
		anthill[var].nbr_ants = nb_ants;
	}
	if (!(ft_strcmp(cmt, END)))
		anthill[var].end = 1;
}

char	*have_same_params_on_rooms(t_room *anthill, char **params)
{
	int	var_1;
	int var_2;
	int var_3;

	var_1 = -1;
	var_2 = ft_atoi(P1);
	var_3 = ft_atoi(P2);
	while (anthill && anthill[++var_1].name)
	{
		if (!(ft_strcmp(anthill[var_1].name, P0)))
			return (MSG_13);
		if (anthill[var_1].coord.x == var_2 && anthill[var_1].coord.y == var_3)
			return (MSG_14);
	}
	return (NULL);
}
