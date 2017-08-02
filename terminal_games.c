//#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

void	print_games()
{
	/*
	printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
	printf("\#######/ /####/ /#####\  /##\_/##\ /#\ /###\   |#|   /###\   |#|     \n");
	printf("   |#|    |#|_   |#|__\#| |#|\#/|#| |#| |#|\#\  |#|  /#/_\#\  |#|     \n");
	printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \#\ |#| |#######| |#|     \n");
	printf("   |#|    |#|__  |#|\#\   |#|   |#| |#| |#|  \#\|#| |#|   |#| |#\___  \n");
	printf("   |#|    \####\ |#| \#\  |#|   |#| \#/ |#|   \###/ |#|   |#| \#####\ \n");
	
	printf(" _______    ___     __   __   _____  ____\n");
	printf("/######/   /###\   /##\_/##\ /####/ /####\\n");
	printf("|#|  __   /#/_\#\  |#|\#/|#| |#|_   \##\#/\n");
	printf("|#| |##\ |#######| |#|   |#| |###|   \##\ \n");
	printf("|#\__|#| |#|   |#| |#|   |#| |#|__  /#\##\\n");
	printf("\######/ |#|   |#| |#|   |#| \####\ \####/\n");*/

	printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
    printf("\\#######/ /####/ /#####\\  /##\\_/##\\ /#\\ /###\\   |#|   /###\\   |#|     \n");
    printf("   |#|    |#|_   |#|__\\#| |#|\\#/|#| |#| |#|\\#\\  |#|  /#/_\\#\\  |#|     \n");
    printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \\#\\ |#| |#######| |#|     \n");
    printf("   |#|    |#|__  |#|\\#\\   |#|   |#| |#| |#|  \\#\\|#| |#|   |#| |#\\___  \n");
    printf("   |#|    \\####\\ |#| \\#\\  |#|   |#| \\#/ |#|   \\###/ |#|   |#| \\#####\\ \n");
	
	printf(" _______    ___     __   __   _____  ____\n");
	printf("/######/   /###\\   /##\\_/##\\ /####/ /####\\ \n");
	printf("|#|  __   /#/_\\#\\  |#|\\#/|#| |#|_   \\##\\#/\n");
	printf("|#| |##\\ |#######| |#|   |#| |###|   \\##\\ \n");
	printf("|#\\__|#| |#|   |#| |#|   |#| |#|__  /#\\##\\ \n");
	printf("\\######/ |#|   |#| |#|   |#| \\####\\ \\####/\n");
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

int 	main(int argc, char **argv)
{
	int ok = 4;
	int out = 0;
	char c;

	while(out != 1)
	{
		printf("=== TERMINAL GAMES ===\n");
		print_games();
		printf("\n(par Idriss Cornuau)\n");
		printf("\nChoisissez un jeu :\n\n");
		printf("1 = Terminal_Snake\n");
		printf("2 = Terminal_Pong\n");
		printf("3 = Terminal_Tetris\n");
		printf("\n4 = quitter\n");
		clear_screen(42 - 23);
		c = getchar();
		if(c == '1')
			system("./Snake/Terminal_Snake");
		else if(c == '2')
			system("./Pong/Terminal_Pong");
		else if(c == '3')
			system("./Tetris/Terminal_Tetris");
		else if(c == '4')
			return(0);
		else
			printf("Mauvaise saisie, veuillez recommencer.\n");
		while((c = getchar()) != '\n' && c != EOF){}
	}
		
  	return(0);
}