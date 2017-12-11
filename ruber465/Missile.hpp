#pragma once

#ifndef MISSILE_H
#define MISSILE_H
#include "MoveableObj3D.hpp"

class Missile : public MoveableObj3D {
private:
	const int missleLifetime = 2000;
	const int missileActivationTimer = 200;
	
	float speed;
	float axisOfRotationDirection;
	float detectionRadius = 5000.0f; 
	
	bool smart;		
	bool fired;
	bool targetLocked;
	
	int updateFrameCount;
	
	glm::vec3 distance;
	glm::vec3 direction;
	glm::quat quaternion;
	glm::vec3 targetVector;
	glm::vec3 missileVector;
	glm::vec3 axisOfRotation;
	glm::vec3 missileLocation;
	glm::vec3 translationAmount;
	glm::mat4 targetMatrixLocation;

public:
	Missile(float modelSize, float modelBoundingRadius, float passedMissleSpeed);

	void update();
	void destroy();
	void makeSmart();
	void fireMissile();
	void setDirection(glm::vec3 passedInDirection);
	void setTarget(glm::mat4 newLocation);
	
	bool isSmart();
	bool hasFired();
	bool isTargetLocked();

	int getUpdateFrameCount();
	
	glm::vec3 getDirection();
	glm::mat4 getTargetMatrix();
};

Missile::Missile(float modelSize, float modelBoundingRadius, float passedMissleSpeed) 
	: MoveableObj3D(modelSize, modelBoundingRadius) {
	smart = false; 
	fired = false;
	targetLocked = false;
	updateFrameCount = 0;
	speed = passedMissleSpeed;
	axisOfRotationDirection = 0;
};

void Missile::destroy() {
	smart = false;
	fired = false;
	targetLocked = false;
	updateFrameCount = 0;
	setTranslationMatrix(identity);
	setOrientationMatrix(translationMatrix);
}

// determines if the missile has been fired
bool Missile::hasFired() {
	return fired;
}
void Missile::fireMissile() {
	fired = true;
}

// Handles smart missile guidance
void Missile::makeSmart() {
	smart = true;
}
bool Missile::isSmart() {
	return smart;
}

bool Missile::isTargetLocked() {
	return targetLocked;
}

// Getters and Setters
void Missile::setDirection(glm::vec3 passedInDirection) {
	direction = passedInDirection;
}
glm::vec3 Missile::getDirection() {
	return direction;
}
void Missile::setTarget(glm::mat4 newLocation) {
	targetMatrixLocation = newLocation;
	targetLocked = true;
}
glm::mat4 Missile::getTargetMatrix() {
	return targetMatrixLocation;
}
int Missile::getUpdateFrameCount() {
	return updateFrameCount;
}

void Missile::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	if(fired == true) {
		updateFrameCount = updateFrameCount + 1;

		distance = glm::vec3(0, 0, -speed);
		translationMatrix = glm::translate(identity, distance);

		if(updateFrameCount > missleLifetime) 
			destroy();

		if(smart && targetLocked) {
			targetVector = getPosition(targetMatrixLocation) - getPosition(orientationMatrix);
			missileVector = getIn(orientationMatrix);

			targetVector = glm::normalize(targetVector);
			missileVector = glm::normalize(missileVector);

			if(!colinear(missileVector, targetVector, 0.1)) {
				axisOfRotation = glm::cross(missileVector, targetVector);
				axisOfRotation = glm::normalize(axisOfRotation);

				axisOfRotationDirection = axisOfRotation.x + axisOfRotation.y + axisOfRotation.z;

				if(axisOfRotationDirection <= 0) {
					rotationAmount = -glm::acos(glm::dot(targetVector, missileVector));
				}
				else {
					rotationAmount = 2 * PI + glm::acos(glm::dot(targetVector, missileVector));
				}

				rotationAxis = axisOfRotation;
				quaternion = glm::angleAxis(rotationAmount, rotationAxis);

				rotationAxis = glm::axis(quaternion);
				rotationAmount = glm::angle(quaternion);
				rotationMatrix = glm::rotate(identity, rotationAmount, rotationAxis);
			}
		}
	}

	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
};

#endif