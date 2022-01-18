/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 12:10:29 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/01/12 13:42:42 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	// int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: left pipe"));
	if (child1 == 0)
		child_one(f1, argv[2], end, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: right pipe"));
	if (child2 == 0)
		child_two(f2, argv[3], end, envp);
	close(end[0]);
	close(end[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		exit(1);
	pipex(f1, f2, argv, envp);
	close(f1);
	close(f2);
	return (0);
}
