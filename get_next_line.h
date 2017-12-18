/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:37:46 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/18 11:16:37 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft/libft.h"

# define BUFF_SIZE 1000

typedef struct			s_file
{
	int					fd;
	char				*buff;
}						t_file;

int		get_next_line(const int fd, char **line);

#endif
