NAME		= game

CC			= g++
INCLUDES	= -Iincludes/.
CFLAGS		= -g $(INCLUDES)
LFLAGS		= -lSDL2 -lSDL2_image

OBJD		= objs
SRCD		= src
SRC			= $(wildcard $(SRCD)/*.cpp)
OBJ			= $(SRC:$(SRCD)/%.cpp=$(OBJD)/%.o)

$(OBJD)/%.o: $(SRCD)/%.cpp
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) $(NAME) is ready to play. $(RESET)
	@echo $(GREEN) "For the play: ./$(NAME) or make run" $(RESET)

clean:
	@rm -rf $(OBJD)
	@echo $(RED) "Object Folder Deleted" $(RESET)

fclean: clean
	@rm $(NAME)
	@echo $(RED) $(NAME) is Removed $(RESET)

run: $(NAME)
	./$(NAME)

re: fclean remessage all

remessage:
	@echo $(CYAN) ------- Recompiling ------- $(RESET)

#	COLORS
RESET	= `tput sgr0`
BLACK	= `tput setaf 0`
RED		= `tput setaf 1`
GREEN	= `tput setaf 2`
YELLOW	= `tput setaf 3`
BLUE	= `tput setaf 4`
MAGENTA	= `tput setaf 5`
CYAN	= `tput setaf 6`
WHITE	= `tput setaf 7`
