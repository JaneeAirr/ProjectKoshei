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

	// конструктор
	GameEngine();
	// метод запуска игрового цикла
	void run();

private:

	// менеджер ресурсов
	AssetManager m_manager; 
	// разрешение экрана
	 Vector2f m_resolution =  Vector2f(static_cast<float>( VideoMode::getDesktopMode().width), 
		static_cast<float>( VideoMode::getDesktopMode().height));
	// графическое окно 
	 RenderWindow m_window; 
	// игра всегда будет в одном из перечисленных состояний
	enum class State { paused, level, level_up, game_over, playing, 
		game_victory, game_load, splash_screen, transition, help };
	// cостояние игры
	State m_state;
	Levels m_levels = Levels(m_window, m_resolution.x, m_resolution.y); 
	// иконка
	 Image m_icon;
	
	// окно mainView
	 View m_mainView =  View( FloatRect(0, 0, 1920, 1080));
	// Игровая музыка
	GameSound m_musik;

	// oбщее игровое время
	 Time m_gameTimeTotal;
	// интервал стрельбы
	 Time m_lastPressed;
	// мировые координаты мышки
	 Vector2f m_mouseWorldPosition;
	// координаты мышки в окне
	 Vector2i m_mouseScreenPosition;
	// игрок
	Player m_player;

	// массив монстров
	 deque<Monster> m_monster;
	// Придметы для подъёма
	 vector<Pickup>  pickup; 
	// патроны 
	GameBullet m_Bullet;   
	// перезарядка оружия
	void recharge();
	
	// размер игрового уровня
	 IntRect m_planet;
	// фон игрового уровня
	 VertexArray m_background;
		
	// метод обработки событий 
	void input();
	// метод обновления переменных, свойств и методов 
	void update( Time const& deltaTime);
	// метод отрисовки объектов в графическом окне
	void draw();
	// рестарт игры
	void restart();
	// новый уровень
	void newLevel();
	// запись рекорда
	void saveHiScore(); 
	// окно HUD
	 View m_hudView =  View( FloatRect(0, 0, m_resolution.x, m_resolution.y));
	
	GameHubText m_HubText;
	GameText m_gametext= GameText(m_resolution);
};

