#pragma once
#include"AssetManager.h"
#include<array>
using namespace std;
using namespace sf;

class Levels
{
	 RenderWindow& m_window;
	// ������ ������ �������
	 array< Sprite, 7> m_background;
	// ������ ������� ����������� ����
	 array< Sound,7> m_sound;
	// �������� ����� ����������� ����
	 array<int, 7> m_time{11,8,5,9,5,12,7};
	// ������ �� �������� �������� ������
	 Sprite* m_bkgr=nullptr;
	// ��������� �������� ����
	 Sprite m_start;
	// ������ ���������� ����� ����������� 
	 Sprite m_splash_screen;
	// �������� � ��������� ����������
	 Sprite m_help;
	// ����� �����
	int m_frame = 0;
	// ����� ����� �����
	 Time m_time_frame;
	// ������������ �������� �����������
	bool m_play = true;
	// ������� ����������� �������
	float m_scale_x;
	float m_scale_y;
	// ��������� ������������ �����������  
	bool vstup = false;  
public:

	Levels( RenderWindow& window, float scale_x, float scale_y);
	// ���������� ��������� ���� �������� ������
	 Sprite * getSprite(int index);
	// ���������� ��������� �����������
	bool getVstup();    
	// ���������� ������ �������� �����������
	void splash_SCR_update( Time deltaTime);
	// ��������� ������ �������� � ����������� ����
	void splash_SCR_draw();
	// ��������� ������� ��������� ������� � ����������� ������
	void createLevels();
	// ��������� �������
	void stop_sound();
	// ��������� ��������� �������� ����
	void start();
	// ���������� �������� ������
	void help();
};

