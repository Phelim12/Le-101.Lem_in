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

#include "lem_in.h"

int	main(int argc, char const *argv[])
{
	t_room	*anthill;

	if (argc > 1)
		return (print_error_argc());
	anthill = parsing_anthill(NULL, NULL, 0, 1);
	if (anthill)
	{
	//	print_anthill(anthill);
		free_anthill(anthill);
	}
	return (0);
}
