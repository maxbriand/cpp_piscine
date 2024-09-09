NAME = Towards_a_more_useful_fixed_point_number_class
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC =	main.cpp \
		Fixed.cpp
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