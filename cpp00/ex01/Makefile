NAME = PhoneBook
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = PhoneBook.cpp
OBJ = PhoneBook.o

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
