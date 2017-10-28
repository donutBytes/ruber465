#pragma once

#ifndef MISSILE_H
#define MISSILE_H
#include "MoveableObj3D.hpp"

class Missile : public MoveableObj3D {
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
	Missile(float modelSize, float modelBoundingRadius);
	void update();
	void setDirection(glm::vec3 passedInDirection);
	glm::mat4 getTargetMatrixLocation();
	glm::vec3 getDirection();
	int getUpdateFrameCount();
};

Missile::Missile(float modelSize, float modelBoundingRadius) : MoveableObj3D(modelSize, modelBoundingRadius) {
	updateFrameCount = 0;
	AORDirection = 0;
};

void Missile::setDirection(glm::vec3 passedInDirection) {
	direction = passedInDirection;
}

glm::mat4 Missile::getTargetMatrixLocation() {
	return targetMatrixLocation;
}

glm::vec3 Missile::getDirection() {
	return direction;
}

int Missile::getUpdateFrameCount() {
	return updateFrameCount;
}

void Missile::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	// Update the orientation matrix of the missile
	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
}

#endif