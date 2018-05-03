/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_all_roads.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 22:25:11 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 22:25:11 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			number_links_room(uintmax_t *link)
{
	int var_1;

	var_1 = 0;
	while (link[var_1])
		var_1++;
	return (var_1);
}

t_room		*next_ptr_not_done(t_room *anthill)
{
	int var_1;
	int var_2;
	int var_3;

	var_2 = 0;
	var_3 = 0;
	var_1 = -1;
	while (anthill[++var_1].name)
		if (((anthill[var_1].dijk.link) && !(anthill[var_1].dijk.done) && 
			(var_2 = number_links_room(anthill[var_1].dijk.link)) && 
			(var_2 < var_3) && !(anthill[var_1].end)) || !(var_3))
			var_3 = var_2;
	var_1 = -1;
	while ((anthill[++var_1].name) && (var_3))
		if ((anthill[var_1].dijk.link) && !(anthill[var_1].dijk.done) && 
			(number_links_room(anthill[var_1].dijk.link) == var_3) && 
			!(anthill[var_1].end))
			return (anthill + var_1);
	return (NULL);
}

void		add_new_link_anthill(t_room *ptr_modif, t_room *ptr_add)
{
	int var_1;

	if (ptr_modif->dijk.done)
		return ;
	if (!(ptr_modif->dijk.link))
	{
		ptr_modif->dijk.len = 1;
		var_1 = number_links_room(ptr_modif->link);
		ptr_modif->dijk.link = ft_newumaxtab(var_1 + 1);
		ptr_modif->dijk.link[0] = (uintmax_t)(ptr_add);
	}
	else
	{
		ptr_modif->dijk.len++;
		var_1 = number_links_room(ptr_modif->dijk.link);
		ptr_modif->dijk.link[var_1] = (uintmax_t)(ptr_add);
	}
}

void	print_anthill_01(t_room *anthill)
{
	int cur1;
	int cur2;

	cur1 = -1;
	while (anthill && anthill[++cur1].name)
	{
		printf("name = %s\t", anthill[cur1].name);
		printf("E = %d\t", anthill[cur1].end);
		printf("S = %d\t", anthill[cur1].start);
		printf("DONE = %d\n\n", anthill[cur1].dijk.done);
		cur2 = 0;
		while (anthill[cur1].dijk.link && anthill[cur1].dijk.link[cur2])
		{
			printf("new_lien %d = %s\t", cur2, ((t_room *)(anthill[cur1].dijk.link[cur2]))[0].name);
			cur2++;
		}
		printf("\n\n");
	}
	printf("\n\n");
}

t_way		*search_all_roads(t_room *anthill)
{
	t_room	*ptr;
	int		var_1;

	ptr = anthill;
	while (!(ptr->start))
		ptr++;
	while (ptr)
	{
		var_1 = -1;
		while (ptr->link[++var_1])
			add_new_link_anthill((t_room *)(ptr->link[var_1]), ptr);
		ptr->dijk.done = 1;
		ptr = next_ptr_not_done(anthill);
	}
	return (NULL);
}
