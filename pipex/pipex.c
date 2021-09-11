/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:31:20 by seopark           #+#    #+#             */
/*   Updated: 2021/09/11 13:56:52 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(char **argv, char **envp, char **paths, int *pipefd)
{
	char	**command;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		open_error(strerror(errno), argv[1]);
		exit (1);
	}
	if (dup2(file1, STDIN_FILENO) == -1)
		perror("child dup2 : ");
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror("child dup2!!: ");
	close(file1);
	command = ft_split(argv[2], ' ');
	if (!command)
		return (1);
	ft_exec(paths, command, envp);
	return (1);
}

int	parent_process(char **argv, char **envp, char **paths, int *pipefd)
{
	char	**command;
	int		file2;

	file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (file2 < 0)
		open_error(strerror(errno), argv[4]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		perror("parent dup2 error : ");
	close(pipefd[1]);
	if (dup2(file2, STDOUT_FILENO) == -1)
		perror("parent dup2!! error: ");
	close(file2);
	command = ft_split(argv[3], ' ');
	if (!command)
		return (1);
	ft_exec(paths, command, envp);
	return (1);
}

void	make_pipe(char **argv, char **envp, char **pahts)
{
	int		pipefd[2];
	pid_t	child_pid;
	int		status;

	child_pid = -1;
	if (pipe(pipefd) == -1)
		print_error_exit("pipe error: ", 1);
	child_pid = fork();
	if (child_pid < 0)
		print_error_exit("fork error: ", 1);
	if (child_pid == 0)
	{
		if (child_process(argv, envp, pahts, pipefd) == 1)
			print_error_exit("child error : ", 1);
	}
	else
	{
		if (waitpid(child_pid, &status, WNOHANG) == -1)
			print_error_exit("waitpid error: ", 1);
		if (parent_process(argv, envp, pahts, pipefd) == 1)
			print_error_exit("parent error : ", 1);
	}
}

char	**find_path(char **envp)
{
	char	**paths;
	int		i;
	int		idx;

	idx = 0;
	while (ft_strncmp("PATH=", envp[idx], 5) != 0)
		idx++;
	paths = ft_split(envp[idx], ':');
	paths[0] = paths[0] + 5;
	if (!paths)
		return (0);
	i = -1;
	while (paths[++i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], "/");
		if (!paths[i])
		{
			ft_free(paths, i);
			return (0);
		}
	}
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc != 5)
		print_error_exit("arguments error: ", 1);
	else
	{
		paths = find_path(envp);
		if (!paths)
			print_error_exit("find path error : ", 1);
		make_pipe(argv, envp, paths);
	}
}
