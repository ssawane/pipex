/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:01:43 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/10 13:18:24 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**paths_pars(char **envp)
{
	char	*path_envp;
	char	**paths;
	char	*tmp;
	size_t	len;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	len = ft_strlen(envp[i]);
	path_envp = ft_substr(envp[i], 5, len - 4);
	paths = ft_split(path_envp, ':');
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
	return (paths);
}

void	execute(char *cmd, char **paths, char **envp)
{
	int		i;
	char	**cmdargc;
	char	*cmd_final;

	cmdargc = ft_split(cmd, ' ');
	i = -1;
	while (paths[++i])
	{
		cmd_final = ft_strjoin(paths[i], cmdargc[0]);
		if (!access(cmd_final, F_OK))
		{
			if (execve(cmd_final, cmdargc, envp) == -1)
			{
				perror ("pipex: bad command");
				exit (0);
			}
			break ;
		}
		free(cmd_final);
	}
	if (paths[i] == 0)
	{
		perror ("pipex: command not found");
		exit (0);
	}
}
