/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:49:06 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 03:45:52 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define FLAG_QUOTES 0
# define FLAG_NO_QUOTES 1
# define ORDERED 1
# define NOT_ORDERED 0
# define REPEATED -1

typedef struct s_number
{
	int				val;
	struct s_number	*next;
	struct s_number	*prev;
	int				pos;
}	t_num;

int		arg_parse(int argc, char **argv);
int		check_repeated(t_num *stack);
int		freebird(int *a);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
t_num	*sort23(t_num *a);
void	sort4(t_num *a);
void	sort5(t_num *a);
char	**ft_split(char const *s, char c);
void	print_nodes(t_num *stack); //borrar
int		min(t_num *stack);
int		max(t_num *stack);
int		is_sorted(t_num	*stack);
t_num	*swap(t_num *stack);
t_num	*rotate(t_num *stack);

#endif