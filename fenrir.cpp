#include "display.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "texture.hpp"

int main(int argc, char *argv[])
{
    Display display(800, 600, "fenrir engine");

    Shader shader("./resources/basicShader");

    Texture texture("./resources/bricks.jpg");

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
        Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        shader.Bind();
        mesh.Draw();

        display.Update();
    }
}
