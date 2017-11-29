/*
Alexander Bickham : alexander.bickham.885@my.csun.edu
Kyung Hyun Kim : kyunghyun.kim.970@my.csun.edu
Benjamin Overton : benjamin.overton.467@my.csun.edu
*/

#pragma once

#ifndef __INCLUDES465__
#define __Windows__
#include "../includes465/include465.hpp"
#include "MoveableObj3D.hpp"
#include "Warbird.hpp"
#include "Missile.hpp"
#endif

//model indexes
const int RUBERINDEX = 0;
const int UNUMINDEX = 1;
const int DUOINDEX = 2;
const int PRIMUSINDEX = 3;
const int SECUNDUSINDEX = 4;
const int SHIPINDEX = 5;
const int SHIPMISSILE = 6;
const int SHIPMISSILE2 = 7;

//Total number of models in the scene
const int totalModels = 8;

//AC3D TriModel names
char* modelFile[totalModels] = {
	"ruber.tri",
	"unum.tri",
	"duo.tri",
	"primus.tri",
	"secendus.tri",
	"warbird.tri",
	"missile.tri",
	"missile.tri"
};

float modelBR[totalModels];
float scaleValue[totalModels];

int vertexCount[totalModels]{
	264 * 3,	//ruber
	264 * 3,	//unum
	264 * 3,	//duo
	1104 * 3,	//primus
	264 * 3,	//secundus
	617 * 3,	//warbird
	927 * 3,	//ship missile
	927 * 3		//ship missile
};

//Shader handles, matrices, etc
char* vertexShaderFile = "simpleVertex.glsl";
char* fragmentShaderFile = "simpleFragment.glsl";

GLuint shaderProgram;
GLuint VAO[totalModels];		//Vertex Array Objects
GLuint buffer[totalModels];		//Vertex Buffer Objects

GLuint MVP;						//Model View Projection Matrix's handle
GLuint vPosition[totalModels];
GLuint vColor[totalModels];
GLuint vNormal[totalModels];

float modelSize[totalModels] = {
	2000.0f,	//ruber
	200.0f,		//unum
	400.0f,		//duo
	100.0f,		//primus
	150.0f,		//secundus
	100.0f,		//warbird
	75.0f,		//ship missile
	75.0f		//ship missile
};

glm::vec3 scale[totalModels];

glm::vec3 translatePosition[totalModels] = {
	glm::vec3(0, 0, 0),				//ruber
	glm::vec3(4000, 0, 0),			//unum 
	glm::vec3(9000, 0 , 0),			//duo
	glm::vec3(11000, 0, 0),			//primus
	glm::vec3(13000, 0, 0),			//secundus
	glm::vec3(15000, 1000, 5000),	//warbird
	glm::vec3(14500, 0, 0),			//missile
	glm::vec3(14500, 0, 0)			//missile
};

glm::mat4 modelMatrix[totalModels];		//set in display()
glm::mat4 viewMatrix;
glm::mat4 projectionMatrix;				//set in reshape()
glm::mat4 ModelViewProjectionMatrix;	//set in display()

// window title strings
char baseStr[50] = "Ruber: ";
char viewStr[15] = "Front View";
char titleStr[100];

void reshape(int width, int height) {
	float aspectRatio = (GLfloat)width / (GLfloat)height;
	float FOVY = glm::radians(60.0f);

	glViewport(0, 0, width, height);
	projectionMatrix = glm::perspective(FOVY, aspectRatio, 1.0f, 100000.0f);
	printf("reshape: FOVY = %5.2f, width = %4d height = %4d aspect = %5.2f \n",
		FOVY, width, height, aspectRatio);
}

}
