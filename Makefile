# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 13:36:55 by abosch            #+#    #+#              #
#    Updated: 2020/03/10 12:32:07 by abosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------#
#											  #
#				   VARIABLES				  #
#											  #
#---------------------------------------------#
NAME = completchef

PUSH = push_swap

CHECKER = checker

CC = gcc
CFLAGS = -Werror -Wextra -Wall

CPPFLAGS = -I$(INC_PATH) -Ilibft/$(INC_PATH)
OPTIFLAGS = -O3

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					SOURCES					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC_PATH = src
SRC_COMMON_NAME = stack.c checks.c operation.c operation_bis.c print.c utils.c
SRC_PUSH_NAME = sort.c push_swap.c
SRC_CHECKER_NAME = checker.c

SRC :=	$(addprefix $(SRC_PATH)/,$(SRC_COMMON_NAME))	\
		$(addprefix $(SRC_PATH)/,$(SRC_PUSH_NAME))		\
		$(addprefix $(SRC_PATH)/,$(SRC_CHECKER_NAME))

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					OBJECTS					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
OBJ_PATH = obj
OBJ_NAME = $(SRC_COMMON_NAME:.c=.o)
OBJ_PUSH_NAME = $(SRC_PUSH_NAME:.c=.o)
OBJ_CHECKER_NAME = $(SRC_CHECKER_NAME:.c=.o)

OBJ := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_PUSH := $(addprefix $(OBJ_PATH)/,$(OBJ_PUSH_NAME))
OBJ_CHECKER := $(addprefix $(OBJ_PATH)/,$(OBJ_CHECKER_NAME))

INC_PATH = include

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					LIBRARY					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
LIBDIR = -Llibft
LIBFLAGS = -lft

LIB_NAME = libft
LIB_PATH = .
LIB_DIR = libft/
LIB_PD := $(addprefix $(LIB_PATH)/, $(LIB_DIR))

LIB := $(addprefix $(LIB_PATH)/$(LIB_DIR), $(addsuffix .a,$(LIB_NAME)))
#---------------------------------------------#
#											  #
#					 RULES					  #
#											  #
#---------------------------------------------#

.PHONY: all, clean, fclean, re, norme, rere, lclean, lfclean, lib, pure

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					RELEASE                   #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: $(NAME)

$(NAME): $(CHECKER) $(PUSH)
	@echo "Push_swap and checker done."

$(PUSH): $(OBJ) $(OBJ_PUSH) $(LIB)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -o $@

$(CHECKER): $(OBJ) $(OBJ_CHECKER) $(LIB)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTIFLAGS) -o $@ -c $<

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					LIB						  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
libs: $(LIB)

$(LIB_PATH)/$(LIB_DIR)%.a: FORCE
	@make -C $(LIB_PATH)/$(LIB_DIR)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					CLEAN					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
lclean:
	@make -C $(LIB_PD) clean

lfclean:
	@make -C $(LIB_PD) fclean

clean: lclean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean lfclean
	@rm -f $(CHECKER) $(PUSH)
	@rm -rf $(OBJ_PATH)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					OTHER					 #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
norme: lnorme
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

lnorme:
	@make -C $(LIB_PD) norme
re: fclean all

rere: lfclean fclean libs all

FORCE:

pure: all clean
