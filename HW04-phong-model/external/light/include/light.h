#pragma once
#ifndef LIGHT_H
#define LIGHT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
using namespace std;
using namespace glm;

class Light
{
public:
	Shader* LightShader;
	string Name;
	vec3 Color;
	vec3 Position;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	Light(Shader& lightShader, const string& name, vec3 color, vec3 position, vec3 ambient, vec3 diffuse, vec3 specular)
	{
		LightShader = &lightShader;
		Name = name;
		Color = color;
		Position = position;
		Ambient = ambient;
		Diffuse = diffuse;
		Specular = specular;
	}
};

class DirLight :public Light
{
public:
	vec3 Direction;

	DirLight(Shader& lightShader, const string& name, vec3 color, vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular) :Light(lightShader, name, color, vec3(1.0), ambient, diffuse, specular)
	{
		Direction = direction;
	}

	void setDirLight()
	{
		(*LightShader).setVec3(Name + ".direction", Direction);
		(*LightShader).setVec3(Name + ".color", Color);
		(*LightShader).setVec3(Name + ".ambient", Ambient);
		(*LightShader).setVec3(Name + ".diffuse", Diffuse);
		(*LightShader).setVec3(Name + ".specular", Specular);
	}
};

class PointLight :public Light
{
public:
	float Constant;
	float Linear;
	float Quadratic;

	PointLight(Shader& lightShader, const string& name, vec3 color, vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic) :Light(lightShader, name, color, position, ambient, diffuse, specular) 
	{
		Constant = constant;
		Linear = linear;
		Quadratic = quadratic;
	}

	void setPointLight()
	{
		(*LightShader).setVec3(Name + ".position", Position);
		(*LightShader).setVec3(Name + ".color", Color);
		(*LightShader).setVec3(Name + ".ambient", Ambient);
		(*LightShader).setVec3(Name + ".diffuse", Diffuse);
		(*LightShader).setVec3(Name + ".specular", Specular);
		(*LightShader).setFloat(Name + ".constant", Constant);
		(*LightShader).setFloat(Name + ".linear", Linear);
		(*LightShader).setFloat(Name + ".quadratic", Quadratic);
	}
};

class SpotLight :public PointLight
{
public:
	vec3 Direction;
	float CutOff;
	float OuterCutOff;

	SpotLight(Shader& lightShader, const string& name, vec3 color, vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic, vec3 direction, float cutoff, float outerCutOff) :PointLight(lightShader, name, color, position, ambient, diffuse, specular, constant, linear, quadratic)
	{
		Direction = direction;
		CutOff = cutoff;
		OuterCutOff = outerCutOff;
	}

	void setSpotLight()
	{
		setPointLight();
		(*LightShader).setVec3(Name + ".direction", Direction);
		(*LightShader).setFloat(Name + ".cutOff", CutOff);
		(*LightShader).setFloat(Name + ".outerCutOff", OuterCutOff);
	}
};

#endif