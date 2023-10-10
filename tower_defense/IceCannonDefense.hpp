#ifndef IceCannonDefense_hpp
#define IceCannonDefense_hpp

#include "Defense.hpp"

class IceCannonDefense: public Defense {
public:
    IceCannonDefense(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* IceCannonDefense_hpp */
