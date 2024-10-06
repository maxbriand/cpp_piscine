NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CPP = c++

SRC =	main.cpp \
		PmergeMe.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
