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
	//масштаб
	 Vector2f  m_scale{1,1};   

	 Vector2f m_resolution;

	// патроны в интерфейсе
	 Sprite spriteAmmoIcon;

	// текст
	 Text levelText;
	 Text ammoText;
	 Text scoreText;
	 Text hiScoreText;
	 Text monsterRemainingText;
	 Text levelNumberText;
	 Text HelpText;

	// линия жизни
	 RectangleShape healthBar;
	 RectangleShape healthBar1;

	std::array< String, 6> m_deadText{L"Никогда не давай страху поражения удержать тебя от игры",L"Когда мне тяжело, я всегда напоминаю себе о том,\n\t что если я сдамся – лучше не станет"
	,L"Мы никогда не потерпим поражения,\n пока душа готова побеждать ...",L"Успеха часто добиваются те, кто не подозревает\n\t\t о неизбежности поражения",
		L"Я могу принять поражение, но я не могу принять\n\t\t\t отсутствие попыток",L"Никакая победа не принесет столько, \nсколько может отнять одно поражение"
	};

	std::array< String, 6> m_victoriqText{ L"Победа над другими даёт силу,\n победа над собой — бесстрашие",L"Величайшая победа —\n победа над самим собой",
		L"В жизни есть более важные вещи,\n\t чем победа и поражение",L"Тактика победителя — убедить врага в том,\n\t\t что он делает всё правильно",
		L"У победителя много друзей, и лишь\n у побежденного они настоящие",L"Пришел, увидел, победил."
	};

	 Text m_text;	
	
public:

	explicit GameText( Vector2f m_resolution);

	void update(GameHubText Hub);

	void draw( RenderWindow& window);

	 Vector2f getScale(); // возвращает масштаб

	void drawText( RenderWindow& window);

	void genText(std::string str);

	void drawGameOver( RenderWindow& window);

	void drawAssistant( RenderWindow& window, int num);

};

