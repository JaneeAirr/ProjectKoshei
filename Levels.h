#pragma once
#include"AssetManager.h"
#include<array>
using namespace std;
using namespace sf;

class Levels
{
	 RenderWindow& m_window;
	// массив картин уровней
	 array< Sprite, 7> m_background;
	// массив озвучки предистории игры
	 array< Sound,7> m_sound;
	// задержка кадра предистории игры
	 array<int, 7> m_time{11,8,5,9,5,12,7};
	// ссылка на картинку текущего уровня
	 Sprite* m_bkgr=nullptr;
	// титульная картинка игры
	 Sprite m_start;
	// спрайт содержащий кадры предистории 
	 Sprite m_splash_screen;
	// картинка с клавишами управления
	 Sprite m_help;
	// номер кадра
	int m_frame = 0;
	// время смены кадра
	 Time m_time_frame;
	// проигрывание анимации предистории
	bool m_play = true;
	// масштаб отображения графики
	float m_scale_x;
	float m_scale_y;
	// окончание проигривания предистории  
	bool vstup = false;  
public:

	Levels( RenderWindow& window, float scale_x, float scale_y);
	// возвращает титульный кадр текущего уровня
	 Sprite * getSprite(int index);
	// возвращает окончание предистории
	bool getVstup();    
	// обновление кадров анимации предистории
	void splash_SCR_update( Time deltaTime);
	// отрисовка кадров анимации в графическом окне
	void splash_SCR_draw();
	// открываем уровень загружаем графику в оперативную память
	void createLevels();
	// выключаем озвучку
	void stop_sound();
	// отрисовка титульной картинки игры
	void start();
	// отображаем картинку помощи
	void help();
};

