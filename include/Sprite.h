#pragma once
#define INCLUDE_SDL
#include "Component.h"
#include "SDL_include.h"

class Sprite : public Component {
  public:
    Sprite(GameObject& associated) : Component(associated), texture(nullptr) {}

    Sprite(GameObject& associated, std::string file)
        : Component(associated), texture(nullptr) {
        Sprite::Open(file);
    }
    ~Sprite() {}

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    int GetWidth() { return width; }
    int GetHeight() { return height; }
    bool IsOpen() { return (bool)Sprite::texture; }

    void Update(float dt) {}
    bool Is(std::string type) { return !type.compare("Sprite"); }

  private:
    SDL_Texture* texture = nullptr;
    int width;
    int height;
    SDL_Rect clipRect;

    SDL_Rect dstRect;
};
