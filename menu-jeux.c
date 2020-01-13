#include "game.h"


void navj();
void menu_jeux();
void blic_testj();
void blic_testjs();


void tableauj(){
    MLV_draw_adapted_text_box(430,355,"ENTER YOUR SAVE NAME:",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_filled_rectangle( 530, 465, 200,45 , MLV_COLOR_BLACK);
    MLV_draw_line(530, 465, 730, 465 , MLV_COLOR_BLUE);
    MLV_draw_line(530, 510, 730, 510 , MLV_COLOR_BLUE);
    MLV_draw_line(530, 465, 530, 510 , MLV_COLOR_BLUE);
    MLV_draw_line(730, 465, 730, 510 , MLV_COLOR_BLUE);
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
     blic_testjs(1);
    return;
  }




int savegamej(players* P){

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image8;
  image8 = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image( image8, 1229, 768);
  MLV_draw_image( image8, 0, 0 );
  FILE* fichier = NULL;
  fichier = fopen("save.txt", "w");
  char *t1;
  char t2 [15];
  if(P->Player2.x_loc == -1500){
    MLV_draw_adapted_text_box(300,465,"SORRY YOU CAN'T SAVE A ONE PLAYER GAME",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
    MLV_wait_seconds(3);
    MLV_draw_image( image8, 0, 0 );
    
    return 0;
  }
  else
  tableauj();
  MLV_wait_input_box(530,465,200,45,MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK," ", &t1 );
  MLV_actualise_window();
  fprintf(fichier,"%s %s %d %s %d\n", t1,P->Player1.name,P->Player1.score,P->Player2.name,P->Player2.score);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image7;
  image7 = MLV_load_image( "Images/backg.jpg" );
  MLV_resize_image( image7, 1229, 768);
  MLV_draw_image( image7, 0, 0 );
  if (t2!=t1){
    MLV_draw_adapted_text_box(430,465,"YOUR GAME WAS SAVED",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  }
  else{
    MLV_draw_adapted_text_box(350,315,"ERROR - EMPTY SET",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  }
  MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  fclose(fichier);
  MLV_wait_seconds(0.5);
  MLV_free_image(image7);
  MLV_free_image(image8);
  blic_testj(P,1);
  return 0;
}

int loadgamej(players *P){
  MLV_clear_window(MLV_COLOR_BLACK);

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image6;
  image6 = MLV_load_image("Game_pics/background.png" );
  MLV_resize_image( image6, 1229, 768);
  MLV_draw_image( image6, 0, 0 );
  FILE* fichier = NULL;
  fichier = fopen("save.txt", "r");

  char a[50],b[50],d[50];
  int c,e;
  if(P->Player2.x_loc == -1500){
    MLV_draw_adapted_text_box(300,465,"SORRY YOU CAN'T LOAD A ONE PLAYER GAME",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
    MLV_wait_seconds(3);
    MLV_draw_image( image6, 0, 0 );
    
    return 0;
  }
  else  if (fichier ==NULL){
    char b [15]= "NO SAVES";
    MLV_draw_filled_rectangle( 440, 325, 340,43 , MLV_COLOR_BLACK);
    MLV_draw_line(440, 325, 780, 325 , MLV_COLOR_BLUE);
    MLV_draw_line(440, 368, 780, 368 , MLV_COLOR_BLUE);
    MLV_draw_line(440, 325, 440, 368 , MLV_COLOR_BLUE);
    MLV_draw_line(780, 325, 780, 368 , MLV_COLOR_BLUE);
    MLV_draw_text(510, 335, "%s", MLV_COLOR_YELLOW,b);
    //MLV_draw_text(710, 335+val, "%d", MLV_COLOR_YELLOW, b);
    MLV_actualise_window();
  }
  else{
    fscanf(fichier,"%s %s %d %s %d",a,b,&c,d,&e);
    MLV_draw_filled_rectangle( 440, 325, 340,43 , MLV_COLOR_BLACK);
    MLV_draw_line(440, 325, 780, 325 , MLV_COLOR_BLUE);
    MLV_draw_line(440, 368, 780, 368 , MLV_COLOR_BLUE);
    MLV_draw_line(440, 325, 440, 368 , MLV_COLOR_BLUE);
    MLV_draw_line(780, 325, 780, 368 , MLV_COLOR_BLUE);
    MLV_draw_text(510, 335, "%s", MLV_COLOR_YELLOW,a);
    MLV_actualise_window();
  }
  fclose(fichier);
  MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image6);
  blic_testj(P,2);
  return 0;
}

void contold_game(players *P){
   FILE* fichier = NULL;
  fichier = fopen("save.txt", "r");

  char a[50],b[50],d[50];
  int c,e;
  fscanf(fichier,"%s %s %d %s %d",a,b,&c,d,&e);
  strcpy(P->Player1.name,b);
  P->Player1.score=c;
  strcpy(P->Player2.name,d);
  P->Player2.score=e;
  return;
}
  
  
  

void buttonj(players *P,int z, int x1, int y1){
    MLV_Sound* sound;
    sound = MLV_load_sound( "Sounds/confirm.ogg" );
  if(x1>525 && x1<700 && y1>315 && y1<365 && z==0){
  
    MLV_play_sound( sound, 1.0 );
    return;
  }
  if(x1>522 && x1<707 && y1>375 && y1<425 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    savegamej(P);
  }
  if(x1>520 && x1<710 && y1>435 && y1<485 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    loadgamej(P);
  }
  if(x1>537 && x1<690 && y1>495 && y1<545 && z==0){
 
    MLV_play_sound( sound, 1.0 );
    P->game_on=0;
    return;
  }
  if (x1>440 && x1<440+340  && y1>325 && y1<325+43  && z==2){
    MLV_play_sound( sound,1.0);
    contold_game(P);
  }
  if (x1>550 && x1<550+165 && y1>600 && y1<600+50 &&( z==1 || z==2)){
    MLV_play_sound( sound,1.0);
    menu_jeux(P);
  }
   else{
     MLV_free_sound(sound);
     blic_testj(P,z);
   }
}


void navj(int x1, int y1, int i){
  if(x1>535 && x1<710 && y1>315 && y1<365 && i==0){
    MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>522 && x1<707 && y1>375 && y1<425 && i==0){
    MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>520 && x1<710 && y1>435 && y1<485 && i==0){
    MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>520 && x1<673 && y1>495 && y1<545  && i==0){
    MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if( i==0){
    MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
    else if (x1>550 && x1<550+165 && y1>600 && y1<600+50 &&( i==1 || i==2)){
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
    else if (i==1 || i==2){
      MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
      MLV_actualise_window();
    }
}

void blic_testj(players *P,int i){
  MLV_flush_event_queue();
  MLV_Event event;
  int x3, y3;
  do {
    event = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    navj(x3,y3,i);
  } while( event != MLV_MOUSE_BUTTON );
  buttonj(P, i, x3, y3);
}
void blic_testjs(int i){
  MLV_flush_event_queue();
  MLV_Event event;
  int x3, y3;
  do {
    event = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    navj(x3,y3,i);
  } while( event != MLV_MOUSE_BUTTON );
  return;
} 

void menu_jeux(players *P){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image( image3, width, height);
  MLV_draw_image( image3, 0, 0 );
  MLV_draw_adapted_text_box(535,315,"RESUME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(520,495,"MAIN MENU", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  blic_testj(P,0);
}



