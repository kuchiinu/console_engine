#pragma once
#include <Windows.h>

//画面に表示する物体の情報を管理する自作構造体
typedef struct Object
{
	//位置(物体の中心ではなく、左上端の位置)
	int position_x;//位置(左右)
	int position_y;//位置(上下)

	/*
	position_xの数値が大きいほど右へ、
	position_yの数値が大きいほど下へ行く。
	多くのゲームでは物体の位置は左上端ではなく、物体の中心を指す。
	今回は特殊。
	*/

	//大きさ
	int width;
	int height;

	//画像
	CHAR_INFO* CH = NULL;
};

void Object_init(Object* input_Object, int input_width,
	int input_height, int input_x, int input_y);//オブジェクトの初期化
void Object_end(Object* input_Object);//オブジェクトの終了処理
void Object_SetPosition(Object* input_Object, int input_x, int input_y);//オブジェクトの移動
void Object_SetPosition(Object* input_Object, int input_x, int input_y);//オブジェクトの移動
void Object_SetColor(Object* input_Object, int font_color, int background_color);//オブジェクトの色の設定

void Object_draw(Object* input_Object);//オブジェクトの描画