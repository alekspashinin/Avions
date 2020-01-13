/*gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` Intro.c `pkg-config --libs-only-l MLV` -o intro*/

#include "game.h"

void intro(){
  int i=0,j=0,k=0;
  const char* Path_intro="Game_pics/giphy-main.jpg";
  MLV_Image* Intro= MLV_load_image(Path_intro);
 
  if( ! Intro ){
    fprintf(stderr, "It was impossible to load the file %s.\n",Path_intro);
    exit(1);
  }

  MLV_Animation* Introd;
  int nb_frames = 39;
  int nb_layers = 1;
  int nb_channels = 1;
  int w = 169 ,h =159 ;
  MLV_Image* images[39];

  images[0] = MLV_copy_partial_image(Intro,0,0,w,h);
  MLV_resize_image(images[0],300,300);

  images[1] = MLV_copy_partial_image(Intro,w,0,w,h);
  MLV_resize_image(images[1],300,300);

  images[2] = MLV_copy_partial_image(Intro,2*w,0,w,h);
  MLV_resize_image(images[2],300,300);

  images[3] = MLV_copy_partial_image(Intro,3*w,0,w,h);
  MLV_resize_image(images[3],300,300);

  images[4] = MLV_copy_partial_image(Intro,4*w,0,w,h);
  MLV_resize_image(images[4],300,300);

  images[5] = MLV_copy_partial_image(Intro,5*w,0,w,h);
  MLV_resize_image(images[5],300,300);

  images[6] = MLV_copy_partial_image(Intro,6*w,0,w,h);
  MLV_resize_image(images[6],300,300);

  images[7] = MLV_copy_partial_image(Intro,7*w,0,w,h);
  MLV_resize_image(images[7],300,300);

  images[8] = MLV_copy_partial_image(Intro,8*w,0,w,h);
  MLV_resize_image(images[8],300,300);

  images[9] = MLV_copy_partial_image(Intro,9*w,0,w,h);
  MLV_resize_image(images[9],300,300);

  images[10] = MLV_copy_partial_image(Intro,10*w,0,w,h);
  MLV_resize_image(images[10],300,300);

  images[11] = MLV_copy_partial_image(Intro,11*w,0,w,h);
  MLV_resize_image(images[11],300,300);

  images[12] = MLV_copy_partial_image(Intro,12*w,0,w,h);
  MLV_resize_image(images[12],300,300);

  images[13] = MLV_copy_partial_image(Intro,13*w,0,w,h);
  MLV_resize_image(images[13],300,300);

  images[14] = MLV_copy_partial_image(Intro,14*w,0,w,h);
  MLV_resize_image(images[14],300,300);

  images[15] = MLV_copy_partial_image(Intro,15*w,0,w,h);
  MLV_resize_image(images[15],300,300);

  images[16] = MLV_copy_partial_image(Intro,16*w,0,w,h);
  MLV_resize_image(images[16],300,300);

  images[17] = MLV_copy_partial_image(Intro,17*w,0,w,h);
  MLV_resize_image(images[17],300,300);

  images[18] = MLV_copy_partial_image(Intro,18*w,0,w,h);
  MLV_resize_image(images[18],300,300);

  images[19] = MLV_copy_partial_image(Intro,19*w,0,w,h);
  MLV_resize_image(images[19],300,300);

  images[20] = MLV_copy_partial_image(Intro,20*w,0,w,h);
  MLV_resize_image(images[20],300,300);

  images[21] = MLV_copy_partial_image(Intro,21*w,0,w,h);
  MLV_resize_image(images[21],300,300);

  images[22] = MLV_copy_partial_image(Intro,22*w,0,w,h);
  MLV_resize_image(images[22],300,300);

  images[23] = MLV_copy_partial_image(Intro,23*w,0,w,h);
  MLV_resize_image(images[23],300,300);

  images[24] = MLV_copy_partial_image(Intro,24*w,0,w,h);
  MLV_resize_image(images[24],300,300);

  images[25] = MLV_copy_partial_image(Intro,25*w,0,w,h);
  MLV_resize_image(images[25],300,300);

  images[26] = MLV_copy_partial_image(Intro,26*w,0,w,h);
  MLV_resize_image(images[26],300,300);

  images[27] = MLV_copy_partial_image(Intro,27*w,0,w,h);
  MLV_resize_image(images[27],300,300);

  images[28] = MLV_copy_partial_image(Intro,28*w,0,w,h);
  MLV_resize_image(images[28],300,300);

  images[29] = MLV_copy_partial_image(Intro,29*w,0,w,h);
  MLV_resize_image(images[29],300,300);

  images[30] = MLV_copy_partial_image(Intro,30*w,0,w,h);
  MLV_resize_image(images[30],300,300);

  images[31] = MLV_copy_partial_image(Intro,31*w,0,w,h);
  MLV_resize_image(images[31],300,300);

  images[32] = MLV_copy_partial_image(Intro,32*w,0,w,h);
  MLV_resize_image(images[32],300,300);

  images[33] = MLV_copy_partial_image(Intro,33*w,0,w,h);
  MLV_resize_image(images[33],300,300);

  images[34] = MLV_copy_partial_image(Intro,34*w,0,w,h);
  MLV_resize_image(images[34],300,300);

  images[35] = MLV_copy_partial_image(Intro,35*w,0,w,h);
  MLV_resize_image(images[35],300,300);

  images[36] = MLV_copy_partial_image(Intro,36*w,0,w,h);
  MLV_resize_image(images[36],300,300);

  images[37] = MLV_copy_partial_image(Intro,37*w,0,w,h);
  MLV_resize_image(images[37],300,300);

  images[38] = MLV_copy_partial_image(Intro,37*w,0,w,h);
  MLV_resize_image(images[38],300,300);
  

  Introd = MLV_create_animation(
				nb_frames,nb_layers,nb_channels
				);
  MLV_add_frame_in_animation(
			     images+0, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+1, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+2, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+3, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+4, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+5, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+6, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+7, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+8, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+9, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+10, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+11, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+12, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+13, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+14, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+15, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+16, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+17, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+18, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+19, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+20, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+21, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+22, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+23, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+24, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+25, NULL, 4, Introd
			     );
   MLV_add_frame_in_animation(
			     images+26, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+27, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+28, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+29, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+30, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+31, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+32, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+33, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+34, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+35, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+36, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+37, NULL, 4, Introd
			     );
  MLV_add_frame_in_animation(
			     images+38, NULL, 4, Introd
			     );
  
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Animation_player* animation_intro = MLV_create_animation_player(Introd);
  MLV_play_animation_player(animation_intro);
  MLV_change_frame_rate (15);
  
  j=MLV_get_time();
  k=9000;
 
  while(j+k>i){
  
  MLV_update_animation_player( animation_intro );
 
  
  MLV_draw_image_from_animation_player(animation_intro,0,(width-300)/2,(height-300)/2);
  MLV_actualise_window();
  MLV_delay_according_to_frame_rate();
  i=MLV_get_time();

  }
    
  
  MLV_free_animation_player( animation_intro );

  MLV_free_animation( Introd );

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
  MLV_free_image( images[18] );
  MLV_free_image( images[19] );
  MLV_free_image( images[20] );
  MLV_free_image( images[21] );
  MLV_free_image( images[22] );
  MLV_free_image( images[23] );
  MLV_free_image( images[24] );
  MLV_free_image( images[25] );
  MLV_free_image( images[26] );
  MLV_free_image( images[27] );
  MLV_free_image( images[28] );
  MLV_free_image( images[29] );
  MLV_free_image( images[30] );
  MLV_free_image( images[31] );
  MLV_free_image( images[32] );
  MLV_free_image( images[33] );
  MLV_free_image( images[34] );
  MLV_free_image( images[35] );
  MLV_free_image( images[36] );
  MLV_free_image( images[37] );
  MLV_free_image( images[38] );
  
  MLV_free_image( Intro );
}



  

  
  

  
  
