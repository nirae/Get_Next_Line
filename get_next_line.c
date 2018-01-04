/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:47:49 by ndubouil          #+#    #+#             */
/*   Updated: 2018/01/04 01:08:50 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strpos(const char *s, int c)
{
	int i;

	if (s == NULL || (char)c == 0)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

t_file	*ft_newfile(int fd)
{
	t_file *file;

	if (!(file = ft_memalloc(sizeof(t_file *))))
		return (NULL);
	file->fd = fd;
	if (!(file->buff = ft_strnew(0)))
	{
		ft_memdel((void **)&file);
		return (NULL);
	}
	return (file);
}

t_list		*ft_lstsearch(t_list **lst, int fd)
{
	t_list		*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (T_FILE_FD == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, sizeof(t_file *))))
		return (NULL);
	tmp->content = ft_newfile(fd);
	ft_lstadd(lst, tmp);
	return (tmp);
}


int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	char			*buff;
	int				n_lus;
	char			*temp;
	int				opt;

	// Erreurs
	if (BUFF_SIZE <= 0 | fd == 1 | (n_lus = read(fd, "", 0)) == -1)
		return (-1);
	// Creation du buffer et du maillon
	if (!(buff = ft_strnew(BUFF_SIZE)) || !(tmp = ft_lstsearch(&lst, fd)))
		return (-1);
	// tant qu'il reste du texte, soit dans le buffer de la liste soit dans le fichier
	while (!ft_strchr(T_FILE_BUFF, '\n') && (n_lus = read(fd, buff, BUFF_SIZE) > 0))
	{
		// Obligatoire pour free l'ancien
		temp = T_FILE_BUFF;
		// Concatene le buffer de la liste avec ce qui a ete lu
		T_FILE_BUFF = ft_strjoin(T_FILE_BUFF, buff);
		ft_strdel(&temp);
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	*line = ft_strsub(T_FILE_BUFF, 0, ft_strpos(T_FILE_BUFF, '\n'));
	if (n_lus == 0 && *T_FILE_BUFF == 0)
	{
		ft_memdel((void **)&T_FILE_BUFF);
		ft_strclr(tmp->content);
		return (0);
	}
	if (ft_strpos(T_FILE_BUFF, '\n') == (int)ft_strlen(T_FILE_BUFF))
		opt = 0;
	else
		opt = 1;
	temp = T_FILE_BUFF;
	T_FILE_BUFF = ft_strsub(T_FILE_BUFF, ft_strpos(T_FILE_BUFF, '\n') + opt, (int)ft_strlen(T_FILE_BUFF));
	ft_strdel(&temp);
	return (1);
}
