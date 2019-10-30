CHECKER	= checker
NAME	= push_swap

SRC = src/

CSRC		= checker.c arr_sotr.c checker_03.c d_2.c \
			  insert.c d.c checker_2.c  uni_2.c numering.c \
			  uni.c val_input.c

PSRC		= arr_sotr.c push_swap.c val_input.c uni.c \
			  uni_2.c d.c d_2.c numering.c insert.c
#COBJ		= $(CSRC:.c=.o)

#POBJ		= $(PSRC:.c=.o)

C_S = $(addprefix $(SRC), $(CSRC))
P_S = $(addprefix $(SRC), $(PSRC))
#OBJ = src/:.c=.o
COBJ = $(CSRC:.c=.o)
POBJ = $(PSRC:.c=.o)

FLGS	= -Wall -Wextra -Werror

all: $(CHECKER) $(NAME)

$(CHECKER): 
	@make -C libft
	gcc -c $(FLGS) $(C_S) #-o $(COBJ)
	gcc  -o $(CHECKER) $(COBJ) libft/libft.a #-L libft 

$(NAME): 
	#$(POBJ)
	make -C libft
	gcc -c $(FLGS) $(P_S) 
	gcc $(POBJ) -o $(NAME)  libft/libft.a

clean:
	@make clean -C libft
	@rm -rf $(COBJ)
	@rm -rf $(POBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(CHECKER) $(COBJ)
	@rm -rf $(NAME) $(POBJ)

re:	fclean all
