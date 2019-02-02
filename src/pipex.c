/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:58:28 by fel-hita          #+#    #+#             */
/*   Updated: 2019/02/02 17:58:28 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	Pipe(char **command1, char **command2, int fd_infile, int fd_outfile)
{
	int fd[2];
	pid_t childPid;
	if (pipe(fd) != 0)
		exit(EXIT_FAILURE);

	if ((childPid = fork()) == -1)
		exit(EXIT_FAILURE);

	if (childPid == 0)
	{
		dup2(fd[1], 1);
		dup2(fd_infile, 0);
		close(fd[0]);
		close(fd[1]);
		execvp(command1[0], command1);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd[0], 0);
		dup2(fd_outfile, 1);
		close(fd[0]);
		close(fd[1]);
		execvp(command2[0], command2);
		exit(EXIT_FAILURE);
	}
}

int		main(int argc, char *argv[])
{
	int 	fd_infile;
	int 	fd_outfile;
	char	**arg1;
	char	**arg2;

	if (argc == 5)
	{
		arg1 = ft_strsplit(argv[2], ' ');
		arg2 = ft_strsplit(argv[3], ' ');
		fd_infile = open(argv[1], O_RDONLY);
		fd_outfile = open(argv[4], O_WRONLY | O_TRUNC);
		Pipe(arg1, arg2, fd_infile, fd_outfile);
	}
	return (0);
}
