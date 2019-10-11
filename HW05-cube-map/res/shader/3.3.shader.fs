#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D textureID;

void main()
{
    //FragColor = mix(texture(textureID, TexCoord), texture(texture2, TexCoord), 0.2);
    FragColor = texture(textureID, TexCoord);
}