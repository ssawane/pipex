/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:27:07 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/10 12:23:49 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**paths_pars(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	pipex(char **argv, char **paths, char **envp);
void	ft_child(char **argv, char **paths, int *end, char **envp);
void	ft_parent(char **argv, char **paths, int *end, char **envp);
void	execute(char *cmd, char **paths, char **envp);

#endif