/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_solve.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 21:52:05 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 21:52:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char	**print_map(char **map)
{
	int var_1;

	var_1 = -1;
	ft_putendl("Map:");
	while (map[++var_1])
	{
		ft_putendl(map[var_1]);
		free(map[var_1]);
	}
	ft_putchar('\n');
	if (map)
		free(map);
	map = NULL;
	return (NULL);
}

void	print_way_one_loop(t_room *anthill, int nbr_ants)
{
	t_room	*end;
	int		var;

	end = anthill;
	var = nbr_ants;
	while (!(end->end))
		end++;
	while (--var > 0)
		ft_printf("L%d-%s ", (nbr_ants - var), end->name);
	ft_printf("L%d-%s\n", (nbr_ants - var), end->name);
	free_anthill(anthill);
	exit(1);
}

void	print_and_move(t_way *best_way, int var_1, int var_2, int *var_3)
{
	t_room	*ptr_1;
	t_room	*ptr_2;

	ptr_1 = ((t_room *)(best_way->road[var_2]));
	ptr_2 = ((t_room *)(best_way->road[var_2 + 1]));
	if (!(ptr_1->nbr_ants) || !(best_way->value) ||
		((ptr_1->start) && !(best_way->ants)))
		return ;
	if (ptr_1->start)
	{
		ptr_2->name_ants = (var_1 - (--(ptr_1->nbr_ants)));
		best_way->ants--;
	}
	else
	{
		ptr_1->nbr_ants = 0;
		ptr_2->name_ants = ptr_1->name_ants;
		ptr_1->name_ants = 0;
	}
	ptr_2->nbr_ants = (ptr_2->end) ? 0 : 1;
	if (*var_3)
		ft_printf(" ");
	ft_printf("L%d-%s", ptr_2->name_ants, ptr_2->name);
	*var_3 = 1;
}

void	print_way_multi_loops(t_way *best_way, int nbr_ants)
{
	int		var_1;
	int		var_2;
	int		var_3;

	var_3 = 0;
	var_1 = -1;
	if (!(stay_on_loops(best_way)))
		return ;
	while (best_way[++var_1].road)
	{
		var_2 = best_way[var_1].len;
		while (--var_2 >= 0)
			print_and_move((best_way + var_1), nbr_ants, var_2, &var_3);
		if (best_way[var_1].value)
			best_way[var_1].value--;
	}
	ft_printf("\n");
	print_way_multi_loops(best_way, nbr_ants);
}
