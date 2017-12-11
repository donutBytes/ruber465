#pragma once

#ifndef WARBIRD_H
#define WARBIRD_H
#include "MoveableObj3D.hpp"

class Warbird : public MoveableObj3D 
{

private:
	glm::vec3 distance;
	glm::vec3 pitchVector;
	glm::vec3 initialPosition; 
	
	float speed;

	int step; 
	int pitch, roll, yaw;

	bool alive;

public:
	Warbird(float modelSize, float modelBoundingRadius, glm::vec3 passedInitialPosition) : MoveableObj3D(modelSize, modelBoundingRadius) {
		initialPosition = passedInitialPosition;
		speed = 10.0f;
		step = 0 , pitch = 0, roll = 0, yaw = 0;
		alive = true;
	};

	bool isAlive() {
		return alive;
	}
	void destroy() {
		orientationMatrix = identity;
		alive = false;
		printf("The warbird is dead. \n");
	}

	float getSpeed() {
		return speed;
	}
	void setSpeed(float newSpeed) {
		speed = newSpeed;
	}

	// Setting rotation variables
	void setMove(int stepSize) {
		step = stepSize;
		printf("move:%i\n", step);
	}
	void setPitch(int newPitch) {
		pitch = newPitch;
		printf("pitch:%i\t", pitch);
	}
	void setRoll(int newRoll) {
		roll = newRoll;
		printf("roll:%i\t", roll);
	}
	void setYaw(int newYaw) {
		yaw = newYaw;
		printf("yaw:%i\t", yaw);
	}

	void update() {
		if(!alive) {
			printf("ded");
			return;
		}

		distance = getIn(orientationMatrix) * (-step * speed);

		rotationAxis = glm::vec3(pitch, yaw, roll);

		if(pitch != 0 || yaw != 0 || roll != 0) {
			printf("%i\t", pitch);
			printf("%i\t", yaw);
			printf("%i\t", roll);
			printf("\n");
			rotationMatrix = glm::rotate(rotationMatrix, rotationAmount, rotationAxis);
		}

		setTranslationMatrix(distance);

		orientationMatrix = translationMatrix * rotationMatrix;

		step = pitch = yaw = roll = 0;
	}
};

#endif
