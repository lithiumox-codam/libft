# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdekker <mdekker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/14 23:09:11 by mdekker       #+#    #+#                  #
#    Updated: 2023/09/13 21:33:17 by mdekker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run test submodules

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCLUDES = -I $(CURDIR)/includes
BUILDDIR = build
SRC = characters/ft_isalpha.c characters/ft_isdigit.c characters/ft_isalnum.c characters/ft_isascii.c \
	characters/ft_toupper.c characters/ft_tolower.c memory/ft_bzero.c memory/ft_memcmp.c memory/ft_memset.c \
	memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memchr.c memory/ft_memchr.c characters/ft_isprint.c \
	strings/ft_strlcpy.c strings/ft_strlcat.c strings/ft_strncmp.c \
	strings/ft_atoi.c strings/ft_strlen.c strings/ft_strchr.c strings/ft_strrchr.c \
	memory/ft_calloc.c strings/ft_strnstr.c strings/ft_strdup.c io/ft_putendl_fd.c io/ft_putstr_fd.c \
	io/ft_putchar_fd.c io/ft_putnbr_fd.c strings/ft_itoa.c strings/ft_striteri.c strings/ft_substr.c \
	strings/ft_strjoin.c strings/ft_strmapi.c strings/ft_strtrim.c strings/ft_split.c strings/ft_atod.c \
	utils/math.c utils/string.c strings/ft_atol.c strings/ft_strcat.c strings/ft_strcpy.c \
	strings/ft_strcmp.c memory/ft_realloc.c memory/vector/vec_init.c memory/vector/vec_push.c \
	memory/vector/vec_pop.c memory/vector/vec_get.c memory/vector/vec_free.c \
	memory/vector/vec_insert.c memory/vector/vec_remove.c memory/vector/vec_find.c \
	memory/vector/vec_apply.c memory/vector/vec_resize.c \
	memory/vector/vec_count.c memory/vector/vec_replace.c memory/vector/vec_set.c \

# PRINTF = printf/build/put.o printf/build/printf.o printf/build/utils.o
OBJECTS = $(addprefix $(BUILDDIR)/, $(SRC:.c=.o))
FOLDERS = $(dir $(SRC))
SPLIT = $(FOLDERS:/=)
CAT = $(addprefix $(BUILDDIR)/, $(FOLDERS))

all: submodules $(NAME)

clean:
	@echo "🧨 Cleaning build folder..."
	@make clean -C printf > /dev/null
	@rm -rf $(BUILDDIR)
	@echo "✅ Done!"

fclean: clean
	@echo "🧨 Force cleaning libft..."
	@make fclean -C printf > /dev/null
	@rm -f $(NAME)
	@echo "✅ Done!"

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	@mkdir -p $(CAT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(PRINTF):
	@echo "📥 Compiling printf..."
	@make -C printf > /dev/null

$(NAME): $(OBJECTS) $(PRINTF)
	@echo "⚙️ Compiling..."
	@ar rc $(NAME) $(OBJECTS) $(PRINTF)
	@echo "✅ Done!"

submodules:
	@echo "📥 Updating submodules..."
	@git submodule sync > /dev/null
	@git submodule update --init --recursive > /dev/null
	@echo "✅ Submodules updated!"

norm:
	@echo "🧐 Norm-i-netting..."
	@norminette $(SRC)
	@echo "✅ Done!"

re:
	@$(MAKE) fclean
	@$(MAKE) all
