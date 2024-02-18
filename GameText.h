#pragma once

#include<array>
#include<random>
#include<format>
#include"MonsterPlanet.h"
#include"AssetManager.h"
#include <fstream>    
using namespace std;
using namespace sf;
class GameText
{
	//�������
	 Vector2f  m_scale{1,1};   

	 Vector2f m_resolution;

	// ������� � ����������
	 Sprite spriteAmmoIcon;

	// �����
	 Text levelText;
	 Text ammoText;
	 Text scoreText;
	 Text hiScoreText;
	 Text monsterRemainingText;
	 Text levelNumberText;
	 Text HelpText;

	// ����� �����
	 RectangleShape healthBar;
	 RectangleShape healthBar1;

	std::array< String, 6> m_deadText{L"������� �� ����� ������ ��������� �������� ���� �� ����",L"����� ��� ������, � ������ ��������� ���� � ���,\n\t ��� ���� � ������ � ����� �� ������"
	,L"�� ������� �� �������� ���������,\n ���� ���� ������ ��������� ...",L"������ ����� ���������� ��, ��� �� �����������\n\t\t � ������������ ���������",
		L"� ���� ������� ���������, �� � �� ���� �������\n\t\t\t ���������� �������",L"������� ������ �� �������� �������, \n������� ����� ������ ���� ���������"
	};

	std::array< String, 6> m_victoriqText{ L"������ ��� ������� ��� ����,\n ������ ��� ����� � ����������",L"���������� ������ �\n ������ ��� ����� �����",
		L"� ����� ���� ����� ������ ����,\n\t ��� ������ � ���������",L"������� ���������� � ������� ����� � ���,\n\t\t ��� �� ������ �� ���������",
		L"� ���������� ����� ������, � ����\n � ������������ ��� ���������",L"������, ������, �������."
	};

	 Text m_text;	
	
public:

	explicit GameText( Vector2f m_resolution);

	void update(GameHubText Hub);

	void draw( RenderWindow& window);

	 Vector2f getScale(); // ���������� �������

	void drawText( RenderWindow& window);

	void genText(std::string str);

	void drawGameOver( RenderWindow& window);

	void drawAssistant( RenderWindow& window, int num);

};

