#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
uniform float time;
out vec4 fragColor;
float duration = 10.0;
float pi = 3.1415926;

vec3 blend(vec4 dstColor,vec4 srcColor)
{
    return srcColor.rgb * srcColor.a + dstColor.rgb * (1.0 - srcColor.a);
}

vec4 getColor(float offset)
{
    vec2 vec = vec2(0.0,0.1);
    float r = time+offset;
    vec = vec2(vec.x*cos(r)-vec.y*sin(r),vec.x*sin(r)+vec.y*cos(r));
    vec2 uv = v_texCoord+vec;
    return texture(tex,uv);
}

void main()
{
    
    //获取原始颜色
    float r = getColor(0.).r;
    float g = getColor(pi*2./3.).g;
    float b = getColor(pi*4./3.).b;
    fragColor = vec4(r, g, b, 1.0);
    
}
