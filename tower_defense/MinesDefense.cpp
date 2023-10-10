#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <utility>
#include <iostream>

#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
#include "GameEngine.hpp"
#include "Collider.hpp"

#include "MinesDefense.hpp"


MinesDefense::MinesDefense(float x, float y) :
    Defense("play/bomb.png", x, y, 20, 1, 50, 2, 1.5 * PlayScene::BlockSize) {
        //fake = new Role("play/deep-pink.png",x,y);
        //Visible= false;
    }

void MinesDefense::Update(float deltaTime){

    //Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    //delay -= deltaTime;

    for (auto& it : scene->ArmyGroup->GetObjects()) {
        Army* army= dynamic_cast<Army*>(it);
        if (!army->Visible||army->id==3)
            continue;
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, army->Position, army->CollisionRadius)) {
        //if(Engine::Collider::IsPointInRect(Position, army->Position, Engine::Point(64,64))){
            for(auto& ie : scene->ArmyGroup->GetObjects()){
                Army* ar = dynamic_cast<Army*>(ie);
                if(InShootingRange(ie->Position)&&ar->id!=3){
                    ar->Hit(INFINITY);
                }
            }
            //float detonate = 1;
            //Sprite::Draw();
            //while(detonate>0) detonate -= deltaTime;

            Hit(INFINITY);
            //getPlayScene()->MinesGroup->RemoveObject(objectIterator);
            //kaboom = true;
            return;
        }
    }
    
//    if(kaboom){
//        std::cout<<"kaboom\n";
//        getPlayScene()->MinesGroup->RemoveObject(objectIterator);
////        return;
//    }
    // Check if out of boundary.
    if (Position.x < 0 || Position.x > PlayScene::GetClientSize().x || Position.y < 0 || Position.y > PlayScene::GetClientSize().y)
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}

void MinesDefense::Draw() const{
    if (PlayScene::DebugMode) {
        // Draw target radius.
        Sprite::Draw();
        al_draw_circle(Position.x, Position.y, shootRadius, al_map_rgb(0, 0, 255), 2);
    }
}

void MinesDefense::CreateBullet(Engine::Point pt){};
