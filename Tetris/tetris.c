#include <termios.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <time.h>

#define HAUTEUR_ECRAN xxx
#define LARGEUR_ECRAN xxx
#define WAIT_TIME xxx//50000

int 	moteur_jeu()
{
	int over = 0;

	while(over == 0)
	{
		init_grid(grid);
		if(nbrPiece == 0)
		{
			nbrPiece = 1;
			init__piece(piece);
			over = test_piece(piece, gridMem);
		}
		else
		{
			if(wait % WAIT_TIME / 2 == 0)
			{
				mode_raw(1);
				if(text_unix_khbit() == 1)
					c = getchar();
				mode_raw(0);
				if(can_move_piece(piece, c, gridMem) == 1)
				{
					move_piece(piece, c, grid);
					c = '\0';
				}
			}
			if(wait == WAIT_TIME)
			{
				if(can_move_piece(piece, 's', gridMem) == 1)
					move_piece(piece, 's', grid);
				else
				{
					nbrPiece == 0;
					piece_to_gridMem(gridMem, piece);
					points += suppr_ligne(gridMem);
				}
				merge_grids(grid, gridMem);
				print_grid(grid);
			}
		}
		while((c = getchar()) != '\n' && c != EOF){}
	}
}

int 	main(int argc, char **argv)
{
	int i = 1;

	while(i)
	{
		clear_screen(42);
		if(intro() == 0)
			return(0);
		else
			moteur_jeu();
	}
	return(0);
}