#pragma once

#ifndef WARBIRD_H
#define WARBIRD_H
#include "MoveableObj3D.hpp"

class Warbird : public MoveableObj3D {
private:
	int updateFrameCount;
	float AORDirection;
	glm::vec3 AOR;
	glm::vec3 direction;
	glm::vec3 distance;
	glm::vec3 missileVector;
	glm::vec3 missileLocation;
	glm::vec3 translationAmount;
	glm::mat4 targetMatrixLocation;
	glm::quat quaternion;
public:
	Warbird(float modelSize, float modelBoundingRadius);
	void update();
	void setDirection(glm::vec3 passedInDirection);
	glm::mat4 getTargetMatrixLocation();
	glm::vec3 getDirection();
	int getUpdateFrameCount();
};

Warbird::Warbird(float modelSize, float modelBoundingRadius) : MoveableObj3D(modelSize, modelBoundingRadius) {
	updateFrameCount = 0;
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

int Warbird::getUpdateFrameCount() {
	return updateFrameCount;
}

void Warbird::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	// Update the orientation matrix of the missile
	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
}

#endif
