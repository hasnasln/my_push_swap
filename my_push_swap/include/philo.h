/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:17:53 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 11:17:55 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define TRUE			1
# define FALSE			0
# define FAIL			0
# define SUCCES			1
# define NOT_ENTERED		-1
# define DEAD			1
# define ALIVE			0
# define FIND			1
# define NOT_FIND		0
# define BEFORE_START	0
# define START			1
# define STOP			2
# define RESET			"\033[0m"
# define RED				"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA			"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

typedef struct s_philo
{
	unsigned int	id;				// filozofun kimliği
	unsigned int	en;				//eat_number
	long long		lmt;			// last_meal_time
	int				take_right;
	int				take_left;
	pthread_mutex_t	*print_m;
	pthread_mutex_t	*eat_m;
	pthread_mutex_t	*rigth_m;
	pthread_mutex_t	*left_m;
	pthread_t		pt_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nop;				//number_of_s_data
	int				ttd;				//time_to_die
	int				tte;				//time_to_eat
	int				tts;				//time_to_sleep
	int				nme;				//number_must_eat
	int				ssf;				// system start
	int				aod;				//any_one_die
	long long		sst;				// system start time
	pthread_mutex_t	*mt;				// muteks dizisi
	pthread_mutex_t	*all_eat_m;			// muteks dizisi
	pthread_mutex_t	print_m;
	pthread_t		detective;
	pthread_mutex_t	detective_m;				
	t_philo			*all_philo;			// tüm filozofların tutulduğu dizi
}	t_data;

// argüman kotrol fonsiyonları
int				argv_correct(int argc, char **argv);
long			ft_atoi(const char *str);
void			print_limit_error(void);
void			print_ture_arguman(void);

// argümanları işleme fonksiyonları
int				define_argv(t_data *s_data, char **argv);

// filozof işlemleri
int				create(t_data *s_data);
int				creat_and_init_muteks(t_data *data, int i, int rv);
int				create_pthread(t_data *data);

// cycle işlemleri
void			*life(void *data);
void			*detective(void *data);
int				take_fork(t_philo *philo);
void			my_wait(long long int time, t_philo *philo);
int				look_ssf(t_data *data);
void			pps(t_philo *philo, char *status);
long long int	my_system_time(void);
void			wait_all_pthread(t_data *data);
int				free_all(t_data *s_data);

#endif