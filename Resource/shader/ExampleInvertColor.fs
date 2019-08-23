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
    //一半时间反色，一半时间不反色
    if (t>duration/2.0)
    {
        fragColor = texture(tex,v_texCoord);
    }
    else
    {
        //获取原始颜色
        vec4 color = texture(tex,v_texCoord);
        //用(1.0,1.0,1.0)减去原始颜色的RGB，但是alpha还是要保持1.0
        fragColor = vec4(vec3(1.0)-color.rgb,1.0);
    }
    
}
