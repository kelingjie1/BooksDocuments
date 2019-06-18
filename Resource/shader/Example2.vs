//声明shader的版本
#version 300 es
//定义shader中的变量
layout(location = 0) in vec2 position;
void main()
{
    //点的大小
    gl_PointSize = 20.;
    //最终的位置
    gl_Position = vec4(position.x, position.y, 0., 1.);
}
