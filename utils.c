#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	close_win(int keycode, void *mlx)
int	close_win(int keycode)
{
	if (keycode == 53)
	{
		// mlx_destroy_window(mlx, mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_map_height(void)
{
	int		fd;
	char	*line;
	int		lineas;

	lineas = 0;
	line = "Hola";
	// atexit(ft_leaks);
	fd = open("./mapa", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			lineas--;
		lineas++;
		printf("%s", line);
		free(line);
	}
	if (line == NULL)
		lineas--;
	close(fd);
	return (lineas);
}

int	ft_map_wide(void)
{
	int		fd;
	char	*line;
	int		size_line;

	size_line = 0;
	line = "Hola";
	ft_leaks();
	fd = open("./mapa", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			size_line = ft_line_lenght(line);
		printf("size_line -> %d", size_line);
		// 	size_line--;
		// size_line++;
		printf("%s", line);
		free(line);
	}
	if (line == NULL)
		size_line--;
	close(fd);
	return (size_line);
}

int	ft_line_lenght(char *line)
{
	int	i;

	i = 0;
	while (line[i] || line[i] != '\n')
		i++;
	return (i);
}
