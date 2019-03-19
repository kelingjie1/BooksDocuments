//声明shader的版本
#version 300 es
//定义shader中的变量
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 a_texCoord;
uniform mat4 vp;
uniform mat4 m;
out vec2 v_texCoord;

void main()
{
    //最终的位置
    vec4 pos = vp*m*vec4(position,1.);
    gl_Position = vec4(pos.x, pos.y, pos.z, pos.w);
    //将纹理坐标插值后传递给FragmentShader
    v_texCoord = a_texCoord;
}
