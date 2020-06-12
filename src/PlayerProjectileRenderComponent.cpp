/*******************************************************************//*
 * Implementation of the PlayerProjectileRenderComponent class.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2014-09-08
 * @modified    2015-02-21
 *********************************************************************/
#include "PlayerProjectileRenderComponent.h"

#include <cstddef>
#include "GameEntity.h"
#include "SDL_util.h"
#include "Texture.h"
#include "Util.h"
#include "WindowElements.h"

PlayerProjectileRenderComponent::PlayerProjectileRenderComponent(GameEntity* gameEntity,
                                               WindowElements* windowElements)
{
    this->gameEntity = gameEntity;
    this->windowElements = windowElements;

    texture = new Texture(windowElements);
    texture->setTexture(Util::fix_path("../data/graphics/sprites/water.png"));

    //renderRect.w = texture->getSpriteWidth();
    //renderRect.h = texture->getSpriteHeight();
    //gameEntity->position.x = playerEntity->position.x;
    //gameEntity->position.y = playerEntity->position.y - (playerEntity->getRenderComponent()->getTexture()->getSpriteHeight())/2 - (texture->getSpriteHeight())/2;
}

void PlayerProjectileRenderComponent::update()
{
    // 코끼리 코에서 물총 나오도록 위치 조정
    renderRect.x = gameEntity->position.x - 4*texture->getSpriteWidth();
    renderRect.y = gameEntity->position.y + texture->getSpriteHeight();
    SDL_RenderCopy(windowElements->renderer, texture->getTexture(), NULL, &renderRect);
}

PlayerProjectileRenderComponent::~PlayerProjectileRenderComponent()
{
    delete texture;
}
