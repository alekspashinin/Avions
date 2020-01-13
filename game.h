#ifndef game_h

#include "Planes.h"
#include<time.h>


int randomise();

void intro();
int game_on(clock_t time_beg, int duration_sec);
void init_2P(planes *GR, players *P);
void init_1P(planes *GR, players *P);
void save_scores(players *P);
void save_score(players *P);
void Players2_new(int duration);
void Player1_new(int duration);
void game_load(planes* GR, players *P, int duration);

void contold_game(players *P);
void navj(int x1,int y1, int i);
void menu_jeux(players *P);
void blic_testj(players *P, int i);
void blic_testjs(int i);
void tableauj();
int savegamej(players *P);
int loadgamej(players *P);
void buttonj(players *P, int z, int x1, int y1);






#endif
