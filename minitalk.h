/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:45:10 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/27 11:04:34 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# ifndef TIMEOUT
#  define TIMEOUT 1
# endif
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/* client.c */
void	handle(int signal);
void	ft_send_char(int pid, char c);

/* serv.c */
void	ft_receve_str(int signal, siginfo_t *info, void *context);

/* utils.c */
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int n);
char	*ft_strjoin(char *str, char c);
int		ft_atoi(char *str);

#endif
