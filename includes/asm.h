/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:08:32 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 18:08:33 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define INST 12
# define REG_MASK_1 0b01000000
# define REG_MASK_2 0b00010000
# define REG_MASK_3 0b00000100
# define IND_MASK_1 0b11000000
# define IND_MASK_2 0b00110000
# define IND_MASK_3 0b00001100
# define DIR_MASK_1 0b10000000
# define DIR_MASK_2 0b00100000
# define DIR_MASK_3 0b00001000
# define TWO_BYTE_MASK 0b11111111
# define FOUR_BYTE_MASK_1 0b00000000111111110000000000000000
# define FOUR_BYTE_MASK_2 0b00000000000000001111111100000000
# define FULL_BYTE 0b11111111
# define MY_LONG_MAX 9223372036854775807
# define FULL_INT 0xffffffff

typedef struct		s_line{
	char			*r_line;
	char			**com;
	int				f_type;
	int				s_type;
	int				t_type;
	int				args_n;
	int				pos;
	int				length;
	int				nbr;
}					t_line;

typedef struct		s_l_list {
	t_line			ent;
	struct s_l_list	*next;
}					t_line_list;

typedef struct		s_main
{
	char			*name;
	char			*comment;
	t_header		*header;
	unsigned char	*bytes;
}					t_main;

int					ft_check_len(t_main *main);
int					ft_check_first_label(t_line_list *list);
void				ft_add_space(char **str);
char				*some_modifying(char **res, char *s);
void				some_modifying_two(char *s, char *ptr, char **res);
int					read_helper(t_line_list **list, char **str, int *nbr);
int					skip_wspcs(char *s);
int					check_eos(char *s);
t_line_list			*create_file(char *line, int nbr);
int					ft_print_err_arg(t_line_list *list, int n);
int					ft_print_err_lexical(t_line_list *list, int n);
int					ft_print_err_inst(t_line_list *list, int n);
int					ft_is_reg(char *str);
void				ft_ad_t(t_line_list *line, int com_n, int type);
int					ft_got_thresh(t_line_list *list);
int					ft_is_delete(char **com);
int					ft_check_lables(t_line_list *list);
int					ft_check_label_char(t_line_list *list, int n);
int					ft_atoi_1(const char *str);
int					ft_atoi_ret(int neg);
void				ft_print_n_err(void);
int					ft_find_inst(char *inst);
char				*ft_get_l_i_str(char *str);
int					ft_get_pos(const char *big, const char *little);
int					ft_spec_case(char *inst, int n);
int					ft_is_need_arg_code(char *inst);
int					w_in_file(t_line_list *file, t_main *main, char *filename);
int					ft_get_max(t_line_list *list);
int					ft_bytecode(t_line_list *list, t_main *main);
int					ft_is_valid(t_line_list *list);
void				ft_clear_list(t_line_list **list);
int					ft_is_label(char *str);
int					ft_remove_labels(t_line_list *list);
int					ft_get_type_param(t_line_list *line);
void				ft_get_position(t_line_list *list);
int					ft_inst_check(char *str);
int					ft_read_file(char *name, t_line_list **list,
									t_main *main, int r);
char				**ft_split_cmd(char *str);
t_line_list			*get_last(t_line_list *list);
int					ft_is_empty(char *str);
int					ft_err(char *err, int ret);
int					get_header(t_main *main, int size);

#endif
