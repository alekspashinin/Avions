/*gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` PlanesGauche.c `pkg-config --libs-only-l MLV` -o jeu */

#include"Planes.h"



void helycop1gauche(planes* GR, players* P, int pos){
 
  const char* Path_Plane100 ="Game_pics/Helicop1002xRouge.png";
  MLV_Image* Plane100 = MLV_load_image( Path_Plane100 );
  MLV_Image* background;
  background  = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image(background,width,height);
  if( ! Plane100 ){
    fprintf(stderr, "It was impossible to load the file %s.\n",Path_Plane100);
    exit(1);
  }
  

  
  MLV_Animation* Plane1;
  int nb_frames = 2;
  int nb_layers = 1;
  int nb_channels = 1;
  int w = 98 ,h =29  ;
  MLV_Image* images[2];
  images[0] = MLV_copy_partial_image( Plane100,99,29,w,h );
  images[1] = MLV_copy_partial_image( Plane100,196,29,w,h );
 
  Plane1 = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
				);
  MLV_add_frame_in_animation(
			     images+0, NULL, 4, Plane1
			     );
  MLV_add_frame_in_animation(
			     images+1, NULL, 4, Plane1
			     );

  MLV_Animation_player* animation_hely1 = MLV_create_animation_player (Plane1);

  MLV_play_animation_player (animation_hely1);

  MLV_change_frame_rate ( 24 );
 
  int avance = -pos;
  int pas = 5;
  int position_y = 150;
  while((avance < width) && (killedhely1(GR,P)==0) && MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) != MLV_PRESSED){
    P->Player1.x_laser = -1000;
    P->Player2.x_laser = -1000;
    MLV_update_animation_player( animation_hely1 );
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_image( background, 0, 0 );
    /*fonction de mise a jours joueurs*/
    actu_players(P);
    
    avance += pas;
    MLV_play_animation_player( animation_hely1 );
                
   
    MLV_draw_image_from_animation_player( animation_hely1, 0, avance, position_y );
    MLV_actualise_window();
    GR->hely1.x=avance; /*revoi la position du plane*/
    MLV_delay_according_to_frame_rate();
		
  }
  
  GR->hely1.x = -2000;
  MLV_free_animation_player( animation_hely1 );
  MLV_free_animation( Plane1 );
  MLV_free_image( images[0] );
  MLV_free_image( images[1] );
  MLV_free_image( Plane100 );
  MLV_free_image( background );
      
}

void helycop2gauche(planes* GR, players* P, int pos){
  const char* Path_Plane200 ="Game_pics/Helicop200xRouge.png";
  MLV_Image* Plane200 = MLV_load_image( Path_Plane200 );
  MLV_Image* background;
  background  = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image(background,width,height);
  if( ! Plane200 ){
    fprintf(stderr, "It was impossible to load the file %s.\n",Path_Plane200);
    exit(1);
  }
  

  MLV_Animation* Plane2;
  int nb_frames = 2;
  int nb_layers = 1;
  int nb_channels = 1;
  int w = 168 ,h =107  ;
  MLV_Image* images[2];
  images[0] = MLV_copy_partial_image( Plane200,10,4,w,h );
  images[1] = MLV_copy_partial_image( Plane200,210,4,155,h );
 
  Plane2 = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
				);
  MLV_add_frame_in_animation(
			     images+0, NULL, 4, Plane2
			     );
  MLV_add_frame_in_animation(
			     images+1, NULL, 4, Plane2
			     );

  MLV_Animation_player* animation_hely2 = MLV_create_animation_player (Plane2);

  MLV_play_animation_player (animation_hely2);

  MLV_change_frame_rate ( 24 );
 
  int avance = -pos;
  int pas = 7;
  int position_y = 200;
  while((avance < width) && (killedhely2(GR,P)==0) && MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) != MLV_PRESSED){
    P->Player1.x_laser = -1000;
    P->Player2.x_laser = -1000;
    MLV_update_animation_player( animation_hely2 );
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_image( background, 0, 0 );
    /*fonction de mise a jours joueurs*/
    actu_players(P);
    avance += pas;
    MLV_play_animation_player( animation_hely2 );
    
    MLV_draw_image_from_animation_player( animation_hely2, 0, avance, position_y );
    MLV_actualise_window();
    GR->hely2.x=avance; /*revoi la position du plane*/
    MLV_delay_according_to_frame_rate();
  }
  
  GR->hely2.x = -2000;
  MLV_free_animation_player( animation_hely2 );
  MLV_free_animation( Plane2 );
  MLV_free_image( images[0] );
  MLV_free_image( images[1] );
  MLV_free_image( Plane200 );
  MLV_free_image( background );
 
}

void planegauche(planes* GR, players* P, int pos){  /*pos = -w = -GR->plane1.taille*/
  const char* Path_Plane300 ="Game_pics/Avion300xrempty.png";
  MLV_Image* Plane300 = MLV_load_image( Path_Plane300 );
  MLV_Image* background;
  background  = MLV_load_image( "Game_pics/background.png" );
  MLV_resize_image(background,width,height);
  if( ! Plane300 ){
    fprintf(stderr, "It was impossible to load the file %s.\n",Path_Plane300);
    exit(1);
  }

    
  MLV_Animation* Plane3;
  int nb_frames = 18;
  int nb_layers = 1;
  int nb_channels = 1;
  int w = 300 ,h =280  ;
  MLV_Image* images[18];
 images[0] = MLV_copy_partial_image( Plane300,0,0,w,h );
   MLV_resize_image(images[0],200,200);
  images[1] = MLV_copy_partial_image( Plane300,w,0,w,h );
   MLV_resize_image(images[1],200,200);
  images[2] = MLV_copy_partial_image( Plane300,2*w,0,w,h );
   MLV_resize_image(images[2],200,200);
  images[3] = MLV_copy_partial_image( Plane300,3*w,0,w,h );
   MLV_resize_image(images[3],200,200);
  images[4] = MLV_copy_partial_image( Plane300,4*w,0,w,h );
   MLV_resize_image(images[4],200,200);
  images[5] = MLV_copy_partial_image( Plane300,5*w,0,w,h );
   MLV_resize_image(images[5],200,200);
  images[6] = MLV_copy_partial_image( Plane300,6*w,0,w,h );
   MLV_resize_image(images[6],200,200);
  images[7] = MLV_copy_partial_image( Plane300,7*w,0,w,h );
   MLV_resize_image(images[7],200,200);
  images[8] = MLV_copy_partial_image( Plane300,8*w,0,w,h );
   MLV_resize_image(images[8],200,200);
  images[9] = MLV_copy_partial_image( Plane300,9*w,0,w,h );
   MLV_resize_image(images[9],200,200);
  images[10] = MLV_copy_partial_image( Plane300,10*w,0,w,h );
   MLV_resize_image(images[10],200,200);
  images[11] = MLV_copy_partial_image( Plane300,11*w,0,w,h );
   MLV_resize_image(images[11],200,200);
  images[12] = MLV_copy_partial_image( Plane300,12*w,0,w,h );
   MLV_resize_image(images[12],200,200);
  images[13] = MLV_copy_partial_image( Plane300,13*w,0,w,h );
   MLV_resize_image(images[13],200,200);
  images[14] = MLV_copy_partial_image( Plane300,14*w,0,w,h );
   MLV_resize_image(images[14],200,200);
  images[15] = MLV_copy_partial_image( Plane300,15*w,0,w,h );
   MLV_resize_image(images[15],200,200);
  images[16] = MLV_copy_partial_image( Plane300,16*w,0,w,h );
   MLV_resize_image(images[16],200,200);
  images[17] = MLV_copy_partial_image( Plane300,17*w,0,w,h );
   MLV_resize_image(images[17],200,200);

  Plane3 = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
				);
  MLV_add_frame_in_animation(
			     images+0, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+1, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+2, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+3, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+4, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+5, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+6, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+7, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+8, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+9, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+10, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+11, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+12, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+13, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+14, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+15, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+16, NULL, 4, Plane3
			     );
  MLV_add_frame_in_animation(
			     images+17, NULL, 4, Plane3
			     );

  
  MLV_Animation_player* animation_plane = MLV_create_animation_player (Plane3);

  MLV_play_animation_player (animation_plane);

  MLV_change_frame_rate ( 24 );
 
  int avance = -pos;
  int pas = 10;
  int position_y = 200-y_plane;
  while((avance < width) && (killedplane(GR,P)==0) && MLV_get_keyboard_state( MLV_KEYBOARD_ESCAPE) != MLV_PRESSED){
    P->Player1.x_laser = -1000;
    P->Player2.x_laser = -1000;
    MLV_update_animation_player( animation_plane );
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_image( background, 0, 0 );
  
    /*fonction de mise a jours joueurs*/
    actu_players(P);
    avance += pas;
    MLV_play_animation_player( animation_plane );
                
    
    MLV_draw_image_from_animation_player( animation_plane, 0, avance, position_y );
    MLV_actualise_window();
    GR->plane1.x=avance;/*revoi la position du plane*/
    MLV_actualise_window();
    /*fprintf(stdout,"%d\n",GR->plane1.x);*/
    MLV_delay_according_to_frame_rate();
   
	        
  }
 
  GR->plane1.x = -2000;
  MLV_free_animation_player( animation_plane );
  MLV_free_animation( Plane3 );
  MLV_free_image( images[0] );
  MLV_free_image( images[1] );
  MLV_free_image( images[2] );
  MLV_free_image( images[3] );
  MLV_free_image( images[4] );
  MLV_free_image( images[5] );
  MLV_free_image( images[6] );
  MLV_free_image( images[7] );
  MLV_free_image( images[8] );
  MLV_free_image( images[9] );
  MLV_free_image( images[10] );
  MLV_free_image( images[11] );
  MLV_free_image( images[12] );
  MLV_free_image( images[13] );
  MLV_free_image( images[14] );
  MLV_free_image( images[15] );
  MLV_free_image( images[16] );
  MLV_free_image( images[17] );

  MLV_free_image( Plane300 );
  MLV_free_image( background );
 
}


