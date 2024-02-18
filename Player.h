#pragma once
#include"Animator.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Player();
	// ����������� �������� ������
	enum class playermove { UpPressed, UpRg, UpLf, DownPressed, 
		DownRg, DownLf, LeftPressed, RightPressed, Stop };
	// ����� ��������� ������ �� ������� ����
	void spawn( IntRect planet,  Vector2f resolution, int tileSize);
	// ����� ������� ���������� ������
	void resetPlayerStats();
	// ���������� ��������� ����� ������
	bool getLive() const;
	// ����� ��������� ����� �������
	bool hit( Time timeHit);
	// ���������� ����� ��� ����� ��� ��������� ���� �� ������
	 Time getLastHitTime() const;
	// ���������� ���������� ������
	 FloatRect getPosition() const;
	// ���������� ����������� ���������� ������
	 Vector2f getCenter() const;
	// ���������� ���� �������� ������
	float getRotation() const;
	// ���������� ����� ������� ������
	 Sprite getSprite() const;
	// ������ ������
	void draw( RenderWindow& win) const;
	// ���������� ������
	void move(playermove mov);
	// ���������� ������� ������ 
	void update( Time deltaTime,  Vector2i mousePosition);
	// ����������� ������������ ���������� �������� 
	void upgradeHealth(float heal);
	// ��������� �������� ������
	void increaseHealthLevel(float amount);
	// ���������� ������� �������� � ������ �� ������ ������?
	float getHealth() const;
	// ���������� ������������ �������� ������
	float getMaxHealth() const;

private:
	// ��������� ����� ������
	const float START_HEALTH = 200;
	// ������� ������
	 Vector2f m_Position;
	// ����������� ������ ������ �  ������ ��������
	 Sprite m_Sprite;
	Animator m_AnimPlayer = Animator(m_Sprite);
	// ���������� ����������� ������
	bool m_animMove = false;
	// ���������� ������
	 Vector2f m_Resolution;
	// ������ �������� ���� 
	 IntRect m_planet;
	// ������ ������� �������� ���� 
	int m_TileSize;
	// � ����� �����������(��) �������� ����� � ������ ������
	playermove m_move;
	// ����� �� �����
	bool m_live = true;
	// �������� ������
	float m_Health;
	// ������������ �������� ������
	float m_MaxHealth;
	// ����� ��������� ���������� ����� �� ������ 
	 Time m_LastHit;
	// ������� ����������� ������
	 Time m_time_moving;
	// �������� ����������� ������ � �������� � �������
	float m_Speed;
	
};

