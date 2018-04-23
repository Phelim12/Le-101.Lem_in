/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_lem_in.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 16:19:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 16:19:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"


void	print_anthill(t_room *anthill)
{
	int cur1;
	int cur2;

	cur1 = -1;
	printf("test\n");
	while (anthill && anthill[++cur1].name)
	{
		printf("name = %s\t", anthill[cur1].name);
		printf("x = %d  y = %d\t", anthill[cur1].coord.x, anthill[cur1].coord.y);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("NB_ants = %d\t", anthill[cur1].nb_ants);
		printf("Len = %d\t", anthill[cur1].len);
		cur2 = 1;
		while (anthill[cur1].link && anthill[cur1].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].link[cur2]))[0].name);
			cur2++;
		}
		printf("\n");
	}
	printf("stop\n");
}

int	main(int argc, char const *argv[])
{
	t_room	*anthill;

	if (argc > 1)
		return (print_error_argc());
	anthill = parsing_anthill(NULL, NULL, 0, 1);
	if (anthill)
	{
		print_anthill(anthill);
		free_anthill(anthill);
	}
	printf("END\n");
	return (0);
}
