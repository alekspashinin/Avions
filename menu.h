#ifndef menu_h

#include "game.h"
#define x 1229
#define y 768
#define x2 200
#define y2 200
#define TAILLE_MAX 100

typedef struct{
  char name[50];
  int score;
}scorez;

typedef scorez scores[100]; 

void nav();
void nav_return();
void menu_princ();
void blic_test();

void cont_game();
int returns(int i, int j);
void tableau(int i,char * t1);
void gamemap();
void loadgame();

int read_scores(FILE* score, scores S);
void arange_scores(scores S, int i);
void tableau_score();

void score();
void ab_authors();
void button(int i,int x1, int y1);





#endif
