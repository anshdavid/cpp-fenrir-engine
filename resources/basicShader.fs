#version 120

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D diffurse;

void main()
{
    gl_FragColor = texture2D(diffurse, texCoord0)
        * clamp(dot(-vec3(0,0,1), normal0), 0.0, 1.5);
}