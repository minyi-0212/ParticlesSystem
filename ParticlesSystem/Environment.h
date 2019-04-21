#pragma once
#include <glm/glm.hpp>
class Environment
{
public:
	static Environment& get_instance();
	glm::vec3 get_gravity() { return _gravity; }
	void set_gravity(glm::vec3& g) { _gravity = g; }
	glm::vec3 get_wind() { return _wind; }
	void set_wind(glm::vec3& w) { _wind = w; }
private:
	Environment() {} //防止外部调用构造创建对象
	Environment(Environment const &environment); //防止拷贝创建对象
	Environment& operator=(Environment const &environment); //防止赋值对象
	glm::vec3 _gravity;
	glm::vec3 _wind;
};

