NAME		= game

CC			= g++
INCLUDES	= -Iincludes/.
CFLAGS		= -g $(INCLUDE)
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
	@echo $(NAME) is ready to play.
	@echo "For the play: ./$(NAME) or make run"

clean:
	@rm -rf $(OBJD)
	@echo "Object Folder Deleted"

fclean: clean
	@rm $(NAME)
	@echo $(NAME) is Removed

run: $(NAME)
	./$(NAME)

re: fclean remessage all

remessage:
	@echo ------- Recompiling -------
