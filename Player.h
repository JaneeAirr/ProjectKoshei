#pragma once
#include"Animator.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Player();
	// направления движения игрока
	enum class playermove { UpPressed, UpRg, UpLf, DownPressed, 
		DownRg, DownLf, LeftPressed, RightPressed, Stop };
	// метод появление игрока на игровом поле
	void spawn( IntRect planet,  Vector2f resolution, int tileSize);
	// метод рестарт параметров игрока
	void resetPlayerStats();
	// возвращает состояние жизни игрока
	bool getLive() const;
	// метод получения урона игроком
	bool hit( Time timeHit);
	// возвращает время как давно был последний удар по игроку
	 Time getLastHitTime() const;
	// возвращает координаты игрока
	 FloatRect getPosition() const;
	// возвращает центральные координаты игрока
	 Vector2f getCenter() const;
	// возвращает угол поворота игрока
	float getRotation() const;
	// возвращает копию спрайта игрока
	 Sprite getSprite() const;
	// рисуем игрока
	void draw( RenderWindow& win) const;
	// перемещаем игрока
	void move(playermove mov);
	// обновление игровой логики 
	void update( Time deltaTime,  Vector2i mousePosition);
	// увеличиваем максимальное количество здоровья 
	void upgradeHealth(float heal);
	// пополняем здоровье игрока
	void increaseHealthLevel(float amount);
	// возвращает сколько здоровья у игрока на данный момент?
	float getHealth() const;
	// возвращает максимальное здоровье игрока
	float getMaxHealth() const;

private:
	// стартовая жизнь игрока
	const float START_HEALTH = 200;
	// позиция игрока
	 Vector2f m_Position;
	// отображение игрока спрайт и  объект анимации
	 Sprite m_Sprite;
	Animator m_AnimPlayer = Animator(m_Sprite);
	// разрешение анимировать игрока
	bool m_animMove = false;
	// разрешение экрана
	 Vector2f m_Resolution;
	// размер игрового поля 
	 IntRect m_planet;
	// размер текстур игрового поля 
	int m_TileSize;
	// в каком направлении(ях) движется игрок в данный момент
	playermove m_move;
	// живой ли игрок
	bool m_live = true;
	// здоровье игрока
	float m_Health;
	// максимальное здоровье игрока
	float m_MaxHealth;
	// время нанесения последнего удара по игроку 
	 Time m_LastHit;
	// частота перемещения игрока
	 Time m_time_moving;
	// скорость перемещения игрока в пикселях в секунду
	float m_Speed;
	
};

