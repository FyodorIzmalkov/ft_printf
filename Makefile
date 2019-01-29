# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:45:36 by lsandor-          #+#    #+#              #
#    Updated: 2019/01/29 18:22:28 by lsandor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

INCLUDE_FOLDERS := -I includes/
SOURCES_FOLDER  := srcs/
OBJECTS_FOLDER  := objs/

vpath %.c srcs

FLAGS := -Wall -Wextra -Werror -g -O2

SOURCES := \
		libft/ft_isdigit.c \
		libft/ft_putstr_fd.c \
		libft/ft_putchar_fd.c \
		libft/ft_atoi.c \
		libft/ft_memalloc.c \
		libft/ft_memcpy.c \
		libft/ft_memdel.c \
		libft/ft_memset.c \
		libft/ft_strcpy.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strdel.c \
		libft/ft_itoa.c \
		libft/ft_strnew.c \
		libft/ft_strncpy.c\
		libft/ft_strcat.c\
		buf.c \
		select_conversion_p_di_str.c \
		conversion_ouxX.c \
		ft_printf.c \
		length_flags.c \
		struct.c \
		flags_validation.c \
		char_conv.c \
		errors.c \
		parce_after_percent.c \
		itoa_base.c \
		conversion_f.c \
		conv_j_z.c \
		precision_str.c\
		d_i_flags.c\
		string_align_functions.c\
		oux_flags.c\
		llitoa.c\
		float_flags.c\
		percent_align.c\
		check_for_ox.c\
		ft_make_string.c

OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

objs/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_FOLDER)

fclean:
	@rm -rf $(OBJECTS_FOLDER)
	@rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean re
