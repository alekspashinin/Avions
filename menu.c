#include "menu.h"

void nav();
void nav_return();
void menu_princ();
void blic_tests();

//void logo1();

//void logo2();



int returns(int i, int j){
  MLV_flush_event_queue();
  MLV_Event event2;
  event2=MLV_NONE;
  int x3, y3;
  do {
    event2 = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    nav_return(x3,y3);
  } while( event2 != MLV_MOUSE_BUTTON );
  if(x3>i && x3<i+165 && y3>j && y3<j+50){
    MLV_wait_seconds(0.5);
  menu_princ();
  }
  return 0;
}

void tableau(int i,char * t1){
    MLV_draw_adapted_text_box(430,355,"ENTER YOUR SAVE NAME:",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_filled_rectangle( 530, 465, 200,45 , MLV_COLOR_BLACK);
    MLV_draw_line(530, 465, 730, 465 , MLV_COLOR_BLUE);
    MLV_draw_line(530, 510, 730, 510 , MLV_COLOR_BLUE);
    MLV_draw_line(530, 465, 530, 510 , MLV_COLOR_BLUE);
    MLV_draw_line(730, 465, 730, 510 , MLV_COLOR_BLUE);
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
    blic_tests(2);
    return;
  }


void newgame(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image9;
  int i=550;
  int j=600;
  image9 = MLV_load_image( "Images/backg.jpg" );
  MLV_resize_image( image9, 1229, 768);
  MLV_draw_image( image9, 0, 0 );
  MLV_draw_adapted_text_box(535,375,"1 PLAYER", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(520,435,"2 PLAYERS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(i,j,"RETURN", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image9);
   blic_test(1);
  return ;
}

void gamemap(){

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *map;
  map=MLV_load_image("Images/gamemap.png");
  MLV_draw_image(map,0,0);
  MLV_free_image(map);
  blic_test(2);
  //returns(550, 600);
  return;
}

void loadgame(){
  
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image6;
  image6 = MLV_load_image( "Images/backg.jpg" );
  MLV_resize_image( image6, 1229, 768);
  MLV_draw_image( image6, 0, 0 );
  FILE* fichier = NULL;
  fichier = fopen("save.txt", "r");
  
  char a[50],b[50],d[50];
  int c,e;
  if (fichier ==NULL){
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
  blic_test(3);
  return ;
}

int read_scores(FILE* score, scores S){
  char a[50];
  int b;
  int i=0;
  while((fscanf(score,"%s %d",a,&b)==2)){
    strcpy(S[i].name,a);
    S[i].score=b;
    i++;
  }
  return i;
}

void arange_scores(scores S, int i){
  int j;
  char temp[50];
  int tempo;
  int k=0;
  while(k<i){
  for(j=i;j>0;j--) {
    if(S[j].score > S[j-1].score){
      strcpy(temp,S[j-1].name);
      tempo=S[j-1].score;
      strcpy(S[j-1].name, S[j].name);
      S[j-1].score= S[j].score;
      strcpy(S[j].name,temp);
      S[j].score=tempo;
   
    }
  }
  k++;
  }
  return;
}
      
void tableau_score(){
  FILE* score = NULL;
  score = fopen("score.txt", "r");
  scores S;
  int j=read_scores(score, S);
  arange_scores(S,j);
  int i=1;
  int val=0;
  while( i<5){
    MLV_draw_filled_rectangle( 440, 325+val, 340,43 , MLV_COLOR_BLACK);
    MLV_draw_line(440, 325+val, 780, 325+val , MLV_COLOR_BLUE);
    MLV_draw_line(440, 368+val, 780, 368+val , MLV_COLOR_BLUE);
    MLV_draw_line(440, 325+val, 440, 368+val , MLV_COLOR_BLUE);
    MLV_draw_line(780, 325+val, 780, 368+val , MLV_COLOR_BLUE);
    MLV_draw_text(450, 335+val, "%d", MLV_COLOR_YELLOW,i);
    MLV_draw_text(510, 335+val, "%s", MLV_COLOR_YELLOW,S[i-1].name);
    MLV_draw_text(710, 335+val, "%d", MLV_COLOR_YELLOW,S[i-1].score);
    val=val+56;
    i++;
    MLV_actualise_window();
  }
  fclose(score);
  return ;
}

void score(){
  MLV_clear_window(MLV_COLOR_BLACK);
 
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image5;
  image5 = MLV_load_image( "Images/backg.jpg" );
  MLV_resize_image( image5, 1229, 768);
  MLV_draw_image( image5, 0, 0 );
  tableau_score();
  MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image5);
  
  blic_test(4);
  //  returns(550, 600);
}

void ab_authors(){
   MLV_clear_window(MLV_COLOR_BLACK);
    MLV_Image *image4;
    image4 = MLV_load_image( "Images/backg.jpg" );
    MLV_resize_image( image4, 1229, 768);
    MLV_draw_image( image4, 0, 0 );
    MLV_Image *photo1;
    photo1 = MLV_load_image( "Images/photo1.png" );
    MLV_resize_image_with_proportions( photo1, 200, 300);
    MLV_draw_image( photo1, 50, 50 );
    MLV_Image *photo2;
    photo2 = MLV_load_image( "Images/photo2.png" );
    MLV_resize_image_with_proportions( photo2, 200, 300);
    MLV_draw_image( photo2, 950, 300 );
    MLV_draw_adapted_text_box(250,50,"NAME:   DIMITRIOS SOUPILAS\nDATE OF BIRTH:   14.12.1998\nNATIONALITY:   GREECE\nCOURS:   L2 INFO\nHOBBIES: SLEEPING", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(551,390,"NAME:   ALEKSEI PASHININ\nDATE OF BIRTH:   19.04.1987\nNATIONALITY:   RUSSIA\nCOURS:   L2 INFO\nHOBBIES: KALASHNIKOV", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(550,600,"RETURN", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
    MLV_wait_seconds(2);
    MLV_free_image(photo1);
    MLV_free_image(photo2);
    MLV_free_image(image4);
    blic_test(5);
}

void cont_game(){
  FILE* fichier = NULL;
  fichier = fopen("save.txt", "r");

  char a[50],b[50],d[50];
  int c,e;
  planes GR;
  players P;
  init_2P(&GR,&P);
  fscanf(fichier,"%s %s %d %s %d",a,b,&c,d,&e);
  strcpy(P.Player1.name,b);
  P.Player1.score=c;
  strcpy(P.Player2.name,d);
  P.Player2.score=e;
  game_load(&GR,&P,120);
  return;
}
  


void button(int z, int x1, int y1){
  MLV_Sound* sound;
  sound = MLV_load_sound( "Sounds/confirm.ogg" );
  if(x1>525 && x1<700 && y1>315 && y1<365 && z==0){
   
 
    MLV_play_sound( sound, 1.0 );
    newgame();
    return;
  }
  else if(x1>522 && x1<707 && y1>375 && y1<425 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    gamemap();
    return;
  }
  else if(x1>520 && x1<710 && y1>435 && y1<485 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    loadgame();
    return;
  }
  else if(x1>537 && x1<690 && y1>495 && y1<545 && z==0){
   

    MLV_play_sound( sound, 1.0 );
  }
  else if(x1>510 && x1<715 && y1>555 && y1<605 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    score();
    return;
  }
  else if(x1>493 && x1<732 && y1>615 && y1<665 && z==0){
   
    MLV_play_sound( sound, 1.0 );
    ab_authors();
    //blic_test(5);
    //returns(550, 600);
    return;
  }
  else if(x1>570 && x1<650 && y1>675 && y1<725  && z==0){
    MLV_free_window();
    exit(0);
    return;
  }
  else if(x1>535 && x1<710 && y1>375 && y1<425 && z==1){
    /*!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER!!!!!!!!!!!!!!!!!!!!!!!!!*/
    Player1_new(60);
    MLV_wait_seconds(0.5);
	

    return;
  }
  else if(x1>520 && x1<704 && y1>435 && y1<485 && z==1){
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 2 PLAYERS!!!!!!!!!!!!!!!!!!!*/
    Players2_new(120);
    MLV_wait_seconds(0.5);
       
    return ;
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50  && z==1){
    MLV_play_sound( sound, 1.0 );

  
    return;
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50 && z==2){
    MLV_play_sound( sound, 1.0 );
   
    
    return;
  }
  else if(x1>440 && x1<440+340  && y1>325 && y1<325+43 && z==3){
    MLV_play_sound( sound, 1.0 );
    cont_game();
    return;
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50 && z==3){
    MLV_play_sound( sound, 1.0 );
    
    
    return;
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50 && z==4){
    MLV_play_sound( sound, 1.0 );
    
   
    return;
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50 && z==5){
    MLV_play_sound( sound, 1.0 );
    
    
    return;
  }
  else{
    MLV_free_sound(sound);
    blic_test(z);
  }
}

void nav_return(int x1, int y1){
  if(x1>550 && x1<550+165 && y1>600 && y1<600+50){
    //   MLV_init_audio( );
    // MLV_Sound* sound;
    // sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else{
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
}

void nav(int x1, int y1, int i){
  if(x1>525 && x1<700 && y1>315 && y1<365 && i==0){
    //   MLV_init_audio( );
    // MLV_Sound* sound;
    // sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>522 && x1<707 && y1>375 && y1<425 && i==0){
    //   MLV_init_audio( );
    // MLV_Sound* sound;
    //sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>520 && x1<710 && y1>435 && y1<485 && i==0){
    //  MLV_init_audio( );
    //  MLV_Sound* sound;
    //  sound = MLV_load_sound( "toggle_switch.ogg" );
    // MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>537 && x1<690 && y1>495 && y1<545  && i==0){
    // MLV_init_audio( );
    //  MLV_Sound* sound;
    //  sound = MLV_load_sound( "toggle_switch.ogg" );
    //  MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>510 && x1<715 && y1>555 && y1<605  && i==0){
    // MLV_init_audio( );
    //MLV_Sound* sound;
    //sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  
  else if(x1>493 && x1<732 && y1>615 && y1<665  && i==0){
    //    MLV_init_audio( );
    //MLV_Sound* sound;
    //sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  
  else if(x1>570 && x1<650 && y1>675 && y1<725  && i==0){
    // MLV_init_audio( );
    //  MLV_Sound* sound;
    // sound = MLV_load_sound( "toggle_switch.ogg" );
    // MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if (i==0){
    MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(522,375,"GAME MAP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  if(x1>535 && x1<710 && y1>375 && y1<425 && i==1){
    //   MLV_init_audio( );
    // MLV_Sound* sound;
    // sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(535,375,"1 PLAYER", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"2 PLAYERS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(550,600,"RETURN", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>520 && x1<704 && y1>435 && y1<485 && i==1){
    // MLV_init_audio( );
    // MLV_Sound* sound;
    //sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(535,375,"1 PLAYER", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"2 PLAYERS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(550,600,"RETURN", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(x1>550 && x1<550+165 && y1>600 && y1<600+50 && i==1){
    //   MLV_init_audio( );
    // MLV_Sound* sound;
    // sound = MLV_load_sound( "toggle_switch.ogg" );
    //MLV_play_sound( sound, 1.0 );
    MLV_draw_adapted_text_box(535,375,"1 PLAYER", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"2 PLAYERS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if(i==1){
    MLV_draw_adapted_text_box(535,375,"1 PLAYER", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(520,435,"2 PLAYERS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if (x1>550 && x1<550+165 && y1>600 && y1<600+50 && i==2){
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if (i==2){
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if (x1>550 && x1<550+165 && y1>600 && y1<600+50 &&( i==3 || i==4 || i==5)){
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLUE,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
  else if (i==3 || i==4 || i==5){
    MLV_draw_adapted_text_box(550,600,"RETURN",10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_actualise_window();
  }
}

void blic_test(int i){
  MLV_flush_event_queue();
  MLV_Event event;
  int x3, y3;
  do {
    event = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    nav(x3,y3,i);
  } while( event != MLV_MOUSE_BUTTON );
  button(i,x3, y3);
  return;
}

void blic_tests(int i){
  MLV_flush_event_queue();
  MLV_Event event;
  int x3, y3;
  do {
    event = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    nav(x3,y3,i);
  } while( event != MLV_MOUSE_BUTTON );
  return;
} 

void menu_princ(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_actualise_window();
  MLV_wait_seconds(1);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "Images/backg.jpg" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_draw_adapted_text_box(525,315,"NEW GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(522,375,"SAVE GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(520,435,"LOAD GAME", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(537,495,"SETTINGS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(510,555,"HIGH SCORES", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(493,615,"ABOUT AUTORS", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(570,675,"EXIT", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  blic_test(0);
}

