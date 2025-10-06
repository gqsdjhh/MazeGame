#include <graphics.h>
#include "game.hpp"
#include "selectmap.hpp"

int main() {
    MapSelector selector;

    int selectedIndex = selector.show();

    Game game(selectedIndex);
    game.Run();

    return 0;
}
