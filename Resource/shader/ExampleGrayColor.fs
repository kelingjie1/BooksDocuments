#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
uniform float time;
out vec4 fragColor;
float duration = 10.0;
void main()
{
    //计算时间
    float t = mod(time,duration);
    //一半时间反色，一半时间不灰度
    if (t>duration/2.0)
    {
        fragColor = texture(tex,v_texCoord);
    }
    else
    {
        //获取原始颜色
        vec4 color = texture(tex,v_texCoord);
        //Gray = R*0.299 + G*0.587 + B*0.114
        float gray = color.r*0.299+color.g*0.587+color.b*0.114;
        fragColor = vec4(gray, gray, gray, 1.0);
    }
    
}
