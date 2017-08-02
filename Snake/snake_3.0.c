#include <termios.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <time.h>

#define HAUTEUR_ECRAN 18
#define LARGEUR_ECRAN 40
#define FREQUENCE_FLY 15
typedef struct element element;

struct element
{
    int x;
    int y;
    char dir;
    int nbr;
};

void    terminal_snake()
{
    /*
    printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
    printf("\#######/ /####/ /#####\  /##\_/##\ /#\ /###\   |#|   /###\   |#|     \n");
    printf("   |#|    |#|_   |#|__\#| |#|\#/|#| |#| |#|\#\  |#|  /#/_\#\  |#|     \n");
    printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \#\ |#| |#######| |#|     \n");
    printf("   |#|    |#|__  |#|\#\   |#|   |#| |#| |#|  \#\|#| |#|   |#| |#\___  \n");
    printf("   |#|    \####\ |#| \#\  |#|   |#| \#/ |#|   \###/ |#|   |#| \#####\ \n");
    
    printf("  ____   ___     _     ___     _   __   _____\n");
    printf(" /####\ /###\   |#|   /###\   |#| /##| /####/\n");
    printf(" \##\#/ |#|\#\  |#|  /#/_\#\  |#|/#/   |#|_  \n");
    printf("  \##\  |#| \#\ |#| |#######| |###|    |###| \n");
    printf(" /#\##\ |#|  \#\|#| |#|   |#| |#|\#\__ |#|__ \n");
    printf(" \####/ |#|   \###/ |#|   |#| |#| \##/ \####\\n");*/

    printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
    printf("\\#######/ /####/ /#####\\  /##\\_/##\\ /#\\ /###\\   |#|   /###\\   |#|     \n");
    printf("   |#|    |#|_   |#|__\\#| |#|\\#/|#| |#| |#|\\#\\  |#|  /#/_\\#\\  |#|     \n");
    printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \\#\\ |#| |#######| |#|     \n");
    printf("   |#|    |#|__  |#|\\#\\   |#|   |#| |#| |#|  \\#\\|#| |#|   |#| |#\\___  \n");
    printf("   |#|    \\####\\ |#| \\#\\  |#|   |#| \\#/ |#|   \\###/ |#|   |#| \\#####\\ \n");
    
    printf("  ____   ___     _     ___     _   __   _____\n");
    printf(" /####\\ /###\\   |#|   /###\\   |#| /##| /####/\n");
    printf(" \\##\\#/ |#|\\#\\  |#|  /#/_\\#\\  |#|/#/   |#|_  \n");
    printf("  \\##\\  |#| \\#\\ |#| |#######| |###|    |###| \n");
    printf(" /#\\##\\ |#|  \\#\\|#| |#|   |#| |#|\\#\\__ |#|__ \n");
    printf(" \\####/ |#|   \\###/ |#|   |#| |#| \\##/ \\####\\\n");
}

void    clear_screen(int nbr)
{
    int i = 0;

    while(i < nbr)
    {
        printf("\n");
        i++;
    }
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

int unix_text_kbhit(void) 
{ 
    struct timeval tv = { 0, 0 }; 
    fd_set readfds; 
  
    FD_ZERO(&readfds); 
    FD_SET(STDIN_FILENO, &readfds); 
  
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1; 
}

int     test_collide(element snake[HAUTEUR_ECRAN * LARGEUR_ECRAN], int nbrElement)
{
    int i = 1;
    while(i < nbrElement)
    {
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            return(1);
        }
        i++;
    }
    return (0);
}

int     move_snake(char move[2], element fly[1], element star[1], element snake[LARGEUR_ECRAN * HAUTEUR_ECRAN], int *nbrElement)
{
    int i = 0;
    element tampon[5];
    tampon[2].x = snake[*nbrElement - 1].x;
    tampon[2].y = snake[*nbrElement - 1].y;

    if(move[0] == 'z')
    {
        tampon[0].x = snake[0].x;
        tampon[0].y = snake[0].y;
        tampon[3].x = tampon[0].x;
        tampon[3].y = tampon[0].y;
        while(i < *nbrElement - 1)
        {
            tampon[1].x = snake[i + 1].x;
            tampon[1].y = snake[i + 1].y;
            snake[i + 1].x = tampon[3].x;
            snake[i + 1].y = tampon[3].y;

            tampon[3].x = tampon[1].x;
            tampon[3].y = tampon[1].y;

            i++;
        }
        snake[0].x = tampon[0].x;
        snake[0].y = tampon[0].y - 1;
    }
    else if(move[0] == 'q')
    {
        tampon[0].x = snake[0].x;
        tampon[0].y = snake[0].y;
        tampon[3].x = tampon[0].x;
        tampon[3].y = tampon[0].y;
        while(i < *nbrElement - 1)
        {
            tampon[1].x = snake[i + 1].x;
            tampon[1].y = snake[i + 1].y;
            snake[i + 1].x = tampon[3].x;
            snake[i + 1].y = tampon[3].y;

            tampon[3].x = tampon[1].x;
            tampon[3].y = tampon[1].y;

            i++;
        }
        snake[0].x = tampon[0].x - 2;
        snake[0].y = tampon[0].y;
    }
    else if(move[0] == 's')
    {
        tampon[0].x = snake[0].x;
        tampon[0].y = snake[0].y;
        tampon[3].x = tampon[0].x;
        tampon[3].y = tampon[0].y;
        while(i < *nbrElement - 1)
        {
            tampon[1].x = snake[i + 1].x;
            tampon[1].y = snake[i + 1].y;
            snake[i + 1].x = tampon[3].x;
            snake[i + 1].y = tampon[3].y;

            tampon[3].x = tampon[1].x;
            tampon[3].y = tampon[1].y;

            i++;
        }
        snake[0].x = tampon[0].x;
        snake[0].y = tampon[0].y + 1;
    }
    else if(move[0] == 'd')
    {
        tampon[0].x = snake[0].x;
        tampon[0].y = snake[0].y;
        tampon[3].x = tampon[0].x;
        tampon[3].y = tampon[0].y;
        while(i < *nbrElement - 1)
        {
            tampon[1].x = snake[i + 1].x;
            tampon[1].y = snake[i + 1].y;
            snake[i + 1].x = tampon[3].x;
            snake[i + 1].y = tampon[3].y;

            tampon[3].x = tampon[1].x;
            tampon[3].y = tampon[1].y;

            i++;
        }
        snake[0].x = tampon[0].x + 2;
        snake[0].y = tampon[0].y;
    }
    if(snake[0].x == star[0].x && snake[0].y == star[0].y)
    {
        snake[*nbrElement].x = tampon[2].x;
        snake[*nbrElement].y = tampon[2].y;
        *nbrElement += 1;
        return(1);
    }
    else if(snake[0].x == fly[0].x && snake[0].y == fly[0].y)
    {
        snake[*nbrElement].x = tampon[2].x;
        snake[*nbrElement].y = tampon[2].y;
        *nbrElement += 1;
        return(3);
    }
    else if(snake[0].x >= LARGEUR_ECRAN - 1 || snake[0].x <= 0 || snake[0].y >= HAUTEUR_ECRAN - 1 || snake[0].y <= 0 || test_collide(snake, *nbrElement) == 1)
        return(2);
    return(0);
}

void    star_to_grid(element star[1], int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], int swi)
{
    if(swi == 0)
        grid[star[0].x][star[0].y] = 4;
    else
        grid[star[0].x][star[0].y] = 6;
}   

void    init_star(element star[1], element snake[LARGEUR_ECRAN * HAUTEUR_ECRAN], int nbrElement)
{
    int i = 0;
    int ok = 0;
    while(ok == 0)
    {
        ok = 1;
        star[0].x = (rand() % (LARGEUR_ECRAN - 2)) + 1;
        star[0].y = (rand() % (HAUTEUR_ECRAN - 2)) + 1;
        if(star[0].x % 2 == 0 && star[0].x <= LARGEUR_ECRAN - 3)
        {
            star[0].x += 1;
        }
        else if(star[0].x % 2 == 0)
            star[0].x -= 1;
        while(i < nbrElement)
        {
            if(snake[i].x == star[0].x && snake[i].y == star[0].y)
                ok = 0;
            i++;
        }
        i = 0;
    }
}

void    snake_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element snake[LARGEUR_ECRAN * HAUTEUR_ECRAN], int nbrElement)
{
    int i = 0;
    while(i < nbrElement)
    {
        if(i == 0)
        {
            grid[snake[i].x][snake[i].y] = 3;
        }
        else
        {
            grid[snake[i].x][snake[i].y] = 2;
        }
        i++;
    }
}

void    print_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
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
                printf("o");
            else if (grid[x][y] == 3)
                printf("@");
            else if (grid[x][y] == 4)
                printf("*");
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

void    init_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
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

int moteur_jeu(void)
{
    FILE *highScore = NULL;
    char score[200];
    char nom[100];

    char move[2];
    char c = '\0';
    int wait = 0;
    int points = 0;
    int swi = 0;
    move[1] = '\0';
    int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN];
    int nbrElement = 1;
    int manger = 1;
    element fly[1];
    element star[1];
    element snake[LARGEUR_ECRAN * HAUTEUR_ECRAN];

    highScore = fopen("score_snake.txt", "r");

    snake[0].nbr = 0;
    if(LARGEUR_ECRAN % 2 == 0)
        snake[0].x = LARGEUR_ECRAN / 2 - 1;
    else
        snake[0].x = LARGEUR_ECRAN / 2;
    snake[0].y = HAUTEUR_ECRAN / 2;
    while(manger < nbrElement)
    {
        snake[manger].nbr = 1;
        manger++;
    }
    manger = 0;
    init_star(star, snake, nbrElement);
    init_star(fly, snake, nbrElement);
    move[0] = 'z';
    while(c == '\0')
    {
        printf("=== TERMINAL SNAKE ===\n\n");
        init_grid(grid);
        snake_to_grid(grid, snake, nbrElement);
        print_grid(grid);
        clear_screen(42 - HAUTEUR_ECRAN - 11);
        printf("Utilisez la touche 'z' pour vous déplacer vers le haut, la touche 's' pour le bas,\n");
        printf("la touche 'd' pour la droite, la touche 'q' pour la gauche.\n\n");
        printf("@ = tête de Snake\no = corps de Snake\n* = But fixe valant 10 points\n# = But volant valant 50 points\n");
        printf("\nAu moment ou vous lancerez la partie Snake se lancera également, préparez vous.\n\n");
        printf("Entrez n'importe quelle touche pour lancer la partie: ");
        c = getchar();
    }
    while((c = getchar()) != '\n' && c != EOF)
    {}
    while(manger != 2)
    {
        if(wait % 100000 / 2 == 0)
        {
            printf("\n=== TERMINAL SNAKE ===\n");
            if(highScore == NULL)
                printf("HIGHSCORE = 0\n");
            else
            {
                fgets(score, 200, highScore);
                printf("%s\n", score);
            }
            init_grid(grid);
            snake_to_grid(grid, snake, nbrElement);
            if(manger == 1)
            {
                manger = 0;
                points += 10;
                init_star(star, snake, nbrElement);
            }
            if(manger == 3)
            {
                manger = 0;
                points += 50;
                swi = 0;
                init_star(fly, snake, nbrElement);
            }
            if(swi == FREQUENCE_FLY)
            {
                swi = 0;
                init_star(fly, snake, nbrElement);
            }
            star_to_grid(star, grid, 0);
            star_to_grid(fly, grid, 1);
            print_grid(grid);
            printf("\nPOINTS = %d\n", points);
            printf("Entrez une direction (z, q, s, d) : ");
            clear_screen(42 - HAUTEUR_ECRAN - 3);
        }
        mode_raw(1);
        if(unix_text_kbhit() == 1)
        {
            fgets(move, sizeof move, stdin);
        }
        mode_raw(0);
        //while((c = getchar()) != '\n' && c != EOF){}
        if(wait > 100000)
        {
            wait = 0;
            manger = move_snake(move, fly, star, snake, &nbrElement);
            swi += 1;
        }
        if (manger == 2)
        {
            printf("\n=== TERMINAL SNAKE ===\n");
            if(highScore == NULL)
            {
                wait = 2000000000;
                printf("HIGHSCORE = 0\n");
            }
            else
            {
                wait = 0;
                fgets(score, 200, highScore);
                printf("%s\n", score);
            }
            print_grid(grid);
            printf("\nPerdu !\nPOINTS = %d\n", points);
            if(wait == 0)
            {
                swi = 0;
                while(score[wait] < '0' || score[wait] > '9')
                    wait++;
                while(score[wait] >= '0' && score[wait] <= '9')
                {
                       nom[swi] = score[wait];
                       swi++;
                       wait++;
                }
                wait = atoi(nom);
                fclose(highScore);
            }
            if(wait < points || wait == 2000000000)
            {
                wait = 0;
                clear_screen(42 - HAUTEUR_ECRAN - 4);
                highScore = fopen("score_snake.txt", "w+");
                printf("NOUVEAU HIGHSCORE ! Entrez votre nom : ");
                fgets(nom, 100, stdin);
                while(nom[wait] != '\0')
                    wait++;
                if(nom[wait - 1] == '\n')
                    nom[wait - 1] = '\0';
                sprintf(score, "HIGHSCORE = %d [%s]", points, nom);
                fprintf(highScore, "%s", score);
                fclose(highScore);
            }
            else
            {
                clear_screen(42 - HAUTEUR_ECRAN - 4);
                printf("Entrez n'importe quelle lettre: ");
                fgets(move, sizeof move, stdin);
                while((c = getchar()) != '\n' && c != EOF){}
            }
        }
        /*while(wait < 99999999)
        {
            wait++;
        }
        wait = 0;*/
        wait++;
    }
    return (0);
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
    printf("=== TERMINAL SNAKE ===\n");
    terminal_snake();
    printf("\n\n(par Idriss Cornuau)\n\n");
    printf("Nouvelle partie ?\n");
    clear_screen(42 - 19);
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

int     main(int argc, char **argv)
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