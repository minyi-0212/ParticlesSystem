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
	Environment() {} //��ֹ�ⲿ���ù��촴������
	Environment(Environment const &environment); //��ֹ������������
	Environment& operator=(Environment const &environment); //��ֹ��ֵ����
	glm::vec3 _gravity;
	glm::vec3 _wind;
};

