NAME = zombieHord
SRC = main.cpp Zombie.cpp zombieHord.cpp
OBJ	= $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re