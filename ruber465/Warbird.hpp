#pragma once

#ifndef WARBIRD_H
#define WARBIRD_H
#include "MoveableObj3D.hpp"

class Warbird : public MoveableObj3D 
{

private:
	float AORDirection;
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
		step = 0;
		pitch = 0;
		roll = 0;
		yaw = 0;

		alive = true;
	};

	bool isAlive() {
		return alive;
	}

	void setSpeed(float newSpeed) {
		speed = newSpeed;
	}

	float getSpeed() {
		return speed;
	}

	void setMove(int value) {
		step = value;
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

	void destroy() {
		orientationMatrix = identity;
		alive = false;
		printf("The warbird is dead. \n");
	}


	void restart() {
		alive = true;
		translationMatrix = glm::translate(identity, initialPosition);
		rotationMatrix = glm::rotate(identity, 0.0f, glm::vec3(0, 1, 0));
	}

	void update() {
		if (!alive) {
			printf("dead");
			return;
		}

		distance = getIn(orientationMatrix) * (-step * speed);

		rotationAxis = glm::vec3(pitch, yaw, roll);

		if (pitch != 0 || yaw != 0 || roll != 0) {
			printf("%i\t", pitch);
			printf("%i\t", yaw);
			printf("%i\t", roll);
			printf("\n");
			rotationMatrix = glm::rotate(rotationMatrix, rotationAmount, rotationAxis);
			// showMat4("transform", transformMatrix[i]);
		}

		setTranslationMatrix(distance);

		orientationMatrix = translationMatrix * rotationMatrix;
		//orientationMatrix = rotationMatrix * translationMatrix;

		step = pitch = yaw = roll = 0;
	}
};

#endif
