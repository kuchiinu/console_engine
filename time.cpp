#pragma comment(lib, "winmm.lib")

#include "time.h"
#include "DrawManager.h"
#include "object.h"

time_info time;

//時間関係の情報を初期化
void time_init(void)
{
	//周波数(命令を処理する速さ)を教えてもらう
	QueryPerformanceFrequency(&time.frequence_time);

	//計測開始時刻をセット
	QueryPerformanceCounter(&time.start_time);

	//FPS表示の準備
	DrawManager* pDrawManager = GetActiveDrawManager();//コンソール情報を取得

	//NumberDisplay_init(&time.fps_display, 0, 0, 0);
}

//fpsを安定させる処理
void time_update(void)
{
	//現在時刻を計測
	QueryPerformanceCounter(&time.end_time);

	//(現在時刻 - 前に計測した時刻) / 周波数 = 経過時間(秒単位)
	time.frameTime = static_cast<float>(time.end_time.QuadPart - time.start_time.QuadPart)
		/ static_cast<float>(time.frequence_time.QuadPart);

	//ループ処理の一周が必要以上に早く終わってしまった場合
	if (time.frameTime < time.MIN_FREAM_TIME)
	{
		//経過時間をミリ秒単位に変換
		DWORD sleepTime = static_cast<DWORD>((time.MIN_FREAM_TIME - time.frameTime) * 1000);

		timeBeginPeriod(1);
		Sleep(sleepTime);   //早く済んだ分待機する(待機時間はミリ秒単位で指定する)
		timeEndPeriod(1);

		//現在の時間を取得
		QueryPerformanceCounter(&time.end_time);

		//FPS
		//(今の時間 - 前フレームの時間) / 周波数 = 経過時間(秒単位)
		time.frameTime = static_cast<float>(time.end_time.QuadPart - time.start_time.QuadPart) 
			/ static_cast<float>(time.frequence_time.QuadPart);
	}

	//FPS
	time.fps = (time.fps * 0.99f) + (0.01f / time.frameTime);

	// 入れ替え
	time.start_time = time.end_time;
}

//fpsの表示(デバッグ用)
void time_draw(void)
{
	NumberDisplay_SetNumber(&time.fps_display, (int)time.fps);
	DrawManager* pDrawManager = GetActiveDrawManager();
	NumberDisplay_SetPosition(&time.fps_display,
		pDrawManager->screen_width - 1 - (time.fps_display.diget - 1), pDrawManager->screen_height - 1);
	NumberDisplay_draw(&time.fps_display);
}