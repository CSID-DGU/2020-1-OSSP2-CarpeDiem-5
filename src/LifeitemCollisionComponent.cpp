/*******************************************************************//*
 * Implementation of the EnemyCollisionComponent class.
 *
 * @author      SeungMinSong
 * @version     1.0
 * @since       2020-05-29
 *********************************************************************/
#include "LifeitemCollisionComponent.h"

#include "CollisionBodyRectangle.h"
#include "CollisionManager.h"
#include "GameEntity.h"
#include "GameEntityManager.h"
#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include "WindowElements.h"

//NOT COMPLETE

LifeitemCollisionComponent::LifeitemCollisionComponent(GameEntity* gameEntity,
                                            WindowElements* windowElements,
                                            CollisionManager* collisionManager)
:   collisionManager(collisionManager), physics(NULL), render(NULL)
{
    this->gameEntity = gameEntity;
    this->windowElements = windowElements;
    physics = gameEntity->getPhysicsComponent();
    render = gameEntity->getRenderComponent();
    collisionManager->addCollisionObject(gameEntity, ENTITY_NEUTRAL);
    this->body = new CollisionBodyRectangle(gameEntity);
    printf("Lifeitem Collision !! \n");
}

LifeitemCollisionComponent::~LifeitemCollisionComponent()
{
    delete body;
    collisionManager->deleteCollisionObject(gameEntity, ENTITY_NEUTRAL);
}

void LifeitemCollisionComponent::update()
{
    collisionManager->checkCollision(gameEntity, ENTITY_FRIENDLY);
}

