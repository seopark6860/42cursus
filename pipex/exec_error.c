/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:31:13 by seopark           #+#    #+#             */
/*   Updated: 2021/09/11 13:32:15 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_exit(char *error_msg, int exit_code)
{
	perror(error_msg);
	exit(exit_code);
}

void	open_error(char *error_msg, char *file)
{
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, error_msg, strlen(error_msg));
	write(2, "\n", 1);
}

void	command_error(char *command)
{
	write(2, "\'", 1);
	write(2, command, strlen(command));
	write(2, "\'", 1);
	print_error_exit(" command not found", 1);
}

int	ft_exec(char **paths, char **command, char **envp)
{
	char	*pathname;
	int		i;

	i = -1;
	while (paths[++i] != NULL)
	{
		pathname = ft_strjoin(paths[i], command[0]);
		if (!pathname)
		{
			ft_free(paths, i);
			return (0);
		}
		if (access(pathname, X_OK) == 0)
		{
			if (execve(pathname, command, envp) == -1)
				print_error_exit("exit error", 1);
		}
	}
	command_error(command[0]);
	return (0);
}
