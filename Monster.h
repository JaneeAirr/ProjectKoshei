#pragma once
#include"Animator.h"
#include <random>
#include <deque>
#include <array>
using namespace std;
using namespace sf;

class Monster
{
private:
	// ��������� ����
	int m_complexity = 0;
	// ���������� ��������
	 Vector2f m_Position;
	// ������ ��� �������
	 Sprite m_Sprite;
	// �������� ��������
	Animator m_AnimPlayer = Animator(m_Sprite);
	// �������� �������
	float m_Speed;
	// ����� �������
	float m_Health;
	// ��������� ��� - ����
	bool m_Alive = true;
	// ����� �� ����� ���� ��� ���
	bool m_novisible = false;
	// ��� �������
	int m_Type;
	// �������� ����������� ����
	 Time m_moveTime;

	public:

	Monster();
	// ��������� ��������� ���� � ����
	bool hit();
	// ������, ��� �� ������
	bool isAlive();
	// ����� ������ ��� ���
	bool getnovisible();
	// ��������� ��������� �������
	void novisible();
	// ������� ������ �������
	void spawn(float startX, float startY, int type, int complexity);
	// ���������� �������������, ������� �������� �������� � ����
	 FloatRect getPosition();
	// �������� ����� ������� ��� ���������
	 Sprite getSprite() const;
	// ��������� �������� ������ ����
	void update( Time deltaTime,  Vector2f playerLocation,  Vector2f resolution);
	// ���������� ��� �������
	int getTypeMonster() const;
	
	};

