#include <graphics.h>
#include "game.hpp"


int main() {
    Game game(true);  // 或 Game game(true) 启动困难模式
    game.run();
    return 0;
}
