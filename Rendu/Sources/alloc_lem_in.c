/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alloc_lem_in.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 22:48:31 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 22:48:31 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_way		empty_way(void)
{
	t_way ret;

	ret.road = NULL;
	ret.len = -1;
	ret.ants = -1;
	ret.value = -1;
	return (ret);
}

char		**new_tab(int size)
{
	char	**result;
	int		var;

	var = 0;
	result = (char **)malloc(sizeof(char *) * (size + 10));
	while (var < (size + 9))
		result[var++] = NULL;
	return (result);
}

t_way		*new_roads(int size)
{
	t_way	*ret;
	int		cur;

	cur = -1;
	ret = (t_way *)malloc(sizeof(t_way) * (size + 5));
	while (++cur < (size + 5))
		ret[cur] = empty_way();
	return (ret);
}

uintmax_t	*new_umax_tab(int size)
{
	uintmax_t	*ret;
	int			cur;

	cur = -1;
	ret = (uintmax_t *)malloc(sizeof(uintmax_t) * (size + 5));
	while (++cur < (size + 5))
		ret[cur] = 0;
	return (ret);
}
