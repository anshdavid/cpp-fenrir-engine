#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#include <iostream>
#include <cassert>
#include <GL/glew.h>
#include "stb_image.h"

class Texture
{
public:
    Texture(const std::string &fileName);

    void Bind(unsigned int unit);

    virtual ~Texture();

protected:
private:
    Texture(const Texture &other) {}
    void operator=(const Texture &other) {}

    GLuint m_texture;
};

#endif // __TEXTURE_H__