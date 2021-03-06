#ifndef TILEMAP_H
#define TILEMAP_H
#include <string>
#include <unordered_map>
#include "Component.h"
#include "TileSet.h"

class TileMap : public Component {
  public:
    TileMap(GameObject& associated, const std::string& file,
            bool infinity = false);
    ~TileMap();

    void Load(const std::string& file);
    void LoadList(const std::string& file);
    void SetTileSet(TileSet* tileSet) { this->tileSet = tileSet; }
    int At(int x, int y, int z = 1);

    void Update(float dt) {}
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const;

    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0) const;

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    int GetDepth() const { return depth; }

    void GetDamageGround(int damage, Vec2 posDamage);
    void ClearEnemyFromMap(Vec2 enemyPos);

    void ItemCollected(Vec2 target, int layer) {
        tileMat[layer][target.y * width + target.x] = 0;
    }

    enum Layers { BASE = 0, BLOCOS, ITENS, INIMIGOS };

  private:
    std::vector<std::vector<int>> tileMat;
    std::vector<std::string> TileMapsFiles;
    std::unordered_map<std::string, int> layerIndex;
    TileSet* tileSet;
    int width = 0, height = 0, depth = 0;
    const int groundLayer = 1;
    const int enemyLayer = 3;
    bool infinity = false;
    int currentFile = 0;

    void GetNextFile();
};

#endif  // TILEMAP_H
