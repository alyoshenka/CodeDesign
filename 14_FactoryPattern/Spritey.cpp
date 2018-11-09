#include "Spritey.h"



Spritey::Spritey()
{	
}

Spritey::Spritey(const Spritey & s)
{
	sprType = s.sprType;

	pos = s.pos;

	rot = s.rot;
	r1 = s.r1;
	r2 = s.r2;

	/*r1.x = s.r1.x;
	r1.y = s.r1.y;
	r1.width = s.r1.width;
	r1.height = s.r1.height;

	r2.x = s.r1.x;
	r2.y = s.r1.y;
	r2.width = s.r1.width;
	r2.height = s.r1.height;*/

	texture = s.texture;
}

Spritey::Spritey(const std::string & filename, const std::string _sprType, float scale)
{
	sprType = _sprType;
	texture = LoadTexture(filename.c_str());
	pos = GetMousePosition();
	rot = 0;
	r1 = { 0, 0, (float)texture.width, (float)texture.height };
	r2 = { 0, 0, r1.width * scale, r1.height * scale };
}


void Spritey::operator=(const Spritey & s)
{
	// Spritey * a = new Spritey();
	sprType = s.sprType;
	pos = s.pos;
	rot = s.rot;
	r1 = s.r1;
	r2 = s.r2;
	texture = s.texture;
}

Spritey::~Spritey()
{
	// UnloadTexture(texture);
}

Spritey * Spritey::Clone()
{
	/*Spritey * s = new Spritey();
	s->sprType = this->sprType;
	s->pos = this->pos;
	s->rot = this->rot;
	s->r1 = this->r1;
	s->r2 = this->r2;
	s->texture = this->texture;
	return s;*/
	return new Spritey(*this);
}

void Spritey::translate(Vector2 delta)
{
	r2.x += delta.x;
	r2.y += delta.y;
}

void Spritey::draw()
{
	// r1 = part of texture
	// r2 = location in window

	DrawTexturePro(texture, r1, r2, { 0,0 }, rot, WHITE);
	// DrawTextureV(texture, pos, WHITE);
}
