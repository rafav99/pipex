/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaldes- <rvaldes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:24 by rvaldes-          #+#    #+#             */
/*   Updated: 2023/06/15 23:30:28 by rvaldes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <stdarg.h>
#include <sys/wait.h>
# include <fcntl.h>
#include "libft/libft.h"
#include "pipex.h"
#include <errno.h>


int	firstpid(int fd[2], t_commands *my_comm, int infile)
{
	int	pid_1;
	int i;
	char *fullcmd;
	pid_1 = fork();
	if(pid_1 < 0)
		exit(2);
	if (pid_1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		i = 0;
		while(my_comm->paths[i] != NULL)
		{	
			fullcmd = ft_strjoin(my_comm->paths[i], my_comm->cmd_1[0]);
			if(infile == -1)
        		exit(EXIT_FAILURE);
			else
				execve(fullcmd, my_comm->cmd_1 , my_comm->envp);
			free(fullcmd);
			i++;
		}
	}
	return(pid_1);
}
int	scondpid(int fd[2], t_commands *my_comm, int outfile)
{
	int	i;
	int	pid_2;
	char *fullcmd;
	pid_2 = fork();
	if(pid_2 < 0)
		exit(2);
	if (pid_2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile,STDOUT_FILENO);
		close(outfile);
		close(fd[0]);
		i = 0;
		while(my_comm->paths[i] != NULL)
		{
			fullcmd = ft_strjoin(my_comm->paths[i], my_comm->cmd_2[0]);
			execve(fullcmd, my_comm->cmd_2 , my_comm->envp);
			free(fullcmd);
			i++;
		}
		
	}
	return(pid_2);
}
void	pstart(char *argv[], t_commands *my_comm, int outfile, int infile)
{
	int	fd[2];
	int	pid_1;
	int pid_2;

	my_comm->cmd_1 = ft_split(argv[2], ' ');
	my_comm->cmd_2 = ft_split(argv[3], ' ');
	if (pipe(fd) == -1)
		exit(2);
	pid_1= firstpid(fd, my_comm, infile);
	pid_2 = scondpid(fd, my_comm, outfile);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	
}


int main(int argc, char *argv[], char *envp[])
{
	int i;
	char	*path_line;
	int outfile;
	int infile;
	t_commands my_comm;

	my_comm.envp = envp;
	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT);
	if (!(access(argv[1], F_OK) == 0))
	{
		printf("pipex: no such file or directory: %s\n", argv[1]);
		infile = -1;
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
	}
	
	i = 0;
	while (envp[i] != 0)
	{ 
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path_line = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break;
		}
		i++;		
	}
	my_comm.paths = ft_split(path_line, ':');
	i = 0;
	while (my_comm.paths[i] != 0)
	{
		my_comm.paths[i] = ft_strjoin(my_comm.paths[i], "/");
		i++;
	}
	if (argc != 5)
	{
		printf("Error\n");
		exit(1);
	}
	
	pstart(argv, &my_comm, outfile, infile);
    return 0;
}