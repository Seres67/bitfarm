#ifndef STARDEW_BOY_SCENE_HPP
#define STARDEW_BOY_SCENE_HPP

#include "bn_optional.h"

enum class scene_type;

class Scene
{

  public:
    virtual ~Scene() = default;

    [[nodiscard]] virtual bn::optional<scene_type> update() = 0;

  protected:
    Scene() = default;
};

#endif // !STARDEW_BOY_SCENE_HPP
