#pragma once

#ifndef WARBIRD_H
#define WARBIRD_H
#include "MoveableObj3D.hpp"

class Warbird : public MoveableObj3D {
private:
	float AORDirection;
	//glm::vec3 AOR;
	glm::vec3 direction;
	glm::vec3 pitchVector;
	glm::vec3 initialPosition; 
	
	glm::vec3 distance;
	
	glm::mat4 targetMatrixLocation;
	//glm::quat quatrnion;

public:
	Warbird(float modelSize, float modelBoundingRadius, glm::vec3 passedInitialPosition);
	void update();
	void setDirection(glm::vec3 passedInDirection);
	glm::mat4 getTargetMatrixLocation();
	glm::vec3 getDirection();
	int getUpdateFrameCount();
};

Warbird::Warbird(float modelSize, float modelBoundingRadius, glm::vec3 passedInitialPosition) : MoveableObj3D(modelSize, modelBoundingRadius) {
	initialPosition = passedInitialPosition;
	
	AORDirection = 0;
};

void Warbird::setDirection(glm::vec3 passedInDirection) {
	direction = passedInDirection;
}

glm::mat4 Warbird::getTargetMatrixLocation() {
	return targetMatrixLocation;
}

glm::vec3 Warbird::getDirection() {
	return direction;
}

void Warbird::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	// Update the orientation matrix of the missile
	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
}

#endif
