/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_anthill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 18:06:09 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 18:06:09 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	realloc_anthill(t_room	**old_anthill, int size)
{
	t_room	*new_anthill;
	int		cur;

	cur = -1;
	new_anthill = (t_room *)malloc(sizeof(t_room) * (size + 20));
	while ((*old_anthill) && (*old_anthill)[++cur].name)
	{
		new_anthill[cur] = (*old_anthill)[cur];
		new_anthill[cur].link = NULL;
		new_anthill[cur].name = ft_strdup((*old_anthill)[cur].name);
		ft_strdel(&(*old_anthill)[cur].name);
	}
	if (size == 100)
		new_anthill[0].name = NULL;
	else
		new_anthill[cur].name = NULL;
	if ((*old_anthill))
		free((*old_anthill));
	(*old_anthill) = new_anthill;
}

void	add_room(t_room **old_anthill, char **params)
{
	static int	size = 100;
	int			cur;

	cur = 0;
	if ((size % 100) == 0)
		realloc_anthill(old_anthill, size);
	while ((*old_anthill) && (*old_anthill)[cur].name)
		cur++;
	(*old_anthill)[cur].end = 0;
	(*old_anthill)[cur].start = 0;
	(*old_anthill)[cur].link = NULL;
	(*old_anthill)[cur].nb_ants = 0;
	(*old_anthill)[cur].len = ft_strlen(P0);
	(*old_anthill)[cur].name = ft_strdup(P0);
	(*old_anthill)[cur].coord.x = ft_atoi(P1);
	(*old_anthill)[cur].coord.y = ft_atoi(P2);
	(*old_anthill)[cur + 1].name = NULL;
	//print_anthill(*old_anthill);
	size++;
}

void		modif_anthill(t_room *anthill, char *cmt, int nb_ants)
{
	int	cur;

	cur = -1;
	while (anthill[(cur + 1)].name)
		cur++;
	if (!(ft_strcmp(cmt, "##start")))
	{
		anthill[cur].start = 1;
		anthill[cur].nb_ants = nb_ants;
	}
	if (!(ft_strcmp(cmt, "##end")))
		anthill[cur].end = 1;
}

intmax_t	*add_link_room(t_room *src, t_room *add)
{
	intmax_t	address;
	intmax_t	*ret;
	int			cur;

	cur = -1;
	address = (intmax_t)add;
	if (!(src->link))
	{
		cur = 1;
		ret = (intmax_t *)malloc(sizeof(intmax_t) * (3));
		ret[0] = 3;
	}
	else
		ret = (intmax_t *)malloc(sizeof(intmax_t) * (src->link[0]));
	while ((src->link) && src->link[++cur])
		ret[cur] = src->link[cur];
	ret[cur++] = address;
	ret[cur] = 0;
	ret[0] += 1;
	cur = 1;
	if ((src->link))
		free(src->link);
	return (ret);
}

void		add_link(t_room *anthill, char **params)
{
	int cur1;
	int cur2;

	cur1 = 0;
	cur2 = 0;
	while (anthill[cur1].name && (ft_strncmp(anthill[cur1].name, P0,\
		anthill[cur1].len) || P0[anthill[cur1].len] != '-'))
		cur1++;
	while (anthill[cur2].name && ft_strncmp(anthill[cur2].name, (P0 + \
		anthill[cur1].len + 1), ft_strlen(P0 + anthill[cur1].len + 1)))
		cur2++;
	anthill[cur1].link = add_link_room((anthill + cur1), (anthill + cur2));
	anthill[cur2].link = add_link_room((anthill + cur2), (anthill + cur1));
}

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
		// cur2 = 1;
		/*while (anthill[cur1].link && anthill[cur1].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].link[cur2]))[0].name);
			cur2++;
		}*/
		printf("\n");
	}
	printf("stop\n");
}


void		fill_anthill(t_room **ptr, char **params, char *cmt, int stage)
{
	static int	save_nb_ants = 0;
	t_room		*new_anthill;

	if (!(save_nb_ants) && (save_nb_ants = ft_atoi(P0)))
		return ;
	if (stage == 1)
	{
		add_room(ptr, params);
		modif_anthill(*ptr, cmt, save_nb_ants);
	}
	if (stage == 2)
		add_link(*ptr, params);
}
