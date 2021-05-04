/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mini.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:21:58 by avogt             #+#    #+#             */
/*   Updated: 2021/05/02 15:28:58 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MINI_H
# define LIBFT_MINI_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 50

int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char *s, char c);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_strdel(char **as);
size_t			ft_strlen(const char *str);
#endif
