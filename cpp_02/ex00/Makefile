SRC		:=	main.cpp Fixed.cpp
OBJ		:=	$(SRC:.cpp=.o)
CC		:=	c++
CFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -g3
RM		:=	rm -rf
NAME	:=	fixed
HEADERS	:=	Fixed.hpp

all:		$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HEADERS)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
