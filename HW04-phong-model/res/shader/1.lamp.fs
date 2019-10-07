#version 330 core
out vec4 FragColor;

uniform vec3 fragcolor;

void main()
{
    // FragColor = vec4(1.0); // set alle 4 vector values to 1.0
	FragColor = vec4(fragcolor, 1.0);
}