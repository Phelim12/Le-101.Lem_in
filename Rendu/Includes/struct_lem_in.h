/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_lem_in.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 23:18:03 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 23:18:03 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_LEM_IN_H
# define STRUCT_LEM_IN_H

typedef struct	s_pos
{
	int			y;
	int			x;
}				t_pos;

typedef struct	s_dijk
{
	uintmax_t	room;
	int			done;
	int			len;
}				t_dijk;

typedef struct	s_way
{
	uintmax_t	*road;
	int			value;
	int			ants;
	int			len;
}				t_way;

typedef struct	s_room
{
	t_dijk		dijk;
	t_pos		coord;
	char		**map;
	uintmax_t	*link;
	char		*name;
	int			len;
	int			end;
	int			size;
	int			start;
	int			nbr_ants;
	int			name_ants;
}				t_room;

#endif
