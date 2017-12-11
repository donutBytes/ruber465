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
const int UNUMMISSILESITEINDEX = 7;
const int SECUNDUSMISSILESITEINDEX = 8;

//Total number of models in the scene
const int totalModels = 9;

//AC3D TriModel names
char* modelFile[totalModels] = {
	"ruber.tri",
	"unum.tri",
	"duo.tri",
	"primus.tri",
	"secendus.tri",
	"warbird.tri",
	"missile.tri",
	"missileSite.tri",
	"missileSite.tri"
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
	108 * 3,	//Unum missile site
	108 * 3		//secundus missile site
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
	75.0f,		//unum missile site
	75.0f		//secundus mmissile site
};

glm::vec3 scale[totalModels];

glm::vec3 translatePosition[totalModels] = {
	glm::vec3(0, 0, 0),				//ruber
	glm::vec3(4000, 0, 0),			//unum 
	glm::vec3(9000, 0, 0),			//duo
	glm::vec3(11000, 0, 0),			//primus
	glm::vec3(13000, 0, 0),			//secundus
	glm::vec3(15000, 0, 0),			//warbird
	glm::vec3(14500, 0, 0),			//missile
	glm::vec3(4000, 50, 0),			// Unum missile Site
	glm::vec3(13000, 150, 0)		// Secundus Missile site
};

// Planet rotational Variables
glm::mat4 transformMatrix[totalModels];
glm::mat4 identityMatrix(1.0f);

float rotationAmount[totalModels] = {
	0.0f,		// Ruber
	0.004f,		// Unum
	0.002f,		// Duo
	0.004f,		// Primus
	0.002f,		// Secundus
	0.02f,		// Warbird
	0.0f,		// Ship Missile
	0.004f,		// Unum Missile Site
	0.002f		// Secundus Missile Site
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

// Setting Front camera
glm::mat4 frontCamera = glm::lookAt(
	glm::vec3(0.0f, 10000.0f, 20000.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)
);
// Setting Top Camera
glm::mat4 topCamera = glm::lookAt(
	glm::vec3(0, 20000.0f, 0),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, -1.0f)
);
// Setting Ship Camera
glm::mat4 shipCamera = glm::lookAt(
	translatePosition[SHIPINDEX] + glm::vec3(0.0f, 300.0f, 1000.0f),
	translatePosition[SHIPINDEX] + glm::vec3(0.0f, 300.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)
);
// Seeting Unum Camera
glm::vec3 unumEye = translatePosition[UNUMINDEX] + (-4000.0f, 0.0f, -4000.0f);
glm::vec3 unumAt = translatePosition[UNUMINDEX];
glm::mat4 unumCamera = glm::lookAt(
	unumEye,
	unumAt,
	glm::vec3(0.0f, 1.0f, 0.0f)
);
// Setting Duo Camera
glm::vec3 duoEye = translatePosition[DUOINDEX] + (-4000.0f, 0.0f, -4000.0f);
glm::vec3 duoAt = translatePosition[DUOINDEX];
glm::mat4 duoCamera = glm::lookAt(
	duoEye,
	duoAt,
	glm::vec3(0.0f, 1.0f, 0.0f)
);

// Create an array of cameras to iterate through
glm::mat4 cameras[totalCameras] = {
	frontCamera,
	topCamera,
	shipCamera,
	unumCamera,
	duoCamera
};

// Set the default camera to the front camera.
int currentCamera = FRONTCAMINDEX;

// Camera Variables
glm::vec3 upVector(0.0f, 1.0f, 0.0f);
glm::vec3 topVector(1.0f, 0.0f, 0.0f);
glm::vec3 warbirdLocation;
glm::vec3 shipCamEyePosition(0, 200, 500);
glm::vec3 planetCamEyePosition(0, 0.0f, -8000);
glm::vec3 topCamEyePosition(0, 20000.0f, 0);
glm::vec3 frontCamEyePosition(0.0f, 10000.0f, 20000.0f);
glm::vec3 camPosition;

// Warbird variables
Warbird * warbird;
int shipSpeedState = 0;
int totalSpeeds = 3;
float shipSpeed[3] = {10.0f, 50.0f, 200.0f};
int shipMissileCount = 9;
glm::mat4 shipOrientationMatrix;
glm::vec3 shipUp(0.0f, 1.0f, 0.0f);
glm::vec3 shipRight(1.0f, 0.0f, 0.0f);
glm::vec3 shipLookingAt(0.0f, 0.0f, -1.0f);

// Ship Missle Variables
float shipMissleSpeed = 20;
Missile * shipMissile;
int shipTargetIndex;

// General Missile Variables 
glm::mat4 missileLocation;
glm::mat4 targetLocation;
float length;
float unumDistance;
float secundusDistance;
glm::vec3 targetPositionVector;
glm::vec3 missilePositionVector;
const int missleLifetime = 2000;
const int missileActivationTimer = 200;
float detectionRadius = 5000.0f; // or 25?

// Missle Site Variables
int unumMissileCount = 5;
int secundusMissileCount = 5;
float enemyMissileSpeed = 5;
bool unumSiteAlive = true;
bool duoSiteAlive = true;

// Warping
int warpIndex = 0;
const int maxWarpSpots = 3;
glm::vec3 warpLocation(1000, 0.0f, -3000);

// window title strings
double currentTime, lastTime, timeInterval;
int frameCount = 0;
int quantumIndex = 0;
int timeQuantum[4] = { 5, 40, 100, 500 }; 

char baseStr[50] = "Ruber: ";
char shipMissileStr[14] = " Warbird 9";
char unumMissileStr[11] = " Unum 5";
char secundusMissileStr[15] = " Duo 5";
char * timerStr[4] = { " U/S 200 ", " U/S 25 ", " U/S 10 ", " U/S 2 " };
char fpsStr[15];
char viewStr[30] = "  View: Front Camera";

char titleStr[100];

// Variables for shader
glm::mat3 normalMatrix;
glm::mat4 modelViewMatrix;
GLuint NormalMatrix;
GLuint ModelViewMatrix;

// Helper functions for initialization
void createWarbird() {
	warbird = new Warbird(modelSize[SHIPINDEX], modelBR[SHIPINDEX], translatePosition[SHIPINDEX]);
	warbird->setTranslationMatrix(translatePosition[SHIPINDEX]);
	warbird->setRotationAmount(rotationAmount[SHIPINDEX]);
	warbird->setPosition(translatePosition[SHIPINDEX]);
}
void createMissiles() {
	// Create the ship missle:
	shipMissile = new Missile(modelSize[SHIPMISSILE], modelBR[SHIPMISSILE], shipMissleSpeed);
}

// Initialization function
void init() {
	shaderProgram = loadShaders(vertexShaderFile, fragmentShaderFile);
	glUseProgram(shaderProgram);

	glGenVertexArrays(totalModels, VAO);
	glGenBuffers(totalModels, buffer);

	// Load the buffers from the model files
	for (int i = 0; i < totalModels; i++) {
		modelBR[i] = loadModelBuffer(modelFile[i], vertexCount[i], VAO[i], buffer[i], shaderProgram,
			vPosition[i], vColor[i], vNormal[i], "vPosition", "vColor", "vNormal");

		//set scale for models given bounding radius
		scale[i] = glm::vec3(modelSize[i] / modelBR[i]);
	}

	MVP = glGetUniformLocation(shaderProgram, "ModelViewProjection");

	// set render state values
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

	// Create and set all the 3D objects:
	for (int i = 0; i < totalModels; i++)
	{
		object3d[i] = new MoveableObj3D(modelSize[i], modelBR[i]);
		object3d[i]->setTranslationMatrix(translatePosition[i]);
		object3d[i]->setRotationAmount(rotationAmount[i]);
	}

	object3d[UNUMINDEX]->setOrbit();
	object3d[DUOINDEX]->setOrbit();

	// Initialize the warbird:
	createWarbird();

	// Initialize missile objects
	createMissiles();
}

void reshape(int width, int height) {
	float aspectRatio = (GLfloat)width / (GLfloat)height;
	float FOVY = glm::radians(60.0f);

	glViewport(0, 0, width, height);
	projectionMatrix = glm::perspective(FOVY, aspectRatio, 1.0f, 100000.0f);
}

// update and display animation state in window title
void updateTitle() {
	strcpy(titleStr, baseStr);
	strcat(titleStr, shipMissileStr);
	strcat(titleStr, unumMissileStr);
	strcat(titleStr, secundusMissileStr);
	strcat(titleStr, timerStr[quantumIndex]);
	strcat(titleStr, fpsStr);

	strcat(titleStr, viewStr);

	glutSetWindowTitle(titleStr);
}

// Warps the warbird to its Unum, Duo, and its original location
void warp() {
	warpIndex = (warpIndex + 1) % maxWarpSpots;

	if (warpIndex == 0) {
		warbird->setTranslationMatrix(
			glm::translate(
				identityMatrix,
				translatePosition[SHIPINDEX]
			)
		);
		warbird->setRotationMatrix(
			glm::rotate(
				identityMatrix,
				0.0f,
				glm::vec3(0, 1, 0)
			)
		);
	}
	else {
		warbird->setTranslationMatrix(
			glm::translate(
				identityMatrix,
				getPosition(
					glm::translate(
						transformMatrix[warpIndex],
						planetCamEyePosition
					)
				)
			)
		);
		warbird->setRotationMatrix(
			glm::rotate(
				object3d[warpIndex]->getRotationMatrix(),
				PI,
				glm::vec3(0, 1, 0)
			)
		);
	}
}

// Method to handle the logic for when the ship fires a missle.
void fireShipMissile() {
	if (shipMissile->hasFired() == false) {
		if (shipMissileCount > 0) {
			printf("firing ship missile\n");
			
			// Set the orientation of the missile
			shipMissile->setTranslationMatrix(warbird->getTranslationMatrix());
			shipMissile->setRotationMatrix(warbird->getRotationMatrix());
			shipMissile->setDirection(getIn(warbird->getRotationMatrix()));

			shipMissile->fireMissile();
			shipMissileCount--;

			// Update title string for missle count
			sprintf(shipMissileStr, " Warbird %i", shipMissileCount);
		}
	}
}

// Handles button presses
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
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

		case 't': case'T':
			quantumIndex > 2 ? quantumIndex = 0 : quantumIndex++;
			break;

		case 's': case 'S':
			shipSpeedState = (shipSpeedState + 1) % totalSpeeds;
			warbird->setSpeed(shipSpeed[shipSpeedState]);
			break;

		case 'w': case'W':
			warp();
			break;

		case 'f': case'F':
			fireShipMissile();
			break;
	}

	updateTitle();
}

// Handles Warbird control
void handleShipMovement(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		(glutGetModifiers() == GLUT_ACTIVE_CTRL) 
			? warbird->setPitch(1) 
			: warbird->setMove(-1);
	}
	if (key == GLUT_KEY_DOWN) {
		(glutGetModifiers() == GLUT_ACTIVE_CTRL) 
			? warbird->setPitch(-1) 
			: warbird->setMove(1);
	}
	if (key == GLUT_KEY_LEFT) {
		(glutGetModifiers() == GLUT_ACTIVE_CTRL) 
			? warbird->setRoll(1) 
			: warbird->setYaw(1);
	}
	if (key == GLUT_KEY_RIGHT) {
		(glutGetModifiers() == GLUT_ACTIVE_CTRL) 
			? warbird->setRoll(-1) 
			: warbird->setYaw(-1);
	}
}


void handleMissiles() {
	// Check to see the update count of the ship missile before activating smart.
	if (shipMissile->hasFired()) {
		if (shipMissile->getUpdateFrameCount() > missileActivationTimer) {
			shipMissile->makeSmart();
		}
	}

	// SHIP MISSILE:
	if (shipMissile->hasFired()) {
		if (shipMissile->isSmart()) {
			if (!shipMissile->isTargetLocked()) {
				// Get the distance from Unum
				missileLocation = shipMissile->getOrientationMatrix();
				targetLocation = object3d[UNUMMISSILESITEINDEX]->getOrientationMatrix();
				missilePositionVector = getPosition(missileLocation);
				targetPositionVector = getPosition(targetLocation);
				unumDistance = distance(missilePositionVector, targetPositionVector);

				// Get the distance from Duo
				missileLocation = shipMissile->getOrientationMatrix();
				targetLocation = object3d[SECUNDUSMISSILESITEINDEX]->getOrientationMatrix();
				missilePositionVector = getPosition(missileLocation);
				targetPositionVector = getPosition(targetLocation);
				secundusDistance = distance(missilePositionVector, targetPositionVector);

				if (unumDistance <= secundusDistance) {
					shipTargetIndex = UNUMMISSILESITEINDEX;
					shipMissile->setTarget(object3d[shipTargetIndex]->getOrientationMatrix());
					printf("Ship Missile Target is UNUM Missile Site \n");
				}
				else if (unumDistance > secundusDistance) {
					shipTargetIndex = SECUNDUSMISSILESITEINDEX;
					shipMissile->setTarget(object3d[shipTargetIndex]->getOrientationMatrix());
					printf("Ship Missile Target is DUO Missile Site \n");
				}
			}
			else
				shipMissile->setTarget(object3d[shipTargetIndex]->getOrientationMatrix());
		}
	}

	else
		shipMissile->setOrientationMatrix(glm::translate(warbird->getOrientationMatrix(), glm::vec3(-33, 0, -30)));

	shipMissile->update();
}

// Display function, last step before sending it to the graphics processor
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	for (int i = 0; i < totalModels; i++) {
		switch (i) {
			case UNUMINDEX: 
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

			case DUOINDEX: 
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

			case PRIMUSINDEX:
				transformMatrix[i] =
					transformMatrix[DUOINDEX] *
					object3d[i]->getRotationMatrix() *
					glm::translate(
						identityMatrix,
						(translatePosition[i] - translatePosition[DUOINDEX])
					);
				object3d[i]->setOrientationMatrix(transformMatrix[i]);


				break;

			case SECUNDUSINDEX:
				transformMatrix[SECUNDUSINDEX] =
					transformMatrix[DUOINDEX] *
					object3d[i]->getRotationMatrix() *
					glm::translate(
						identityMatrix,
						(translatePosition[SECUNDUSINDEX] - translatePosition[DUOINDEX])
					);
				object3d[i]->setOrientationMatrix(transformMatrix[i]);

				object3d[SECUNDUSMISSILESITEINDEX]->setTranslationMatrix(object3d[SECUNDUSINDEX]->getTranslationMatrix());
				object3d[SECUNDUSMISSILESITEINDEX]->setOrientationMatrix(object3d[SECUNDUSINDEX]->getRotationMatrix());
				object3d[SECUNDUSMISSILESITEINDEX]->setTranslationMatrix(glm::translate(object3d[SECUNDUSINDEX]->getTranslationMatrix(), glm::vec3(0, 400, 0)));
				transformMatrix[SECUNDUSMISSILESITEINDEX] = glm::translate(object3d[SECUNDUSINDEX]->getOrientationMatrix(), glm::vec3(0, 400, 0));
				object3d[SECUNDUSMISSILESITEINDEX]->setOrientationMatrix(transformMatrix[SECUNDUSMISSILESITEINDEX]);

				break;

			case SHIPINDEX:
				object3d[SHIPINDEX]->setTranslationMatrix(warbird->getTranslationMatrix());
				object3d[SHIPINDEX]->setRotationMatrix(warbird->getRotationMatrix());
				object3d[SHIPINDEX]->setRotationAmount(warbird->getRotationAmount());
				object3d[SHIPINDEX]->setOrientationMatrix(warbird->getOrientationMatrix());

				modelMatrix[i] = object3d[i]->getModelMatrix();
				shipOrientationMatrix = object3d[i]->getOrientationMatrix();

				// Update Ship's Camera:
				warbirdLocation = getPosition(shipOrientationMatrix);
				if (currentCamera == SHIPCAMINDEX) 
					cameras[SHIPCAMINDEX] = glm::lookAt(
						getPosition(glm::translate(object3d[i]->getModelMatrix(), shipCamEyePosition)),
						glm::vec3(warbirdLocation.x, warbirdLocation.y, warbirdLocation.z),
						upVector
					);
				
				break;

			case SHIPMISSILE:
				object3d[SHIPMISSILE]->setTranslationMatrix(shipMissile->getTranslationMatrix());
				object3d[SHIPMISSILE]->setRotationMatrix(shipMissile->getRotationMatrix());
				object3d[SHIPMISSILE]->setOrientationMatrix(shipMissile->getOrientationMatrix());
				
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

	frameCount++;

	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeInterval = currentTime - lastTime;
	if (timeInterval >= 1000)
	{
		sprintf(fpsStr, " F/S %4d ", (int)(frameCount / (timeInterval / 1000.0f)));
		lastTime = currentTime;
		frameCount = 0;
	}

	updateTitle();
}

// Update
void update(int i) {
	glutTimerFunc(timeQuantum[quantumIndex], update, 1);

	// Update all of the objects in the scene
	for (int index = 0; index < totalModels; index++) {
		object3d[index]->update();
	}

	// Update the Unum Missile Site
	object3d[UNUMMISSILESITEINDEX]->setTranslationMatrix(object3d[UNUMINDEX]->getTranslationMatrix());
	object3d[UNUMMISSILESITEINDEX]->setOrientationMatrix(object3d[UNUMINDEX]->getRotationMatrix());
	object3d[UNUMMISSILESITEINDEX]->setTranslationMatrix(glm::translate(object3d[UNUMINDEX]->getTranslationMatrix(), glm::vec3(0, 200, 0)));
	transformMatrix[UNUMMISSILESITEINDEX] = glm::translate(object3d[UNUMINDEX]->getOrientationMatrix(), glm::vec3(0, 135, 0));
	object3d[UNUMMISSILESITEINDEX]->setOrientationMatrix(transformMatrix[UNUMMISSILESITEINDEX]);
	
	// Update the warbird object
	warbird->update();

	// Handles the ship's missile
	handleMissiles();

	glutPostRedisplay();
}

// Main
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	//Configure glut options
	glutInitWindowSize(800, 600);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Ruber: Front Camera");

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	//initialize scene
	init();

	//set glut callback functions
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleShipMovement);

	glutIdleFunc(NULL);
	glutTimerFunc(timeQuantum[quantumIndex], update, 1);

	glutMainLoop(); 

	return 0;
}