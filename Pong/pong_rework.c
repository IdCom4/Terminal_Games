#include <termios.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <time.h>

#define HAUTEUR_ECRAN 20
#define LARGEUR_ECRAN 61
#define WAIT_TIME 50000

typedef struct element element;

struct element {
	int x;
	int y;
	char L;
	char H;
};

void	terminal_pong()
{
	/*
	printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
	printf("\___ ___/ /  __/ /  __ \  /  \_/  \ / \ /   \   | |   / _ \   | |     \n");
	printf("   | |    | |_   | |__\ | | |\_/| | | | | |\ \  | |  / /_\ \  | |     \n");
	printf("   | |    |  _|  |   __/  | |   | | | | | | \ \ | | |  ___  | | |     \n");
	printf("   | |    | |__  | |\ \   | |   | | | | | |  \ \| | | |   | | | \___  \n");
	printf("   |_|    \____\ |_| \_\  |_|   |_| \_/ |_|   \ __/ |_|   |_| \_____\ \n");
	
	printf(" _____      ___     ___     _   _______ \n");
	printf("/  __ \    / _ \   /   \   | | /  ____/ \n");
	printf("| |__\ |  / / \ \  | |\ \  | | | |  __  \n");
	printf("|  ___/  | |   | | | | \ \ | | | | |_ \ \n");
	printf("| |       \ \_/ /  | |  \ \| | | \__| | \n");
	printf("|_|        \___/   |_|   \ __/ \______/ \n");*/
	printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
	printf("\\#######/ /####/ /#####\\  /##\\_/##\\ /#\\ /###\\   |#|   /###\\   |#|     \n");
	printf("   |#|    |#|_   |#|__\\#| |#|\\#/|#| |#| |#|\\#\\  |#|  /#/_\\#\\  |#|     \n");
	printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \\#\\ |#| |#######| |#|     \n");
	printf("   |#|    |#|__  |#|\\#\\   |#|   |#| |#| |#|  \\#\\|#| |#|   |#| |#\\___  \n");
	printf("   |#|    \\####\\ |#| \\#\\  |#|   |#| \\#/ |#|   \\###/ |#|   |#| \\#####\\ \n");
	
	printf(" _____      ___     ___     _   _______ \n");
	printf("/#####\\    /###\\   /###\\   |#| /######/ \n");
	printf("|#|__\\#|  /#/ \\#\\  |#|\\#\\  |#| |#|  __  \n");
	printf("|#####/  |#|   |#| |#| \\#\\ |#| |#| |##\\ \n");
	printf("|#|       \\#\\_/#/  |#|  \\#\\|#| |#\\__|#| \n");
	printf("|#|        \\###/   |#|   \\###/ \\######/ \n");
}

int unix_text_kbhit(void) 
{ 
    struct timeval tv = { 0, 0 }; 
    fd_set readfds; 
  
    FD_ZERO(&readfds); 
    FD_SET(STDIN_FILENO, &readfds); 
  
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1; 
}

void    mode_raw(int activer) 
{ 
    static struct termios cooked; 
    static int raw_actif = 0; 
  
    if (raw_actif == activer) 
        return; 
  
    if (activer) 
    { 
        struct termios raw; 
  
        tcgetattr(STDIN_FILENO, &cooked); 
  
        raw = cooked; 
        cfmakeraw(&raw); 
        tcsetattr(STDIN_FILENO, TCSANOW, &raw); 
    } 
    else 
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked); 
  
    raw_actif = activer; 
}

void 	clear_screen(int nbrLigne)
{
	int i = 0;

	while(i < nbrLigne)
	{
		printf("\n");
		i++;
	}
}

int 	move_balle(element balle[1], element joueur[2])
{
	if(balle[0].L == '+' && balle[0].H == '+')
	{
		if(balle[0].x >= LARGEUR_ECRAN - 2)
		{
			return(0);
		}
		else if(balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x < LARGEUR_ECRAN - 3)
		{
			balle[0].H = '-';
			balle[0].y -= 1;
			balle[0].x += 2;
		}
		else if((balle[0].y < HAUTEUR_ECRAN - 2 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			balle[0].L = '-';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			balle[0].L = '-';
			balle[0].H = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else
		{
			balle[0].y += 1;
			balle[0].x += 2;
		}
		return(1);
	}
	else if(balle[0].L == '-' && balle[0].H == '-')
	{
		if(balle[0].x <= 1)
		{
			return(0);
		}
		else if(balle[0].y <= 1 && balle[0].x > 2)
		{
			balle[0].H = '+';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y > 1 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			balle[0].L = '+';
			balle[0].y -= 1;
			balle[0].x += 2;
			return(2);
		}
		else if((balle[0].y <= 1 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			balle[0].L = '+';
			balle[0].H = '+';
			balle[0].y += 1;
			balle[0].x += 2;
			return(2);
		}
		else
		{
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		return(1);
	}
	else if(balle[0].L == '+' && balle[0].H == '-')
	{
		if(balle[0].x >= LARGEUR_ECRAN - 2)
		{
			return(0);
		}
		else if(balle[0].y <= 1 && balle[0].x < LARGEUR_ECRAN - 3)
		{
			balle[0].H = '+';
			balle[0].y += 1;
			balle[0].x += 2;
		}
		else if((balle[0].y > 1 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			balle[0].L = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y <= 1 && balle[0].x == LARGEUR_ECRAN - 3) && (balle[0].y >= joueur[1].y && balle[0].y <= joueur[1].y + 2))
		{
			balle[0].L = '-';
			balle[0].H = '+';
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		else
		{
			balle[0].y -= 1;
			balle[0].x += 2;
		}
		return(1);
	}
	else if(balle[0].L == '-' && balle[0].H == '+')
	{
		if(balle[0].x <= 1)
		{
			return(0);
		}
		else if(balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x > 2)
		{
			balle[0].H = '-';
			balle[0].y -= 1;
			balle[0].x -= 2;
		}
		else if((balle[0].y < HAUTEUR_ECRAN - 2 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			balle[0].L = '+';
			balle[0].y += 1;
			balle[0].x += 2;
			return(2);
		}
		else if((balle[0].y >= HAUTEUR_ECRAN - 2 && balle[0].x == 2) && (balle[0].y >= joueur[0].y && balle[0].y <= joueur[0].y + 2))
		{
			balle[0].L = '+';
			balle[0].H = '-';
			balle[0].y -= 1;
			balle[0].x += 2;
			return(2);
		}
		else
		{
			balle[0].y += 1;
			balle[0].x -= 2;
		}
		return(1);
	}
}

void	move_joueur(element joueur[2], char *c)
{
	if(*c == 'z' && joueur[0].y > 1)
		joueur[0].y -= 1;
	else if(*c == 's' && joueur[0].y < HAUTEUR_ECRAN - 4)
		joueur[0].y += 1;
	else if(*c == 'o' && joueur[1].y > 1)
		joueur[1].y -= 1;
	else if(*c == 'l' && joueur[1].y < HAUTEUR_ECRAN - 4)
		joueur[1].y += 1;
	*c = ' ';
}

void	joueur_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element joueur[2])
{
	int nbrJoueur = 0;
	int length = 0;

	while(nbrJoueur < 2)
	{
		while(length < 3)
		{
			if(nbrJoueur == 0)
				grid[1][joueur[0].y + length] = 3;
			else
				grid[LARGEUR_ECRAN - 2][joueur[1].y + length] = 3;
			length++;
		}
		length = 0;
		nbrJoueur++;
	}
}

void	balle_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element balle[1])
{
	grid[balle[0].x][balle[0].y] = 4;
}

void    print_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], int plus, int mode, int point)
{
	FILE *highScore = NULL;
	char score[200];
	highScore = fopen("score_pong.txt", "r");

    int x = 0;
    int y = 0;
    printf("=== TERMINAL PONG ===\n");
    if(mode == 1)
    {
    	if(highScore == NULL)
    		printf("HIGHSCORE = 0\n");
    	else
    	{
    		fgets(score, 200, highScore);
    		printf("%s\n", score);
    		fclose(highScore);
    	}
    	printf("POINTS = %d\n", point);
    }
    else
    	printf("\n\n");
    while(y < HAUTEUR_ECRAN)
    {
        while(x < LARGEUR_ECRAN)
        {
            if (grid[x][y] == 0)
                printf("-");
            else if (grid[x][y] == 1)
                printf("|");
            else if (grid[x][y] == 2)
                printf(" ");
            else if (grid[x][y] == 3)
                printf("#");
            else if (grid[x][y] == 4)
                printf("o");
            x++;
        }
        y++;
        x = 0;
        if (y <= HAUTEUR_ECRAN)
            printf("\n");   
    }
    printf("JOUEUR 1 ");
    while(x < LARGEUR_ECRAN - 18)
    {
    	printf(" ");
    	x++;
    }
    printf(" JOUEUR 2\n");
    if(mode == 1)
    	clear_screen(38 - HAUTEUR_ECRAN - plus);
    else
    	clear_screen(38 - HAUTEUR_ECRAN - plus);
}

void    init_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int x = 0;
    int y = 0;
    while(y < HAUTEUR_ECRAN)
    {
        while(x < LARGEUR_ECRAN)
        {
            grid[x][y] = 2;
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

void	move_IA(element joueur[2], element balle[0])
{
	if(balle[0].x == LARGEUR_ECRAN - 3 && balle[0].L == '+')
		joueur[1].y = balle[0].y - 1;
	if(joueur[1].y <= 0)
		joueur[1].y = 1;
	else if(joueur[1].y >= HAUTEUR_ECRAN - 3)
		joueur[1].y = HAUTEUR_ECRAN - 4;
}

int 	moteur_jeu()
{
	FILE *highScore = NULL;
	char score[200];
	char nom[100];

	highScore = fopen("score_pong.txt", "r");

	int point = 0;
	char c = '\0';
	int mode = 0;
	int wait = 0;
	int over = 1;
	int difficulte;
	int difficulte2 = 15000;
	int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN];
	element joueur[2];
	element balle[1];
	balle[0].x = LARGEUR_ECRAN / 2;
	if((LARGEUR_ECRAN / 2) % 2 != 0)
		balle[0].x -= 1;
	balle[0].y = (rand() % (HAUTEUR_ECRAN - 7)) + 3;
	if(rand() % 2 == 0)
		balle[0].L = '-';
	else
		balle[0].L = '+';
	if(rand() % 2 == 0)
		balle[0].H = '+';
	else
		balle[0].H = '-';
	joueur[0].y = HAUTEUR_ECRAN / 2 - 1;
	joueur[1].y = HAUTEUR_ECRAN / 2 - 1;

	init_grid(grid);
	joueur_to_grid(grid, joueur);
	print_grid(grid, 2, mode, point);
	printf("1 = Mode contre l'IA (Tenez le plus longtemps possible !)\n");
	printf("2 = Mode 2 Joueurs (Que le meilleur gagne !)\n");
	while(mode != 1 && mode != 2)
	{
		c = getchar();
		mode = c - 48;
		while((c = getchar()) != '\n' && c != EOF)
    	{}
		if(mode != 1 && mode != 2)
			printf("Mauvaise saisie, recommencez.\n");
	}
	c = '\0';
	if(mode == 1)
		balle[0].L = '+';
	else
		difficulte2 = 8000;
	while(c == '\0')
	{
		init_grid(grid);
		joueur_to_grid(grid, joueur);
		balle_to_grid(grid, balle);
		print_grid(grid, 3 + mode, 0, point);
		printf("Joueur 1: utilisez la touche 'z' pour vous déplacer vers le haut et la touche 's' pour vous déplacer vers le bas.\n");
		if(mode == 2)
			printf("Joueur 2: utilisez la touche 'o' pour vous déplacer vers le haut et la touche 'l' pour vous déplacer vers le bas.\n");
		printf("\nAu moment ou vous lancerez la partie la balle sera lancée également, préparez vous.\n");
		printf("Entrez une difficulté pour lancer la partie (1, 2, 3): \n");
		c = getchar();
		if(c == '2')
		{
			difficulte2 = 20000;
			difficulte = 1;
		}
		else if(c == '3')
			difficulte = 2;
		else
			difficulte = 0;
	}
	while((c = getchar()) != '\n' && c != EOF)
    {}
	while(over)
	{
		mode_raw(1);
		if(unix_text_kbhit() == 1)
			c = getchar();
		mode_raw(0);
		if(wait == WAIT_TIME - (difficulte2 * difficulte))
		{
			over = move_balle(balle, joueur);
			wait = 0;
			if(over == 2)
				point++;
		}
		if(wait % WAIT_TIME / 2 == 0)
		{
			move_joueur(joueur, &c);
			if(mode == 1 && over != 0)
			{
				move_IA(joueur, balle);
			}
			init_grid(grid);
			balle_to_grid(grid, balle);
			joueur_to_grid(grid, joueur);
			print_grid(grid, 0, mode, point);
		}
		wait++;
	}
	if(balle[0].L == '-' && mode == 2)
	{
		print_grid(grid, 2, mode, point);
		printf("Le joueur 1 perd, le joueur 2 gagne !\n\n");
		printf("Entrez n'importe quelle lettre: ");
		c = getchar();
		while((c = getchar()) != '\n' && c != EOF)
    	{}
	}
	else if(mode == 2)
	{
		print_grid(grid, 2, mode, point);
		printf("Le joueur 2 perd, le joueur 1 gagne !\n\n");
		printf("Entrez n'importe quelle lettre: ");
		c = getchar();
		while((c = getchar()) != '\n' && c != EOF)
    	{}
	}
	else
	{
		if(highScore == NULL)
		{
			print_grid(grid, 2, mode, point);
			printf("Perdu ! POINTS = %d\n\n", point);
		
            highScore = fopen("score_pong.txt", "w+");
            printf("NOUVEAU HIGHSCORE ! Entrez votre nom : ");
            fgets(nom, 100, stdin);
            while(nom[wait] != '\0')
                wait++;
            if(nom[wait - 1] == '\n')
                nom[wait - 1] = '\0';
            sprintf(score, "HIGHSCORE = %d [%s]", point, nom);
            fprintf(highScore, "%s", score);
            fclose(highScore);
		}
		else
		{
			wait = 0;
			difficulte = 0;
			fgets(score, 200, highScore);
			while(score[wait] < '0' || score[wait] > '9')
			{
                wait++;
			}
            while(score[wait] >= '0' && score[wait] <= '9')
            {
                nom[difficulte] = score[wait];
                wait++;
                difficulte++;
            }
            fclose(highScore);
            wait = atoi(nom);
            if(wait < point)
            {
            	print_grid(grid, 2, mode, point);
            	printf("Perdu ! POINTS = %d\n\n", point);
            	highScore = fopen("score_pong.txt", "w+");
                printf("NOUVEAU HIGHSCORE ! Entrez votre nom : ");
                fgets(nom, 100, stdin);
                while(nom[wait] != '\0')
                    wait++;
                if(nom[wait - 1] == '\n')
                    nom[wait - 1] = '\0';
                sprintf(score, "HIGHSCORE = %d [%s]", point, nom);
                fprintf(highScore, "%s", score);
                fclose(highScore);
            }
            else
            {
            	print_grid(grid, 2, mode, point);
				printf("Perdu ! POINTS = %d\n\n", point);
				printf("Entrez n'importe quelle lettre: ");
				c = getchar();
				while((c = getchar()) != '\n' && c != EOF)
    			{}
            }
            	
		}
	}
	
	return(0);
}

int ft_str_compare(char str[])
{
    int i = 0;
    char oui[] = "oui\0";
    char non[] = "non\0";

    while(str[i] != '\0' && (str[i] == oui[i] || str[i] == non[i]))
        i++;
    if(i > 3 || i < 3)
        return(2);
    else
    {
        i = 0;
        while(str[i] == oui[i] && str[i] != '\0')
            i++;
        if(str[i] == '\0')
            return (1);
        else
            return (0);
    }
    return(0);
}

int intro(void)
{
    char str[4];
    int i = 1;
    char c;

    str[3] = '\0';
    printf("=== TERMINAL PONG ===\n");
    terminal_pong();
    printf("\n(par Idriss Cornuau)\n");
    clear_screen(25);
    printf("Nouvelle partie ?\n");
    printf("oui / non\n");
    while(i)
    {
        fgets(str, sizeof str, stdin);
        while((c = getchar()) != '\n' && c != EOF)
        {}
        if(ft_str_compare(str) == 0)
        {
            i = 0;
            return(0);
        }
        else if(ft_str_compare(str) == 1)
        {
            i = 0;
            return(1);
        }
        else
            printf("Mauvaise saisie, recommencez.\n");
    }
    return (0);
}

int 	main(int argc, char **argv)
{
	srand(time(NULL));
    int i = 0;
    while(i == 0)
    {
        clear_screen(42);
        if (intro() == 0)
            return(0);
        else 
        {
            moteur_jeu();
        }
    }
    return (0);
}