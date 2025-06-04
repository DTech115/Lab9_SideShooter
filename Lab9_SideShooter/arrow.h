//DT Nesimi

#include "player.h"
#include "ghost.h"

class Arrow
{
public:
	Arrow();
	~Arrow();
	void DrawArrow();
	void FireArrow(player& Player);
	void UpdateArrow(int WIDTH);
	void CollideArrow(ghost ghosts[], player& Player, int cSize);	//takes player too now
private:
	int x;
	int y;
	bool live;
	int speed;
	ALLEGRO_BITMAP* image;
};

