#ifndef FreezePotion_hpp
#define FreezePotion_hpp

#include "Army.hpp"

class FreezePotion: public Army {
public:
    FreezePotion(int x, int y);
    void CreateBullet(Engine::Point pt) override;
    void CreateField(float x, float y);
    void Update(float deltaTime) override;
    void Hit(float damage) override;
};


#endif /* FreezePotion_hpp */
