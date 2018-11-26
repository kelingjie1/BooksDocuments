#version 300 es
precision highp float;
in vec2 v_texCoord;

uniform vec2 pos;
uniform vec2 viewSize;
uniform sampler2D tex;

out vec4 fragColor;
float scale = 2.0;
void main()
{
    vec2 uv = vec2(v_texCoord.x*viewSize.x,v_texCoord.y*viewSize.y);
    vec2 p = vec2(pos.x*viewSize.x,pos.y*viewSize.y);
    float dis = distance(uv,p);
    if (dis<100.0)
    {
        uv = vec2((uv.x-p.x)/scale+p.x,(uv.y-p.y)/scale+p.y);
    }
    else if (dis<105.0)
    {
        fragColor = vec4(0.0,0.0,0.0,1.0);
        return;
    }
    fragColor = texture(tex,vec2(uv.x/viewSize.x,uv.y/viewSize.y));
}
