#include "RockCollision.h"


void RockCollision::SetCollisonRect(Rect rect)
{
	targetRect = rect;
}

bool RockCollision::OnCollision(Rect& collisionRect)
{
	if (stageCollision->OnCollision(targetRect, collisionRect)) return true;

	if (playerCollision->AnyCollision(targetRect, collisionRect)) return true;


}