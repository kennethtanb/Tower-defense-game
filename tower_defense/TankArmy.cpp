
#include "TankArmy.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>


#include "AudioHelper.hpp"
//#include "ArmyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
//#include "ArcherBullet.hpp"

//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
TankArmy::TankArmy(int x, int y) : Army("play/enemy-4.png", x, y, 20, 0, 0.0, 50, 2, 1.5 * PlayScene::BlockSize) {};

void TankArmy::CreateBullet(Engine::Point pt){};
