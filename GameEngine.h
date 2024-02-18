#pragma once

#include<iostream>
#include "AssetManager.h"
#include "Player.h"
#include "MonsterPlanet.h"
#include "GameText.h"
#include "Pickup.h"   
#include "GameSound.h" 
#include "Levels.h"		

using namespace sf;
using namespace std;

class GameEngine
{
public:

	// �����������
	GameEngine();
	// ����� ������� �������� �����
	void run();

private:

	// �������� ��������
	AssetManager m_manager; 
	// ���������� ������
	 Vector2f m_resolution =  Vector2f(static_cast<float>( VideoMode::getDesktopMode().width), 
		static_cast<float>( VideoMode::getDesktopMode().height));
	// ����������� ���� 
	 RenderWindow m_window; 
	// ���� ������ ����� � ����� �� ������������� ���������
	enum class State { paused, level, level_up, game_over, playing, 
		game_victory, game_load, splash_screen, transition, help };
	// c�������� ����
	State m_state;
	Levels m_levels = Levels(m_window, m_resolution.x, m_resolution.y); 
	// ������
	 Image m_icon;
	
	// ���� mainView
	 View m_mainView =  View( FloatRect(0, 0, 1920, 1080));
	// ������� ������
	GameSound m_musik;

	// o���� ������� �����
	 Time m_gameTimeTotal;
	// �������� ��������
	 Time m_lastPressed;
	// ������� ���������� �����
	 Vector2f m_mouseWorldPosition;
	// ���������� ����� � ����
	 Vector2i m_mouseScreenPosition;
	// �����
	Player m_player;

	// ������ ��������
	 deque<Monster> m_monster;
	// �������� ��� �������
	 vector<Pickup>  pickup; 
	// ������� 
	GameBullet m_Bullet;   
	// ����������� ������
	void recharge();
	
	// ������ �������� ������
	 IntRect m_planet;
	// ��� �������� ������
	 VertexArray m_background;
		
	// ����� ��������� ������� 
	void input();
	// ����� ���������� ����������, ������� � ������� 
	void update( Time const& deltaTime);
	// ����� ��������� �������� � ����������� ����
	void draw();
	// ������� ����
	void restart();
	// ����� �������
	void newLevel();
	// ������ �������
	void saveHiScore(); 
	// ���� HUD
	 View m_hudView =  View( FloatRect(0, 0, m_resolution.x, m_resolution.y));
	
	GameHubText m_HubText;
	GameText m_gametext= GameText(m_resolution);
};

