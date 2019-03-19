#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
//帧所在的列
uniform float x;
//帧所在的行
uniform float y;
//每帧宽度，0~1
uniform float width;
//每帧高度，0~1
uniform float height;

out vec4 fragColor;
void main()
{
    fragColor = texture(tex,vec2((v_texCoord.x+x)*width,1.0-(v_texCoord.y+y)*height));
}
