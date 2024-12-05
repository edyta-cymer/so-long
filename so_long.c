/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:13:18 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:13:20 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftPrintfGnl/libft.h"
#include "so_long.h"

int	display_error(char *message)
{
	ft_printf("Error\n%s", message);
	return (-1);
}

char	*str_join_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (*s1)
		free(s1);
	free(s2);
	return (temp);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**parse_map(char *file_name)
{
	int			fd;
	char		*temp;
	char		*res;
	char		**array;

	res = "";
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror("Error\n ");
	temp = get_next_line(fd);
	if (!temp)
		return (NULL);
	while (temp != NULL)
	{
		res = str_join_free(res, temp);
		temp = get_next_line(fd);
	}
	array = ft_split(res, '\n');
	free(res);
	return (array);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (display_error("Ensure map file is provided"));
	map = parse_map(argv[1]);
	if (!map)
		return (display_error("Error encountered during map parsing"));
	if (!is_valid(map))
	{
		free_map(map);
		return (display_error("Map validation failed"));
	}
	start_game(map);
	return (0);
}
