SRC		:=	main.cpp Harl.cpp
OBJ		:=	$(SRC:.cpp=.o)
CC		:=	c++
CFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -g3
RM		:=	rm -rf
NAME	:=	harl
HEADERS	:=	Harl.hpp

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
