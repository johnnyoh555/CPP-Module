CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC 	= main HumanA HumanB Weapon
SRCS	= $(addsuffix .cpp, $(SRC))
OBJS_DIR= ./objs/
OBJS	= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
NAME	= War

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean	:
	rm -rf $(OBJS_DIR)

fclean	: clean
	rm -rf $(NAME)

re		: 
	make fclean
	make all
.PHONY	: all clean fclean re