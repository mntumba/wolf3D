/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:52:24 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/09 15:37:16 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(new_str = (char*)malloc((i + 2) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		new_str[i] = str[i];
	new_str[i + 1] = '\0';
	return (new_str);
}

static char		*read_file(const int fd)
{
	int				i;
	int				len;
	char			buf[BUF_SIZE];
	char			*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	while ((len = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
	{
		str = ft_strdup(str);
		str[i++] = buf[0];
	}
	return ((len == 0 && i == 0) ? NULL : str);
}

static void		fill_map(t_wolf *wolf, char *str, int j)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[len])
		len++;
	if (!(wolf->map[j] = (char*)malloc(len * sizeof(char))))
		exit(EXIT_FAILURE);
	len = 0;
	while (str[++i])
		if (str[i] != ' ')
			wolf->map[j][len++] = str[i];
}

void			ft_parser(t_wolf *wolf)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	if ((fd = open("map", O_RDONLY)) == 1 &&
		write(1, "Fail to open the map\n", 21))
		exit(EXIT_FAILURE);
	if (!(wolf->map = (char**)malloc(24 * sizeof(char*))))
		exit(EXIT_FAILURE);
	while ((line = read_file(fd)) != NULL)
		fill_map(wolf, line, i++);
	free(line);
	close(fd);
}
