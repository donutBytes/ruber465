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

MoveableObj3D * object3d[totalModels];

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

//Warbird
Warbird * warbird;

glm::vec3 translatePosition[totalModels] = {
	glm::vec3(0, 0, 0),				//ruber
	glm::vec3(4000, 0, 0),			//unum 
	glm::vec3(9000, 0 , 0),			//duo
	glm::vec3(11000, 0, 0),			//primus
	glm::vec3(13000, 0, 0),			//secundus
	glm::vec3(15000, 0, 0),			//warbird
	glm::vec3(14500, 0, 0),			//missile
	glm::vec3(14500, 0, 0)			//missile
};

// Planet rotational Variables
glm::mat4 transformMatrix[totalModels];
glm::mat4 identityMatrix(1.0f); // initialized identity matrix.

float rotationAmount[totalModels] = {
	0.0f,		// Ruber
	0.004f,		// Unum
	0.002f,		// Duo
	0.004f,		// Primus
	0.002f,		// Secundus
	0.0f,		// Warbird
	0.0f,		// Missile
	0.0f		// Missile
};

glm::mat4 modelMatrix[totalModels];		//set in display()
glm::mat4 viewMatrix;					//set in init()
glm::mat4 projectionMatrix;				//set in reshape()
glm::mat4 ModelViewProjectionMatrix;	//set in display()

										// Cameras
const int totalCameras = 5;

const int FRONTCAMINDEX = 0;
const int TOPCAMINDEX = 1;
const int SHIPCAMINDEX = 2;
const int UNUMCAMINDEX = 3;
const int DUOCAMINDEX = 4;

char* cameraNames[totalCameras] = {
	"Front Camera",
	"Top Camera",
	"Ship Camera",
	"Unum Camera",
	"Duo Camera" };

glm::mat4 camera;

glm::mat4 frontCamera = glm::lookAt(
	glm::vec3(0.0f, 10000.0f, 20000.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)
);

glm::mat4 topCamera = glm::lookAt(
	glm::vec3(0, 20000.0f, 0),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, -1.0f)
);

glm::mat4 shipCamera = glm::lookAt(
	translatePosition[SHIPINDEX] + glm::vec3(0.0f, 300.0f, 1000.0f),
	translatePosition[SHIPINDEX] + glm::vec3(0.0f, 300.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)
);

glm::vec3 unumEye = translatePosition[UNUMINDEX] + (-4000.0f, 0.0f, -4000.0f);
glm::vec3 unumAt = translatePosition[UNUMINDEX];

glm::mat4 unumCamera = glm::lookAt(
	unumEye,
	unumAt,
	glm::vec3(0.0f, 1.0f, 0.0f)
);

glm::vec3 duoEye = translatePosition[DUOINDEX] + (-4000.0f, 0.0f, -4000.0f);
glm::vec3 duoAt = translatePosition[DUOINDEX];

glm::mat4 duoCamera = glm::lookAt(
	duoEye,
	duoAt,
	glm::vec3(0.0f, 1.0f, 0.0f)
);

glm::mat4 cameras[totalCameras] =
{
	frontCamera,
	topCamera,
	shipCamera,
	unumCamera,
	duoCamera
};

// Set the default camera to the front camera.

int currentCamera = FRONTCAMINDEX;

// window title strings
char baseStr[50] = "Ruber: ";
char viewStr[15] = "Front Camera";
char titleStr[100];

// Variables for shader
glm::mat3 normalMatrix;
glm::mat4 modelViewMatrix;
GLuint NormalMatrix;
GLuint ModelViewMatrix;


/* init */
void init() {
	//Load shader programs
	shaderProgram = loadShaders(vertexShaderFile, fragmentShaderFile);
	glUseProgram(shaderProgram);

	//Generate VAOs and VBOs
	glGenVertexArrays(totalModels, VAO);
	glGenBuffers(totalModels, buffer);

	///Load the buffers from the model files
	for (int i = 0; i < totalModels; i++) {
		modelBR[i] = loadModelBuffer(modelFile[i], vertexCount[i], VAO[i], buffer[i], shaderProgram,
			vPosition[i], vColor[i], vNormal[i], "vPosition", "vColor", "vNormal");

		//set scale for models given bounding radius
		scale[i] = glm::vec3(modelSize[i] / modelBR[i]);
	}

	MVP = glGetUniformLocation(shaderProgram, "ModelViewProjection");
	// ModelViewMatrix = glGetUniformLocation(shaderProgram, "ModelViewMatrix");
	// NormalMatrix = glGetUniformLocation(shaderProgram, "NormalMatrix");

	///set render state values
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

	/// Create and set all the 3D objects:
	for (int i = 0; i < totalModels; i++)
	{
		object3d[i] = new MoveableObj3D(modelSize[i], modelBR[i]);
		object3d[i]->setTranslationMatrix(translatePosition[i]);
		object3d[i]->setRotationAmount(rotationAmount[i]);

		/// Set the planet flags:
		if (i == UNUMINDEX || i == DUOINDEX)
			object3d[i]->setOrbit();
	}

	/// Create the warbird:
	warbird = new Warbird(modelSize[SHIPINDEX], modelBR[SHIPINDEX], translatePosition[SHIPINDEX]);
	warbird->setTranslationMatrix(translatePosition[SHIPINDEX]);
	warbird->setRotationAmount(rotationAmount[SHIPINDEX]);
	warbird->setPosition(translatePosition[SHIPINDEX]);

}

void reshape(int width, int height) {
	float aspectRatio = (GLfloat)width / (GLfloat)height;
	float FOVY = glm::radians(60.0f);

	glViewport(0, 0, width, height);
	projectionMatrix = glm::perspective(FOVY, aspectRatio, 1.0f, 100000.0f);
	printf("reshape: FOVY = %5.2f, width = %4d height = %4d aspect = %5.2f \n",
		FOVY, width, height, aspectRatio);
}

// update and display animation state in window title
void updateTitle() {
	strcpy(titleStr, baseStr);
	strcat(titleStr, viewStr);

	glutSetWindowTitle(titleStr);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 033: case 'q':  case 'Q':
		exit(EXIT_SUCCESS);
		break;

	case 'v': case 'V':
		currentCamera = ((currentCamera + 1) % totalCameras);
		strcpy(viewStr, cameraNames[currentCamera]);
		break;

	case 'x': case 'X':
		currentCamera = currentCamera==0 ? currentCamera = totalCameras-1 : ((currentCamera - 1) % totalCameras);
		strcpy(viewStr, cameraNames[currentCamera]);
		break;
	}

	updateTitle();
}

/* display */

void display() {
	//printf("display\t");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Actually clears the window to color specified in glClearColor()
														//associate shader variables with vertex arrayshere

	for (int i = 0; i < totalModels; i++)
	{
		switch (i)
		{
		case UNUMINDEX: // If it's planet Unum (planet closest to Ruber with no moons):
			transformMatrix[i] = object3d[i]->getOrientationMatrix();
			if (currentCamera == UNUMCAMINDEX)
			{
				cameras[UNUMCAMINDEX] = glm::lookAt(
					getPosition(glm::translate(transformMatrix[i], unumEye)),
					getPosition(transformMatrix[UNUMINDEX]),
					glm::vec3(0.0f, 1.0f, 0.0f)
				);
			}
			break;

		case DUOINDEX: // If it's planet Duo (planest farthest from Ruber with moons Secundus and Primus):
			transformMatrix[i] = object3d[i]->getOrientationMatrix();
			if (currentCamera == DUOCAMINDEX)
			{
				cameras[DUOCAMINDEX] = glm::lookAt(
					getPosition(glm::translate(transformMatrix[i], duoEye)),
					getPosition(transformMatrix[DUOINDEX]),
					glm::vec3(0.0f, 1.0f, 0.0f)
				);
			}
			break;

		case PRIMUSINDEX: // If its Primus, one of the moons, orbit around planet Duo.
			transformMatrix[i] =
				transformMatrix[DUOINDEX] *
				object3d[i]->getRotationMatrix() *
				glm::translate(
					identityMatrix,
					(translatePosition[i] - translatePosition[DUOINDEX])
				);
			object3d[i]->setOrientationMatrix(transformMatrix[i]);

			// For Debugging:
			//showMat4("rotation", moonRotationMatrix);
			showMat4("transform", transformMatrix[i]);
			break;

		case SECUNDUSINDEX: // If its Secundus, one of the moons, orbit around planet Duo.
			transformMatrix[SECUNDUSINDEX] =
				transformMatrix[DUOINDEX] *
				object3d[i]->getRotationMatrix() *
				glm::translate(
					identityMatrix,
					(translatePosition[SECUNDUSINDEX] - translatePosition[DUOINDEX])
				);
			object3d[i]->setOrientationMatrix(transformMatrix[i]);

			break;

		default:
			break;
		}

		viewMatrix = cameras[currentCamera];

		ModelViewProjectionMatrix = projectionMatrix * cameras[currentCamera] * object3d[i]->getModelMatrix();
		modelMatrix[i] = glm::translate(glm::mat4(), translatePosition[i]) * glm::scale(glm::mat4(), glm::vec3(scale[i]));
		glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(ModelViewProjectionMatrix));
		modelViewMatrix = viewMatrix * object3d[i]->getModelMatrix();
		normalMatrix = glm::mat3(modelViewMatrix);
		glUniformMatrix3fv(NormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
		glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(ModelViewProjectionMatrix));


		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_TRIANGLES, 0, vertexCount[i]);
	}

	glutSwapBuffers();
	updateTitle();
}

/* update */
void update(int i) {
	glutTimerFunc(5, update, 1);

	// Update all of the object3D's
	for (int index = 0; index < totalModels; index++) {
		object3d[index]->update();
		//printf("rotation: %f\n", object3d[index]->getRotationAmount());
	}

	// Update the warbird object
	warbird->update();

	glutPostRedisplay();
}

/* main */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	//Configure glut options
	glutInitWindowSize(800, 600);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//testing
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Ruber: Front Camera");

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	//initialize scene
	init();

	//set glut callback functions
	glutDisplayFunc(display); //continuously called for interacting with the window
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutIdleFunc(NULL);
	glutTimerFunc(5, update, 1);

	glutMainLoop(); //This call passes control to enter GLUT event processing cycle

	return 0;
}