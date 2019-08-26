//定义shader中的变量
precision highp float;
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 a_texCoord;
layout(location = 2) in vec3 normal;
uniform mat4 vp;
uniform mat4 m;
out vec2 v_texCoord;
out float scale;

void main()
{
    //最终的位置
    vec4 pos = vp*m*vec4(position,1.);
    gl_Position = vec4(pos.x, pos.y, pos.z, pos.w);
    //将纹理坐标插值后传递给FragmentShader
    v_texCoord = a_texCoord;
    vec4 norm = normalize(m*vec4(normal,0.));

    vec3 lightDir = normalize(vec3(-1.0,-1.0,0.0));
    float diffuse = 0.8;

    scale = length(normal);
    float diff = max(dot(norm.xyz,lightDir), 0.0);
    scale = diffuse * diff+0.1;
}
