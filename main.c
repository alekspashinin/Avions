#include"menu.h"

int main( int argc, char *argv[] ){
  MLV_init_audio( );
  MLV_Music* music = MLV_load_music( "Sounds/creationandbeyond.ogg" );
  MLV_play_music( music, 1.0, -1 );
  MLV_create_full_screen_window_with_default_font("Projet","Projet",x,y,"Fonts/neuropol.ttf" , 20);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image;
  image = MLV_load_image( "Images/Logo1.jpg" );
  MLV_resize_image_with_proportions( image, 800, 600);
  MLV_draw_image( image,402, 84 );
  MLV_actualise_window();
  MLV_free_image( image );
  MLV_wait_seconds(3);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image2;
  image2 = MLV_load_image( "Images/logo.png" );
  MLV_resize_image_with_proportions( image2, 800, 600);
  MLV_draw_image( image2, 212, 84 );
  MLV_actualise_window();
  MLV_free_image( image2 );
  MLV_wait_seconds(3);

  while(1){
  menu_princ();
  }
  
  MLV_free_window();
  exit(0);
}
