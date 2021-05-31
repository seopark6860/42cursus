/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:55:18 by seopark           #+#    #+#             */
/*   Updated: 2021/05/29 15:24:15 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		gnl_strchr(const char *s, int c);
char	*ft_makeline(char *buf, char **line, int i);
int		check_newline(char **buf, char **line);
int		left_buf(char **buf, char **line);

size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
void	*gnl_memmove(void *dst, const void *src, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
#endif
