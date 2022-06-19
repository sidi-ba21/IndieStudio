/*
** EPITECH PROJECT, 2022
** Draw
** File description:
** Draw
*/

#include "Draw.hpp"

void Raylib::Draw::initWindow()
{
    InitWindow(screenWidth, screenHeight, "Bomberman");
    if (!IsWindowReady())
        throw GraphicsError("Failed to create window");
    ToggleFullscreen();
    SetTargetFPS(60);
}

void Raylib::Draw::closeWindow()
{
    CloseWindow();
}

bool Raylib::Draw::game_loop()
{
    return !WindowShouldClose();
}

void Raylib::Draw::draw_map(std::size_t n)
{
    DrawTextureEx(_texture[n], (Vector2){screenWidth - _texture[n].width * 4.0f - 20, 20.0f}, 0.0, 4.0, WHITE);
    DrawRectangleLines(screenWidth - _texture[n].width * 4 - 20, 20, _texture[n].width * 4, _texture[n].height * 4, GREEN);
}

void Raylib::Draw::draw_background(std::size_t n)
{
    DrawTextureV(_texture[n], Vector2{0, 0}, WHITE);
}

void Raylib::Draw::draw_bomb(std::size_t n)
{
    DrawSphere(_vector3[n], 0.3, BLACK);
    DrawSphereWires(_vector3[n], 0.3, 10, 10, BROWN);
}

void Raylib::Draw::draw_box(std::size_t n, std::size_t x, std::size_t y, float z, std::size_t h)
{
    DrawCubeTexture(get_texture(n), Vector3{x - 16.0f, z, y - 8.f}, 1, h, 1, WHITE);
}

void Raylib::Draw::remove_box(float x, float y)
{
    DrawCube(Vector3{x, 0.1, y}, 1, 1, 1, RED);
}

void Raylib::Draw::draw_score(std::vector<int> &score, std::string hightscore, float time)
{
    DrawText("The map generated is : ", 1410, 20, 30, MAGENTA);
    DrawText(TextFormat("SCORE       : %u", score[0]), 15, 120, 30, MAGENTA);
    DrawText(TextFormat("SCORE       : %u", score[1]), 15, 220, 30, MAGENTA);
    DrawText(TextFormat("SCORE       : %u", score[2]), 15, 320, 30, MAGENTA);
    DrawText(TextFormat("HI-SCORE: %s", hightscore.c_str()), 15, 20, 40, RED);
    auto tmp = time;
    auto minutes = (float)(int)(tmp / 60);
    auto seconds = (float)((int)tmp % 60);
    DrawText(TextFormat("Elapsed Time: %02.0f : %02.0f", minutes, seconds), 800, 100, 40, MAGENTA);
}

void Raylib::Draw::draw_text_player(std::vector<int> &life)
{
    if (life[0] > 0)
        DrawText(TextFormat("LIFE       : %u / 100", life[0]), 1600, 120, 30, MAGENTA);
    else if (life[0] <= 0){
        DrawText(TextFormat("LIFE       : "), 1600, 120, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 120, 30, RED);
    }
    if (life[1] > 0)
        DrawText(TextFormat("LIFE       : %u / 100", life[1]), 1600, 220, 30, MAGENTA);
    else if (life[1] <= 0) {
        DrawText(TextFormat("LIFE       : "), 1600, 220, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 220, 30, RED);
    }
    if (life[2] > 0)
        DrawText(TextFormat("LIFE       : %u / 100", life[2]), 1600, 320, 30, MAGENTA);
    else if (life[2] <= 0) {
        DrawText(TextFormat("LIFE       : "), 1600, 320, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 320, 30, RED);
    }
}

void Raylib::Draw::draw_speed_up(Texture2D texture)
{
    DrawCubeTexture(texture, (Vector3){-13, 0.1, -4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-14, 0.1, 4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){14, 0.1, 4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){13, 0.1, -5}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-9, 0.1, -3}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-7, 0.1, 3}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){5, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){10, 0.1, 2}, 0.80f, 0.1f, 0.80f, WHITE);
}

void Raylib::Draw::draw_speed_down(Texture2D texture)
{
    DrawCubeTexture(texture, (Vector3){-12, 0.1, -1}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-11, 0.1, 5}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){6, 0.1, -1}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){12, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-5, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){-4, 0.1, 0}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){2, 0.1, -4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(texture, (Vector3){0, 0.1, 6}, 0.80f, 0.1f, 0.80f, WHITE);
}
