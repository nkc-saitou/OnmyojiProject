#include "StageCollision.h"
#include "Collision.h"

#include "DxLib.h"

void StageCollision::CollisionRangeSet()
{
	for (int i = 0; i < collisionPos.size(); i++)
	{
		Rect tempRect;

		tempRect.top = collisionPos[i].y * graphSize;
		tempRect.left = collisionPos[i].x * graphSize;
		tempRect.bottom = tempRect.top + graphSize;
		tempRect.right = tempRect.left + graphSize;

		collisionRange.push_back(tempRect);
	}
}

bool StageCollision::OnCollision(Rect playerRect, Rect& collisionRect)
{
	for (int i = 0; i < collisionRange.size(); i++)
	{
		if (Collision::Instance()->CheckRectAndRect(playerRect, collisionRange[i]))
		{
			collisionRect = collisionRange[i];
			return true;
		}
	}

	return false;
}

void StageCollision::SetCollsionPosition(vector<position> pos)
{
	collisionPos = pos;
	CollisionRangeSet();
}