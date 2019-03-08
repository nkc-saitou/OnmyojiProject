#include "CollisionRectProvider.h"

CollisionRectProvider::CollisionRectProvider()
{
	topRect.top = 0;
	topRect.bottom = graphSize;
	topRect.left = 0;
	topRect.right = screenSizeX;

	bottomRect.top = screenSizeY - graphSize;
	bottomRect.bottom = screenSizeY;
	bottomRect.left = 0;
	bottomRect.right = screenSizeX;

	leftRect.top = 0;
	leftRect.bottom = screenSizeY;
	leftRect.left = 0;
	leftRect.right = graphSize;

	rightRect.top = 0;
	rightRect.bottom = screenSizeY;
	rightRect.left = screenSizeX - graphSize;
	rightRect.right = screenSizeX;
}

void CollisionRectProvider::RemoveRockRectVec(int index)
{
	rockRectVec.erase(rockRectVec.begin() + index);
}

void CollisionRectProvider::RemoveStageRectVec(int index)
{
	stageRectVec.erase(stageRectVec.begin() + index);
}

void CollisionRectProvider::RemoveGoalRectVec(int index)
{
	goalRectVec.erase(goalRectVec.begin() + index);
}