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

class MoveableObj3D {

protected:
	bool orbit = false;
	
	float modelSize;
	float rotationAmount;
	float modelBoundingRadius;
	
	glm::vec3 scale;
	glm::mat4 identity;
	glm::mat4 scaleMatrix;
	glm::mat4 modelMatrix;
	glm::vec3 rotationAxis;
	glm::mat4 rotationMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 orientationMatrix;

public:
	// Constructor
	MoveableObj3D(float modelSize, float modelBoundingRadius);

	void update();
	void setOrbit();
	void setPosition(glm::vec3 newPosition);
	void setRotationAmount(float passedRadianAmount);
	void setOrientationMatrix(glm::mat4 newOrientation);
	void setTranslationMatrix(glm::vec3 passedTranslation);
	void setRotationMatrix(glm::mat4 passedRotationMatrix);
	void setTranslationMatrix(glm::mat4 passedTranslationMatrix);
	
	float getRotationAmount();

	glm::mat4 getModelMatrix();
	glm::mat4 getRotationMatrix();
	glm::mat4 getOrientationMatrix();
	glm::mat4 getTranslationMatrix();
};


MoveableObj3D::MoveableObj3D(float modelSize, float modelBoundingRadius) {
	scale = glm::vec3(modelSize / modelBoundingRadius);
	scaleMatrix = glm::scale(glm::mat4(), glm::vec3(scale));

	identity = glm::mat4();

	rotationMatrix = identity;
	orientationMatrix = identity;
	translationMatrix = identity;
	modelMatrix = identity;

	rotationAxis = glm::vec3(0, 1, 0);
}

glm::mat4 MoveableObj3D::getModelMatrix() {
	return orientationMatrix * scaleMatrix;
}

// Handles rotation matrix
glm::mat4 MoveableObj3D::getRotationMatrix() {
	return rotationMatrix;
}
void MoveableObj3D::setRotationMatrix(glm::mat4 passedRotationMatrix) {
	rotationMatrix = passedRotationMatrix;
}

// handles orientation matrix
glm::mat4 MoveableObj3D::getOrientationMatrix() {
	return orientationMatrix;
}
void MoveableObj3D::setOrientationMatrix(glm::mat4 newOrientation) {
	orientationMatrix = newOrientation;
}

// Handles Translation Matrix of the object
glm::mat4 MoveableObj3D::getTranslationMatrix() {
	return translationMatrix;
}
void MoveableObj3D::setTranslationMatrix(glm::vec3 passedTranslation) {
	translationMatrix = glm::translate(translationMatrix, passedTranslation);
}
void MoveableObj3D::setTranslationMatrix(glm::mat4 passedTranslationMatrix) {
	translationMatrix = passedTranslationMatrix;
}

// Handles the rotation amount for things such as turning and orbiting
float MoveableObj3D::getRotationAmount() {
	return rotationAmount;
}
void MoveableObj3D::setRotationAmount(float passedRadianAmount) {
	rotationAmount = passedRadianAmount;
}

void MoveableObj3D::setOrbit() {
	orbit = true;
}

// Handles world coordinates
void MoveableObj3D::setPosition(glm::vec3 newPosition) {
	orientationMatrix[3][0] = newPosition.x;
	orientationMatrix[3][1] = newPosition.y;
	orientationMatrix[3][2] = newPosition.z;
}

// Updates the rotation and orientation matrix.
void MoveableObj3D::update() {
	rotationMatrix = glm::rotate(
		rotationMatrix, 
		rotationAmount, 
		rotationAxis
	);

	if(orbit == true) 
		orientationMatrix = rotationMatrix * translationMatrix;
	else 
		orientationMatrix = translationMatrix * rotationMatrix;
}
#endif