/*gcc -Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` explosion.c `pkg-config --libs-only-l MLV` -o jeu */
#include "Planes.h"



void explosion(int x_expl, int y_expl){

  MLV_Sound* explosion = MLV_load_sound("Game_music/explosion_with_metal_debris.ogg" );
int i=0,j=0,k=0;

MLV_Image* e1=MLV_load_image("explosion/0.gif");
MLV_Image* e2=MLV_load_image("explosion/1.gif");
MLV_Image* e3=MLV_load_image("explosion/2.gif");
MLV_Image* e4=MLV_load_image("explosion/3.gif");
MLV_Image* e5=MLV_load_image("explosion/4.gif");
MLV_Image* e6=MLV_load_image("explosion/5.gif");
MLV_Image* e7=MLV_load_image("explosion/6.gif");
MLV_Image* e8=MLV_load_image("explosion/7.gif");
MLV_Image* e9=MLV_load_image("explosion/8.gif");
MLV_Image* e10=MLV_load_image("explosion/9.gif");
MLV_Image* e11=MLV_load_image("explosion/10.gif");
MLV_Image* e12=MLV_load_image("explosion/11.gif");
MLV_Image* e13=MLV_load_image("explosion/12.gif");
MLV_Image* e14=MLV_load_image("explosion/13.gif");
MLV_Image* e15=MLV_load_image("explosion/14.gif");
MLV_Image* e16=MLV_load_image("explosion/15.gif");
MLV_Image* e17=MLV_load_image("explosion/16.gif");
MLV_Image* e18=MLV_load_image("explosion/17.gif");
MLV_Image* e19=MLV_load_image("explosion/18.gif");
MLV_Image* e20=MLV_load_image("explosion/19.gif");
MLV_Image* e21=MLV_load_image("explosion/20.gif");
MLV_Image* e22=MLV_load_image("explosion/21.gif");
MLV_Image* e23=MLV_load_image("explosion/22.gif");
MLV_Image* e24=MLV_load_image("explosion/23.gif");
MLV_Image* e25=MLV_load_image("explosion/24.gif");
MLV_Image* e26=MLV_load_image("explosion/25.gif");
MLV_Image* e27=MLV_load_image("explosion/26.gif");
MLV_Image* e28=MLV_load_image("explosion/27.gif");
MLV_Image* e29=MLV_load_image("explosion/28.gif");
MLV_Image* e30=MLV_load_image("explosion/29.gif");
MLV_Image* e31=MLV_load_image("explosion/30.gif");
MLV_Image* e32=MLV_load_image("explosion/31.gif");
MLV_Image* e33=MLV_load_image("explosion/32.gif");
MLV_Image* e34=MLV_load_image("explosion/33.gif");
MLV_Image* e35=MLV_load_image("explosion/34.gif");
MLV_Image* e36=MLV_load_image("explosion/35.gif");
MLV_Image* e37=MLV_load_image("explosion/36.gif");
MLV_Image* e38=MLV_load_image("explosion/37.gif");
MLV_Image* e39=MLV_load_image("explosion/38.gif");
MLV_Image* e40=MLV_load_image("explosion/39.gif");
MLV_Image* e41=MLV_load_image("explosion/40.gif");
MLV_Image* e42=MLV_load_image("explosion/41.gif");
MLV_Image* e43=MLV_load_image("explosion/42.gif");
MLV_Image* e44=MLV_load_image("explosion/43.gif");
MLV_Image* e45=MLV_load_image("explosion/44.gif");
MLV_Image* e46=MLV_load_image("explosion/45.gif");
MLV_Image* e47=MLV_load_image("explosion/46.gif");
MLV_Image* e48=MLV_load_image("explosion/47.gif");
MLV_Image* e49=MLV_load_image("explosion/48.gif");
MLV_Image* e50=MLV_load_image("explosion/49.gif");
MLV_Image* e51=MLV_load_image("explosion/50.gif");
MLV_Image* e52=MLV_load_image("explosion/51.gif");
MLV_Image* e53=MLV_load_image("explosion/52.gif");
MLV_Image* e54=MLV_load_image("explosion/53.gif");
MLV_Image* e55=MLV_load_image("explosion/54.gif");
MLV_Image* e56=MLV_load_image("explosion/55.gif");
MLV_Image* e57=MLV_load_image("explosion/56.gif");
MLV_Image* e58=MLV_load_image("explosion/57.gif");
MLV_Image* e59=MLV_load_image("explosion/58.gif");
MLV_Image* e60=MLV_load_image("explosion/59.gif");
MLV_Image* e61=MLV_load_image("explosion/60.gif");
MLV_Image* e62=MLV_load_image("explosion/61.gif");
MLV_Image* e63=MLV_load_image("explosion/62.gif");
MLV_Image* e64=MLV_load_image("explosion/63.gif");
MLV_Image* e65=MLV_load_image("explosion/64.gif");
MLV_Image* e66=MLV_load_image("explosion/65.gif");
MLV_Image* e67=MLV_load_image("explosion/66.gif");
MLV_Image* e68=MLV_load_image("explosion/67.gif");
MLV_Image* e69=MLV_load_image("explosion/68.gif");
MLV_Image* e70=MLV_load_image("explosion/69.gif");
MLV_Image* e71=MLV_load_image("explosion/70.gif");
MLV_Image* e72=MLV_load_image("explosion/71.gif");
MLV_Image* e73=MLV_load_image("explosion/72.gif");
MLV_Image* e74=MLV_load_image("explosion/73.gif");
MLV_Image* e75=MLV_load_image("explosion/74.gif");
MLV_Image* e76=MLV_load_image("explosion/75.gif");
MLV_Image* e77=MLV_load_image("explosion/76.gif");
MLV_Image* e78=MLV_load_image("explosion/77.gif");
MLV_Image* e79=MLV_load_image("explosion/78.gif");
MLV_Image* e80=MLV_load_image("explosion/79.gif");
MLV_Image* e81=MLV_load_image("explosion/80.gif");
MLV_Image* e82=MLV_load_image("explosion/81.gif");
MLV_Image* e83=MLV_load_image("explosion/82.gif");
MLV_Image* e84=MLV_load_image("explosion/83.gif");
MLV_Image* e85=MLV_load_image("explosion/84.gif");
MLV_Image* e86=MLV_load_image("explosion/85.gif");
MLV_Image* e87=MLV_load_image("explosion/86.gif");
MLV_Image* e88=MLV_load_image("explosion/87.gif");
MLV_Image* e89=MLV_load_image("explosion/88.gif");
MLV_Image* e90=MLV_load_image("explosion/89.gif");
MLV_Image* e91=MLV_load_image("explosion/90.gif");
MLV_Image* e92=MLV_load_image("explosion/91.gif");
MLV_Image* e93=MLV_load_image("explosion/92.gif");
MLV_Image* e94=MLV_load_image("explosion/93.gif");
MLV_Image* e95=MLV_load_image("explosion/94.gif");

MLV_Animation* Explos;
int nb_frames = 95;
int nb_layers = 1;
int nb_channels = 1;
MLV_Image* images[95];

images[0]=e1;
images[1]=e2;
images[2]=e3;
images[3]=e4;
images[4]=e5;
images[5]=e6;
images[6]=e7;
images[7]=e8;
images[8]=e9;
images[9]=e10;
images[10]=e11;
images[11]=e12;
images[12]=e13;
images[13]=e14;
images[14]=e15;
images[15]=e16;
images[16]=e17;
images[17]=e18;
images[18]=e19;
images[19]=e20;
images[20]=e21;
images[21]=e22;
images[22]=e23;
images[23]=e24;
images[24]=e25;
images[25]=e26;
images[26]=e27;
images[27]=e28;
images[28]=e29;
images[29]=e30;
images[30]=e31;
images[31]=e32;
images[32]=e33;
images[33]=e34;
images[34]=e35;
images[35]=e36;
images[36]=e37;
images[37]=e38;
images[38]=e39;
images[39]=e40;
images[40]=e41;
images[41]=e42;
images[42]=e43;
images[43]=e44;
images[44]=e45;
images[45]=e46;
images[46]=e47;
images[47]=e48;
images[48]=e49;
images[49]=e50;
images[50]=e51;
images[51]=e52;
images[52]=e53;
images[53]=e54;
images[54]=e55;
images[55]=e56;
images[56]=e57;
images[57]=e58;
images[58]=e59;
images[59]=e60;
images[60]=e61;
images[61]=e62;
images[62]=e63;
images[63]=e64;
images[64]=e65;
images[65]=e66;
images[66]=e67;
images[67]=e68;
images[68]=e69;
images[69]=e70;
images[70]=e71;
images[71]=e72;
images[72]=e73;
images[73]=e74;
images[74]=e75;
images[75]=e76;
images[76]=e77;
images[77]=e78;
images[78]=e79;
images[79]=e80;
images[80]=e81;
images[81]=e82;
images[82]=e83;
images[83]=e84;
images[84]=e85;
images[85]=e86;
images[86]=e87;
images[87]=e88;
images[88]=e89;
images[89]=e90;
images[90]=e91;
images[91]=e92;
images[92]=e93;
images[93]=e94;
images[94]=e95;

MLV_play_sound(explosion,1.0);
Explos = MLV_create_animation(
nb_frames,nb_layers,nb_channels
  );
MLV_add_frame_in_animation(
images+0, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+1, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+2, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+3, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+4, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+5, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+6, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+7, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+8, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+9, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+10, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+11, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+12, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+13, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+14, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+15, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+16, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+17, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+18, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+19, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+20, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+21, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+22, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+23, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+24, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+25, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+26, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+27, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+28, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+29, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+30, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+31, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+32, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+33, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+34, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+35, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+36, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+37, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+38, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+39, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+40, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+41, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+42, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+43, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+44, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+45, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+46, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+47, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+48, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+49, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+50, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+51, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+52, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+53, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+54, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+55, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+56, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+57, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+58, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+59, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+60, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+61, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+62, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+63, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+64, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+65, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+66, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+67, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+68, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+69, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+70, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+71, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+72, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+73, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+74, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+75, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+76, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+77, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+78, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+79, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+80, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+81, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+82, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+83, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+84, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+85, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+86, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+87, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+88, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+89, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+90, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+91, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+92, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+93, NULL, 4, Explos
  );
MLV_add_frame_in_animation(
images+94, NULL, 4, Explos
  );
  
MLV_Animation_player* animation_explos = MLV_create_animation_player(Explos);
MLV_play_animation_player(animation_explos);
MLV_change_frame_rate (120);

 j=MLV_get_time();
  k=1000;
 
  while(j+k>i){
  
MLV_update_animation_player( animation_explos );
 
  
MLV_draw_image_from_animation_player(animation_explos,0,x_expl,y_expl);
MLV_actualise_window();
MLV_delay_according_to_frame_rate();

 i=MLV_get_time();

}
  
MLV_free_animation_player( animation_explos );
MLV_free_animation( Explos );

  MLV_free_image(  images[0] );
  MLV_free_image(  images[1] );
  MLV_free_image(  images[2] );
  MLV_free_image(  images[3] );
  MLV_free_image(  images[4] );
  MLV_free_image(  images[5] );
  MLV_free_image(  images[6] );
  MLV_free_image(  images[7] );
  MLV_free_image(  images[8] );
  MLV_free_image(  images[9] );
  MLV_free_image(  images[10] );
  MLV_free_image(  images[11] );
  MLV_free_image(  images[12] );
  MLV_free_image(  images[13] );
  MLV_free_image(  images[14] );
  MLV_free_image(  images[15] );
  MLV_free_image(  images[16] );
  MLV_free_image(  images[17] );
  MLV_free_image(  images[18] );
  MLV_free_image(  images[19] );
  MLV_free_image(  images[20] );
  MLV_free_image(  images[21] );
  MLV_free_image(  images[22] );
  MLV_free_image(  images[23] );
  MLV_free_image(  images[24] );
  MLV_free_image(  images[25] );
  MLV_free_image(  images[26] );
  MLV_free_image(  images[27] );
  MLV_free_image(  images[28] );
  MLV_free_image(  images[29] );
  MLV_free_image(  images[30] );
  MLV_free_image(  images[31] );
  MLV_free_image(  images[32] );
  MLV_free_image(  images[33] );
  MLV_free_image(  images[34] );
  MLV_free_image(  images[35] );
  MLV_free_image(  images[36] );
  MLV_free_image(  images[37] );
  MLV_free_image(  images[38] );
  MLV_free_image(  images[39] );
  MLV_free_image(  images[40] );
  MLV_free_image(  images[41] );
  MLV_free_image(  images[42] );
  MLV_free_image(  images[43] );
  MLV_free_image(  images[44] );
  MLV_free_image(  images[45] );
  MLV_free_image(  images[46] );
  MLV_free_image(  images[47] );
  MLV_free_image(  images[48] );
  MLV_free_image(  images[49] );
  MLV_free_image(  images[50] );
  MLV_free_image(  images[51] );
  MLV_free_image(  images[52] );
  MLV_free_image(  images[53] );
  MLV_free_image(  images[54] );
  MLV_free_image(  images[55] );
  MLV_free_image(  images[56] );
  MLV_free_image(  images[57] );
  MLV_free_image(  images[58] );
  MLV_free_image(  images[59] );
  MLV_free_image(  images[60] );
  MLV_free_image(  images[61] );
  MLV_free_image(  images[62] );
  MLV_free_image(  images[63] );
  MLV_free_image(  images[64] );
  MLV_free_image(  images[65] );
  MLV_free_image(  images[66] );
  MLV_free_image(  images[67] );
  MLV_free_image(  images[68] );
  MLV_free_image(  images[69] );
  MLV_free_image(  images[70] );
  MLV_free_image(  images[71] );
  MLV_free_image(  images[72] );
  MLV_free_image(  images[73] );
  MLV_free_image(  images[74] );
  MLV_free_image(  images[75] );
  MLV_free_image(  images[76] );
  MLV_free_image(  images[77] );
  MLV_free_image(  images[78] );
  MLV_free_image(  images[79] );
  MLV_free_image(  images[80] );
  MLV_free_image(  images[81] );
  MLV_free_image(  images[82] );
  MLV_free_image(  images[83] );
  MLV_free_image(  images[84] );
  MLV_free_image(  images[85] );
  MLV_free_image(  images[86] );
  MLV_free_image(  images[87] );
  MLV_free_image(  images[88] );
  MLV_free_image(  images[89] );
  MLV_free_image(  images[90] );
  MLV_free_image(  images[91] );
  MLV_free_image(  images[92] );
  MLV_free_image(  images[93] );
  MLV_free_image(  images[94] );

  MLV_free_sound( explosion );
 


}





