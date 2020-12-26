#include "display.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "texture.hpp"

int main(int argc, char *argv[])
{
    Display display(800, 600, "fenrir engine");

    Shader shader("./resources/basicShader");

    Texture texture("./resources/logof.png");

    Transform transform;

    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
        Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(0, 0)),
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    float counter = 0.0f;

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCoutner = cosf(counter);

        transform.GetPos().x = sinCounter;
        transform.GetRot().z = counter;
        transform.SetScale(glm::vec3(cosCoutner, cosCoutner, cosCoutner));

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform);
        mesh.Draw();

        display.Update();

        counter += 0.01f;
    }
}
