/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:44:43 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/21 18:14:00 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i = 0;

	line = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (0);
		while (get_next_line(fd, &line) > 0)
		{
			i++;
			ft_putendl(line);
			//ft_memdel((void **)&line);
		}	
		ft_putnbr(i);
		close(fd);
	}
	return (0);
}
