#include <graphics.h>

#include "map.hpp"

int main(){
    initgraph(600, 600);
	setbkcolor(WHITE);
    bool running = true;
    ExMessage msg;

	BeginBatchDraw();

	Map game_map(60, 60);
	game_map.generate();

    while (running)
    {
		DWORD start_time = GetTickCount();

        while (peekmessage(&msg))
        {
			if (msg.message == WM_LBUTTONDOWN){
				int x = msg.x;
				int y = msg.y;

				int index_x = x / 20;
				int index_y = y / 20;
			}
        }

		// 这里是游戏的主要逻辑和渲染代码

		

        cleardevice();
		game_map.display();


        FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;

        if (delta_time < 16) {
			Sleep(16 - delta_time);
        }
    }

    return 0;
}