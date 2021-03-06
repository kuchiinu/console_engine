#pragma once
#include <Windows.h>

//コンソールと画面表示に関わる情報をまとめた自作構造体
typedef struct DrawManager
{
	HANDLE handle;//コンソールウィンドウの情報を持つ変数

	CONSOLE_FONT_INFOEX font_config;//フォント関係の情報を持つ変数

	CHAR_INFO* screen_buffer;//画面に表示する文字列

	CONSOLE_CURSOR_INFO cursor_Info;//カーソル関係の情報を持つ変数

	int screen_width = 20;//コンソールウィンドウの横幅
	int screen_height = 20;//コンソールウィンドウの縦幅
	int font_width = 18;//フォントの横幅
	int font_height = 18;//フォントの縦幅;
};

/*
CHAR_INFOは文字色と背景色の情報を追加出来る特殊なchar型変数
*/

void DrawManager_init(void);//コンソールと描画機能の初期化
void DrawManager_end(void);//コンソールと描画機能の終了処理
void DrawManager_clear(void);//バッファのリセット
void DrawManager_present(void);//バッファを画面へ表示

DrawManager* GetActiveDrawManager(void);//コンソールと描画機能を取得