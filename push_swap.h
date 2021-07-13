#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <string.h>
# include "get_next_line.h"

typedef struct s_node
{
	int				value;
	char			*cmd;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*cmd_list;
}				t_data;

int			find_min_pos(t_node *stack);
int			find_max_pos(t_node *stack);
int			is_sorted(t_node *stack);
t_node		*create_new_node(int value);
t_node		*ft_lstlast(t_node *lst);
void		add_back(t_node **head, t_node *node_to_insert);
void		sa(t_data *data);
void		ss(t_data *data);
void		sb(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
void		rr(t_data *data);
void		sort_three_numbers(t_data *data);
void		exec_inst(char *str, t_data *data);
t_node		*create_new_node2(char *str);
void		exec_save_inst(char *str, t_data *data);
void		sort_four_num(t_data *data);
int			find_oper(t_data *data, int *i, int pos, int j);
int			lent_stack(t_node	*stack);
t_node		*conv_tab_tolinkedlist(char **argv, int argc, t_data **data);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
char		*strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
int			is_sorted(t_node *stack);
void		printlist(t_node *head);
void		printlist_cmds(t_node *head);
void		sort_five_num(t_data *data);
int			get_l_closestnum(t_data *data, int p);
int			get_r_closestnum(t_data *data, int num);
void		sortmorethanfive(t_data *data);
void		ft_puterror(char *error, t_data **data);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		check_isdigit(char **tab, t_data **data);
int			is_duplicate(t_node *stack, t_data **data);
void		init(t_data *data);
char		**ft_split(char const *s, char c);
void		free_node(t_node **node);
int			clear_all(t_data **data);
int			ret(char **str);
int			rotate_max(t_data *data, int max_i, int max_op);
void		move_to_a(t_data *data);
int			get_size(t_node *a);
#endif