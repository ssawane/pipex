/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:27:24 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/10 14:15:25 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent(char **argv, char **paths, int *end, char **envp)
{
	int	f2;
	int	status;

	waitpid(-1, &status, 0);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 == -1)
	{
		perror("pipex: outfile error");
		exit(0);
	}
	dup2(end[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(end[1]);
	close(f2);
	execute(argv[3], paths, envp);
}

void	ft_child(char **argv, char **paths, int *end, char **envp)
{
	int	f1;

	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
	{
		perror("pipex: infile error");
		exit(0);
	}
	f1 = open(argv[1], O_RDONLY);
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	execute(argv[2], paths, envp);
}

void	pipex(char **argv, char **paths, char **envp)
{
	int		end[2];
	pid_t	child;

	if (pipe(end) == -1)
	{
		perror("pipex: pipe error");
		exit(0);
	}
	child = fork();
	if (child < 0)
	{
		perror("pipex: fork error");
		exit(0);
	}
	else if (child == 0)
		ft_child(argv, paths, end, envp);
	else if (child > 0)
		ft_parent(argv, paths, end, envp);
	close(end[0]);
	close(end[1]);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc == 5)
	{
		paths = paths_pars(envp);
		pipex(argv, paths, envp);
	}
	else
	{
		perror("pipex: wrong number of arguments");
		exit(0);
	}
	return (0);
}
