#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "IceCannonDefense.hpp"
#include "AudioHelper.hpp"
#include "IceCannonBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"

//Defense(std::string imgDefense, float x, float y, float radius, float coolDown, int hp, int id, float shootRadius);
IceCannonDefense::IceCannonDefense(float x, float y) :
    Defense("play/ice-cannon.png", x, y, 20, 0.5, 50, 3, 500) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}

void IceCannonDefense::CreateBullet(Engine::Point pt) {
    int dx = pt.x - Position.x;
    int dy = pt.y - Position.y;
    double len = sqrt(pow(dx, 2) + pow(dy, 2));
    Engine::Point diff = Engine::Point(dx / len, dy / len);
    Engine::Point rotateDiff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(rotateDiff.y, rotateDiff.x) + ALLEGRO_PI / 2;
    getPlayScene()->BulletGroup->AddNewObject(new IceCannonBullet(Position , diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
