/*******************************************************************//*
 * Physics component for PlayerInstructionsProjectile.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2015-02-01
 * @modified    2015-02-19
 *********************************************************************/
#ifndef SPACESHOOTER_PLAYERINSTRUCTIONSPROJECTILEPHYSICSCOMPONENT_
    #define SPACESHOOTER_PLAYERINSTRUCTIONSPROJECTILEPHYSICSCOMPONENT_

#include "PhysicsComponent.h"

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include "Timer.h"
#include "Vector2D.h"

class GameEntity;
class RenderComponent;

struct WindowElements;

class PlayerInstructionsProjectilePhysicsComponent : public PhysicsComponent
{
    private:
        RenderComponent* render;
        Timer timeBasedMovementTimer;

        int xGrid;
        int yGrid;
        int xMin;
        int yMin;
        int xMax;
        int yMax;

    public:
        Vector2D velocity;
        int velocityPerSecond;

        //Constructor
        PlayerInstructionsProjectilePhysicsComponent(GameEntity* gameEntity, WindowElements* windowElements);

        //Destructor
        ~PlayerInstructionsProjectilePhysicsComponent();

        //Methods
        void update();
        void pauseTimers();
        void resumeTimers();
};

#endif
