#include "PlayerCollision.h"

bool PlayerCollision::OnCollision()
{
	if (stageCollision->OnCollision(playerRect)) return true;
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