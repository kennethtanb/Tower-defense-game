//
//  IceField.cpp
//  tower_defense
//
//  Created by Kenneth Tan on 2022/5/22.
//

#include "IceField.hpp"
#include <cmath>
#include <string>
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"

PlayScene* IceField::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

IceField::IceField(float x, float y) : Sprite("play/bullet-1.png", x, y), timeFreeze(2) {
    bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/bullet-1.png"));
}


void IceField::Update(float deltaTime){
    
    timeFreeze -= deltaTime;
    if (timeFreeze <= 0) {
//        std::cout<<"masuk"<<std::endl;
        getPlayScene()->EffectGroup->RemoveObject(objectIterator);
        timeFreeze = 2;
        return;
    }
}
