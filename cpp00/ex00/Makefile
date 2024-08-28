NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = megaphone.cpp
OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CPP) $(FLAGS) -c $(SRC)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all
