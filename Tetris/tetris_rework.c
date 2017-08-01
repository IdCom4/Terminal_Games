#include <termios.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <time.h>

#define HAUTEUR_ECRAN 20
#define LARGEUR_ECRAN 15
#define WAIT_TIME 100000
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

void    init_piece(element piece[1])
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

    piece[0].allPiece[PIECE_3][VERSION_3][0][2] = 0;
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
    piece[0].numPiece = (rand() % 7) + 1;

    piece[0].x = LARGEUR_ECRAN / 2 - LARGEUR_PIECE / 2;
    piece[0].y = 1;
}
/*typedef struct element element;

struct element {
	int x;
	int y;
	int type;
};*/

void    terminal_snake()
{
    /*
    printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
    printf("\#######/ /####/ /#####\  /##\_/##\ /#\ /###\   |#|   /###\   |#|     \n");
    printf("   |#|    |#|_   |#|__\#| |#|\#/|#| |#| |#|\#\  |#|  /#/_\#\  |#|     \n");
    printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \#\ |#| |#######| |#|     \n");
    printf("   |#|    |#|__  |#|\#\   |#|   |#| |#| |#|  \#\|#| |#|   |#| |#\___  \n");
    printf("   |#|    \####\ |#| \#\  |#|   |#| \#/ |#|   \###/ |#|   |#| \#####\ \n");
    
    printf("_________  _____ _________  _____    _   ____ \n");
    printf("\#######/ /####/ \#######/ /#####\  /#\ /####\\n");
    printf("   |#|    |#|_      |#|    |#|__\#| |#| \##\#/\n");
    printf("   |#|    |###|     |#|    |#####/  |#|  \##\ \n");
    printf("   |#|    |#|__     |#|    |#|\#\   |#| /#\##\\n");
    printf("   |#|    \####\    |#|    |#| \#\  \#/ \####/\n");*/

    printf("_________  _____  _____    __   __   _   ___     _     ___     __     \n");
    printf("\\#######/ /####/ /#####\\  /##\\_/##\\ /#\\ /###\\   |#|   /###\\   |#|     \n");
    printf("   |#|    |#|_   |#|__\\#| |#|\\#/|#| |#| |#|\\#\\  |#|  /#/_\\#\\  |#|     \n");
    printf("   |#|    |###|  |#####/  |#|   |#| |#| |#| \\#\\ |#| |#######| |#|     \n");
    printf("   |#|    |#|__  |#|\\#\\   |#|   |#| |#| |#|  \\#\\|#| |#|   |#| |#\\___  \n");
    printf("   |#|    \\####\\ |#| \\#\\  |#|   |#| \\#/ |#|   \\###/ |#|   |#| \\#####\\ \n");
    
    printf("_________  _____ _________  _____    _   ____ \n");
    printf("\\#######/ /####/ \\#######/ /#####\\  /#\\ /####\\ \n");
    printf("   |#|    |#|_      |#|    |#|__\\#| |#| \\##\\#/\n");
    printf("   |#|    |###|     |#|    |#####/  |#|  \\##\\ \n");
    printf("   |#|    |#|__     |#|    |#|\\#\\   |#| /#\\##\\ \n");
    printf("   |#|    \\####\\    |#|    |#| \\#\\  \\#/ \\####/\n");

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

int     suppr_ligne(int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int yBis;
    int xBis;
    int points = 0;
    int combo = 1;
    int Y = 1;
    int X = 1;
    int compteur = 0;
    while(Y < HAUTEUR_ECRAN - 1)
    {
        while(X < LARGEUR_ECRAN - 1)
        {
            if(gridMem[X][Y] == 3)
                compteur++;
            if(compteur == LARGEUR_ECRAN - 2)
            {
                points += 100 * combo;
                combo++;
                yBis = Y;
                xBis = 1;
                while(yBis > 0)
                {
                    while(xBis < LARGEUR_ECRAN - 1)
                    {
                        if(yBis == 1)
                            gridMem[xBis][yBis] = 2;
                        else
                            gridMem[xBis][yBis] = gridMem[xBis][yBis - 1];
                        xBis++;
                    }
                    xBis = 1;
                    yBis--;
                }
            }
            X++;
        }
        compteur = 0;
        X = 1;
        Y++;
    }
    return(points);
}

int     can_move_piece(element piece[1], char c, int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{

    int Y = 0;
    int X = 0;

    if(c == 'q')
    {
        while(Y < HAUTEUR_PIECE)
        {
            while(X < LARGEUR_PIECE)
            {
                if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1 && gridMem[piece[0].x + X - 1][piece[0].y + Y] != 2)
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
                if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1 && gridMem[piece[0].x + X][piece[0].y + Y + 1] != 2)
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
                if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1 && gridMem[piece[0].x + X + 1][piece[0].y + Y] != 2)
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

void	move_piece(element piece[1], char *c)
{
	/*if(*c == 'z' && piece[0].y > 1)
		piece[0].y -= 1;*/
	if(*c == 's')
		piece[0].y += 1;
	else if(*c == 'q')
		piece[0].x -= 1;
	else if(*c == 'd')
		piece[0].x += 1;
    *c = ' ';
}

void	piece_to_grid(element piece[1], int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int X = 0;
    int Y = 0;
    while(Y < HAUTEUR_PIECE)
    {
        while(X < LARGEUR_PIECE)
        {
            if(piece[0].allPiece[piece[0].numPiece - 1][piece[0].numVersion - 1][X][Y] == 1)
                grid[piece[0].x + X][piece[0].y + Y] = 3;
            X++;
        }
        X = 0;
        Y++;
    }


	//grid[piece[0].x][piece[0].y] = piece[0].type;
}

void    print_grid(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int x = 0;
    int y = 0;
    printf("\n=== TERMINAL TETRIS ===\n\n");
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
                printf("O");
            else if (grid[x][y] == 5)
                printf("@");
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

/*void    init_piece(element piece[1])
{
    piece[0].type = (rand() % 3) + 3;
    piece[0].x = LARGEUR_ECRAN / 2;
    piece[0].y = 1;
}*/

void    merge_grids(int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN], int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int X = 0;
    int Y = 0;

    while(Y < HAUTEUR_ECRAN - 1)
    {
        while(X < LARGEUR_ECRAN - 1)
        {
            grid[X][Y] = gridMem[X][Y];
            X++;
        }
        X = 0;
        Y++;
    }
}

int     can_rotate_piece(element piece[1], int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN])
{
    int X = 0;
    int Y = 0;
    int newVersion = piece[0].numVersion + 1;
    if(newVersion > piece[0].nbrVersion[piece[0].numPiece - 1] )
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

int     rotate_piece(element piece[1], char *c)
{
    int newVersion = piece[0].numVersion + 1;
    if(newVersion > piece[0].nbrVersion[piece[0].numPiece - 1])
        piece[0].numVersion = 1;
    else
        piece[0].numVersion = newVersion;
    *c = ' ';
}

int 	moteur_jeu()
{
	char c = '\0';
	int grid[LARGEUR_ECRAN][HAUTEUR_ECRAN];
    int gridMem[LARGEUR_ECRAN][HAUTEUR_ECRAN];
	int wait = 0;
	int over = 0;
    int moveAuto = 0;
    int points = 0;
	element piece[1];
	/*piece[0].type = 3;
	piece[0].x = LARGEUR_ECRAN / 2;
	piece[0].y = 1;*/
    init_piece(piece);

	while(c == '\0')
	{
		init_grid(grid);
		print_grid(grid);
		clear_screen(42 - HAUTEUR_ECRAN - 5);
		printf("Utilisez la touche 'z' pour vous déplacer vers le haut et la touche 's' pour vous déplacer vers le bas.\n");
		printf("Utilisez la touche 'q' pour vous déplacer vers la gauche et la touche 'd' pour vous déplacer vers la droite.\n");
		printf("\nAu moment ou vous lancerez la partie la première pièce se lancera également, préparez vous.\n");
		printf("Entrez n'importe quelle touche pour lancer la partie: \n");
		c = getchar();
	}
	while((c = getchar()) != '\n' && c != EOF)
    {}
    
    init_grid(gridMem);
	while(over == 0)
	{
        //printf("wait == %d\n", wait);
        mode_raw(1);
		if(unix_text_kbhit() == 1)
			c = getchar();
        mode_raw(0);
        //printf("après mode_raw\n");
		if(wait == WAIT_TIME)
		{
            if(c == 'm' && can_rotate_piece(piece, gridMem) == 1)
                rotate_piece(piece, &c);
            if(can_move_piece(piece, c, gridMem) == 1)
                move_piece(piece, &c);

            if(moveAuto == 4)
            {
                if(can_move_piece(piece, 's', gridMem) == 1)
                {
                        c = 's';
                        move_piece(piece, &c);
                }
                else
                {
                    piece_to_grid(piece, gridMem);
                    points += suppr_ligne(gridMem);
                    init_piece(piece);
                }
                moveAuto = 0;
            }
            printf("can_move_piece = %d\n", can_move_piece(piece, 's', gridMem));
            moveAuto++;
            wait = 0;
		}
		if(wait == 0 || wait == WAIT_TIME / 2)
		{
            //printf("dans le wait == 0\n");
			init_grid(grid);
            //printf("init_grid good\n");
            merge_grids(grid, gridMem);
            //printf("merge_grids good\n");
			piece_to_grid(piece, grid);
            //printf("piece to grid good\n");
			print_grid(grid);
            //printf("print_grid good\n");
            printf("\nPOINTS = %d\n", points);
			clear_screen(42 - HAUTEUR_ECRAN - 3);
            //printf("hors du wait == 0\n");
		}
		wait++;
	}
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
    printf("=== TERMINAL TETRIS ===\n");
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