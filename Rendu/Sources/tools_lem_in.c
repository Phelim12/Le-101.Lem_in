/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_lem_in.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 18:04:40 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 18:04:40 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			print_error_argc(void)
{
	ft_putendl_fd("lem-in: take no argument", 2);
	ft_putendl_fd("usage: lem-in", 2);
	return (0);
}

t_way		ft_branch_null(void)
{
	t_way ret;

	ret.branch = NULL;
	ret.len = -1;
	return (ret);
}

void	free_tree(t_way *tree)
{
	int cur;

	cur = -1;
	while (tree[++cur].branch)
		free(tree[cur].branch);
	free(tree);
}

int 		size_anthill(t_room *anthill)
{
	int	ret;
	
	ret = 0;
	while (anthill[ret].name)
		ret++;
	return (ret);
}

t_way		*ft_newtree(int size)
{
	t_way	*ret;
	int		cur;

	cur = -1;
	ret = (t_way *)malloc(sizeof(t_way) * (size + 5));
	while (++cur < size)
		ret[cur] = ft_branch_null();
	return (ret);
}

uintmax_t	*ft_newumaxtab(int size)
{
	uintmax_t	*ret;
	int			cur;

	cur = -1;
	ret = (uintmax_t *)malloc(sizeof(uintmax_t) * (size + 5));
	while (++cur < (size + 5))
		ret[cur] = 0;
	return (ret);
}

void		free_anthill(t_room *anthill)
{
	int cur;

	cur = -1;
	while (anthill && anthill[++cur].name)
	{
		if (anthill[cur].link)
			free(anthill[cur].link);
		free(anthill[cur].name);
	}
	if (anthill)
		free(anthill);
}
