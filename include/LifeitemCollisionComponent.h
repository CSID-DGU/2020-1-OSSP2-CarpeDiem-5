/*******************************************************************//*
 * Collision component for Lifeitem.
 *
 * @author      SeungMinSong
 * @version     1.0
 * @since       2020-05-29
 *********************************************************************/
#ifndef SPACESHOOTER_LIFEITEMCOLLISIONCOMPONENT_
    #define SPACESHOOTER_LIFEITEMCOLLISIONCOMPONENT_

#include "CollisionComponent.h"

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include "Timer.h"
#include "Vector2D.h"

#include "CollisionBodyRectangle.h"
#include "CollisionManager.h"
#include "GameEntity.h"
#include "GameEntityManager.h"
#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include "WindowElements.h"

class CollisionManager;
class GameEntity;
class GameEntityManager;
class PhysicsComponent;
class RenderComponent;

struct WindowElements;

class LifeitemCollisionComponent : public CollisionComponent
{
    private:
        CollisionManager* collisionManager;

        PhysicsComponent* physics;
        RenderComponent* render;

    public:
        //Constructor
        LifeitemCollisionComponent(GameEntity* gameEntity, WindowElements* windowElements,CollisionManager* collisionManager);
        

        //Destructor
        ~LifeitemCollisionComponent();
        

        //Methods
        void update();
        
};

#endif
