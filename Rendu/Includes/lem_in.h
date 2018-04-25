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

typedef struct	s_dijkstra
{
	int			len;
	int			done;
	uintmax_t	after;
}				t_dijkstra;

typedef struct	s_way
{
	uintmax_t	*branch;
	int			len_branch;
}				t_way;

typedef struct 	s_room
{
	t_dijkstra	save;
	uintmax_t	*link;
	t_pos		coord;
	char 		*name;
	int			len;
	int			end;
	int			size;
	int			start;
	int			nb_ants;
}				t_room;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              tools_parsing.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

uintmax_t	*realloc_room(t_room *src);
char		*check_start_end(char *line, char *cmt);
void		realloc_anthill(t_room **old_anthill, int size);
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
void		free_anthill(t_room *anthill);

#endif