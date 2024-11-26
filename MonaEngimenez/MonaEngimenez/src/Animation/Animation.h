#pragma once

#include <vector>

#include "Exporter.h"
#include "Frame/Frame.h"


class MONA_ENGIMENEZ Animation
{
public:
    Animation(int initialX, int initialY, int maxFrames, float maxAnimationTime, int spriteWidth, int spriteHeight,int frameWidth, int frameHeight);
    Animation();
	~Animation();
    bool hasFrames();
    void addFrames();
    void update();
    void GetFrame(float positions[]);
    void SetCurrentFrame(int frame);
    bool operator==(const Animation& animation) const;
    Frame* currentFrame;
    std::vector<Frame*> totalFrames;

private:
    std::vector<Frame> framesInAnimation;
    int spriteWidth;
    int spriteHeight;
    int frameWidth;
    int frameHeight;
    int currentFrameCounter;
    int maxFramesInAnimation;
    float maxAnimationTime;
    float currentTime;
    int initialX;
    int initialY;
    int id;

};

