precision highp float;
in vec2 v_texCoord;
uniform sampler2D tex;
out vec4 fragColor;
void main()
{
    fragColor = texture(tex,v_texCoord);
}
