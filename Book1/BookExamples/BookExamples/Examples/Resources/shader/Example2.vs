#version 300 es

layout(location = 0) in vec2 position;

void main()
{
    gl_PointSize = 20.;
    gl_Position = vec4(position.x, position.y, 0., 1.);
}
