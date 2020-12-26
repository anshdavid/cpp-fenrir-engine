#ifndef __SHADER_H__
#define __SHADER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>

#include "transform.hpp"

class Shader
{
public:
    Shader(const std::string &fileName);

    void Bind();
    void Update(const Transform &transform);

    virtual ~Shader();

protected:
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader &other) {}
    void operator=(const Shader &other) {}

    enum
    {
        TRANSFORM_U,

        NUM_UNIFORMS
    };

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // __SHADER_H__