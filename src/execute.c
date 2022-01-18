/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 09:49:07 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/01/12 11:44:53 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_split_null_termininate(char **cmd1_2d)
{
	int	i;

	i = 0;
	while (cmd1_2d[i])
		i++;
	cmd1_2d[i] = NULL;
	return (cmd1_2d);
}

static char	*find_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

static char	*get_command(char *cmd, char **paths)
{
	char	*path_cmd;
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		ft_check_malloc(tmp);
		path_cmd = ft_strjoin(tmp, cmd);
		ft_check_malloc(path_cmd);
		free(tmp);
		if (!access(path_cmd, F_OK))
			return (path_cmd);
		free(path_cmd);
		paths++;
	}
	return (NULL);
}

void	execute_execve(char *cmd, char **env)
{
	char	**cmd_2d;
	char	**paths_2d;
	char	*cmd_path;
	int		check_execve;

	cmd_2d = ft_split(cmd, ' ');
	ft_check_malloc(cmd_2d);
	ft_split_null_termininate(cmd_2d);
	paths_2d = ft_split(find_paths(env), ':');
	ft_check_malloc(paths_2d);
	cmd_path = get_command(cmd_2d[0], paths_2d);
	printf("%s \n", cmd_path);
	if (!cmd_path)
	{
		perror("No path found");
		exit(1);
	}
	check_execve = execve(cmd_path, cmd_2d, env);
	free(cmd_path);
	ft_split_free(cmd_2d);
	ft_split_free(paths_2d);
	if (check_execve < 0)
		return (perror("Execution failed"));
}
