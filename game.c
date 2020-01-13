
#include"game.h"

int randomise(){
  int i;
  srand(time(NULL));
  i = rand()%2;
  if(i==0){
    return 1;
  }
  else return 0;
}

int exit_game(int x){
  if(x==1){
    return 0;
      }
  else return 1;
}

int game_on(clock_t time_beg, int duration_sec){
  int seconds_past,miliseconds,time_left;
  clock_t cur_time;
  cur_time=clock();
  miliseconds = cur_time - time_beg;
  seconds_past = (miliseconds/(CLOCKS_PER_SEC));
  time_left=duration_sec-seconds_past;
  /*clock_t time_beg
  time_beg=clock();*/
  if(time_left<=0){
    return 0;
  }
  else return 1;

}

void init_2P(planes *GR, players *P){
  P->Player1.score = 0;
  P->Player2.score = 0;
  P->Player1.taille = 235;
  P->Player2.taille = 235;
  P->Player1.x_loc = width/2 ;
  P->Player2.x_loc = width/2-P->Player2.taille ;
  P->Player1.x_laser = -1000;
  P->Player2.x_laser = -1000;

  GR->hely1.x = -2000;
  GR->hely1.taille = 98;
  GR->hely1.points = 400;
  GR->hely2.x = -2000;
  GR->hely2.taille = 168;
  GR->hely2.points = 300;
  GR->plane1.x = -2000;
  GR->plane1.taille = 200;
  GR->plane1.points = 350;
  P->game_on=1;

}

void init_1P(planes *GR, players *P){
  P->Player1.score = 0;
  P->Player2.score = 0;
  P->Player1.taille = 235;
  P->Player1.x_loc =  (width/2)-(P->Player1.taille/2);
  P->Player2.x_loc = -1500  ;
  P->Player1.x_laser = -1000;
  P->Player2.x_laser = -1000;
  P->Player2.taille = 235;
  strcpy(P->Player2.name, "panda");
  GR->hely1.x = -2000;
  GR->hely1.taille = 98;
  GR->hely1.points = 400;
  GR->hely2.x = -2000;
  GR->hely2.taille = 168;
  GR->hely2.points = 300;
  GR->plane1.x = -2000;
  GR->plane1.taille = 200;
  GR->plane1.points = 350;
  P->game_on=1;
}
  

void Players2_new(int duration){

  int i,j;
  players P;
  planes GR;
  init_2P(&GR,&P);
  clock_t time_beg;
  time_beg=clock();
  get_names(&P);
  intro();
  
  while(game_on(time_beg,duration)==1 && P.game_on != 0){
    if(randomise()==0){
      planedroite(&GR,&P,300);
    }

    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED ){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    
    for(i=0;i<4;i++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
	menu_jeux(&P);
      }
      if(P.game_on==0){
	return;
      }
      if(randomise()==0){
	helycop2gauche(&GR,&P,169);
      }
      else helycop2droite(&GR,&P,169);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    if(randomise()==0){
      planegauche(&GR,&P,300);
    }
    
    for(j=0;j<2;j++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
        menu_jeux(&P);
      }
      if(P.game_on==0){
	return;
      }
      if(randomise()==0){
	helycop1droite(&GR,&P,100);
      }
      else helycop1gauche(&GR,&P,100);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    if(randomise()==0){
      planedroite(&GR,&P,300);
    }
    else planegauche(&GR,&P,300);
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
  }
  print_scores(&P);
  // save_scores(&P);
  return;
}

void Player1_new(int duration){
  int i,j;
  players P;
  planes GR;
  init_1P(&GR,&P);
  clock_t time_beg;
  time_beg=clock();
  get_name(&P);
  intro();
  
  
  while(game_on(time_beg,duration)==1 && P.game_on != 0){
    if(randomise()==0){
      planedroite(&GR,&P,300);
    }

    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED ){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    
    for(i=0;i<4;i++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
	menu_jeux(&P);
      }
      if(P.game_on==0){
	return;
      }
      if(randomise()==0){
	helycop2gauche(&GR,&P,169);
      }
      else helycop2droite(&GR,&P,169);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    if(randomise()==0){
      planegauche(&GR,&P,300);
    }
    
    for(j=0;j<2;j++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
        menu_jeux(&P);
      }
      if(P.game_on==0){
	return;
      }
      if(randomise()==0){
	helycop1droite(&GR,&P,100);
      }
      else helycop1gauche(&GR,&P,100);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
    if(randomise()==0){
      planedroite(&GR,&P,300);
    }
    else planegauche(&GR,&P,300);
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(&P);
    }
    if(P.game_on==0){
      return;
    }
  }
  print_score(&P);
  //save_score(&P);
  return;
}
	  
      
void game_load(planes* GR, players *P, int duration){

  int i,j;
  clock_t time_beg;
  time_beg=clock();
  intro();
  
  
  while(game_on(time_beg,duration)==1 && P->game_on != 0){
    if(randomise()==0){
      planedroite(GR,P,300);
    }

    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED ){
      menu_jeux(P);
    }
    if(P->game_on==0){
      return;
    }
    
    for(i=0;i<4;i++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
	menu_jeux(P);
      }
      if(P->game_on==0){
	return;
      }
      if(randomise()==0){
	helycop2gauche(GR,P,169);
      }
      else helycop2droite(GR,P,169);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(P);
    }
    if(P->game_on==0){
      return;
    }
    if(randomise()==0){
      planegauche(GR,P,300);
    }
    
    for(j=0;j<2;j++){
      if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
        menu_jeux(P);
      }
      if(P->game_on==0){
	return;
      }
      if(randomise()==0){
	helycop1droite(GR,P,100);
      }
      else helycop1gauche(GR,P,100);
    }
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(P);
    }
    if(P->game_on==0){
      return;
    }
    if(randomise()==0){
      planedroite(GR,P,300);
    }
    else planegauche(GR,P,300);
    if(MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) == MLV_PRESSED){
      menu_jeux(P);
    }
    if(P->game_on==0){
      return;
    }
  }
  print_score(P);
  //save_score(&P);
  return;
}
	  
