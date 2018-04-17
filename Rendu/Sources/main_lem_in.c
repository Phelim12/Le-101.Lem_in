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

# include "lem_in.h"

int	print_error_argc()
{
	ft_putendl_fd("lem-in: take no argument", 2);
	ft_putendl_fd("usage: lem-in", 2);
	return (0);
}

char	*check_start_end(char *line, char *cmt)
{
	static int 	stop = 0;

	if (!(ft_strcmp(line, "##start")) && ++stop)
		return ("##start\0");
	if (!(ft_strcmp(line, "##end")) && ++stop)
		return ("##end\0");
	if (line[0] == '#')
		return (cmt);
	if (stop++ == 1)
		return (cmt);
	stop = 0;
	return ("");
}

void	modif_anthill(t_room *anthill, char *cmt, int nb_ants)
{
	int			cur;

	cur = -1;
	while (anthill[(cur + 1)].name)
		cur++;
	if (!(ft_strcmp(cmt, "##start")))
	{
		anthill[cur].start = 1;
		anthill[cur].nb_ants = nb_ants;
	}
	if	(!(ft_strcmp(cmt, "##end")))
		anthill[cur].end = 1;
}

t_room	*realloc_anthill(t_room *old_anthill, char **params)
{
	static int 	size = 2;
	t_room		*ret;
	int			cur;

	cur = 0;
	ret = (t_room *)malloc(sizeof(t_room) * (size++));
	while (size > 3 && old_anthill[cur].name)
	{
		ret[cur] = old_anthill[cur];
		ret[cur].name = ft_strdup(old_anthill[cur].name);
		ft_strdel(&old_anthill[cur++].name);
	}
	if (old_anthill)
		free(old_anthill);
	ret[cur].end = 0;
	ret[cur].start = 0;
	ret[cur].nb_ants = 0;
	ret[cur].link = NULL;
	ret[cur].len = ft_strlen(params[0]);
	ret[cur].name = ft_strdup(params[0]);
	ret[cur].coord.x = ft_atoi(params[1]);
	ret[cur].coord.y = ft_atoi(params[2]);
	ret[++cur].name = NULL;
	return (ret);
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

void	add_link(t_room *anthill, char **params)
{
	int cur1;
	int cur2;

	cur1 = 0;
	cur2 = 0;
	while (anthill[cur1].name && (ft_strncmp(anthill[cur1].name, params[0],\
		anthill[cur1].len) || params[0][anthill[cur1].len] != '-'))
		cur1++;
	while (anthill[cur2].name && ft_strncmp(anthill[cur2].name, (params[0] + \
		anthill[cur1].len + 1), ft_strlen(params[0] + anthill[cur1].len + 1)))
		cur2++;
	anthill[cur1].link = add_link_room((anthill + cur1), (anthill + cur2));
	anthill[cur2].link = add_link_room((anthill + cur2), (anthill + cur1));
}

void	fill_anthill(t_room **old_anthill, char **params, int stage, char *cmt)
{
	static int	save_nb_ants = 0;
	t_room 		*new_anthill;

	if (!(save_nb_ants) && (save_nb_ants = ft_atoi(params[0])))
		return ;
	if (stage == 1)
	{
		new_anthill = realloc_anthill(*old_anthill, params);
		modif_anthill(new_anthill, cmt, save_nb_ants);
		*old_anthill = new_anthill;
	}
	if (stage == 2)
		add_link(*old_anthill, params);
}

t_room	*parsing_anthill(t_room *ret, char *cmt, int stage, int cur)
{
	char	**params;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		params = ft_strsplit(line, ' ');
		cmt = check_start_end(line, cmt);
		ft_strdel(&line);
		if ((line = check_error_anthill(ret, params, &stage)))
			return (print_error_anthill(line, ft_itoa(cur), stage));
		if (params[0][0] != '#')
			fill_anthill(&ret, params, stage, cmt);
		ft_tabdel(params);
		cur++;
	}
	return (ret);
}

int main(int argc, char const *argv[])
{
	t_room	*anthill;
	int cur;
	int cur2;

	if (argc > 1)
		return (print_error_argc());
	anthill = parsing_anthill(NULL, NULL, 0, 1);
	cur = -1;
	while (anthill && anthill[++cur].name)
	{
		printf("%jd\t", (intmax_t)(anthill+ cur));
		printf("%s\t", anthill[cur].name);
		printf("%d  %d\t", anthill[cur].coord.x, anthill[cur].coord.y);
		printf("end = %d\t", anthill[cur].end);
		printf("%d\t", anthill[cur].start);
		printf("%d\t", anthill[cur].nb_ants);
		printf("%d\t", anthill[cur].len);
		cur2 = 1;
		while (anthill[cur].link && anthill[cur].link[cur2])
		{
			printf("lien %d = %s\t", cur2, ((t_room *)(anthill[cur].link[cur2]))[0].name);
			cur2++;
		}
		printf("\n");
	}
	return 0;
}















