##
## Clement-Muth && Sarah-Keppler
## Makefile NanoTekSpice
##

NAME	=	nanotekspice

CC	=	g++

RM	=	rm -f

PATH_COMP	=	./components/
COMP	=	Input.cpp	\
		Clock.cpp	\
		True.cpp	\
		False.cpp	\
		Output.cpp	\
		2716_rom.cpp	\
		4001_nor.cpp	\
		4011_nand.cpp	\
		4030_xor.cpp	\
		4040_counter.cpp\
		4069_not.cpp	\
		4071_or.cpp	\
		4081_and.cpp	\
		Logger.cpp


PATH_PARSER	=	./parser/
PARSER	=	Parser.cpp		\
			InputConsole.cpp

PATH_NTS	=	./
NTS	=	Core.cpp	\
		Error.cpp	\
		Factory.cpp	\
		main.cpp

SRCS	=	$(addprefix $(PATH_COMP), $(COMP))	\
			$(addprefix $(PATH_NTS), $(NTS))	\
			$(addprefix $(PATH_PARSER), $(PARSER))

CXXFLAGS += -Wall -Wextra -Werror

OBJS		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CXXFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) *~ vgcore.* ./components/*~ ./parser/*~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
