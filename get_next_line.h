/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:37:46 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/09 17:39:01 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 7
# define T_FILE_BUFF ((t_file *)(tmp->content))->buff
# define T_FILE_FD ((t_file *)(tmp->content))->fd

typedef struct			s_file
{
	int					fd;
	char				*buff;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
