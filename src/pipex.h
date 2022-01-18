/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 12:10:37 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/01/11 11:02:44 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

void	child_one(int f1, char *cmd1, int *end, char **env);
void	child_two(int f2, char *cmd2, int *end, char **env);
void	execute_execve(char *cmd, char	**env);

#endif