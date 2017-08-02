#include <termios.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <time.h>

#define HAUTEUR_ECRAN 30
#define LARGEUR_ECRAN 30
#define WAIT_TIME 200000
#define NBR_PIECE 7
#define NBR_VERSION 4
#define LARGEUR_PIECE 4
#define HAUTEUR_PIECE 4
#define PIECE_1 0
#define PIECE_2 1
#define PIECE_3 2
#define PIECE_4 3
#define PIECE_5 4
#define PIECE_6 5
#define PIECE_7 6
#define VERSION_1 0
#define VERSION_2 1
#define VERSION_3 2
#define VERSION_4 3

typedef struct element element;

struct element {
	int allPiece[NBR_PIECE][NBR_VERSION][LARGEUR_PIECE][HAUTEUR_PIECE];
	int nbrVersion[NBR_PIECE];
	int numPiece;
	int numVersion;
	int x;
	int y;
};

void	init__piece(element piece[0])
{
	//Piece 1 v1
	piece[0].allPiece[PIECE_1][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_1][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_1][VERSION_1][2][0] = 1;
	piece[0].allPiece[PIECE_1][VERSION_1][3][0] = 1;

	piece[0].allPiece[PIECE_1][VERSION_1][0][1] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][1][1] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][2][1] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_1][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_1][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_1][VERSION_1][3][3] = 0;

	//Piece 1 v2
	piece[0].allPiece[PIECE_1][VERSION_2][0][0] = 1;
	piece[0].allPiece[PIECE_1][VERSION_2][1][0] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_1][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_1][VERSION_2][1][1] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_1][VERSION_2][0][2] = 1;
	piece[0].allPiece[PIECE_1][VERSION_2][1][2] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_1][VERSION_2][0][3] = 1;
	piece[0].allPiece[PIECE_1][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_1][VERSION_2][3][3] = 0;

	//Piece 2 v1
	piece[0].allPiece[PIECE_2][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_2][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_2][VERSION_1][2][0] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_2][VERSION_1][0][1] = 1;
	piece[0].allPiece[PIECE_2][VERSION_1][1][1] = 1;
	piece[0].allPiece[PIECE_2][VERSION_1][2][1] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_2][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_2][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_2][VERSION_1][3][3] = 0;

	//Piece 3 v1
	piece[0].allPiece[PIECE_3][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_1][2][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_3][VERSION_1][0][1] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][1][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_1][2][1] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_3][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_3][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_1][3][3] = 0;

	//Piece 3 v2
	piece[0].allPiece[PIECE_3][VERSION_2][0][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_2][1][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_3][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_2][1][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_3][VERSION_2][0][2] = 1;
	piece[0].allPiece[PIECE_3][VERSION_2][1][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_3][VERSION_2][0][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_2][3][3] = 0;

	//Piece 3 v3
	piece[0].allPiece[PIECE_3][VERSION_3][0][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][1][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_3][2][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][3][0] = 0;

	piece[0].allPiece[PIECE_3][VERSION_3][0][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_3][1][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_3][2][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_3][3][1] = 0;

	piece[0].allPiece[PIECE_3][VERSION_3][0][2] = 1;
	piece[0].allPiece[PIECE_3][VERSION_3][1][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][2][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][3][2] = 0;

	piece[0].allPiece[PIECE_3][VERSION_3][0][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][1][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][2][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_3][3][3] = 0;

	//Piece 3 v4
	piece[0].allPiece[PIECE_3][VERSION_4][0][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][1][0] = 1;
	piece[0].allPiece[PIECE_3][VERSION_4][2][0] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][3][0] = 0;

	piece[0].allPiece[PIECE_3][VERSION_4][0][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_4][1][1] = 1;
	piece[0].allPiece[PIECE_3][VERSION_4][2][1] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][3][1] = 0;

	piece[0].allPiece[PIECE_3][VERSION_4][0][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][1][2] = 1;
	piece[0].allPiece[PIECE_3][VERSION_4][2][2] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][3][2] = 0;

	piece[0].allPiece[PIECE_3][VERSION_4][0][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][1][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][2][3] = 0;
	piece[0].allPiece[PIECE_3][VERSION_4][3][3] = 0;

	//Piece 4 v1
	piece[0].allPiece[PIECE_4][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_1][2][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_4][VERSION_1][0][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_1][1][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][2][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_4][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_4][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_1][3][3] = 0;

	//Piece 4 v2
	piece[0].allPiece[PIECE_4][VERSION_2][0][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_2][1][0] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_4][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_2][1][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_4][VERSION_2][0][2] = 1;
	piece[0].allPiece[PIECE_4][VERSION_2][1][2] = 1;
	piece[0].allPiece[PIECE_4][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_4][VERSION_2][0][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_2][3][3] = 0;

	//Piece 4 v3
	piece[0].allPiece[PIECE_4][VERSION_3][0][0] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][1][0] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][2][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_3][3][0] = 0;

	piece[0].allPiece[PIECE_4][VERSION_3][0][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_3][1][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_3][2][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_3][3][1] = 0;

	piece[0].allPiece[PIECE_4][VERSION_3][0][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][1][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][2][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][3][2] = 0;

	piece[0].allPiece[PIECE_4][VERSION_3][0][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][1][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][2][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_3][3][3] = 0;

	//Piece 4 v4
	piece[0].allPiece[PIECE_4][VERSION_4][0][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_4][1][0] = 1;
	piece[0].allPiece[PIECE_4][VERSION_4][2][0] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][3][0] = 0;

	piece[0].allPiece[PIECE_4][VERSION_4][0][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][1][1] = 1;
	piece[0].allPiece[PIECE_4][VERSION_4][2][1] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][3][1] = 0;

	piece[0].allPiece[PIECE_4][VERSION_4][0][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][1][2] = 1;
	piece[0].allPiece[PIECE_4][VERSION_4][2][2] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][3][2] = 0;

	piece[0].allPiece[PIECE_4][VERSION_4][0][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][1][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][2][3] = 0;
	piece[0].allPiece[PIECE_4][VERSION_4][3][3] = 0;

	//Piece 5 v1
	piece[0].allPiece[PIECE_5][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_1][2][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_5][VERSION_1][0][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][1][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][2][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_5][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_5][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_1][3][3] = 0;

	//Piece 5 v2
	piece[0].allPiece[PIECE_5][VERSION_2][0][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_2][1][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_5][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_2][1][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_5][VERSION_2][0][2] = 1;
	piece[0].allPiece[PIECE_5][VERSION_2][1][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_5][VERSION_2][0][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_2][3][3] = 0;

	//Piece 5 v3
	piece[0].allPiece[PIECE_5][VERSION_3][0][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_3][1][0] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][2][0] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][3][0] = 0;

	piece[0].allPiece[PIECE_5][VERSION_3][0][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_3][1][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_3][2][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_3][3][1] = 0;

	piece[0].allPiece[PIECE_5][VERSION_3][0][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][1][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][2][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][3][2] = 0;

	piece[0].allPiece[PIECE_5][VERSION_3][0][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][1][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][2][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_3][3][3] = 0;

	//Piece 5 v4
	piece[0].allPiece[PIECE_5][VERSION_4][0][0] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][1][0] = 1;
	piece[0].allPiece[PIECE_5][VERSION_4][2][0] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][3][0] = 0;

	piece[0].allPiece[PIECE_5][VERSION_4][0][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][1][1] = 1;
	piece[0].allPiece[PIECE_5][VERSION_4][2][1] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][3][1] = 0;

	piece[0].allPiece[PIECE_5][VERSION_4][0][2] = 1;
	piece[0].allPiece[PIECE_5][VERSION_4][1][2] = 1;
	piece[0].allPiece[PIECE_5][VERSION_4][2][2] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][3][2] = 0;

	piece[0].allPiece[PIECE_5][VERSION_4][0][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][1][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][2][3] = 0;
	piece[0].allPiece[PIECE_5][VERSION_4][3][3] = 0;

	//Piece 6 v1
	piece[0].allPiece[PIECE_6][VERSION_1][0][0] = 1;
	piece[0].allPiece[PIECE_6][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_6][VERSION_1][2][0] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_6][VERSION_1][0][1] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][1][1] = 1;
	piece[0].allPiece[PIECE_6][VERSION_1][2][1] = 1;
	piece[0].allPiece[PIECE_6][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_6][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_6][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_1][3][3] = 0;

	//Piece 6 v2
	piece[0].allPiece[PIECE_6][VERSION_2][0][0] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][1][0] = 1;
	piece[0].allPiece[PIECE_6][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_6][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_6][VERSION_2][1][1] = 1;
	piece[0].allPiece[PIECE_6][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_6][VERSION_2][0][2] = 1;
	piece[0].allPiece[PIECE_6][VERSION_2][1][2] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_6][VERSION_2][0][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_6][VERSION_2][3][3] = 0;

	//Piece 7 v1
	piece[0].allPiece[PIECE_7][VERSION_1][0][0] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][1][0] = 1;
	piece[0].allPiece[PIECE_7][VERSION_1][2][0] = 1;
	piece[0].allPiece[PIECE_7][VERSION_1][3][0] = 0;

	piece[0].allPiece[PIECE_7][VERSION_1][0][1] = 1;
	piece[0].allPiece[PIECE_7][VERSION_1][1][1] = 1;
	piece[0].allPiece[PIECE_7][VERSION_1][2][1] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][3][1] = 0;

	piece[0].allPiece[PIECE_7][VERSION_1][0][2] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][1][2] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][2][2] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][3][2] = 0;

	piece[0].allPiece[PIECE_7][VERSION_1][0][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][1][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][2][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_1][3][3] = 0;

	//Piece 7 v2
	piece[0].allPiece[PIECE_7][VERSION_2][0][0] = 1;
	piece[0].allPiece[PIECE_7][VERSION_2][1][0] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][2][0] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][3][0] = 0;

	piece[0].allPiece[PIECE_7][VERSION_2][0][1] = 1;
	piece[0].allPiece[PIECE_7][VERSION_2][1][1] = 1;
	piece[0].allPiece[PIECE_7][VERSION_2][2][1] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][3][1] = 0;

	piece[0].allPiece[PIECE_7][VERSION_2][0][2] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][1][2] = 1;
	piece[0].allPiece[PIECE_7][VERSION_2][2][2] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][3][2] = 0;

	piece[0].allPiece[PIECE_7][VERSION_2][0][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][1][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][2][3] = 0;
	piece[0].allPiece[PIECE_7][VERSION_2][3][3] = 0;

	//init nbr_version
	piece[0].nbrVersion[PIECE_1] = 2;
	piece[0].nbrVersion[PIECE_2] = 1;
	piece[0].nbrVersion[PIECE_3] = 4;
	piece[0].nbrVersion[PIECE_4] = 4;
	piece[0].nbrVersion[PIECE_5] = 4;
	piece[0].nbrVersion[PIECE_6] = 2;
	piece[0].nbrVersion[PIECE_7] = 2;

	piece[0].numVersion = 1;

	piece[0].x = LARGEUR_ECRAN / 2 - 5;
	piece[0].y = 1;
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

int 	can_move_piece(element piece[1], char c, int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{

	int Y = 0;
	int X = 0;

	if(c == 'q')
	{
		while(Y < HAUTEUR_PIECE)
		{
			while(X < LARGEUR_PIECE)
			{
				if(copie[0].allPiece[copie[0].numPiece - 1][copie[0].numVersion - 1][X][Y] == 1 && gridMem[copie[0].x + X - 1][copie[0].y + Y] != 2)
					return(0);
				else
					X++;
			}
			X = 0;
			Y++;
		}
		return(1);
	}
	if(c == 's')
	{
		Y = HAUTEUR_PIECE - 1;
		while(X < LARGEUR_PIECE)
		{
			while(Y >= 0)
			{
				if(copie[0].allPiece[copie[0].numPiece - 1][copie[0].numVersion - 1][X][Y] == 1 && gridMem[copie[0].x + X][copie[0].y + Y + 1] != 2)
					return(0);
				else
					Y--;
			}
			Y = HAUTEUR_PIECE - 1;
			X++;
		}
		return(1);
	}
	if(c == 'd')
	{
		X = LARGEUR_PIECE - 1;
		while(Y < HAUTEUR_PIECE)
		{
			while(X >= 0)
			{
				if(copie[0].allPiece[copie[0].numPiece - 1][copie[0].numVersion - 1][X][Y] == 1 && gridMem[copie[0].x + X + 1][copie[0].y + Y] != 2)
					return(0);
				else
					X--;
			}
			X = LARGEUR_PIECE - 1;
			Y++;
		}
		return(1);
	}
	return(0);
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
                printf(" ");
            else if (grid[x][y] == 3)
                printf("#");
            x++;
        }
        y++;
        x = 0;
        if (y < HAUTEUR_ECRAN)
            printf("\n");   
    }
}

int 	rotate_piece(element piece[0])
{
	int newVersion = piece[0].numVersion + 1;
	if(piece[0].nbrVersion[piece[0].numPiece - 1] < newVersion)
		piece[0].numVersion = 1;
	else
		piece[0].numVersion = newVersion;
}

int 	can_rotate_piece(element piece[1], int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int X = 0;
	int Y = 0;
	int newVersion = piece[0].numVersion + 1;
	if(piece[0].nbrVersion[piece[0].numPiece - 1] < newVersion)
		newVersion = 1;

	while(Y < HAUTEUR_PIECE)
	{
		while(X < HAUTEUR_PIECE)
		{
			if(piece[0].allPiece[piece[0].numPiece - 1][newVersion - 1][X][Y] == 1 && gridMem[piece[0].x + X][piece[0].y + Y] != 2)
				return(0);
			else
				X++;
		}
		X = 0;
		Y++;
	}
	return(1);
}

void	move_piece(element piece[1], char c, int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int X = 0;
	int Y = 0;
	int tamp = 0;

	if(c == 'q')
	{
		piece[0].x -= 1;
	}
	if(c == 's')
	{
		piece[0].y += 1;
	}
	if(c == 'd')
	{
		piece[0].x += 1;
	}
	while(Y < HAUTEUR_PIECE)
	{
		while(X < HAUTEUR_PIECE)
		{
			if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1)
				grid[piece[0].x + X][piece[0].y + Y] = 3;
			X++;
		}
		X = 0;
		Y++;
	}
}

void	piece_to_gridMem(int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN], element piece[0])
{
	int Y = 0;
	int X = 0;

	while(Y < HAUTEUR_PIECE)
	{
		while(X < HAUTEUR_PIECE)
		{
			if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1)
				gridMem[piece[0].x + X][piece[0].y + Y] = 3;
			X++;
		}
		X = 0;
		Y++;
	}
}

void	choose_piece(element piece[1])
{
	piece[0].numPiece = rand() % NBR_PIECE;
	piece[0].x = LARGEUR_ECRAN / 2;
	piece[0].y = 1;
}

int 	suppr_ligne(int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int X = 1;
	int Y = 1;
	int compteur = 0;
	int points = 0;
	while(Y < HAUTEUR_ECRAN - 1)
	{
		while(X < LARGEUR_ECRAN - 1)
		{
			if(gridMem[X][Y] == 3)
				compteur++;
			X++;
		}
		if(compteur == LARGEUR_ECRAN - 2)
		{
			X = 1;
			while(X < LARGEUR_ECRAN - 1)
			{
				if(Y == 1)
					gridMem[X][Y] = 2;
				else
					gridMem[X][Y] = gridMem[X][Y - 1];
				X++;
			}
			points += 100;
		}
		X = 1;
		Y++;
	}
	return(points);
}

void	merge_grids(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
	int X = 0;
	int Y = 0;

	while(Y < HAUTEUR_ECRAN - 1)
	{
		while(X < LARGEUR_ECRAN)
		{
			if(gridMem[X][Y] == 3)
				grid[X][Y] = gridMem[X][Y];
			X++;
		}
		X = 0;
		Y++;
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

void	piece_to_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], element piece[1])
{
	int X = 0;
	int Y = 0;

	while(Y < HAUTEUR_PIECE)
	{
		while(X < LARGEUR_PIECE)
		{
			if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion- 1][X][Y] == 1)
				grid[piece[0].x + X][piece[0].y + Y] = 3;
			X++;
		}
		X = 0;
		Y++;
	}
}

int 	moteur_jeu()
{
	char c = '\0';
	char move[20];
	int wait = -1;
	int points;
	int over = 0;
	int nbrPiece = 0;
	int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN];
	int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN];
	element piece[1];
	
	init__piece(piece);
	init_grid(gridMem);
	printf("avant le while, moteur\n");
	while(over == 0)
	{
		init_grid(grid);
		if(wait == WAIT_TIME)
		{
			printf("nbrPiece = %d\n", nbrPiece);
			printf("wait == WAIT_TIME\n");
			if(nbrPiece == 0)
			{
				printf("nbrPiece = 0\n");
				nbrPiece = 1;
				choose_piece(piece);
				printf("choose_piece good\n");
				if(can_move_piece(piece, 's', gridMem) == 0)
					over = 1;
				printf("can_move_piece != 0\n");
			}
			printf("mode raw activé\n");
			mode_raw(1);
			if(unix_text_kbhit() == 1)
				fgets(move, sizeof move, stdin);
			mode_raw(0);
			c = move[0];
			//while((c = getchar()) != '\n' && c != EOF){}
			printf("mode raw désactivé\n");
			if(can_move_piece(piece, c, gridMem) == 1 && c != '\0')
			{
				printf("can and will move piece\n");
				if(can_rotate_piece(piece, gridMem) == 1 && c == 'm')
					rotate_piece(piece);
				else
					move_piece(piece, c, grid);
				c = '\0';
			}
			printf("can't or don't want to move piece\n");
			if(can_move_piece(piece, 's', gridMem) == 1)
				move_piece(piece, 's', grid);
			else
			{
				printf("piece to grid\n");
				nbrPiece == 0;
				piece_to_gridMem(gridMem, piece);
				points += suppr_ligne(gridMem);
			}
			wait = 0;
		}

		if(wait == WAIT_TIME / 2 || wait == 0)
		{
			piece_to_grid(grid, piece);
			printf("wait == WAIT_TIME\n");
			merge_grids(grid, gridMem);
			printf("grids mergées\n");
			print_grid(grid);
			clear_screen(42 - HAUTEUR_ECRAN - 3);
			printf("print grid ok\n");
			printf("wait = 0\n");
		}
		wait++;
	}
}

int 	main(int argc, char **argv)
{
	int i = 1;
	srand(time(NULL));

	moteur_jeu();

	/*while(i)
	{
		clear_screen(42);
		if(intro() == 0)
			return(0);
		else
			moteur_jeu();
	}*/
	return(0);
}