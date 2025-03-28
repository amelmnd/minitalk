/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:59:41 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 10:22:02 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	*itoa_logic(long int n, int n_len, char *result);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//work to memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

//check cara
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// work to char *
int		ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_free_str(char **str);

// put value in terminal
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

// ft_printf
int		ft_printf(const char *format, ...);
char	*ft_unsigned_itoa(unsigned int n);
void	check_c(char c, int *len);
void	check_s(char *element, int *len);
void	temp_str(char *fn, int *len);
void	convert_base_x(unsigned int n, char *base, int *len);
void	convert_base_p(unsigned long int n, int *len);

#endif
