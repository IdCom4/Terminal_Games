#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define HAUTEUR_ECRAN 15
#define LARGEUR_ECRAN 43
typedef struct element element;

struct element
{
	int x;
	int y;
	char X[2];
	char Y[2];
	int nbr;
};

void	clear_screen(int nbr)
{
	int i = 0;

	while(i < nbr)
	{
		printf("\n");
		i++;
	}
}

int 	move_balle(element balle[1], element joueur[2])
{
	//printf("collide\n");
	if(balle[0].X[0] == '+' && balle[0].Y[0] == '+')
	{
		//printf("in 1\n");
		if(balle[0].x >= LARGEUR_ECRAN - 2)
		{
			//printf("option 1\n");
			return(0);
		}
		else if(balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x < LARGEUR_ECRAN - 3)
		{
			//printf("option 2\n");
			balle[0].Y[0] = '-';
			balle[0].y -= 1;
			balle[0].x += 2;
		}
		else if((balle[0].y < HAUTEUR_ECRAN - 2 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			//printf("option 3\n");
			balle[0].X[0] = '-';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			//printf("option 4\n");
			balle[0].X[0] = '-';
			balle[0].Y[0] = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else
		{
			balle[0].y += 1;
			balle[0].x += 2;
		}
		//printf("out\n");
		return(1);
	}
	else if(balle[0].X[0] == '-' && balle[0].Y[0] == '-')
	{
		//printf("in 2\n");
		if(balle[0].x <= 1)
		{
			//printf("option 1\n");
			return(0);
		}
		else if(balle[0].y <= 1 && balle[0].x > 2)
		{
			//printf("option 2\n");
			balle[0].Y[0] = '+';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y > 1 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			//printf("option 3\n");
			balle[0].X[0] = '+';
			balle[0].y -= 1;
			balle[0].x += 2;
		}
		else if((balle[0].y <= 1 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			//printf("option 4\n");
			balle[0].X[0] = '+';
			balle[0].Y[0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
		}
		else
		{
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		//printf("out\n");
		return(1);
	}
	else if(balle[0].X[0] == '+' && balle[0].Y[0] == '-')
	{
		//printf("in 3\n");
		if(balle[0].x >= LARGEUR_ECRAN - 2)
		{
			//printf("option 1\n");
			return(0);
		}
		else if(balle[0].y <= 1 && balle[0].x < LARGEUR_ECRAN - 3)
		{
			//printf("option 2\n");
			balle[0].Y[0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
		}
		else if((balle[0].y > 1 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			//printf("option 3\n");
			balle[0].X[0] = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y <= 1 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			//printf("option 4\n");
			balle[0].X[0] = '-';
			balle[0].Y[0] = '+';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else
		{
			balle[0].y -= 1;
			balle[0].x += 2;
		}
		//printf("out\n");
		return(1);
	}
	else if(balle[0].X[0] == '-' && balle[0].Y[0] == '+')
	{
		//printf("in 4\n");
		if(balle[0].x <= 1)
		{
			//printf("option 1\n");
			return(0);
		}
		else if(balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x > 2)
		{
			//printf("option 2\n");
			balle[0].Y[0] = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y < HAUTEUR_ECRAN - 2 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			//printf("option 3\n");
			balle[0].X[0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
		}
		else if((balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			//printf("option 4\n");
			balle[0].X[0] = '-';
			balle[0].Y[0] = '+';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else
		{
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		//printf("out\n");
		return(1);
	}
}
/*int	move_balle(element balle[1], element joueur[2])
{
	if(balle[0].Y[0][0] == '+' && balle[0].X[0][0] == '+')
	{
		if(balle[0].y + 1 != HAUTEUR_ECRAN - 1 && (balle[0].x == LARGEUR_ECRAN - 3 && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2)))
		{
			balle[0].X[0][0] = '-';
			balle[0].y += 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y + 1 == HAUTEUR_ECRAN - 1 && (balle[0].x == LARGEUR_ECRAN - 3 && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2)))
		{
			balle[0].Y[0][0] = '-';
			balle[0].X[0][0] = '-';
			balle[0].y -= 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y + 1 != HAUTEUR_ECRAN - 1 && balle[0].x + 1 != LARGEUR_ECRAN - 1)
		{
			balle[0].y += 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y + 1 == HAUTEUR_ECRAN - 1 && balle[0].x + 1 != LARGEUR_ECRAN - 1)
		{
			balle[0].Y[0][0] = '-';
			balle[0].y -= 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].x + 1 == LARGEUR_ECRAN - 1)
			return(0);
		
	}
	else if(balle[0].Y[0][0] == '-' && balle[0].X[0][0] == '-')
	{
		if(balle[0].y - 1 != 0 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].X[0][0] = '+';
			balle[0].y -= 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y - 1 == 0 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].Y[0][0] = '+';
			balle[0].X[0][0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y - 1 != 0 && balle[0].x - 1 != 0)
		{
			balle[0].y -= 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y - 1 == 0 && balle[0].x - 1 != 0)
		{
			balle[0].Y[0][0] = '+';
			balle[0].y += 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].x - 1 == 0)
			return(0);
	}
	else if(balle[0].Y[0][0] == '+' && balle[0].X[0][0] == '-')
	{
		if(balle[0].y + 1 != HAUTEUR_ECRAN - 1 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].X[0][0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y + 1 == HAUTEUR_ECRAN - 1 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].Y[0][0] = '-';
			balle[0].X[0][0] = '+';
			balle[0].y -= 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y + 1 != HAUTEUR_ECRAN - 1 && balle[0].x - 1 != 0)
		{
			balle[0].y += 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y + 1 == HAUTEUR_ECRAN - 1 && balle[0].x - 1 != 0)
		{
			balle[0].Y[0][0] = '-';
			balle[0].y -= 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].x - 1 == 0)
			return(0);
	}
	else if(balle[0].Y[0][0] == '-' && balle[0].X[0][0] == '+')
	{
		if(balle[0].y - 1 != 0 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].X[0][0] = '-';
			balle[0].y += 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y - 1 == 0 && (balle[0].x == 2 && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2)))
		{
			balle[0].Y[0][0] = '+';
			balle[0].X[0][0] = '-';
			balle[0].y += 1;
			balle[0].y -= 2;
			return(1);
		}
		else if(balle[0].y - 1 != 0 && balle[0].x + 1 != LARGEUR_ECRAN - 1)
		{
			balle[0].y -= 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].y - 1 == 0 && balle[0].x + 1 != LARGEUR_ECRAN - 1)
		{
			balle[0].Y[0][0] = '+';
			balle[0].y += 1;
			balle[0].x += 2;
			return(1);
		}
		else if(balle[0].x + 1 == LARGEUR_ECRAN - 1)
			return(0);
	}
	return(0);
}*/

void	print_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int x = 0;
	int y = 0;
	while(y < HAUTEUR_ECRAN)
	{
		while(x < LARGEUR_ECRAN)
		{
			if (grid[x][y] == 0)
				printf("-");
			else if (grid[x][y] == 1)
				printf("|");
			else if (grid[x][y] == 2)
				printf("#");
			else if (grid[x][y] == 3)
				printf("@");
			else if (grid[x][y] == 4)
				printf("o");
			else if (grid[x][y] == 5)
				printf(" ");
			else if (grid[x][y] == 6)
				printf("#");
			x++;
		}
		y++;
		x = 0;
		if (y < HAUTEUR_ECRAN)
			printf("\n");	
	}
}

void	balle_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element balle[1])
{
	grid[balle[0].x][balle[0].y] = 4;
}

void	joueur_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element joueur[2])
{
	if(joueur[0].y + 2 >= HAUTEUR_ECRAN - 1)
	{
		grid[1][HAUTEUR_ECRAN - 4] = 2;
		grid[1][HAUTEUR_ECRAN - 3] = 2;
		grid[1][HAUTEUR_ECRAN - 2] = 2;
	}
	else
	{
		grid[1][joueur[0].y] = 2;
		grid[1][joueur[0].y + 1] = 2;
		grid[1][joueur[0].y + 2] = 2;
	}
	if(joueur[1].y + 2 >= HAUTEUR_ECRAN - 1)
	{
		grid[LARGEUR_ECRAN - 2][HAUTEUR_ECRAN - 4] = 2;
		grid[LARGEUR_ECRAN - 2][HAUTEUR_ECRAN - 3] = 2;
		grid[LARGEUR_ECRAN - 2][HAUTEUR_ECRAN - 2] = 2;
	}
	else
	{
		grid[LARGEUR_ECRAN - 2][joueur[1].y] = 2;
		grid[LARGEUR_ECRAN - 2][joueur[1].y + 1] = 2;
		grid[LARGEUR_ECRAN - 2][joueur[1].y + 2] = 2;
	}
}

void	init_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int x = 0;
	int y = 0;
	while(y < HAUTEUR_ECRAN)
	{
		while(x < LARGEUR_ECRAN)
		{
			grid[x][y] = 5;
			x++;
		}
		y++;
		x = 0;
	}
	y = 0;
	x = 0;
	while(x < LARGEUR_ECRAN)
	{
		grid[x][0] = 0;
		grid[x][HAUTEUR_ECRAN - 1] = 0;
		x++;
	}
	while(y < HAUTEUR_ECRAN)
	{
		grid[0][y] = 1;
		grid[LARGEUR_ECRAN - 1][y] = 1;
		y++;
	}
}

int 	moteur_jeu()
{
	int time = 0;
	char c;
	char move[4];
	int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN];
	int over = 1;
	int swi = 1;
	element joueur[2];
	joueur[0].y = HAUTEUR_ECRAN / 2 + 1;
	joueur[1].y = HAUTEUR_ECRAN / 2 + 1;
	element balle[1];
	/*balle[0].x = (rand() % (LARGEUR_ECRAN / 2) - 3) + LARGEUR_ECRAN / 2 + 1;
	if(balle[0].x % 2 != 0)
		balle[0].x += 1;
	balle[0].y = (rand() % (HAUTEUR_ECRAN - 3)) + 1;*/
	balle[0].x = LARGEUR_ECRAN - 7;
	balle[0].y = HAUTEUR_ECRAN - 2;
	balle[0].Y[0] = '+';
	balle[0].X[0] = '-';
	while(over)
	{
		printf("=== Terminal Pong ===\n");
		init_grid(grid);
		over = move_balle(balle, joueur);
		balle_to_grid(grid, balle);
		joueur_to_grid(grid ,joueur);
		print_grid(grid);
		if(balle[0].x == 22)
		{
			clear_screen(43 - HAUTEUR_ECRAN - 1);
			if(swi == 1)
			{
				swi = 2;
				printf("Joueur 1,entrez une position (entre 1 et %d): ", HAUTEUR_ECRAN);
				fgets(move, sizeof move, stdin);
				/*while((c = getchar()) != '\n' && c != EOF)
				{}*/
				joueur[0].y = atoi(move);
			}
			else
			{
				swi = 1;
				printf("Joueur 2,entrez une position (entre 1 et %d): ", HAUTEUR_ECRAN);
				fgets(move, sizeof move, stdin);
				/*while((c = getchar()) != '\n' && c != EOF)
				{}*/
				joueur[1].y = atoi(move);
			}
		}
		else if(over == 1){
			clear_screen(42 - HAUTEUR_ECRAN);
		}
		else {
			clear_screen(41 - HAUTEUR_ECRAN);
		}
		while(time < 30000000)
		{
			time++;
		}
		time = 0;
	}
	printf("PERDU !\n");
	return(0);
}

int		main(int argc, char **argv)
{
	srand(time(NULL));
	moteur_jeu();
	return(0);
}