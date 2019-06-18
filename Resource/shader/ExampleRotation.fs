#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
uniform float time;
out vec4 fragColor;
void main()
{
    vec2 uv = vec2(v_texCoord.x-0.5,v_texCoord.y-0.5);
    float dis = distance(v_texCoord,vec2(0.5,0.5));
    float r = time/dis/100.0;
    //坐标旋转公式
    //x = x * cos(r) – y * sin(r)
    //y = x * sin(r) + y * cos(r)
    uv = vec2(uv.x*cos(r)-uv.y*sin(r),uv.x*sin(r)+uv.y*cos(r));
    uv = vec2(uv.x+0.5,uv.y+0.5);
    //不渲染超过显示区域的图片
    if (uv.x<0.0||uv.x>1.0||uv.y<0.0||uv.y>1.0)
    {
        discard;
    }
    fragColor = texture(tex,uv);
}
