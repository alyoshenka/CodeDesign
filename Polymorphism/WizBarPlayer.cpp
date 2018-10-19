#include "WizBarPlayer.h"



bool WizBarPlayer::moveTo(const Vector2 & dest)
{
	// if wizard
	// not best implementation but it works
	if (speed == 0) {
		position = dest;
		return true;
	}

	// if very close
	if (dest.x - position.x >= -1 && dest.x - position.x <= 1 
		&& dest.y - position.y >= -1 && dest.y - position.y <= 1) {

		// do nothing
		return true;
	}
	// else
	// move to dest at speed
	Vector2 direction = { 1,1 };

	// set negative directions
	if (dest.x < position.x) {
		direction.x = -1;
	}
	if (dest.y > position.y) {
		direction.y = -1;
	}

	// move
	position.x += speed * direction.x;
	position.y -= speed * direction.y;

	return false;
}

WizBarPlayer::WizBarPlayer()
{
	mySprite = LoadTexture("assets/elf1.png");
}

WizBarPlayer::WizBarPlayer(const std::string & fileName)
{
	// unload existing texture
	UnloadTexture(mySprite);
	// load new texture
	mySprite = LoadTexture(fileName.c_str());
}


WizBarPlayer::~WizBarPlayer()
{
	UnloadTexture(mySprite);
}

void WizBarPlayer::draw()
{
	// offset for size
	DrawTexture(mySprite, position.x - 8, position.y - 16, WHITE);
}

void WizBarPlayer::update()
{
	// on mouse click
	if (IsMouseButtonPressed(0)) {
		// update destination
		destination = GetMousePosition();
	}

	moveTo(destination);
}

bool WizBarPlayer::attack(Rectangle enemy)
{
	return false;
}
