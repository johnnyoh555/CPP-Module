CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98
SRC 	= megaphone
SRCS	= $(addsuffix .cpp, $(SRC))
OBJS_DIR= ./objs/
OBJS	= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
NAME	= megaphone

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS)	: $(SRCS)
	mkdir $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS_DIR)

fclean	: clean
	rm -rf $(NAME)

re		: 
	make fclean
	make all

.PHONY	: all clean fclean re