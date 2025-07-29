#include "pipex.h"
int open_file(char *file, int in_or_out)
{
	int fd;
	if (in_or_out == 0)
		fd = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd == -1)
	{
		perror("pipex: open");
		exit(1);
	}
	return(fd);
}
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
char *my_get_env(char *env[])
{
	int i;

	i = 0;
	while(env[i])
	{
		if(0 == ft_strncmp(env[i], "PATH=", 5))
			return(env[i] + 5);
		i++;
	}
	return(NULL);
}
char *get_path(char *cmd, char *env[])
{
	int i;
	char *part_path;
	char *path;
	char **paths;
	char **s_cmd;

	i = 0;
	paths = ft_split(my_get_env(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (paths[i])
	{
		part_path=ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if(access(path, F_OK | X_OK) == 0)
		{
			free_split(s_cmd);
			return(free_split(paths), path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	free_split(s_cmd);
	return(NULL);	
}
