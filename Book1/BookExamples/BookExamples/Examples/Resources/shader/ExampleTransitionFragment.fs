#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
uniform float time;
out vec4 fragColor;
float duration = 10.0;
float lineCount = 40.0;
void main()
{
    //计算时间
    float t = mod(time,duration);
    //一半时间正向运动，一半时间反向运动
    if (t>duration/2.0)
    {
        t = duration - t;
    }
    //计算每行的归一化高度
    float lineHeight = 1.0/lineCount;
    //计算平移之后的纹理坐标
    vec2 uv = v_texCoord;
    if (mod(uv.y,lineHeight*2.0)<lineHeight)
    {
        uv.x-=t/duration;
    }
    else
    {
        uv.x+=t/duration;
    }
    //不渲染超过显示区域的图片
    if (uv.x<0.0||uv.x>1.0||uv.y<0.0||uv.y>1.0)
    {
        discard;
    }
    fragColor = texture(tex,uv);
}
