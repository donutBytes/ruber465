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
#include <iostream>
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

//Camera indexes
const int FRONTCAMERAINDEX = 0;
const int TOPCAMERAINDEX = 1;
const int SHIPCAMERAINDEX = 2;
const int UNUMCAMERAINDEX = 3;
const int DUOCAMERAINDEX = 4;

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

float modelBR[totalModels];

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
glm::mat4 translationMatrix[totalModels];
glm::vec3 translatePosition[totalModels] = {
	glm::vec3(0, 0, 0),		    //ruber
	glm::vec3(4000, -50, 0),    //unum 
	glm::vec3(9000, 0 , 0),		//duo
	glm::vec3(8100, 0, 0),		//primus
	glm::vec3(7250, 0, 0),		//secundus
	glm::vec3(5000, 1000, 5000),//warbird
	glm::vec3(0, 0, 0),			//missile
	glm::vec3(0, 0, 0)			//missile
};

float rotationAmount[totalModels] = {
	0.0f,			//Ruber
	0.004f,			//Unum
	0.002f,			//Duo
	0.002f,			//Primus
	0.004f,			//Secundus
	0.0f,			//Warbird
	0.0f,			//Missile
	0.0f			//Missile
};

MoveableObj3D* obj3D[totalModels];

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

glm::mat4 modelMatrix[totalModels];		//set in display()
glm::mat4 viewMatrix;
glm::mat4 projectionMatrix;				//set in reshape()
glm::mat4 modelViewProjectionMatrix;	//set in display()

										//Camera

char* cameraNames[5] = { "Front Camera", "Top Camera", "Ship Camera", "Unum Camera", "Duo Camera" };
int currentCamera = 0;
int maxCameras = 5;

//Camera Matrices
glm::mat4 mainCamera;
glm::mat4 frontCamera;
glm::mat4 topCamera;
glm::mat4 shipCamera;
glm::mat4 unumCamera;
glm::mat4 duoCamera;

glm::vec3 upVector(0.0f, 1.0f, 0.0f);
glm::vec3 topVector(1.0f, 0.0f, 0.0f);
glm::vec3 shipPosition;
glm::vec3 shipCamEyePosition(0, 200, 500);
glm::vec3 planetCamEyePosition(0, 0.0f, -8000);
glm::vec3 topCamEyePosition(0, 20000.0f, 0);
glm::vec3 frontCamEyePosition(0.0f, 10000.0f, 20000.0f);
glm::vec3 camPosition;


//Planet rotational variables
GLfloat eyeDistanceMultiplier = 10.0f;
GLfloat eyeDistance;
glm::mat4 identityMatrix(1.0f);
glm::mat4 transformMatrix[totalModels];
glm::vec3 rotationalAxis(0.0f, 1.0f, 0.0f);

//Ship Global variables
Warbird* warbird;
glm::mat4 shipOrientationMatrix;
glm::vec3 shipUp(0.0f, 1.0f, 0.0f);
glm::vec3 shipRight(1.0f, 0.0f, 0.0f);
glm::vec3 shipLookingAt(0.0f, 0.0f, -1.0f);

//Missle Variables
MoveableObj3D* shipMissileObj;
Missile* shipMissile;

//Missile Variables
glm::mat4 missileLocation;
glm::mat4 targetLocation;
GLfloat length;
GLfloat unumLength;
GLfloat duoLength;
glm::vec3 targetPositionVector;
glm::vec3 missilePositionVector;

//Timer variables
int timerDelay = 5;	//A delay of 5 ms is 200 updates/second
int frameCount = 0;
int timeQuantumState = 0;
int timeQuantum[4] = { 5, 40, 100, 500 };
double currentTime;
double lastTime;
double timeInterval;
bool idleTimerFlag = false;

//Vertex Buffer and Array Objects
GLuint textIBO;
GLuint textBuf;
GLuint textVAO;

//Variables that reference texture information in the vertex and fragment shader programs
GLuint texturePosition;
GLuint vertexTextCoord;
GLuint isTexture;
GLuint texture;
GLuint Texture;
GLuint NormalMatrix;
GLuint ModelViewMatrix;
glm::mat3 normalMatrix;
glm::mat4 modelViewMatrix;
//glm::mat4 modelViewProjectionMatrix;

//Light Variables
GLuint Ruber;

//square information used to draw the square texture box for the program
//default rotation and translation matrices for the texture
glm::mat4 squareRotation = glm::mat4();
glm::mat4 translateSquare = glm::mat4();
const int numberOfSquares = 6;
float squareRotationAmount = 0.0f;	//default rotation amount

									//the order the vertices will be drawn
static const unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0
};

//the texture coordinates and order
static const GLfloat textCoords[] = {
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 0.0f
};

//location of the vertices
static const GLfloat squareVertices[16] = {
	-50000.0f, -50000.0f, 0.0f, 1.0f,
	50000.0f, -50000.0f, 0.0f, 1.0f,
	50000.0f, 50000.0f, 0.0f, 1.0f,
	-50000.0f, 50000.0f, 0.0f, 1.0f
};

//locations of each plane
glm::vec3 squareTranslationAmounts[6] = {
	glm::vec3(0.0f, 0.0f, -50000.0f),
	glm::vec3(0.0f, 0.0f, 50000.0f),
	glm::vec3(0.0f, -50000.0f, 0.0f),
	glm::vec3(0.0f, 50000.0f, 0.0f),
	glm::vec3(-50000.0f, 0.0f, 0.0f),
	glm::vec3(50000.0f, 0.0f, 0.0f)
};

//what axis to rotate each plane on
glm::vec3 squareRotationAxis[6] = {
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)
};

void init() {
	//Load shader programs
	shaderProgram = loadShaders(vertexShaderFile, fragmentShaderFile);
	glUseProgram(shaderProgram);

	//Generate VAOs and VBOs
	glGenVertexArrays(totalModels, VAO);
	glGenBuffers(totalModels, buffer);

	//Load the buffers from the model files
	for (int i = 0; i < totalModels; i++) {
		modelBR[i] = loadModelBuffer(modelFile[i], vertexCount[i], VAO[i], buffer[i], shaderProgram,
			vPosition[i], vColor[i], vNormal[i], "vPosition", "vColor", "vNormal");
		if (modelBR[i] == -1.0f) {
			printf("loadTriModel error: returned -1.0f \n");
			system("exit");
		}
		else
			printf("loaded %s model with %7.2f bounding radius \n", modelFile[i], modelBR[i]);

		//set scale for models given bounding radius
		scale[i] = glm::vec3(modelSize[i] / modelBR[i]);
	}

	MVP = glGetUniformLocation(shaderProgram, "ModelViewProjection");
	ModelViewMatrix = glGetUniformLocation(shaderProgram, "ModelViewMatrix");
	NormalMatrix = glGetUniformLocation(shaderProgram, "NormalMatrix");

	frontCamera = glm::lookAt(
		frontCamEyePosition,
		translatePosition[RUBERINDEX],
		upVector
	);

	topCamera = glm::lookAt(
		topCamEyePosition,
		translatePosition[RUBERINDEX],
		topVector
	);

	unumCamera = glm::lookAt(
		planetCamEyePosition,
		translatePosition[UNUMINDEX],
		upVector
	);

	duoCamera = glm::lookAt(
		planetCamEyePosition,
		translatePosition[DUOINDEX],
		upVector
	);

	shipCamera = glm::lookAt(
		shipCamEyePosition,
		translatePosition[SHIPINDEX],
		upVector
	);

	mainCamera = frontCamera;

	//set render state values
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

	//Create and set all the 3D objects
	for (int i = 0; i < totalModels; i++) {
		obj3D[i] = new MoveableObj3D(modelSize[i], modelBR[i]);
		obj3D[i]->setTranslationMatrix(translatePosition[i]);
		obj3D[i]->setRotationAmount(rotationAmount[i]);

		if (i == UNUMINDEX || i == DUOINDEX)
			obj3D[i]->setOrbit();
	}

	//Create the warbird
	warbird = new Warbird(modelSize[SHIPINDEX], modelBR[SHIPINDEX]);
	warbird->setTranslationMatrix(translatePosition[SHIPINDEX]);
	warbird->setRotationAmount(rotationAmount[SHIPINDEX]);
	warbird->setPosition(translatePosition[SHIPINDEX]);

	//Create the ship missile
	shipMissile = new Missile(modelSize[SHIPMISSILE], modelBR[SHIPMISSILE]);

	//set up the indices buffer
	glGenBuffers(1, &textIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, textIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//set up the vertex attributes
	glGenVertexArrays(1, &textVAO);
	glBindVertexArray(textVAO);

	//initialize a buffer object
	glGenBuffers(1, &textBuf);
	glBindBuffer(GL_ARRAY_BUFFER, textBuf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices) + sizeof(textCoords), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(squareVertices), squareVertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(squareVertices), sizeof(textCoords), textCoords);

	//set up vertex arrays
	texturePosition = glGetAttribLocation(shaderProgram, "vPosition");
	glVertexAttribPointer(texturePosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vertexTextCoord);

	vertexTextCoord = glGetAttribLocation(shaderProgram, "vTextCoord");
	glVertexAttribPointer(vertexTextCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(squareVertices)));
	glEnableVertexAttribArray(vertexTextCoord);

	//Set initial texture indicator to false
	//This variable indicates when the texture is being drawn
	isTexture = glGetUniformLocation(shaderProgram, "IsTexture");
	glUniform1ui(isTexture, false);

	//get elapsed time
	lastTime - glutGet(GLUT_ELAPSED_TIME);
}

void reshape(int width, int height) {
	float aspectRatio = (GLfloat)width / (GLfloat)height;
	float FOVY = glm::radians(60.0f);

	glViewport(0, 0, width, height);
	projectionMatrix = glm::perspective(FOVY, aspectRatio, 1.0f, 100000.0f);
	printf("reshape: FOVY = %5.2f, width = %4d height = %4d aspect = %5.2f \n",
		FOVY, width, height, aspectRatio);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Actually clears the window to color specified in glClearColor()
														//associate shader variables with vertex arrayshere
	for (int i = 0; i < totalModels; i++) {
		switch (i) {
		case UNUMINDEX:
			transformMatrix[i] = obj3D[i]->getOrientationMatrix();
			//Update Unum's camera
			unumCamera = glm::lookAt(getPosition(glm::translate(transformMatrix[i], planetCamEyePosition)), getPosition(transformMatrix[i]), upVector);
			if (currentCamera == UNUMCAMERAINDEX)
				mainCamera = unumCamera;
			break;

		case DUOINDEX:
			transformMatrix[i] = obj3D[i]->getOrientationMatrix();
			//Update Duo's camera
			duoCamera = glm::lookAt(getPosition(glm::translate(transformMatrix[i], planetCamEyePosition)), getPosition(obj3D[i]->getOrientationMatrix()), upVector);
			if (currentCamera == DUOCAMERAINDEX)
				mainCamera = duoCamera;
			break;
		case PRIMUSINDEX: //If it's Primus, one of the moons, orbit around the planet Duo
			transformMatrix[i] = transformMatrix[DUOINDEX] * obj3D[i]->getRotationMatrix() * glm::translate(identityMatrix, (translatePosition[SECUNDUSINDEX] - translatePosition[DUOINDEX]));
			obj3D[i]->setOrientationMatrix(transformMatrix[i]);
			break;
		case SHIPINDEX:
			obj3D[SHIPINDEX]->setTranslationMatrix(warbird->getTranslationMatrix());
			obj3D[SHIPINDEX]->setRotationMatrix(warbird->getRotationMatrix());
			obj3D[SHIPINDEX]->setRotationAmount(warbird->getRotationAmount());
			obj3D[SHIPINDEX]->setOrientationMatrix(warbird->getOrientationMatrix());

			modelMatrix[i] = obj3D[i]->getModelMatrix();
			shipOrientationMatrix = obj3D[i]->getOrientationMatrix();

			//update ship's camera
			camPosition = getPosition(glm::translate(obj3D[i]->getModelMatrix(), shipCamEyePosition));
			shipPosition = getPosition(shipOrientationMatrix);
			shipCamera = glm::lookAt(camPosition, glm::vec3(shipPosition.x, shipPosition.y, shipPosition.z), upVector);
			if (currentCamera == SHIPCAMERAINDEX)
				mainCamera = shipCamera;
			break;
		}

		viewMatrix = mainCamera;
		modelViewProjectionMatrix = projectionMatrix * viewMatrix * obj3D[i]->getModelMatrix();
		glUniformMatrix3fv(MVP, 1, GL_FALSE, glm::value_ptr(modelViewProjectionMatrix));
		modelViewMatrix = viewMatrix * obj3D[i]->getModelMatrix();
		normalMatrix = glm::mat3(modelViewMatrix);
		glUniformMatrix3fv(NormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
		glUniformMatrix4fv(ModelViewMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMatrix));
		if (i == 0)
			glUniform1ui(Ruber, true);
		else
			glUniform1ui(Ruber, false);

		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_TRIANGLES, 0, vertexCount[i]);
	}

	glUniform1ui(isTexture, true);
	for (int i = 0; i < numberOfSquares; i++) {
		if (i > 1)
			squareRotationAmount = PI / 2;
		else
			squareRotationAmount = 0.0f;
		modelViewMatrix = viewMatrix * glm::translate(translateSquare, squareTranslationAmounts[i]) * glm::rotate(squareRotation, squareRotationAmount, squareRotationAxis[i]);
		glUniformMatrix4fv(ModelViewMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMatrix));
		normalMatrix = glm::mat3(modelViewMatrix);
		glUniformMatrix3fv(NormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
		modelViewProjectionMatrix = projectionMatrix * modelViewMatrix;
		glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(modelViewProjectionMatrix));
		glBindVertexArray(textVAO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, textIBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	}

	glUniform1ui(isTexture, false);
	glutSwapBuffers();
	frameCount++;
	//see if a second has passed to set estimated fps information
	currentTime = glutGet(GLUT_ELAPSED_TIME); //get elapsed system time
	timeInterval = currentTime - lastTime;
	if (timeInterval >= 1000) {
		lastTime = currentTime;
		frameCount = 0;
	}
}

void switchCamera(int camera) {
	switch (camera) {
	case FRONTCAMERAINDEX:
		mainCamera = frontCamera;
		break;
	case TOPCAMERAINDEX:
		mainCamera = topCamera;
		break;
	case SHIPCAMERAINDEX:
		mainCamera = shipCamera;
		break;
	case UNUMCAMERAINDEX:
		mainCamera = unumCamera;
		break;
	case DUOCAMERAINDEX:
		mainCamera = duoCamera;
		break;
	default:
		return;
	}
	printf("Current Camera: %s\n", cameraNames[camera]);
	display();
}

void update(int i) {
	glutTimerFunc(timeQuantum[timeQuantumState], update, 1);

	//update all of the 
	for (int i = 0; i < totalModels; i++)
		obj3D[i]->update();

	//Update the Warbird object
	warbird->update();

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'v':
	case 'V':
		currentCamera = (currentCamera + 1) % maxCameras;
		switchCamera(currentCamera);
		break;
	case 'x':
	case 'X':
		if (currentCamera == 0)
			currentCamera = 5;
		currentCamera = (currentCamera - 1) % maxCameras;
		switchCamera(currentCamera);
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	//Configure glut options
	glutInitWindowSize(1024, 800);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Comp 465 Project 1: Phase 1");

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	//initialize scene
	init();

	//set glut callback functions
	glutDisplayFunc(display); //continuously called for interacting with the window
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutIdleFunc(NULL);
	glutTimerFunc(timeQuantum[timeQuantumState], update, 5);

	glutMainLoop(); //This call passes control to enter GLUT event processing cycle

	return 0;
}
