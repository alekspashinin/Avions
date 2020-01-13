/*gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` Players.c `pkg-config --libs-only-l MLV` -o PL */

#include"Players.h"


  
void laser_P1(players *P, int i){

MLV_Image *L1;
  L1 = MLV_load_image( "Game_pics/turret_attack_blue.png" );
  
  P->Player1.x_laser=P->Player1.x_loc+(P->Player1.taille/2);
  MLV_draw_image(L1, P->Player1.x_loc, 150-y_dif);
 
  MLV_actualise_window();
  



 }

void laser_P2(players *P, int i){
  MLV_Image *L2;
  L2 = MLV_load_image( "Game_pics/turret_attack_red.png" );

  P->Player2.x_laser=P->Player2.x_loc+(P->Player2.taille/2);
  MLV_draw_image(L2,P->Player2.x_loc, 150-y_dif);
  MLV_actualise_window();

  MLV_free_image(L2);
} 
  


void pos_player1(players *P){

  MLV_Image *pl1;

  //MLV_Sound* laser1;
  //laser1=MLV_load_sound("Game_music/Shot_01.ogg");
 
 
  pl1 = MLV_load_image( "Game_pics/turret.png" );

  int pas = 40;
  
  if((P->Player1.x_loc >= 0) && (P->Player1.x_loc + P->Player1.taille <= width)){
    if(MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED){
      if(P->Player1.x_loc - pas >= 0){
	P->Player1.x_loc -= pas;
      }
    }
    else if(MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED){
      if(P->Player1.x_loc + pas <= width - P->Player1.taille){
	P->Player1.x_loc += pas;
      }
    }
  }
  MLV_draw_image( pl1, P->Player1.x_loc, 700-y_dif );
  MLV_draw_text(P->Player1.x_loc+(P->Player1.taille/3),height-50,"%d",MLV_COLOR_RED,P->Player1.score);

  if(MLV_get_keyboard_state( MLV_KEYBOARD_SPACE) == MLV_PRESSED){
    //MLV_play_sound(laser1, 0.7);
 laser_P1(P,P->Player1.x_loc);
  }

  MLV_free_image(pl1);


}

void pos_player2(players *P){
  // MLV_Sound* laser1;
    //laser1=MLV_load_sound("Game_music/Shot_01.ogg");
  
  MLV_Image *pl2;
  pl2 = MLV_load_image( "Game_pics/turret.png" );
  
  int pas = 40;
  
  if((P->Player2.x_loc >= 0) && (P->Player2.x_loc + P->Player2.taille <= width)){
    if(MLV_get_keyboard_state( MLV_KEYBOARD_q ) == MLV_PRESSED){
      if(P->Player2.x_loc - pas >=0){
      P->Player2.x_loc -= pas;
      }
    }
    else if(MLV_get_keyboard_state( MLV_KEYBOARD_d) == MLV_PRESSED){
      if(P->Player2.x_loc + pas <= width - P->Player2.taille){
	P->Player2.x_loc += pas;
      }
    }
  }
   MLV_draw_image( pl2, P->Player2.x_loc, 700-y_dif );
   MLV_draw_text(P->Player2.x_loc+(P->Player2.taille/3),height-50,"%d",MLV_COLOR_RED,P->Player2.score);

   if(MLV_get_keyboard_state( MLV_KEYBOARD_z ) == MLV_PRESSED){
    laser_P2(P,P->Player2.x_loc);
    //MLV_play_sound(laser1, 0.7);
  }
  MLV_free_image(pl2);
}

void actu_players(players *P){
  pos_player1(P);
  pos_player2(P);
  
}

int exist(char *i, int j, char *a, int b){
  int c;
  int res;
  c=strcmp(i,a); 
  if (c==0 && b==j){ 
    res=0;
  }
  else{
    res=1;
  }
  return res;
}

void ajouter(char * i, int j){
  char a[50];
  int b;
  FILE* fichier = NULL;
  fichier = fopen("score.txt", "a+");
  while((fscanf(fichier,"%s %d",a, &b))!=EOF){
    if (exist( i, j, a, b)==1){
      fprintf(fichier,"\n%s %d", i,j);
    }
  }
  fclose(fichier);
}


void print_scores(players *P){
  MLV_Image* background;
  background  = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image(background,width,height);
  MLV_draw_image( background, 0, 0 );
  MLV_draw_adapted_text_box(525,315,"%s : %d", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER, P->Player1.name, P->Player1.score);
  MLV_draw_adapted_text_box(522,375,"%s : %d", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER, P->Player2.name, P->Player2.score);
  MLV_free_image(background);
  MLV_actualise_window();
  ajouter(P->Player1.name,P->Player1.score);
  ajouter(P->Player2.name,P->Player2.score);
  MLV_wait_seconds(5);
}

void print_score(players *P){
  MLV_Image* background;
  background  = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image(background,width,height);
  MLV_draw_image( background, 0, 0 );
  MLV_draw_adapted_text_box(525,315,"%s : %d", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER, P->Player1.name, P->Player1.score);
  MLV_free_image(background);
  MLV_actualise_window();
  MLV_wait_seconds(5);
  ajouter(P->Player1.name,P->Player1.score);
}
  

void get_names(players *P){

  char* a;
  char* b;

  MLV_clear_window(MLV_COLOR_BLACK);

  MLV_wait_input_box(width/3,height/2,500,45,MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,"Player 1 (right): ", &a );
 
  MLV_wait_input_box(width/3,height/2,500,45,MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,"Player 2 (left) : ", &b );

  strcpy(P->Player1.name,a);
  strcpy(P->Player2.name,b);
  
}

void get_name(players *P){

  char* a;

  MLV_clear_window(MLV_COLOR_BLACK);
  
  MLV_wait_input_box(width/3,height/2,500,45,MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,"Name : ", &a );

  strcpy(P->Player1.name,a);

}
  

  



  
