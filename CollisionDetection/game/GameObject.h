#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../libraries/GLM/glm.hpp"
#include "../libraries/GLM/gtc/quaternion.hpp"

class GameObject
{
	private:
		std::string _name;
		int _id;

		glm::vec3 _position;
		glm::vec3 _scale;
		glm::quat _direction;

		std::vector<std::shared_ptr<GameObject>> _children;
	public:
		GameObject(void);
		~GameObject(void);

		void translate(glm::vec3 position);
		void scale(glm::vec3 scale);
		void rotate(glm::vec3 axis);
};

