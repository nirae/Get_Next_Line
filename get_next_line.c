/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:47:49 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/14 14:52:12 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_file			*file;

	file->fd = fd;
	file->current_line = "test";
	if (!lst)
	{
		if (!(lst = ft_lstnew(file, sizeof(t_file *))))
			return (-1);
	}
	else
		ft_lstaddend(&lst, ft_lstnew(file, sizeof(t_file *)));
	return (0);
}
