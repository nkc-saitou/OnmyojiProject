#pragma once
#include "Singleton.h"
#include "RectShape.h"
#include "SettingProvider.h"
#include <vector>

/*
///////////////////////////////////////////
CollisionRectProvider�N���X

�T�v�@�F�����蔻��͈̔͂�S�ċL�^���Ă���
///////////////////////////////////////////
*/
class CollisionRectProvider : public Singleton <CollisionRectProvider>
{

	Rect playerRect;
	std::vector<Rect> rockRectVec;
	std::vector<Rect> stageRectVec;
	std::vector<Rect> goalRectVec;

	const int screenSizeX = SettingProvider::Instance()->screenSizeX;
	const int screenSizeY = SettingProvider::Instance()->screenSizeY;

	const int graphSize = 64;

	Rect topRect;
	Rect bottomRect;
	Rect leftRect;
	Rect rightRect;


public:

	CollisionRectProvider();

	void SetPlayerRect(Rect rect) { playerRect = rect; }
	Rect GetPlayerRect() { return playerRect; }

	void SetRockRect(std::vector<Rect> rectVec) { rockRectVec = rectVec; }
	std::vector<Rect> GetRockRect() { return rockRectVec; }
	void RemoveRockRectVec(int index);

	void SetStageRect(std::vector<Rect> rectVec) { stageRectVec = rectVec; }
	std::vector<Rect> GetStageRect() { return stageRectVec; }
	void RemoveStageRectVec(int index);

	void SetGoalRect(std::vector<Rect> rectVec) { goalRectVec = rectVec; }
	std::vector<Rect> GetGoalRect() { return goalRectVec; }
	void RemoveGoalRectVec(int index);

	Rect GetTopEdgeStageRect() { return topRect; }
	Rect GetBottomEdgeStageRect() { return bottomRect; }
	Rect GetLeftEdgeStageRect() { return leftRect; }
	Rect GetRightEdgeStageRect() { return rightRect; }
};