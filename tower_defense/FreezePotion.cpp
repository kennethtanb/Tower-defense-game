//
//  FreezePotion.cpp
//  tower_defense
//
//  Created by Kenneth Tan on 2022/5/21.
//

#include "FreezePotion.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>


#include "AudioHelper.hpp"
//#include "ArmyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
#include "ArcherBullet.hpp"
#include "Defense.hpp"
#include "IceField.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "Collider.hpp"


//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
FreezePotion::FreezePotion(int x, int y) : Army
("play/cold.png", x, y, 20, 1, 0.0, 50, 3, 1.5 * PlayScene::BlockSize) {};
float freezeTime = 1;//because after we set the reload time, it takes another second to wait, so we just set it as 1s to compensate for the wait.
bool snow = false;

void FreezePotion::Update(float deltaTime){
    PlayScene* scene = getPlayScene();
    if (isPreview) return;
    
    if(!snow){
        //std::cout<<"snow\n";
        for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++)
                    getPlayScene()->EffectGroup->AddNewObject(new IceField(this->Position.x + i*64,this->Position.y + j*64));
        snow = true;
    }
    
    
    for (auto& it : scene->DefenseGroup->GetObjects()) {
        Defense* def= dynamic_cast<Defense*>(it);
        if (!def->Visible){
            continue;
        }
        if (Engine::Collider::IsCircleOverlap(Position, shootRadius, def->Position, def->CollisionRadius)) {
            
            def->reload = 0.1;
            std::cout<<"collision\n";
            //getPlayScene()->BulletGroup->RemoveObject(objectIterator);
//            return;
        }
    }
    
    
    freezeTime -= deltaTime;
    if (freezeTime <= 0) {
        std::cout<<"masuk"<<std::endl;
        //OnExplode();
        snow = false;
        freezeTime = 1;
        
        for (auto& it : scene->DefenseGroup->GetObjects()) {
            Defense* def= dynamic_cast<Defense*>(it);
            std::cout<<"masuk lagi\n";
//            def->Enabled = true;
//            def->Target = nullptr;
            def->reload = 1;
//            def->Update(deltaTime);
            std::cout<<def->reload<<std::endl;
                //return;
        }
        
        Hit(100);
    }
    

}

void FreezePotion::Hit(float damage){
    HP -= damage;
    if (HP <= 0) {
        // Remove all Defense's reference to target.
        for (auto& it: lockedDefenses)
            it->Target = nullptr;
        getPlayScene()->ArmyGroup->RemoveObject(objectIterator);
    }
}

void FreezePotion::CreateField(float x, float y){
    getPlayScene()->EffectGroup->AddNewObject(new IceField(x ,y));
}

void FreezePotion::CreateBullet(Engine::Point pt){}
