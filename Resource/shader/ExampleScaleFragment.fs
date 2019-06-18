#version 300 es
precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
uniform float scale;
out vec4 fragColor;
void main()
{
    //计算缩放之后的纹理坐标
    vec2 uv = vec2((v_texCoord.x-0.5)/scale+0.5,(v_texCoord.y-0.5)/scale+0.5);
    //不渲染超过缩放之后显示区域的图片
    if (uv.x<0.0||uv.x>1.0||uv.y<0.0||uv.y>1.0)
    {
        discard;
    }
    fragColor = texture(tex,uv);
}
