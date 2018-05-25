/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_lem_in.h                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/10 22:53:27 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 22:53:27 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FUNCTION_LEM_IN_H
# define FUNCTION_LEM_IN_H

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            alloc_lem_in.c .c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_way		empty_way(void);
char		**new_tab(int size);
t_way		*new_roads(int size);
uintmax_t	*new_umax_tab(int size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            best_road_group.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		init_roads(t_way *roads, int nbr_ants);
int			have_junction(t_way *roads, t_way road_b);
t_way		*best_road_group(t_way *roads, int nbr_ants);
int			how_many_turn_solve(t_way *roads, int nbr_ants);
void		new_road_group(t_way **ptr_1, t_way *ptr_2, t_way *ptr_3);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              check_anthill.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*check_have_end_start(t_room *anthill);
char		*check_number_of_ants(char **params, int *stage);
char		*check_links_between_rooms(t_room *anthill, char **params);
char		*check_coordinate_of_the_room(t_room *anthill, char **params);
char		*check_error_anthill(t_room *anthill, char **params, int *stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            find_ways_dijkstra.c                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_way		undesrstand_dijkstra(t_room *ptr);
t_way		best_way_dijkstra(t_room *anthill);
t_way		*find_ways_dijkstra(t_room *anthill);
void		block_road(t_way *roads, int *cursor);
t_room		*new_pointer_dijkstra(t_room *anthill, t_room *ptr);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              free_lem_in.c                                 ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		free_roads(t_way *roads);
void		free_anthill(t_room *anthill);
void		parsing_free_all(char ***params, char ***result, t_room **anthill);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              main_lem_in.c                                 ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			check_error_no_way(t_room *anthill);
void		free_params_main(t_room **p1, t_way **p2, t_way **p3);
void		init_params_main(t_room **p1, t_way **p2, t_way **p3, char ***p4);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             parsing_anthill.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		add_link(t_room *anthill, char **params);
void		add_room(t_room **old_anthill, char **params);
char		**parsing_anthill(t_room **ret, char *cmt, int stage, int cur);
void		fill_anthill(t_room **ptr, char **params, char *cmt, int stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               print_error.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			print_error_argc(const char *name);
void		print_error_empty_file(char **map);
void		print_error_no_way(t_room *anthill, char **map);
void		*print_error_anthill(char *error, int line_number, int stage);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               print_solve.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		**print_map(char **map);
void		print_way_one_loop(t_room *anthill, int nbr_ants);
void		print_way_multi_loops(t_way *best_way, int nbr_ants);
void		print_and_move(t_way *best_way, int var_1, int var_2, int *var_3);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              realloc_lem_in.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

uintmax_t	*realloc_links(t_room *src);
char		**realloc_map_anthill(char **map, int size);
void		realloc_anthill(t_room **old_anthill, int size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              recover_value.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			find_nbr_roads(t_way *roads);
t_room		*end_anthill(t_room *anthill);
int			find_nbr_ways(t_room *anthill);
int			find_nbr_ants(t_room *anthill);
t_room		*start_anthill(t_room *anthill);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              tools_lem_in.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			stay_on_loops(t_way *best_way);
int			check_link_start_end(t_room *anthill);
void		sort_ways_short_to_long(t_way *roads);
void		reset_anthill_dijkstra(t_room *anthill);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              tools_parsing.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			how_many_end(t_room *anthill);
int			how_many_start(t_room *anthill);
char		*next_end_or_start(char *line, char *cmt);
void		set_start_and_end(t_room *anthill, char *cmt, int nb_ants);
char		*have_same_params_on_rooms(t_room *anthill, char **params);

#endif
