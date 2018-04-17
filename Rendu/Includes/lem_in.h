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

typedef struct 	s_room
{
	intmax_t	*link;
	t_pos		coord;
	char 		*name;
	int			len;
	int			end;
	int			start;
	int			nb_ants;
}				t_room;

char	*check_coordinate_of_the_room(t_room *anthill, char **params);
char	*check_number_of_ants(char **params, int *stage);
char	*check_links_between_rooms(t_room *anthill, char **params);
void	*print_error_anthill(char *error, char *line_number, int stage);
char	*check_error_anthill(t_room *anthill, char **params, int *stage);

#endif