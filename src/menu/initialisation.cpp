/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** initialisation
*/

#include "menu.hpp"

Bomberman::Menu::Menu() {}

void Bomberman::Button::init()
{
    button = LoadTexture(filename.c_str());
}

void Bomberman::Menu::init()
{
    InitAudioDevice();
    this->musiic.init("./sounds/menu.mp3", 2, false);
    this->sfx = LoadSound("./sounds/explosion8bit.wav");

    this->btns.push_back(Bomberman::Button("Png/basic_play.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 250.0,540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_option.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 450.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_exit.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 850.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_tuto.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 650.0, 540, 120}));

    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){0, 0, 100, 100}, (Rectangle){1300, 400, 100, 100}));
    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){0, 0, 100, 100}, (Rectangle){1300, 700, 100, 100}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){0, 0, 100, 100}, (Rectangle){400, 400, 100, 100}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){0, 0, 100, 100}, (Rectangle){400, 700, 100, 100}));

    /*resume*/ this->btns.push_back(Bomberman::Button("Png/basic_resume.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 300, 540, 120}));
    /*options*/ this->btns.push_back(Bomberman::Button("Png/basic_option.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 450, 540, 120}));
    /*title*/ this->btns.push_back(Bomberman::Button("Png/basic_home.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 600, 540, 120}));
    /*quit*/ this->btns.push_back(Bomberman::Button("Png/basic_exit.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 750, 540, 120}));
    /*filler*/this->btns.push_back(Bomberman::Button("Png/+.png", (Rectangle){0, 0, 0, 0}, (Rectangle){0, 0, 0, 0}));
    for (size_t i = 0; i < this->btns.size(); i++)
        this->btns[i].init();
    PlayMusicStream(musiic.get_ost());
}

Bomberman::Menu::~Menu()
{
    UnloadSound(this->sfx);
    CloseAudioDevice();
    for (size_t i = 0; i < this->btns.size(); i++)
        UnloadTexture(this->btns[i].button);
}