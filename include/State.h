#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>
#include "GameObject.h"
#include "InputManager.h"
#include "Music.h"
#include "TileSet.h"

class State {
  public:
    State();
    virtual ~State() { objectArray.clear(); }
    bool QuitRequested() const { return quitRequested; }
    void LoadAssets();
    void Update(float dt);
    void Render() const;
    void Start();
    std::weak_ptr<GameObject> AddObject(GameObject* go);
    std::weak_ptr<GameObject> GetObjectPrt(GameObject* go);

  private:
    Music* music = nullptr;
    TileSet* tileSet = nullptr;
    bool quitRequested = false;
    std::vector<std::shared_ptr<GameObject>> objectArray;
    bool started = false;

    InputManager& input;
};

#endif
