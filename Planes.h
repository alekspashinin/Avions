#ifndef Planes_h

#include "Players.h"

typedef struct{
  int x;
  int taille;
  int points;
}plane;

typedef struct{
  plane hely1;
  plane hely2;
  plane plane1;
}planes;

void explosion(int x_expl, int y_expl);

void helycop1gauche(planes* GR,players* P, int pos);
void helycop2gauche(planes* GR,players* P, int pos);
void planegauche(planes* GR,players* P, int pos);

void helycop1droite(planes* GR, players* P, int pos);
void helycop2droite(planes* GR, players* P, int pos);
void planedroite(planes* GR, players* P, int pos);
int killed(planes *GR,players *P);
int killedplane(planes *GR,players *P);
int killedhely1(planes *GR,players *P);
int killedhely2(planes *GR,players *P);

#endif
