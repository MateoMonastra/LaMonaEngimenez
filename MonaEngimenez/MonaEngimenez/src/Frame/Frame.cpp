#include "Frame/Frame.h"

#include <iostream>


glm::vec2 Frame::getUVCoord(int id)
{
    if (id >= maxFrameSize && id < 0)
    {
        std::cout << "Id UV outside range" << std::endl;
        return { 0, 0 };
    }
    else
    {
        return uvCoord[id];
    }
}

Frame::Frame(glm::vec2 firstUV, glm::vec2 secondUV, glm::vec2 thirdUV, glm::vec2 fourthUV)
{
    uvCoord[0] = firstUV;
    uvCoord[1] = secondUV;
    uvCoord[2] = thirdUV;
    uvCoord[3] = fourthUV;
}

Frame::Frame()
{
    uvCoord[0] = glm::vec2(0.0f, 1.0f); // Inferior izquierdo
    uvCoord[1] = glm::vec2(1.0f, 1.0f); // Inferior derecho
    uvCoord[2] = glm::vec2(1.0f, 0.0f); // Superior derecho
    uvCoord[3] = glm::vec2(0.0f, 0.0f); // Superior izquierdo
}
