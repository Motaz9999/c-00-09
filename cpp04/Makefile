NAME = test02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = Animal.cpp Robot.cpp Dog.cpp Cat.cpp practice02.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re :fclean all

.PHONY :all clean fclean re
