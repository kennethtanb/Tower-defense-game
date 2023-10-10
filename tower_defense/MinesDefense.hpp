//
//  MinesDefense.hpp
//  tower_defense
//
//  Created by Kenneth Tan on 2022/5/23.
//

#ifndef MinesDefense_hpp
#define MinesDefense_hpp

#include "Defense.hpp"
#include "Sprite.hpp"
#include "GameEngine.hpp"
#include "Role.hpp"

class MinesDefense: public Defense {
public:
    MinesDefense(float x, float y);
    void Update(float deltaTime) override;
    void Draw() const override;
    void CreateBullet(Engine::Point pt) override;
    float delay = 4;
    bool kaboom = false;
};

#endif /* MinesDefense_hpp */
