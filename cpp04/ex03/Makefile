NAME = Interface_and_recap
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC =	main.cpp \
		Materia/AMateria.cpp \
		Materia/Cure.cpp \
		Materia/Ice.cpp \
		Character/Character.cpp \
		MateriaSource/MateriaSource.cpp 
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@ -IMateria -ICharacter -IMateriaSource  

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
