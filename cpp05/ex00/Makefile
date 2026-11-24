NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = $(OBJ:.o=.d)
#this for dependency files so when u update header just use make not make re to update the executable
#also the falags are for it -MMD make the .d   -MP for make error so it cant not happen
#bc there are .o files take some values from .hpp so it required to be updated always 
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#so this to make sure that the make file read the .d files and check for updates
-include $(DEPS)

clean:
		rm -rf $(OBJ) $(DEPS)
fclean: clean
		rm -rf $(NAME)
re: fclean all
