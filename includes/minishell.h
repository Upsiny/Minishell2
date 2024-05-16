/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:47:27 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:13 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>

# define DOLLAR_STOP "`~!@#$%^&*()-=+[]{}\'\"\\|:;,<>./"

typedef enum s_type
{
	TOKEN_PIPE,
	TOKEN_STRING,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_REDIR,
}	t_type;

struct	s_data;

typedef struct s_cmd
{
	char			**cmd;
	char			**stdin;
	char			**stdout;
	struct s_cmd	*next;
	struct s_data	*data;
}	t_cmd;

/*typedef struct s_lexer
{
	char			*content;
	int				token_type;
	int				index;
	char			**cmd;
	char			**stdin;
	char			**stdout;
	struct s_lexer	*next;
}	t_lexer;*/

typedef struct s_data
{
	t_cmd	*st_cmd; // struct des commandes
	pid_t	pid;
	char	*prompt; //le prompt qu'on envoie au minishell
	char	*content_here; //le contenue des heredocs
	char	**cp_env; //copie de l'env pour notre minishell
	char	**cp_exp;
	t_list	*s_lex; //structure du lexer
	int		lexer_check; // index du char que l'on regarde dans le prompt pour le lexer
	char	lexer_char; // char que l'on regarde dans le prompt pour le lexer
	int		index_lexer; // index pour le lexer (ou en est-on au niveau de la list)
	int		index_cmd;
	int		in_pipe; // sommes nous dans un pipe?
//	bool	in_pipe;
	int		nb_cmds;
	char	*val_home; // value de l'home dans l'env
//	char	*pwd;
//	char	*oldpwd;
	int		ret_err; // le retour d'erreur du projet / a mettre en variable globale pour envoyer aux signaux
	char	*tmp_dollar; //la value du dollar pour l'expender
	bool	bdq; //booleen pour dire que nous sommes en double quotes / lexer
	bool	bsq; //booleen pour dire que nous sommes dans une single quote / lexer
}	t_data;

//////////// Lexer_Parser //////////////////

t_data	*init_struct(char **envp);
char	**ft_tabcpy(char **tab);
void	lexer_advance(t_data *data);
void	init_lexer(t_data *data);
int		lexer_work(t_data *data);
int		ft_lexer_alpha(t_data *data);
int		ft_lexer_quotes(t_data *data);
int		ft_check_endquote(t_data *data, char c);
int		ft_lexer_redir(t_data *data);
int		ft_lexer_pipe(t_data *data);
void	get_dollar(t_data *data);
void	implement_list(t_data *data, int type, int index, int start);
int		ft_check_lst(t_data *data);
void	ft_free_lst(t_data *data);
void	ft_heredoc(t_list *tmp, t_data *data);
void	replace_prompt(t_data *data, char *value, int start, int end);
int		ft_lexer_str(t_data *data); // new lexer alpha

//////////// Signaux ////////////////

void	ft_signaux(void);

//////////// Erreurs ///////////////

void	ft_error_msg(char *msg);
int		ft_error_parsing(char *msg);
void	error_lexer(char *msg);
void	ft_print_error_msg1(char *s1);
void	ft_print_error_msg2(char *s1, char *s2);
void	ft_print_error_msg3(char *s1, char *s2, char *s3);

//////////// BUILTINS //////////////

int		ft_nb_slash(char *str);
void	pwd_builtin(t_data *data);
char	*get_home_value(char **cp_env);
void	get_pwd(t_data *data);
void	cd_builtin(t_data *data, char **cmd);
void	cd_go_home(t_data *data);
int		cd_go_arg(char *arg);
void	change_value_env(t_data *data, char **cmd);
void	change_value_exp(t_data *data, char **cmd);
void	cpy_value(char *name_var, char **str, char *new_val);
void	change_val_pwdpath(t_data *data, char **cmd, int exp);
void	change_val_exp(t_data *data, char *new_pwd);
void	change_val_env(t_data *data, char *new_pwd);
void	change_value_pwd_exp(t_data *data);
void	change_value_pwd_env(t_data *data);
void	change_value_oldpwd(t_data *data, int exp);
char	*verif_pwd(char *line);
int		recup_new_pwd_exp(t_data *data);
int		recup_new_pwd_env(t_data *data);
void	echo_builtin(char **cmd);
void	exit_builtin(t_data *data, char **cmd);
void	env_builtin(t_data *data, char **cmd);
void	unset_builtin(t_data *data, char **cmd);
char	**order_exp(char **cp_env);
int		check_var(char *str);
void	export_builtin(t_data *data, char **cmd);
int		is_valid_exp(char *str);
int		is_valid_exp2(char *str);
int		count_variables(char **env);
void	print_export(char **cp_exp);
char	*get_env_value(char **env, const char *var);
void	add_variable(t_data *data, char *variable);
void	add_reponame_env(t_data *data, char *repo);
void	add_reponame_exp(t_data *data, char *repo);
void	cpy_value(char *name_var, char **str, char *new_val);
char	*join_var(char *str1, char *new_val);
void	cd_go_home(t_data *data);
void	update_variable(char **env, char *variable);
int		variable_exists(char **env, char *variable);
void	add_variable(t_data *data, char *variable);

//////////// EXECUTION /////////////

int		ft_strcmp(char *s1, char *s2);
void	ft_set_path_and_execve(t_data *data, char **cmd);
void	ft_execution(t_data *data, char **all_path, char **pathcmd, char **cmd);
char	**verif_cmd_struct(char **cmd);
void	redir_builtins_or_execve(t_data *data, char **cmd);
int		aff_errcmd(char **cmd);

//////////// UTILS /////////////////

void	*free_ptr(void *ptr);
void	free_tab(char **tab);
void	print_list(t_data *data);
int		ft_isspace(char c);
int		ft_count_list(t_list *head);
int		ft_tab_len(char **tab);
char	**ft_cpytab(char **tab);
char	*search_in_env(t_data *data, char *str);
char	*ft_strndup(const char *src, size_t n);
char	**build_cmd_from_lexer(t_data *data);
char	*ft_strcat(char *dest, char *src);
char	**add_cmd_before_args(t_data *data, char **args);
void	free_2d_arr(char **arr);
char	**ft_2d_strdup(char **src);
char	*append(char before, char *str);
int		ft_isinside(char c);

#endif
