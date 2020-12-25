#version 330 core

varying vec2 texCoord0;

uniform sampler2D diffurse;

void main()
{
    
    gl_FragColor = texture2D(diffurse, texCoord0);//vec4(1.0, 0.0, 0.0, 1.0);
}