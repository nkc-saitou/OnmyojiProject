#pragma once

class Rock
{
	const int graphSize = 64;

	double x = 0, y = 0;


	void Move();

	void Draw();

	void Collision();

public:
	// スタート時のポジションをセット
	void SetStartPos(double posX, double posY);

	void Update();
};