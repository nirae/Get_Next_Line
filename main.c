/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:44:43 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/20 21:10:03 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY))< 0)
			return (0);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		close(fd);
	}
	return (0);
}
