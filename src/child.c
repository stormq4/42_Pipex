/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 15:24:16 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/01/12 13:43:23 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int f1, char *cmd1, int *end, char **env)
{
	int			child1;

	child1 = dup2(end[1], 1);
	if (child1 < 0)
		return (perror("Dup2: end[1] from stdout/1"));
	close(end[0]);
	child1 = dup2(f1, 0);
	if (child1 < 0)
		return (perror("Dup2: f1 from stdin/0"));
	execute_execve(cmd1, env);
}

void	child_two(int f2, char *cmd2, int *end, char **env)
{
	int			child2;

	child2 = dup2(end[0], 0);
	if (child2 < 0)
		return (perror("Dup2: end[0] from stdin/0"));
	close(end[1]);
	child2 = dup2(f2, 1);
	if (child2 < 0)
		return (perror("Dup2: f2 from stdin/1"));
	execute_execve(cmd2, env);
}
