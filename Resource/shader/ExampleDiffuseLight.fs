precision highp float;
in vec2 v_texCoord;
in float scale;
uniform sampler2D tex;
out vec4 fragColor;
void main()
{
    fragColor = texture(tex,v_texCoord)*scale;
}
