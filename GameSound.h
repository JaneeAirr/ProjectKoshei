#pragma once
#include <SFML/Audio.hpp>
#include "AssetManager.h"

using namespace std;
using namespace sf;
class GameSound
{   
	// ������ �������� ��������
     vector< Sound> m_sound; 	
		
public:
	
	// ������� ������ �������� ��������
	void create_sound( vector< string>& sound);
	// ����� ��������� ��������� ������� �������� �������������� � ���������� �������
	bool play(int index, bool loop);
	// ����� ���������� ��������� ������� �������� �������������� � ���������� �������
	void stop(int index);
	// ����� ���������� ���� �������� ��������
	void all_stop();
};

