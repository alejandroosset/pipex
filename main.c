#include "pipex.h"
void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (!path || access(path, F_OK | X_OK) != 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_split(s_cmd);
		exit(127);
	}
    execve(path, s_cmd, env);
	perror("pipex");
	free_split(s_cmd);
	exit(126);
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
}
int main (int ac, char*av[], char *env[])
{
    int p_fd[2];
    pid_t pid;
    if (5 != ac || -1==pipe(p_fd))
        return(ft_putendl_fd("./pipex infile cmd cmd outfile\n", 2), 0);    
    pid = fork();
    if(pid<0)
        return(ft_putendl_fd("./invalid command\n", 2), 0);
    if (!pid)
		child(av, p_fd, env);
	parent(av, p_fd, env);
}
