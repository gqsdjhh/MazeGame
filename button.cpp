#include <graphics.h>

#include "button.hpp"

Button::Button(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed) {
    region = rect;

    loadimage(&img_idle, path_img_idle);
    loadimage(&img_hovered, path_img_hovered);
    loadimage(&img_pushed, path_img_pushed);
}

void Button::ProcessEvent(const ExMessage& msg) {
    switch (msg.message)
    {
    case WM_MOUSEMOVE:
        if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
            status = Status::Hovered;
        else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
            status = Status::Idle;
        break;
    case WM_LBUTTONDOWN:
        if (CheckCursorHit(msg.x, msg.y))
            status = Status::Pushed;
        break;
    case WM_LBUTTONUP:
        if (status == Status::Pushed)
            OnClick();
        break;
    default:
        break;
    }
}

void Button::Draw() {
    switch (status)
    {
    case Status::Idle:
        putimage(region.left, region.top, &img_idle);
        break;
    case Status::Hovered:
        putimage(region.left, region.top, &img_hovered);
        break;
    case Status::Pushed:
        putimage(region.left, region.top, &img_pushed);
        break;
    }
}

void Button::SetGameStarted(int flag) {
    is_game_started = flag;
}

bool Button::CheckCursorHit(int x, int y)
{
    return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
}

StartGameButton::StartGameButton(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed)
    : Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {
}

void StartGameButton::OnClick() {
    SetGameStarted(true);
}

QuitGameButton::QuitGameButton(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed)
    : Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {
}

void QuitGameButton::OnClick(){
    SetGameStarted(false);
}
