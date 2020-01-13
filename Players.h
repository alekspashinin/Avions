#ifndef Players_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#define width 1229
#define height 768 

/*pour 1229x768 y_dif=312, pour 1440x900=180,pour 1680x1050=30,pour 1920x1080 = 0 */
#define y_dif 312

/*pour 1920x1080 = 0 sinon 100*/
#define y_plane 100

typedef struct{
  int score;
  int x_loc;
  char name[50];
  int x_laser;
  int taille;
}player;

typedef struct{
  player Player1;
  player Player2;
  int game_on;
}players;


void laser_P2(players *P, int i);
void laser_P1(players *P, int i);

void pos_player1(players *P);
void pos_player2(players *P);
void actu_players(players *P);

void print_scores(players *P);
void print_score(players *P);
void get_names(players *P);
void get_name(players *P);

#endif
