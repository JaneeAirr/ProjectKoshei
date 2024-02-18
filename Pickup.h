

#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
class Pickup
{
private:
	
	// ������, �������������� ���� �����
	 Sprite m_Sprite;
	// ������ ������� ������� �������� �����
	int m_Value;
	// ��� ��� �� ����� (��������, ������� � �.�.)
    int m_Type;
	// ��������� ��������� � ������������ ������
	bool m_Spawned=true;
	float m_SecondsSinceSpawn;
	float m_SecondsToLive=15;
		
public:
	// ������ ����� �����
	void spawn( Vector2f pos, int type);
	// ��������� ��������� ������
	 FloatRect getPosition() const;
	// �������� ������ ��� ���������
	 Sprite getSprite() const;
	// ��������� ����� ������ ����
	void update(float elapsedTime);
	// ���������� ��� ��� �����
	bool isSpawned() const;
	// ������ ������
	int gotIt();
	// �������� ��� ������
	int getType() const;
};




