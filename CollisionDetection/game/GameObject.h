#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../libraries/GLM/glm.hpp"
#include "../libraries/GLM/gtc/quaternion.hpp"
#include "../application/Object.h"

class GameObject : public Object
{
	private:
		glm::vec3 _scale;

		std::vector<std::shared_ptr<GameObject>> _children;
	public:
		GameObject();
		~GameObject();

		void scale(glm::vec3 scale);
		void rotate(glm::vec3 axis);
};

