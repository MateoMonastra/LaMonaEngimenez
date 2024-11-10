#include "CollisionManager.h"


bool CollisionManager::CheckCollisionRecRec(Entity2D* entityOne, Entity2D* entityTwo)
{
    if (entityOne->GetTranslation().x < entityTwo->GetTranslation().x + entityTwo->GetScale().x &&
        entityOne->GetTranslation().x + entityOne->GetScale().x > entityTwo->GetTranslation().x &&
        entityOne->GetTranslation().y < entityTwo->GetTranslation().y + entityTwo->GetScale().y &&
        entityOne->GetTranslation().y + entityOne->GetScale().y > entityTwo->GetTranslation().y)
    {
        return true;
    }
    else
    {
        return false;
    }
}