/*******************************************************************//*
 * Render component for misc Sprites.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2015-02-01
 * @modified    2015-02-20
 *********************************************************************/
#ifndef SPACESHOOTER_SPRITERENDERCOMPONENT_
    #define SPACESHOOTER_SPRITERENDERCOMPONENT_

#include "RenderComponent.h"

#include <string>

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include "Timer.h"

class GameEntity;

struct WindowElements;

class SpriteRenderComponent : public RenderComponent
{
    private:
        Timer timer;
        bool timedSprite;
        int activeTime;

    public:
        //Constructor
        SpriteRenderComponent(GameEntity* gameEntity,
                               WindowElements* windowElements);

        //Destructor
        ~SpriteRenderComponent();

        //Methods
        void update();
        void setRenderRect(SDL_Rect* rect);
        void setActiveTimer(int msec);
};

#endif
