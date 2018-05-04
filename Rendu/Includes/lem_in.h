/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 16:20:16 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 16:20:17 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Libft/Includes/libft.h"
# define	TRUE 1
# define	FALSE 0
# define	P0 params[0]
# define	P1 params[1]
# define	P2 params[2]
# define	P3 params[3]

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃            This structure groups position x (width), y (height).           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_pos
{
	int	y;
	int x;
}				t_pos;

typedef struct	s_way
{
	uintmax_t	*road;
	int			value;
	int			ants;
	int			len;
}				t_way;

typedef struct	s_dijk
{
	uintmax_t	*link;
	int			done;
	int			len;
}				t_dijk;

typedef struct 	s_room
{
	t_dijk		dijk;
	uintmax_t	*link;
	int			size;
	t_pos		coord;
	char 		*name;
	int			len;
	int			end;
	int			start;
	int			nbr_ants;
	int			name_ants;
}				t_room;

typedef struct	s_info
{
	uintmax_t	*tab_1;
	int		nbr_rooms;
	t_way	*roads;
	t_pos	coord;
	t_room	*ptr;
}				t_info;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             find_one_road.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
t_way		follow_rooms(t_room *ptr);
int			search_all_roads(t_info *params);
t_room		*refresh_anthill(t_room *anthill, t_room *ptr);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             find_all_roads.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_way		*search_all_roads_01(t_room *anthill, int size);
// void		block_road(t_room **anthill, int start, int go);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              tools_parsing.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

uintmax_t	*realloc_room(t_room *src);
int 		size_anthill(t_room *anthill);
char		*check_start_end(char *line, char *cmt);
void		realloc_anthill(t_room **old_anthill, int size);
void		print_error_no_way(t_room *anthill, t_way *roads);
void		modif_anthill(t_room *anthill, char *cmt, int nb_ants);
void		*print_error_anthill(char *error, int line_number, int stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             parsing_anthill.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		add_link(t_room *anthill, char **params);
void		add_room(t_room **old_anthill, char **params);
t_room		*parsing_anthill(t_room *ret, char *cmt, int stage, int cur);
void		fill_anthill(t_room **ptr, char **params, char *cmt, int stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              check_anthill.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*check_number_of_ants(char **params, int *stage);
char		*check_links_between_rooms(t_room *anthill, char **params);
char		*check_have_end_start(t_room *anthill, int start, int end);
char		*check_coordinate_of_the_room(t_room *anthill, char **params);
char		*check_error_anthill(t_room *anthill, char **params, int *stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             tools_anthill.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/


int			print_error_argc();
t_way		ft_branch_null(void);
t_way		*ft_newroads(int size);
void		free_roads(t_way *roads);
uintmax_t	*ft_newumaxtab(int size);
void		free_anthill(t_room *anthill);
void		print_anthill(t_room *anthill);
void		print_roads(t_way *roads);
void		reset_anthill(t_room **anthill);
void		ft_sort_time(t_way *roads);

#endif