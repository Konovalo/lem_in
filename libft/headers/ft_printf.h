/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:16:24 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/28 22:44:50 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <float.h>
# include "libft.h"

# define MAX_NUM_BUFF_SIZE 128
# define DIGS "0123456789abcdef0123456789ABCDEF"
# define MINUS "-"
# define PLUS "+"
# define SPACE " "
# define PTR "0x"
# define PTR_UPP "0X"
# define NULL_STR "(null)"
# define ZERO "0"

/*
** === Глобальные переменные и структуры ===
*/

/*
** Список параметров функции ft_printf(...).
*/

va_list		g_argslist;

/*
** Структура преобразования для аргумента функции.
** 1) Флаги:
**  a) f_minus - выводимое значение выравнивается по левому краю в пределах
**  минимальной ширины поля. По умолчанию по правому.
**  б) f_plus - всегда указывать знак (плюс или минус) для выводимого
**  десятичного числового значения. По умолчанию только для отрицательных
**  чисел.
**  в) f_space - помещать перед результатом пробел, если первый символ
**  значения не знак. По умолчанию вывод может начинаться с цифры.
**  г) f_hash - ПОД ВОПРОСОМ, БУДЕМ РЕАЛИЗОВЫВАТЬ ИЛИ НЕТ.
**  д) f_zero - дополнять поле до ширины, указанной в поле ширина управляющей
**  последовательности, символом 0. По умолчанию дополняется пробелами.
** 2) width - модификатор ширины поля.
** 3) precision - модификатор точности.
** 4) uppercase - признак выводa прописными буквами, например для модификаторов
** %F, %X.
** 5) modifier - модификатор размера передаваемых данных. Может принимать
** следущие значения:
**	а) 10. hh - принудительное приведение к char или unsigned char. Для типов
**	d, i, o, u, x, X.
**	б) 11. h - принудительное приведе��ие к short или unsigned short. Для типов
**	d, i, o, u, x, X.
**	в) 20. l - long или unsigned long. Для типов d, i, o, u, x, X.
**	г) 21. ll - long long или unsigned long long. Для типов d, i, o, u, x, X.
**	д) 30. z - size_t для типов d, i, o, u, x, X.
**	е) 35. j - intmax_t или uintmax_t. Для типов d, i, o, u, x, X.
**	ж) 40. L - long double. Для типов a, A, e, E, f, F, g, G.
** 6) dotpresent - флаг начичия "точки" - разделителя между модификаторами
** ширины и точности.
** 7) isint - флаг, является ли поданный аргумент целым числом.
** 8) curconv_sbmcnt - количество символов добаыленных в буффер при обработке
** текущего преобразования. Например, ("%10d", 5) - 3 символа,
** % - не учитывается.
** 9) *prefix - сслыка на префикс, см. выше константы возможных префиксов.
*/

typedef struct	s_conv
{
	int		f_minus;
	int		f_hash;
	int		f_zero;
	int		width;
	int		precision;
	int		uppercase;
	int		modifier;
	int		dotpresent;
	int		isint;
	int		curconv_sbmcnt;
	char	*prefix;
}				t_conv;

typedef struct	s_buff
{
	char	*ptr;
	char	*start;
	size_t	size;

}				t_buff;

t_buff			g_buff;

/*
** Экземпляр структуры t_conv. Инициализируктся всякий раз когда встречается
** преобразование.
*/

t_conv			g_conv;

/*
** Мыссив для хранения основания систем счисления.
*/

char			g_num_bases[127];

/*
** buff_op.c
*/

char			*buff_addstr(const char *s, int n);
char			*buff_addchar(char c, int n);

/*
** doprintd.c
*/

char			*doprintf_2(const char *str);
void			doprintf_3(const char *str);

/*
** ft_printf.c
*/

int				ft_printf(const char *str, ...);
void			get_tokens(char **str);

/*
** get_flgstkns.c
*/

int				get_flags(char flag);
void			get_tokens(char **str);

/*
** init.c
*/

void			init_conversion(void);
void			init_numeric_beses(void);
char			*init_buff(void);

/*
** put_char.c
*/

char			*put_char(char c);

/*
** put_exp.c
*/

char			get_ldexp(long double *n, int *exp);
char			*put_ldexp(long double n);

/*
** put_float.c
*/

char			*put_ldtoa(long double n);

/*
** put_ptr.c
*/

char			*put_ptr(size_t n);

/*
** put_sign_int.c
*/

char			*put_ctoa_base(char n, int base);
char			*put_stoa_base(short n, int base);
char			*put_itoa_base(int n, int base);

/*
** put_sign_int2.c
*/

char			*put_ltoa_base(long n, int base);
char			*put_lltoa_base(long long n, int base);
char			*put_imaxtoa_base(intmax_t n, int base);
char			*put_ssizetoa_base(ssize_t n, int base);

/*
** put_str.c
*/

char			*put_str(const char *s);

/*
** put_usign_int.c
*/

char			*put_uctoa_base(unsigned char n, int base);
char			*put_ustoa_base(unsigned short int n, int base);
char			*put_uitoa_base(unsigned n, int base);

/*
** put_usign_int2.c
*/

char			*put_ultoa_base(unsigned long n, int base);
char			*put_ulltoa_base(unsigned long long n, int base);
char			*put_sizetoa_base(size_t n, int base);
char			*put_uimaxtoa_base(uintmax_t n, int base);

/*
** switch_exp.c
*/

char			*switch_exp();

/*
** switch_float.c
*/

char			*switch_float(void);

/*
** switch_int.c
*/

char			*switch_int(const char *str);

/*
** switch_uint.c
*/

char			*switch_uint(const char *str);

/*
** utils.c
*/

int				check_spec_val(long double n);
char			*zeros_insert(long long n, int base, int len_if_null);
int				number_len(long long n, int base);
int				ismodifier(const char *s);
int				isprec_option(char c);

/*
** valid_seq.c
*/

char			*valid_seq(const char *str);

#endif
