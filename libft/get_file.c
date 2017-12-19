/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:48:33 by rpatoux           #+#    #+#             */
/*   Updated: 2017/05/25 11:49:18 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*file_error(char *av)
{
	ft_putstr("No file : ");
	ft_putstr(av);
	ft_putstr(" \n");
	return (NULL);
}

char			*get_file(char *av)
{
	int		fd;
	char	*str;
	char	*tmp;

	if (!(str = (char*)malloc(sizeof(char) * 1)))
		return (0);
	str[0] = '\0';
	if ((fd = open(av, O_RDONLY)) == -1)
		return (file_error(av));
	if (get_next_line((int const)fd, &tmp) <= 0)
		return (NULL);
	str = ft_strjoin_f(str, tmp);
	str = ft_strjoin_f(str, "\n");
	free(tmp);
	tmp = NULL;
	while (get_next_line((int const)fd, &tmp))
	{
		str = ft_strjoin_f(str, tmp);
		str = ft_strjoin_f(str, "\n");
		free(tmp);
		tmp = NULL;
	}
	close(fd);
	return (str);
}
