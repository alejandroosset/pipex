#ifndef PIPEX_H
# define PIPEX_H
# include "include/libft/libft.h"
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <string.h>
char *my_get_env(char *env[]);
char	*get_path(char *cmd, char **env);
int open_file(char *file, int in_or_out);
void	free_split(char **split);
#endif