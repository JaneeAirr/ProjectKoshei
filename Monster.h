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
	// сложность игры
	int m_complexity = 0;
	// координаты монстров
	 Vector2f m_Position;
	// спрайт для монстра
	 Sprite m_Sprite;
	// анимация монтстра
	Animator m_AnimPlayer = Animator(m_Sprite);
	// скорость монстра
	float m_Speed;
	// жизнь монстра
	float m_Health;
	// состояние жив - мёртв
	bool m_Alive = true;
	// видно на карте труп или нет
	bool m_novisible = false;
	// тип монстра
	int m_Type;
	// интервал перемещения моба
	 Time m_moveTime;

	public:

	Monster();
	// обработка попадания пули в моба
	bool hit();
	// узнаем, жив ли монстр
	bool isAlive();
	// виден монстр или нет
	bool getnovisible();
	// изменение видимости монстра
	void novisible();
	// создаем нового монстра
	void spawn(float startX, float startY, int type, int complexity);
	// возвращаем прямоугольник, который является позицией в мире
	 FloatRect getPosition();
	// получаем копию спрайта для рисования
	 Sprite getSprite() const;
	// обновляем монстров каждый кадр
	void update( Time deltaTime,  Vector2f playerLocation,  Vector2f resolution);
	// возвращает тип монстра
	int getTypeMonster() const;
	
	};

