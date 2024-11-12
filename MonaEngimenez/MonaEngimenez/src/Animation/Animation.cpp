#include "Animation.h"

#include <iostream>

#include "Timer/Time.h"

int AnimationIDCounter = 0;

Animation::Animation(int initialX, int initialY, int maxFrames, float maxAnimationTime, int spriteWidth,
    int spriteHeight, int frameWidth,
    int frameHeight)
{
    AnimationIDCounter++;
    this->initialX = initialX;
    this->initialY = initialY;
    this->maxFramesInAnimation = maxFrames;
    this->maxAnimationTime = maxAnimationTime;
    this->spriteHeight = spriteHeight;
    this->spriteWidth = spriteWidth;
    this->frameHeight = frameHeight;
    this->frameWidth = frameWidth;
    id = AnimationIDCounter;
    addFrames();
    currentTime = 0;
    currentFrame = totalFrames.front();
}



Animation::Animation()
{
    while (!totalFrames.empty())
    {
        Frame* aux = totalFrames.back();
        totalFrames.pop_back();
        delete aux;
    }
    maxFramesInAnimation = 0;
}

bool Animation::hasFrames()
{
    return maxFramesInAnimation > 0;
}

void Animation::addFrames()
{
    float spriteWidthF = spriteWidth;
    float spriteHeightF = spriteHeight;
    for (int i = 0; i < maxFramesInAnimation; ++i)
    {
        glm::vec2 topRight = glm::vec2((initialX + (i * frameWidth) + frameWidth) / spriteWidthF,
            (initialY + frameHeight) / spriteHeightF);

        glm::vec2 botRight = glm::vec2((initialX + (i * frameWidth) + frameWidth) / spriteWidthF,
            initialY / spriteHeightF);

        glm::vec2 botLeft = glm::vec2((initialX + i * frameWidth) / spriteWidthF,
            initialY / spriteHeightF);

        glm::vec2 topLeft = glm::vec2((initialX + i * frameWidth) / spriteWidthF,
            ((initialY + frameHeight) / spriteHeightF));

        Frame* aux = new Frame(topRight, botRight, botLeft, topLeft);
        totalFrames.push_back(aux);
    }
}

void Animation::update()
{
    currentTime += Time::getDeltaTime();

    while (currentTime > maxAnimationTime)
    {
        currentTime -= maxAnimationTime;
    }

    float frameLengh = (maxAnimationTime / maxFramesInAnimation);
    currentFrameCounter = static_cast<int>(currentTime / frameLengh);
    currentFrame = totalFrames[currentFrameCounter];

    //  std::cout << "Current Time : " << currentTime << std::endl;
}

void Animation::GetFrame(float positions[])
{
	//Update();

	if (currentFrameCounter >= 0 && currentFrameCounter < maxFramesInAnimation)
	{
        positions[2] = currentFrame->getUVCoord(2)[0];
        positions[3] = currentFrame->getUVCoord(2)[1];

        positions[6] = currentFrame->getUVCoord(1)[0];
        positions[7] = currentFrame->getUVCoord(1)[1];

        positions[10] = currentFrame->getUVCoord(0)[0];
        positions[11] = currentFrame->getUVCoord(0)[1];

        positions[14] = currentFrame->getUVCoord(3)[0];
        positions[15] = currentFrame->getUVCoord(3)[1];
	}
}

void Animation::SetCurrentFrame(int frame)
{
    currentFrame = totalFrames[frame];
}


bool Animation::operator==(const Animation& animation) const
{
    return (id == animation.id);

}