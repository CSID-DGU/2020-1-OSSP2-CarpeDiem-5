/*******************************************************************//*
 * Render component for Lifeitem.
 *
 * @author      SeungMinSong
 * @version     1.0
 * @since       2020-05-29
 *********************************************************************/
#ifndef SPACESHOOTER_LIFEITEMRENDERCOMPONENT_
    #define SPACESHOOTER_LIFEITEMRENDERCOMPONENT_

#include "RenderComponent.h"

#ifdef _WIN32
	#include <SDL.h>
#endif

#ifdef __linux
	#include <SDL2/SDL.h>
#endif

#include <cstddef>
#include "GameEntity.h"
#include "SDL_util.h"
#include "Texture.h"
#include "Util.h"
#include "WindowElements.h"

class GameEntity;

struct WindowElements;

class LifeitemRenderComponent : public RenderComponent
{
    public:
        //Constructor
        LifeitemRenderComponent(GameEntity* gameEntity, WindowElements* windowElements);
        

        //Destructor
        ~LifeitemRenderComponent();
        

        //Methods
        void update();
        
};

#endif
