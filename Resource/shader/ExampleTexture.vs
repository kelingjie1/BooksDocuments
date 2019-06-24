//声明shader的版本
#version 300 es
//定义shader中的变量
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 a_texCoord;

out vec2 v_texCoord;
void main()
{
    //最终的位置
    gl_Position = vec4(position.x, position.y, 0., 1.);
    //将纹理坐标插值后传递给FragmentShader
    v_texCoord = a_texCoord;
}
