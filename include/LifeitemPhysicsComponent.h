/*******************************************************************//*
 * Physics component for Lifeitem.
 *
 * @author      SeungMinSong
 * @version     1.0
 * @since       2020-05-29
 *********************************************************************/
#ifndef SPACESHOOTER_LIFEITEMPHYSICSCOMPONENT_
    #define SPACESHOOTER_LIFEITEMPHYSICSCOMPONENT_

#include "PhysicsComponent.h"

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include "IObserver.h"
#include "MovementPattern.h"
#include "Timer.h"
#include "Vector2D.h"

#include "GameEntity.h"
#include "GameEntityFactory.h"
#include "GameState.h" // Observing
#include "Level.h" // For SpawnData struct
#include "RenderComponent.h"
#include "WindowElements.h"

class GameEntity;
class GameEntityFactory;
class RenderComponent;

struct WindowElements;

class LifeitemPhysicsComponent : public PhysicsComponent,
                                public IObservable
{
    private:
        GameEntityFactory* gameEntityFactory;

        RenderComponent* render;
        Timer timeBasedMovementTimer;
        Timer projectileCapTimer;

        MovementPattern movement;

    public:
        Vector2D velocity;
        int velocityPerSecond;
        bool shooting;
        const int offScreenBuffer = 25;
        int score;

        //Constructor
        LifeitemPhysicsComponent(GameEntity* gameEntity,WindowElements* windowElements,GameEntityFactory* gameEntityFactory);
         

        //Destructor
        ~LifeitemPhysicsComponent();

        //Methods
        void update();
        
        void pauseTimers();
        
        void resumeTimers();
        
        void onHit();
        
        void onDestroy();
        
        MovementPattern* getMovementPattern();
        
        void getLife();
        

        //Virtual methods from IObservable
        //void notify(GameEntity* entity, int event);
};

#endif
