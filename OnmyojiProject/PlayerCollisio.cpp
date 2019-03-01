#include "PlayerCollision.h"
#include "SettingProvider.h"

/////////////////////////////////////////////////////
//引数			:プレイヤーと当たったオブジェクトの範囲を受け取りたいRect
//戻り値		:プレイヤーが当たっていたらtrue
//動作			:プレイヤーと当たっているかどうかを調べる
/////////////////////////////////////////////////////
bool PlayerCollision::OnCollision(Rect& collisionRect)
{
	if (stageCollision->OnCollision(playerRect,collisionRect)) return true;
	else return false;
}

/////////////////////////////////////////////////////
//引数			:プレイヤーの当たり判定
//戻り値		:なし
//動作			:プレイヤーの当たり判定の範囲を設定する
/////////////////////////////////////////////////////
void PlayerCollision::SetPlayerRect(Rect targetRect)
{
	playerRect = targetRect;
}

/////////////////////////////////////////////////////
//引数			:選択したステージ番号
//戻り値		:なし
//動作			:壁の当たり判定を設定する
/////////////////////////////////////////////////////
void PlayerCollision::SetRockRect(int stageNum)
{
	stageCollision->SetCollsionPosition(StageInpoter::Instance()->GetCollisionData()[SettingProvider::Instance()->GetStageNumber()]);
}