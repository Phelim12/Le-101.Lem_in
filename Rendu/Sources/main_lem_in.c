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

void	print_tree(t_room *anthill, t_way *tree)
{
	t_room *test;
	int cur = 0;
	int cur1 = -1;
	int cur2 = 0;

	while (anthill[cur2].name)
		cur2++;
	while (tree[++cur1].len != -1)
	{
		cur = 0;
		while (cur <= tree[cur1].len)
		{
			if (tree[cur1].branch[cur])
			{
				test = (t_room *)tree[cur1].branch[cur];
				printf("%s->", test->name);
			}
			cur++;
		}
		printf("\n");
	}
}

void	print_anthill(t_room *anthill)
{
	int cur1;
	int cur2;

	cur1 = -1;
	while (anthill && anthill[++cur1].name)
	{
		printf("name = %s\t", anthill[cur1].name);
		printf("x = %d  y = %d\t", anthill[cur1].coord.x, anthill[cur1].coord.y);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("NB_ants = %d\t", anthill[cur1].nb_ants);
		printf("Len = %d\t", anthill[cur1].len);
		printf("Done = %d\t", anthill[cur1].save.done);
		cur2 = 1;
		while (anthill[cur1].link && anthill[cur1].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].link[cur2]))[0].name);
			cur2++;
		}
		printf("\n");
	}
	printf("\n\n");
}

void	free_tree(t_way *tree)
{
	int cur;

	cur = -1;
	while (tree[++cur].branch)
		free(tree[cur].branch);
	free(tree);
}

int	main(int argc, char const *argv[])
{
	t_room	*anthill;
	t_way	*tree;

	if (argc > 1)
		return (print_error_argc());
	anthill = parsing_anthill(NULL, NULL, 0, 1);
	if (anthill)
	{
		tree = search_all_roads(anthill, size_anthill(anthill));
		print_tree(anthill, tree);
	}
	if (tree)
		free_tree(tree);
	if (anthill)
		free_anthill(anthill);
	return (0);
}
