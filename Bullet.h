#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Bullet
{
private:
	// ���������� ����
	Vector2f m_Position;
	// ����� ����
	CircleShape m_BulletShape;
	// ���� � �����
	bool m_InFlight = false;
	// �������� ����
	float m_BulletSpeed = 1000;
	// ��������� �����
	 Vector2f m_BulletDistance;
	// ������� ����� ����
	 Vector2f m_Max;
	 Vector2f m_Min;
	
public:
	
	Bullet();
	// ���������� ���� ����
	void stop();
	// ������� ��������� ����
	bool isInFlight();
	// ��������� ����
	void shoot(float startX, float startY,
		float xTarget, float yTarget);
	// ������� ���������� � ��������� ����
	FloatRect getPosition();
	// ������� ������ ����
	CircleShape getShape();
	// ���������� ������� ������
	void update(float elapsedTime);
};



	