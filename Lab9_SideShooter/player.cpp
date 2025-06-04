//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(image1);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);

}
player::player(int HEIGHT)
{

	image = al_load_bitmap("Kirby0.png");
	image1 = al_load_bitmap("Kirby1.png");
	image2 = al_load_bitmap("Kirby2.png");
	image3 = al_load_bitmap("Kirby3.png");
	image4 = al_load_bitmap("Kirby4.png");

	x = 20;
	y = HEIGHT / 2;
	lives = 5;
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;
}

// depending on the lives, a different kirby image is drawn!
void player::DrawPlayer()
{
	if (lives >= 5) {
		al_draw_bitmap(image, x, y, 0);
	}
	else if (lives == 4) {
		al_draw_bitmap(image1, x, y, 0);
	}
	else if (lives == 3) {
		al_draw_bitmap(image2, x, y, 0);
	}
	else if (lives == 2) {
		al_draw_bitmap(image3, x, y, 0);
	}
	else if (lives <= 1) {
		al_draw_bitmap(image4, x, y, 0);
	}

	//	draws kirby at the top left to represent his lives! each one is drawn a little to the right of the last
	//	when lives go down, they are redrawn with one less.
	for (int i = 0; i < lives; i++) {
		al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 20 + (i * 40), 20, 32, 32, 0);
	}
}
void player::MoveUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y > HEIGHT-boundy)
		y = HEIGHT-boundy;
}
void player::MoveLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if (x > 300)
		x = 300;
}
