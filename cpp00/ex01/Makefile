NAME = PhoneBook
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC =	PhoneBook.cpp \
		Contact.cpp \
		main.cpp
OBJ = $(patsubst %.c, %.o, $(SRC))

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
