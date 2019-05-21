#pragma once

/*
///////////////////////////////////////////
CollisionObjType列挙隊

概要　：当たり判定を持つオブジェクトを列挙
///////////////////////////////////////////
*/
enum class CollisionObjType
{
	player,
	wall,
	rock,
	enemy_one,
	enemy_two,
	goal
};