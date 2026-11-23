NAME = test04
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = practice04.cpp 
OBJ = $(SRC:.cpp=.o)
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
re: fclean all
