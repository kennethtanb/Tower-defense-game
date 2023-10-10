#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "IceCannonBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
#include "GameEngine.hpp"
#include "Collider.hpp"

class Defense;

//Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* defenseParent);
IceCannonBullet::IceCannonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent) :
    Bullet("play/iceball.png", 500, 2, position, forwardDirection, rotation, parent) {
}

void IceCannonBullet::Update(float deltaTime){
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();

    for (auto& it : scene->ArmyGroup->GetObjects()) {
        Army* army= dynamic_cast<Army*>(it);
        if (!army->Visible){
            continue;
        }
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, army->Position, army->CollisionRadius)) {
            army->Hit(damage);
            if(army->id != 2)
                army->speed = 20;
            getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }
    if (Position.x < 0 || Position.x > PlayScene::GetClientSize().x || Position.y < 0 || Position.y > PlayScene::GetClientSize().y)
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}
