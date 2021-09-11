/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:09:25 by seopark           #+#    #+#             */
/*   Updated: 2021/09/11 13:10:46 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

/*
**		pipex.c
*/
int		main(int argc, char **argv, char **envp);
char	**find_path(char **envp);
void	make_pipe(char **argv, char **envp, char **pahts);
int		parent_process(char **argv, char **envp, char **pahts, int *pipefd);
int		child_process(char **argv, char **envp, char **pahts, int *pipefd);

/*
**		exec_error.c
*/
void	print_error_exit(char *error_msg, int exit_code);
void	open_error(char *error_msg, char *file);
void	command_error(char *command);
int		ft_exec(char **paths, char **command, char **envp);

/*
**		libft_split.c
*/
char	**ft_split(char const *s, char c);
char	**ft_split2(char **res, char const *s, char c);
char	**ft_free(char **res, int idx);
int		ft_word_cnt(char const *s, char c);
char	*f_substr(char const *s, unsigned int start, size_t len);

/*
**		libft_utils.c
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);

#endif