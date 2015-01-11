
      #########.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ###/

NAME = ft_retro

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -O3

LDFLAGS = -lncurses -lpthread

SOURCES = AGameEntity.cpp			\
					AShip.cpp						\
					AMissile.cpp				\
					BasicMissile.cpp		\
					Game.cpp						\
					World.cpp						\
					Player.cpp

OBJECTS = $(SOURCES:.cpp=.o)


# Colors
NO_COLOR     = \x1b[0m
OK_COLOR     = \x1b[32;01m
ERROR_COLOR  = \x1b[31;01m
WARN_COLOR   = \x1b[33;01m
SILENT_COLOR = \x1b[30;01m


.PHONY: all re clean fclean

all: $(NAME)

%.o: %.cpp
	@printf "$(SILENT_COLOR)$<$(NO_COLOR)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo " $(OK_COLOR)✓$(NO_COLOR)"

$(NAME): $(OBJECTS) main.o
	@printf "$(SILENT_COLOR)$(NAME)$(NO_COLOR)"
	@$(CXX) $(CXXFLAGS) main.o $(OBJECTS) $(LDFLAGS) -o $(NAME)
	@echo " $(OK_COLOR)Done ✓$(NO_COLOR)"

clean:
	@rm -f $(OBJECTS) main.o
	@echo "$(SILENT_COLOR)Cleaned objects$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(SILENT_COLOR)Cleaned $(NAME)$(NO_COLOR)"

re: fclean all
