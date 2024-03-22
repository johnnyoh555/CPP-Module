CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC 	= main RPN
SRCS	= $(addsuffix .cpp, $(SRC))
OBJS_DIR= ./objs/
OBJS	= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
NAME	= RPN

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean	:
	$(RM) -r $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY	: all clean fclean re