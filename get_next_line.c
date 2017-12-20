/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:47:49 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/20 23:23:10 by ndubouil         ###   ########.fr       */
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
	return (-1);
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
		{
			ft_putendl("fd trouve");
			return (tmp);
		}
		tmp = tmp->next;
	}
	//if (!(tmp = ft_lstnew(ft_newfile(fd), sizeof(t_file *))))
	if (!(tmp = ft_lstnew(NULL, sizeof(t_file *))))
		return (NULL);
	tmp->content = ft_newfile(fd);
	ft_lstadd(lst, tmp);
	return (tmp);
}


int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	char			*buff;
	int				n_lus;
	char			*temp;

	if (BUFF_SIZE <= 0 || fd == 1 || (n_lus = read(fd, "", 0)) == -1)
		return (-1);
	if (!(buff = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	ft_lstsearch(&lst, fd);
	//tmp->content = ft_newfile(fd);
	if (T_FILE_BUFF == NULL)
		ft_putendl("null");
	//T_FILE_BUFF = ft_strjoin(T_FILE_BUFF, "test");
	//ft_putstr(T_FILE_BUFF);
	while ((ft_strpos(T_FILE_BUFF, '\n') < 0) && (n_lus = read(fd, buff, BUFF_SIZE) > 0))
	{
		temp = T_FILE_BUFF;
		T_FILE_BUFF = ft_strjoin(T_FILE_BUFF, buff);
		//ft_putendl(T_FILE_BUFF);
		ft_strdel(&temp);
	}
	*line = ft_strsub(T_FILE_BUFF, 0, ft_strpos(T_FILE_BUFF, '\n'));
	T_FILE_BUFF = ft_strsub(temp, ft_strpos(temp, '\n') + 1, ft_strpos(temp, '\0') - 1);
	return (1);
}

/*
int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				n_lus;
	//char			tmp[BUFF_SIZE];
	char			*tmp;
	char			*result;
	int				pos;
	char			*temp;
	t_list			*tmp_lst;

	if (!(tmp_lst = ft_lstsearch(lst, fd)))
	{
		if (lst == NULL)
		{
			if (!(lst = ft_lstnew(ft_newfile(fd), sizeof(t_file *))))
				return (-1);
		}
		else
			ft_lstaddend(&lst, ft_lstnew(ft_newfile(fd), sizeof(t_file *)));
		tmp_lst = ft_lstsearch(lst, fd);
	}
	result = ft_strnew(0);
	tmp = ft_strnew(sizeof(char) * BUFF_SIZE);
	if (((t_file *)(tmp_lst->content))->buff != NULL)
	{
		ft_putnbr((int)ft_strlen(((t_file *)(tmp_lst->content))->buff));
		tmp = ft_strjoin(tmp, ((t_file *)(tmp_lst->content))->buff);
		ft_memdel((void **)(&((t_file *)(tmp_lst->content))->buff));
	}

	while ((n_lus = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		// Si il y a un '\n' dans le buffer
		if ((pos = ft_strmatch(tmp, '\n')) >= 0)
		{
			// recupere le troncon jusqu'au '\n'
			temp = ft_strsub(tmp, 0, pos);
			// l'ajoute au resultat
			result = ft_strjoin(result, temp);
			// free le temp
			//ft_strdel(&temp);
			// Passe le \n
			read(fd, "", 1);
			// ajoute le reste du buffer dans la liste
			if (!(((t_file *)(tmp_lst->content))->buff = ft_strsub(tmp, pos + 1, BUFF_SIZE)))
				return (-1);
			break;
		}
		//temp = ft_strsub(tmp, 0, n_lus);
		result = ft_strjoin(result, tmp);
		//ft_strdel(&temp);
		// Fin de fichier
		if (n_lus < BUFF_SIZE)
			break;
	}
	*line = result;
	ft_putstr(result);
	return (0);
}*/
