/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include <unistd.h>

Bomberman::Core::Core()
{
    InitWindow(screenWidth, screenHeight, "BOOOOOMBERMAAN");
    ToggleFullscreen();
    init();
    game_loop();
}

void Bomberman::Core::init(void)
{
    this->background = LoadTexture("Png/space_background.png"); // Load map texture
    _player.init();
    _ai.init_AI();
    _camera.init();
    _map.init();
    _menu.init();
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    this->mapPixels = LoadImageColors(_map.get_image());
    this->breakable_texture = LoadTexture("Png/woodx_brick.png");
    this->grass_texture = LoadTexture("Png/grass_cube.png");
    this->brick_texture = LoadTexture("Png/brick_cube.png");
    _rectGrass = Rectangle{(float)grass_texture.width / 2, (float)grass_texture.height / 2,
                           (float)grass_texture.width / 2, (float)grass_texture.height / 2};
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        DrawTextureV(background, Vector2 {0, 0}, WHITE);
        this->_rotate_ai = _ai.move_AI();
        this->rt = _player.Player_move(this->mapPixels, this->_map.get_cubicTexture());
        this->r = _player.Player_animation(this->mapPixels, this->_map.get_cubicTexture());
        _map.update();
        _camera.Camera_move();
        _menu.update();
        Draw();
    }
}

void Bomberman::Core::Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true)
    {
        Draw3d();
        Draw2d();
    }
    else
        _menu.loop();
    EndDrawing();
}

void Bomberman::Core::Draw2d()
{
    DrawTextureEx(_map.get_cubicTexture(), (Vector2){screenWidth - _map.get_cubicTexture().width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - _map.get_cubicTexture().width * 4 - 20, 20, _map.get_cubicTexture().width * 4, _map.get_cubicTexture().height * 4, GREEN);
    DrawText("The map generated is : ", 1410, 20, 30, GRAY);
    DrawFPS(10, 1060);
    DrawText(TextFormat("SCORE: %i", _score.get_score1()), 1400, 200, 40, GRAY);
    DrawText(TextFormat("SCORE: %i", _score.get_score2()), 300, 200, 40, GRAY);
    _score.writeScore(std::to_string(_score.get_score1()));
    _score.writeScore(std::to_string(_score.get_score2()));
    DrawText(TextFormat("HI-SCORE: %s", _score.getHightScore().c_str()), 10, 20, 40, RED);
    // DrawText in format convert second to minutes and seconds
    auto tmp = GetTime();
    auto minutes = (float)(int)tmp / 60;
    auto seconds = (float)((int)tmp % 60);
    DrawText(TextFormat("Elapsed Time: %02.0f : %02.0f", minutes, seconds), 800, 100, 40, MAGENTA);

}

void Bomberman::Core::Draw_breakabke()
{
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 32; x++)
        {
            if (COLOR_EQUAL(mapPixels[y * this->_map.get_cubicTexture().width + x], RED))
            {
                DrawCubeTexture(breakable_texture, Vector3{x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
            if (COLOR_EQUAL(mapPixels[y * this->_map.get_cubicTexture().width + x], BLACK))
            {
                DrawCubeTextureRec(grass_texture, _rectGrass, {x - 16.0f, 0.1, y - 8.f},
                1, 0, 1, WHITE);
            }
            if (COLOR_EQUAL(mapPixels[y * this->_map.get_cubicTexture().width + x], WHITE))
            {
                DrawCubeTexture(brick_texture, {x - 16.0f, 0.5, y - 8.f},
                1, 1, 1, WHITE);
            }
        }
    }
}

void Bomberman::Core::Remove_breakable(Vector3 pos)
{
    int x = pos.x + 16;
    int y = pos.z + 8;
    /*
        for (int i = -1; i < 2; i++) {
            if ((x + i > -15 && x + i < 15) &&
                (COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x + i], RED)
            || COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x + i], BLACK))) {
                 mapPixels[y * _map.get_cubicTexture().width + x + i] = BLACK;
                DrawCube(Vector3{(float)(x + i - 16) , _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
            }
            else if (x + i <= -15 && x + i >= 15)
                break;
        }
        for (int i = -1; i < 2; i++) {
            if ((y + i > -7 && y + i < 7) &&
                (COLOR_EQUAL(mapPixels[(y + i) * _map.get_cubicTexture().width + x], RED)
            || COLOR_EQUAL(mapPixels[(y + i) * _map.get_cubicTexture().width + x], BLACK))) {
                 mapPixels[(y + i) * _map.get_cubicTexture().width + x] = BLACK;
                DrawCube(Vector3{(float)(x - 16) , _bomb_pos.y, (float)(y + i - 8)}, 1, 1, 1, RED);
            }
            else if (y + i <= -7 && y + i >= 7)
                break;
        }
        */
    if (COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x], BLACK))
    {
        mapPixels[y * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x < 15 && (COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x + 1], RED) || COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x + 1], BLACK)))
    {
        mapPixels[y * _map.get_cubicTexture().width + x + 1] = BLACK;
        DrawCube(Vector3{(float)(x + 1 - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x > -15 && (COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x - 1], RED) || COLOR_EQUAL(mapPixels[y * _map.get_cubicTexture().width + x - 1], BLACK)))
    {
        mapPixels[y * _map.get_cubicTexture().width + x - 1] = BLACK;
        DrawCube(Vector3{(float)(x - 1 - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (y < 7 && (COLOR_EQUAL(mapPixels[(y + 1) * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(mapPixels[(y + 1) * _map.get_cubicTexture().width + x], BLACK)))
    {
        mapPixels[(y + 1) * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y + 1 - 8)}, 1, 1, 1, RED);
    }
    if (y > -7 && (COLOR_EQUAL(mapPixels[(y - 1) * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(mapPixels[(y - 1) * _map.get_cubicTexture().width + x], BLACK)))
    {
        mapPixels[(y - 1) * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y - 1 - 8)}, 1, 1, 1, RED);
    }
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(_camera.get_Camera());
    DrawModelEx(_ai.get_Model(), _ai.get_pos(), (Vector3){ 0, 1, 0 }, _rotate_ai, (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model(), _player.get_pos(1), (Vector3){0, 1, 0}, r, (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model2(), _player.get_pos(2), (Vector3){0, 1, 0}, rt, (Vector3){1, 1, 1}, WHITE);
   // DrawModel(_map.get_model(), _map.get_pos(), 1.0f, WHITE);
    Draw_breakabke();
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && pressed < 1)
    {
        _bomb_pos = _player.get_pos(1);
        printf("%2.f, %2.f\n", _bomb_pos.x, _bomb_pos.z);
        pressed = 1;
        this->time1 = std::time(nullptr);
    }
    if (pressed > 0 && pressed < 3)
    {
        DrawSphere(Vector3{_bomb_pos}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos}, 0.3, 10, 10, BROWN);
    }
    if (IsKeyReleased(KEY_RIGHT_SHIFT))
    {
        pressed = 2;
    }
    if (pressed == 2 || pressed == 3)
    {
        std::time_t now = std::time(nullptr);
        if (now - time1 > 6)
            pressed = 0;
        else if (now - time1 > 3)
        {
            Remove_breakable(_bomb_pos);
            _score.update1();
            pressed = 3;
        }
    }

    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT)) && pressed2 < 1)
    {
        _bomb_pos2 = _player.get_pos(2);
        pressed2 = 1;
        this->time2 = std::time(nullptr);
    }
    if (pressed2 > 0 && pressed2 < 3)
    {
        DrawSphere(Vector3{_bomb_pos2}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos2}, 0.3, 10, 10, BROWN);
    }
    if (IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyReleased(KEY_LEFT_SHIFT))
    {
        pressed2 = 2;
    }
    if (pressed2 == 2 || pressed2 == 3)
    {
        std::time_t now2 = std::time(nullptr);
        if (now2 - time2 > 6)
            pressed2 = 0;
        else if (now2 - time2 > 3)
        {
            Remove_breakable(_bomb_pos2);
            _score.update2();
            pressed2 = 3;
        }
    }
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
