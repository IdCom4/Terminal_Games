
TERM = Terminal
NAME = $(TERM)_Games

P_TETRIS = ./$(TERM)_Tetris/
P_SNAKE = ./$(TERM)_Snake/
P_PONG = ./$(TERM)_Pong/

SNAKE = $(P_SNAKE)$(TERM)_Snake
TETRIS = $(P_TETRIS)$(TERM)_Tetris
PONG = $(P_PONG)$(TERM)_Pong

SCORE = score.txt
S_TETRIS = $(P_TETRIS)$(SCORE)
S_SNAKE = $(P_SNAKE)$(SCORE)
S_PONG = $(P_PONG)$(SCORE)

GREEN = \033[0;32m
YELLOW = \033[1;33m
ORANGE = \033[0;33m

all: help

help:
	@echo "${ORANGE}=== OPTIONS ==="
	@echo "${YELLOW}Enter \"${GREEN}make setup${YELLOW}\" to set everything up right after the download of $(NAME). (required to play in the future)"
	@echo "${YELLOW}Enter \"${GREEN}make play${YELLOW}\" to play."
	@echo "${YELLOW}Enter \"${GREEN}make score${YELLOW}\" to see all scores of each game."
	@echo "${YELLOW}Enter \"${GREEN}make del_score${YELLOW}\" to reset all the previous scores."
	@echo "${YELLOW}Enter \"${GREEN}make re${YELLOW}\" to clean every files in $(NAME), it automatically do a \"make setup\" after. (don't worry, won't hurt your games at all)"
	@echo "${YELLOW}Enter \"${GREEN}make help${YELLOW}\" or simply \"make\" to show this menu again."

setup: $(TETRIS) $(SNAKE) $(PONG)
	@echo "${YELLOW}>> Compiling source code files..."
	@gcc -o $(TETRIS) $(TETRIS).c
	@echo "${GREEN}>> $(TERM)_Tetris OK."
	@gcc -o $(SNAKE) $(SNAKE).c
	@echo "${GREEN}>> $(TERM)_Snake OK."
	@gcc -o $(PONG) $(PONG).c
	@echo "${GREEN}>> $(TERM)_Pong OK."
	@echo "${GREEN}>> Games created."
	@gcc -o $(NAME) $(NAME).c
	@echo "${GREEN}>> $(NAME) created."

play:
	@./$(NAME)

score:
	@echo "${ORANGE}=== TETRIS ==="
	@cat $(S_TETRIS)
	@echo "${ORANGE}=== SNAKE ==="
	@cat $(S_SNAKE)
	@echo "${ORANGE}=== PONG ==="
	@cat $(S_PONG)
	
del_score:
	@echo "${YELLOW}>> Reseting scores..."
	@rm -f $(SCORES)
	@echo "${GREEN}>> Scores reseted."

clean: del_score
	@echo "${YELLOW}>> Deleting $(NAME)..."
	@rm -f $(TETRIS) $(SNAKE) $(PONG) $(NAME)
	@echo "${GREEN}>> $(NAME) Deleted."

re: clean setup
	@echo "${GREEN}>> Re successfully done."
