#pragma once

#include <graphics.h>

class Button
{
public:
    Button(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed);
    ~Button() = default;
    void ProcessEvent(const ExMessage& msg);
    void Draw();
    void SetGameStarted(int flag);

protected:
    virtual void OnClick() = 0;

private:
    enum class Status {
        Idle = 0,
        Hovered,
        Pushed
    };

    RECT region;
    IMAGE img_idle;
    IMAGE img_hovered;
    IMAGE img_pushed;
    Status status = Status::Idle;
    int is_game_started = 0;

    bool CheckCursorHit(int x, int y);
};

// 开始游戏按钮
class StartGameButton : public Button
{
public:
    StartGameButton(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed);
    ~StartGameButton() = default;

protected:
    void OnClick();
};

// 退出游戏按钮
class QuitGameButton : public Button
{
public:
    QuitGameButton(RECT rect, LPCSTR path_img_idle, LPCSTR path_img_hovered, LPCSTR path_img_pushed);
    ~QuitGameButton() = default;

protected:
    void OnClick();
};
