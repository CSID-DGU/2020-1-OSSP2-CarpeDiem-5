/*******************************************************************//*
 * Implementation of the LifeitemPhysicsComponent class.
 *
 * @author      SeungMinSong
 * @version     1.0
 * @since       2020-05-29
 *********************************************************************/
#include "LifeitemPhysicsComponent.h"

#include "GameEntity.h"
#include "GameEntityFactory.h"
#include "GameState.h" // Observing
#include "Level.h" // For SpawnData struct
#include "RenderComponent.h"
#include "WindowElements.h"

LifeitemPhysicsComponent::LifeitemPhysicsComponent(GameEntity* gameEntity,
                                            WindowElements* windowElements,
                                            GameEntityFactory* gameEntityFactory)
:   gameEntityFactory(gameEntityFactory),
    render(NULL),
    velocity(0,150),
    velocityPerSecond(500),
    shooting(true)
{
    this->gameEntity = gameEntity;
    this->windowElements = windowElements;
    render = gameEntity->getRenderComponent();
    printf("Lifeitem Physics !! \n");
}

LifeitemPhysicsComponent::~LifeitemPhysicsComponent()
{
}

void LifeitemPhysicsComponent::update()
{
	float timeSinceLastFrame = timeBasedMovementTimer.getTimeOnTimer() / 1000.f;
    //x = x + speedPerSeconds*secondsSinceLastFrame
    //gameEntity->xPos += (xVel * timeSinceLastFrame);
    //gameEntity->position += velocity*timeSinceLastFrame;

    gameEntity->position += movement.getCurrentVelocity()*timeSinceLastFrame;

    int spriteWidth = render->getTexture()->getSpriteWidth();
    int spriteHeight = render->getTexture()->getSpriteHeight();

    if (!gameEntity->active)
    {
        if (gameEntity->position.x + spriteWidth/2 > 0 &&
            gameEntity->position.y + spriteHeight/2 > 0 &&
            gameEntity->position.x - spriteWidth/2 < windowElements->WINDOW_WIDTH &&
            gameEntity->position.y - spriteHeight/2 < windowElements->WINDOW_HEIGHT)
        {
            gameEntity->active = true;
        }
    }
    else
    {
        if (gameEntity->position.x + spriteWidth/2 + offScreenBuffer < 0 ||
            gameEntity->position.y + spriteHeight/2 + offScreenBuffer < 0 ||
            gameEntity->position.x - spriteWidth/2 - offScreenBuffer > windowElements->WINDOW_WIDTH ||
            gameEntity->position.y - spriteHeight/2 - offScreenBuffer > windowElements->WINDOW_HEIGHT)
        {
            gameEntity->remove = true;
        }

        // if (!gameEntity->remove && shooting)
        // {
        //     if (projectileCapTimer.isStarted())
        //     {
        //         if (projectileCapTimer.getTimeOnTimer()>2500)
        //         {
        //             SpawnData data;
        //             data.type = "enemyProjectile";
        //             data.x = gameEntity->position.x;
        //             data.y = gameEntity->position.y + render->getRenderRect().h/2;
        //             gameEntityFactory->createEntity(data);
        //             projectileCapTimer.stop();
        //         }
        //     }
        //     else
        //     {
        //         SpawnData data;
        //         data.type = "enemyProjectile";
        //         data.x = gameEntity->position.x;
        //         data.y = gameEntity->position.y + render->getRenderRect().h/2;
        //         gameEntityFactory->createEntity(data);
        //     }
        //     projectileCapTimer.start();
        // }
    }
    timeBasedMovementTimer.stop();
    timeBasedMovementTimer.start();

}

void LifeitemPhysicsComponent::pauseTimers()
{
    timeBasedMovementTimer.pause();
    projectileCapTimer.pause();
    movement.pauseTimers();
}

void LifeitemPhysicsComponent::resumeTimers()
{
    timeBasedMovementTimer.resume();
    projectileCapTimer.resume();
    movement.resumeTimers();
}

void LifeitemPhysicsComponent::onHit()
{
    if (!decrementHealth(1))
    {
       // getLife();
        onDestroy();    
        printf("LifeitemPhysicsComponent::onHit\n");
    }
}

void LifeitemPhysicsComponent::onDestroy()
{
    //gameEntityFactory->createExplosion(gameEntity);
    SpawnData data;
    data.type = "explosion";
    data.x = gameEntity->position.x;
    data.y = gameEntity->position.y;
    data.width = render->getRenderRect().w;
    data.height = render->getRenderRect().h;
    gameEntityFactory->createEntity(data);
    gameEntity->remove = true;
    printf("LifeitemPhysicsComponent::onDestroy()\n");
    notify(gameEntity, LIFEITEM_DESTROYED);
}

MovementPattern* LifeitemPhysicsComponent::getMovementPattern()
{
    return &movement;
}
// void LifeitemPhysicsComponent::getLife()
// {
//     SpawnData data;
//     data.type = "lifeitem";
//     data.x = gameEntity->position.x;
//     data.y = gameEntity->position.y;
//     data.width = render->getRenderRect().w;
//     data.height = render->getRenderRect().h;
//     gameEntityFactory->createEntity(data);
//     gameEntity->remove = true;
//     notify(gameEntity, LIFEITEM_DESTROYED);    
//     printf("LifeitemPhysicsComponent::getLife\n");            
// }
