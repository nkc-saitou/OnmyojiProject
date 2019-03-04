#include "ObjectCollision.h"
#include "Collision.h"

bool ObjectCollision::OnCollision(Rect myRect, Rect opponentRect)
{
	if (Collision::Instance()->CheckRectAndRect(myRect, opponentRect))
	{
		return true;
	}
	return false;
}