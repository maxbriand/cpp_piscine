NAME = My_First_Class_in_Orthodox_Canonical_Form
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC =	Fixed.cpp \
		main.cpp
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