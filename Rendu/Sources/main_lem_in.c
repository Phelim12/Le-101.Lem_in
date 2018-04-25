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

void	print_tree(t_way *tree)
{
	sleep(2);
	printf("print\n");
	t_room *test;
	int cur = 0;
	int cur1 = 0;

	while (tree[cur1].branch)
	{
		cur = 0;
		while (tree[cur1].branch[cur])
		{
			if (tree[cur1].branch[cur])
			{
				test = (t_room *)tree[cur1].branch[cur];
				printf("%s\t", test->name);
			}
			cur++;
		}
		printf("\n");
		cur1++;
	}
	sleep(2);
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
	printf("stop\n");
}

int		max_branch(t_room *anthill)
{
	int ret;
	int cur1;
	int cur2;

	cur1 = 0;
	cur2 = 0;
	while (!(anthill[cur1].start))
		cur1++;
	while (anthill[cur1].link[cur2])
		cur2++;
	ret = cur2;
	cur1 = 0;
	cur2 = 0;
	while (!(anthill[cur1].end))
		cur1++;
	while (anthill[cur1].link[cur2])
		cur2++;
	if (cur2 < ret)
		ret = cur2;
	return (ret + 2);
}

t_way	end_tree()
{
	t_way ret;

	ret.branch = NULL;
	ret.len_branch = -1;
	return (ret);
}

void	fill_dijkstra(t_room *go, t_room *from)
{
	if ((go->save.len > (from->save.len + 1) || !(go->save.len)) && !(go->save.done))
	{
		go->save.len = (from->save.len + 1);
		go->save.after = (uintmax_t)(from);
	}
}

t_room *refresh_anthill(t_room *anthill)
{
	int cur;
	int min;

	cur = 0;
	min = 0;
	while (anthill[cur].name)
	{
		if (((min > anthill[cur].save.len && anthill[cur].save.len > 0) || !(min)) && !(anthill[cur].save.done))
			min = anthill[cur].save.len;
		cur++;
	}
	cur = 0;
	if (!(min))
		return (NULL);
	while (1)
	{
		if ((anthill[cur].save.len == min && !(anthill[cur].save.done)) || !(anthill[cur].name))
			break;
		cur++;
	}
	return (anthill + cur);
}

t_way	fill_branch(t_room *anthill)
{
	t_room	*ptr;
	t_way	ret;
	int		cur;

	ptr = anthill;
	while (!(ptr->end))
		ptr++;
	if (ptr->save.after)
	{
		cur = ptr->save.len;
		ret.len_branch = cur;
		ret.branch = (uintmax_t *)malloc(sizeof(uintmax_t) * (cur + 5));
		ret.branch[cur + 1] = 0;
		ret.branch[cur--] = (uintmax_t)ptr;
		while (!(ptr->start))
		{
			ret.branch[cur--] = ptr->save.after;
			ptr = (t_room *)(ptr->save.after);
		}
		ret.branch[cur] = (uintmax_t)ptr;
	}
	else
		return (end_tree());
	return (ret);
}

t_way	search_new_branch(t_room *anthill, t_way *tree)
{
	t_way	ret;
	t_room	*ptr;
	int		cur;

	ptr = anthill;
	while (!(ptr->start))
		ptr++;
	while (ptr && !(ptr->end))
	{
		cur = -1;
		while (ptr->link[++cur])
			fill_dijkstra((t_room *)(ptr->link[cur]), ptr);
		ptr->save.done = 1;
		ptr = refresh_anthill(anthill);
	}
	return ((fill_branch(anthill)));
}

void	reset_anthill_dijkstra(t_room **anthill, t_way *tree)
{
	t_room	*ptr;
	int		cur1;
	int		cur2;

	cur1 = -1;
	while ((*anthill)[++cur1].name)
	{
		(*anthill)[cur1].save.len = 0;
		(*anthill)[cur1].save.done = 0;
		(*anthill)[cur1].save.after = 0;
	}
	cur1 = -1;
	while (tree[++cur1].len_branch != -1)
	{
		cur2 = 0;
		while (tree[cur1].branch[(++cur2 + 1)])
		{
			ptr = (t_room *)tree[cur1].branch[cur2];
			ptr->save.done = 1;
		}
	}
}

t_way	*search_all_branch(t_room *anthill)
{
	t_way	*ret;
	int		cur1;
	int		cur2;

	cur1 = 0;
	cur2 = -1;
	ret = (t_way *)malloc(sizeof(t_way) * (max_branch(anthill)));
	while (1)
	{
		print_anthill(anthill);
		ret[++cur2] = search_new_branch(anthill, ret);
		ret[cur2 + 1] = end_tree();
		if (!(ret[cur2].branch))
			break ;
		reset_anthill_dijkstra(&anthill, ret);
	}
	return (ret);
}


int	main(int argc, char const *argv[])
{
	t_room	*test;
	t_room	*anthill;
	t_way	*tree;

	if (argc > 1)
		return (print_error_argc());
	anthill = parsing_anthill(NULL, NULL, 0, 1);
	if (anthill)
		tree = search_all_branch(anthill);
	print_tree(tree);
	/*if (anthill)
		free_anthill(anthill);*/
	return (0);
}
