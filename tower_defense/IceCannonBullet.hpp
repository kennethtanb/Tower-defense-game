#ifndef IceCannonBullet_hpp
#define IceCannonBullet_hpp

#include "Bullet.hpp"

class Army;
class Defense;
namespace Engine {
struct Point;
}  // namespace Engine

class IceCannonBullet : public Bullet {
public:
    explicit IceCannonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent);
    void Update(float deltaTime) override;
};

#endif /* IceCannonBullet_hpp */
