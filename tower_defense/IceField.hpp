//
//  IceField.hpp
//  tower_defense
//
//  Created by Kenneth Tan on 2022/5/22.
//

#ifndef IceField_hpp
#define IceField_hpp
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>
//#include "Army.hpp"
#include "Sprite.hpp"

class PlayScene;

class IceField: public Engine::Sprite {
protected:
    PlayScene* getPlayScene();
    float timeFreeze;
    std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
//    float timeSpan = 0.5;
public:
    IceField(float x, float y);
    void Update(float deltaTime) override;
};

#endif /* IceField_hpp */
