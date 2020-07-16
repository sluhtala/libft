NAME = libft.a
SRC = srcs
CFILES= ft_atoi.c\
	ft_isdigit.c\
	ft_memcmp.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_strcpy.c\
	ft_strjoin.c\
	ft_strncmp.c\
	ft_strsplit.c\
	ft_bzero.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_strdel.c\
	ft_strlcat.c\
	ft_strncpy.c\
	ft_strstr.c\
	ft_intlen.c\
	ft_itoa.c\
	ft_memdel.c\
	ft_putendl.c\
	ft_strcat.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_isalnum.c\
	ft_memalloc.c\
	ft_memmove.c\
	ft_putendl_fd.c\
	ft_strchr.c\
	ft_strequ.c\
	ft_strmap.c\
	ft_strnew.c\
	ft_strtrim.c\
	ft_isalpha.c\
	ft_memccpy.c\
	ft_memset.c\
	ft_putnbr.c\
	ft_strclr.c\
	ft_striter.c\
	ft_strmapi.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_isascii.c\
	ft_memchr.c\
	ft_power.c\
	ft_putnbr_fd.c\
	ft_strcmp.c\
	ft_striteri.c\
	ft_strncat.c\
	ft_strrchr.c\
	ft_toupper.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstappend.c\
	ft_printlst.c\
	ft_strtoupper.c\
	ft_strtolower.c\
	ft_realloc.c\
	ft_pow.c\
	get_next_line.c\

PFDIR = ft_printf
PFFILES= create_list.c\
	error_manager.c\
	free_list.c\
	ft_printf.c\
	initialize_pf.c\
	is_fspecif.c\
	get_data.c\
	ft_itoa_u.c\
	ft_itoa_l.c\
	ft_itoa_ul.c\
	number_manager.c\
	ft_itoa_base.c\
	ft_itoa_base_ll.c\
	hex_manager.c\
	save_float.c\
	save_ldouble.c\
	float_manager.c\
	get_valid_flags.c\
	apply_flags.c\
	is_hex.c\
	apply_preci.c
PCFILES=$(addprefix $(SRC)/,$(CFILES)) 
PPRINTF = $(addprefix $(PFDIR)/, $(PFFILES))
PRINTF = $(addprefix $(SRC)/, $(PPRINTF))
OFILES = $(CFILES:.c=.o) $(PFFILES:.c=.o)
PATHCFILES=$(PCFILES) $(PRINTF)
INCLUDES = include
all: $(NAME)

$(NAME):
	@echo "creating library"
	@gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(PATHCFILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "library created"
.PHONY:clean

clean:
	@rm -f $(OFILES)
	@echo "clean"
fclean:clean
	@rm -f $(NAME)
	@echo "fclean"
re: fclean all
