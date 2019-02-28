#include "PlayerCollision.h"

bool PlayerCollision::OnCollision(Rect& collisionRect)
{
	if (stageCollision->OnCollision(playerRect,collisionRect)) return true;
	else return false;
}

void PlayerCollision::SetPlayerRect(Rect targetRect)
{
	playerRect = targetRect;
}

void PlayerCollision::SetRockRect(int stageNum)
{
	stageCollision->SetCollsionPosition(StageInpoter::Instance()->GetCollisionData()[stageNum]);
}