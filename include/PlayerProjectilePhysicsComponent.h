/*******************************************************************//*
 * Physics component for PlayerProjectile.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2014-09-08
 * @modified    2015-02-19
 *********************************************************************/
#ifndef SPACESHOOTER_PLAYERPROJECTILEPHYSICSCOMPONENT_
    #define SPACESHOOTER_PLAYERPROJECTILEPHYSICSCOMPONENT_

#include "PhysicsComponent.h"

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include "Level.h" // For SpawnData struct
#include "Timer.h"
#include "Vector2D.h"

class GameEntity;
class GameEntityFactory;
class RenderComponent;

struct WindowElements;

class PlayerProjectilePhysicsComponent : public PhysicsComponent
{
    private:
        RenderComponent* render;
        Timer timeBasedMovementTimer;
        GameEntityFactory* factory;

    public:
        Vector2D velocity;
        int velocityPerSecond;

        //Constructor
        PlayerProjectilePhysicsComponent(GameEntity* gameEntity,
                                        WindowElements* windowElements,
                                        GameEntityFactory* factory);

        //Destructor
        ~PlayerProjectilePhysicsComponent();

        //Methods
        void update();
        void pauseTimers();
        void resumeTimers();
        void onHit();
        void onDestroy();
};

#endif
