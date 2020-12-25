#ifndef __MESH_H__
#define __MESH_H__

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>

class Vertex
{
public:
    Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }

    inline glm::vec3 *GetPos() { return &pos; }
    inline glm::vec2 *GetTexCoord() { return &texCoord; }

protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
public:
    Mesh(Vertex *vertices, unsigned int numVertices);

    virtual ~Mesh();

    void Draw();

protected:
private:
    Mesh(const Mesh &other);
    void operator=(const Mesh &other);

    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif // __MESH_H__