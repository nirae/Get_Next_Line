/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:47:49 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/18 14:51:09 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strmatch(const char *s, int c)
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

t_list		*ft_lstsearch(t_list *lst, int fd)
{
	while (lst != NULL)
	{
		if (((t_file *)lst->content)->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/*void	ft_strreanew(char **str1, char *str2)
{
	char	*result;

	// Verifier la taille
	if ((result = ft_strjoin(*str1, str2)))
	{
		ft_strdel(str1);
		*str1 = result;
	}
}*/

t_file	*ft_newfile(int fd)
{
	t_file *file;

	if (!(file = ft_memalloc(sizeof(t_file *))))
		return (NULL);
	file->fd = fd;
	file->buff = NULL;
	return (file);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_file			*file;
	int				n_lus;
	//char			tmp[BUFF_SIZE];
	char			*tmp;
	char			*result;
	int				pos;
	char			*temp;
	t_list			*tmp_lst;

	if (!(tmp_lst = ft_lstsearch(lst, fd)))
	{
		file = ft_newfile(fd);
		if (!lst)
		{
			if (!(lst = ft_lstnew(file, sizeof(t_file *))))
				return (-1);
		}
		else
			ft_lstaddend(&lst, ft_lstnew(file, sizeof(t_file *)));
	}
	result = ft_strnew(0);
	tmp = ft_strnew(BUFF_SIZE);
	while ((n_lus = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (((t_file *)(tmp_lst->content))->buff != NULL)
			tmp = ft_strjoin(tmp, ((t_file *)(tmp_lst->content))->buff);
		// Si il y a un '\n' dans le buffer
		if ((pos = ft_strmatch(tmp, '\n')) >= 0)
		{
			// recupere le troncon jusqu'au '\n'
			temp = ft_strsub(tmp, 0, pos);
			// l'ajoute au resultat
			result = ft_strjoin(result,	 temp);
			// free le temp
			ft_strdel(&temp);
			// ajoute le reste du buffer dans la liste
			if (!(((t_file *)(tmp_lst->content))->buff = ft_strsub(tmp, pos + 1, BUFF_SIZE)))
				return (-1);
			break;
		}
		temp = ft_strsub(tmp, 0, n_lus);
		result = ft_strjoin(result, temp);
		//ft_strdel(&temp);
		// Fin de fichier
		if (n_lus < BUFF_SIZE)
			break;
	}
	*line = result;
	//ft_putendl(result);
	return (0);
}
