/*
File: MoveableObj3D.hpp
Description: Represent the scale, translation, and rotation of a 3D object.
*/
#pragma once

#ifndef __INCLUDES465__
#define __Windows__
#include "../includes465/include465.hpp"
#endif

#ifndef MOVEABLEOBJ3D_H
#define MOVEABLEOBJ3D_H

class MoveableObj3D{

protected:

	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 orientationMatrix;
	glm::mat4 modelMatrix;
	glm::mat4 identity;
	glm::vec3 scale;
	glm::vec3 rotationAxis;
	float rotationAmount;
	float modelSize;
	float modelBoundingRadius;
	bool orbit = false;

public:

	// Constructor
	MoveableObj3D(float modelSize, float modelBoundingRadius);

	// Returns the model matrix for the 3D object.
	glm::mat4 getModelMatrix();

	// Returns the rotational matrix for the 3D object.
	glm::mat4 getRotationMatrix();

	// Returns the orientation matrix for the 3D object.
	glm::mat4 getOrientationMatrix();

	glm::mat4 getTranslationMatrix();

	float getRotationAmount();

	// Translates the translation matrix by a passed in amount.
	void setTranslationMatrix(glm::vec3 passedTranslation);

	// Sets the translation matrix to an outside matrix.
	void setTranslationMatrix(glm::mat4 passedTranslationMatrix);

	// Sets the rotation matrix to an outside matrix.
	void setRotationMatrix(glm::mat4 passedRotationMatrix);

	// Sets the rotational rate for the 3D object.
	void setRotationAmount(float passedRadianAmount);

	// Sets the orientational matrix.
	void setOrientationMatrix(glm::mat4 newOrientation);

	// Sets the object flag to a planet orbit.
	void setOrbit();

	/* Changes the position of the object
	to a new position without affecting it's orientation.
	*/
	void setPosition(glm::vec3 newPosition);

	// Updates the rotation and orientation matrix.
	void update();
};


MoveableObj3D::MoveableObj3D(float modelSize, float modelBoundingRadius) {
	// Scale the model to the desired size
	scale = glm::vec3(modelSize / modelBoundingRadius);
	scaleMatrix = glm::scale(glm::mat4(), glm::vec3(scale));

	identity = glm::mat4();		// initialize the identity matrix

	// No initial rotation, orientation, or translation
	rotationMatrix = identity;
	orientationMatrix = identity;
	translationMatrix = identity;

	modelMatrix = identity;

	rotationAxis = glm::vec3(0, 1, 0);
}

glm::mat4 MoveableObj3D::getModelMatrix() {
	return orientationMatrix * scaleMatrix;
}

glm::mat4 MoveableObj3D::getRotationMatrix() {
	return rotationMatrix;
}

glm::mat4 MoveableObj3D::getOrientationMatrix()
{
	return orientationMatrix;
}

glm::mat4 MoveableObj3D::getTranslationMatrix()
{
	return translationMatrix;
}

float MoveableObj3D::getRotationAmount()
{
	return rotationAmount;
}

void MoveableObj3D::setTranslationMatrix(glm::vec3 passedTranslation)
{
	translationMatrix = glm::translate(translationMatrix, passedTranslation);
}

void MoveableObj3D::setTranslationMatrix(glm::mat4 passedTranslationMatrix)
{
	translationMatrix = passedTranslationMatrix;
}

void MoveableObj3D::setRotationMatrix(glm::mat4 passedRotationMatrix)
{
	rotationMatrix = passedRotationMatrix;
}

void MoveableObj3D::setRotationAmount(float passedRadianAmount)
{
	rotationAmount = passedRadianAmount;
}

// Sets the orientational matrix.
void MoveableObj3D::setOrientationMatrix(glm::mat4 newOrientation)
{
	orientationMatrix = newOrientation;
}

// Sets the object flag to a planet orbit.
void MoveableObj3D::setOrbit()
{
	orbit = true;
}

/* Changes the position of the object
to a new position without affecting it's orientation.
*/
void MoveableObj3D::setPosition(glm::vec3 newPosition)
{
	orientationMatrix[3][0] = newPosition.x;
	orientationMatrix[3][1] = newPosition.y;
	orientationMatrix[3][2] = newPosition.z;
}

// Updates the rotation and orientation matrix.
void MoveableObj3D::update()
{
	rotationMatrix = glm::rotate(
		rotationMatrix, 
		rotationAmount, 
		rotationAxis
	);

	// Set the orientation matrix based on what type of object it is:
	if (orbit == true) {
		//printf("orbit: true\t");
		orientationMatrix = rotationMatrix * translationMatrix;
	}
	else {
		//printf("orbit: false\t");
		orientationMatrix = translationMatrix * rotationMatrix;
	}
}
#endif