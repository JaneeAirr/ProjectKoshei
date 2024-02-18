#include "MonsterPlanet.h"
#include "Monster.h"

using namespace std;
using namespace sf;

int createBackground( VertexArray& rVA,  IntRect planet, int index)
{
    // будет использоваться для получения начального числа для механизма случайных чисел
     random_device rd;
     mt19937 gen(rd());
    // размер плитки
    const int TILE_SIZE = 200;
    // количество вариантов плиток
    const int TILE_TYPES = 9;
    // количество вершин
    const int VERTS_IN_QUAD = 4;
    // ширина мира
    int worldWidth = planet.width / TILE_SIZE;
    // высота мира
    int worldHeight = planet.height / TILE_SIZE;
    // тип примитива
    rVA.setPrimitiveType( Quads);
    // установить размер массива вершин
    rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);
    // начать с начала массива вершин
    int currentVertex = 0;

    for (int w = 0; w < worldWidth; w++)
    {
        for (int h = 0; h < worldHeight; h++)
        {
            // позиционируйте каждую вершину в текущем четырехугольнике
            rVA[currentVertex + 0].position =  Vector2f(static_cast<float>(w * TILE_SIZE), static_cast<float>(h * TILE_SIZE));
            rVA[currentVertex + 1].position =  Vector2f(static_cast<float>((w * TILE_SIZE) + TILE_SIZE), static_cast<float>(h * TILE_SIZE));
            rVA[currentVertex + 2].position =  Vector2f(static_cast<float>((w * TILE_SIZE) + TILE_SIZE), static_cast<float>((h * TILE_SIZE) + TILE_SIZE));
            rVA[currentVertex + 3].position =  Vector2f(static_cast<float>(w * TILE_SIZE), static_cast<float>((h * TILE_SIZE) + TILE_SIZE));

            // определяем позицию в текстуре для текущего четырехугольника
            // трава, камень, куст или стена
            if (h == 0 || h == worldHeight - 1 ||
                w == 0 || w == worldWidth - 1)
            {
                // Используем текстуру стены
                rVA[currentVertex + 0].texCoords =  Vector2f(TILE_SIZE * TILE_TYPES, TILE_SIZE*(index-1));
                rVA[currentVertex + 1].texCoords =  Vector2f(TILE_SIZE * TILE_TYPES + TILE_SIZE, TILE_SIZE*(index-1));
                rVA[currentVertex + 2].texCoords =  Vector2f(TILE_SIZE * TILE_TYPES + TILE_SIZE, TILE_SIZE*index);
                rVA[currentVertex + 3].texCoords =  Vector2f(TILE_SIZE * TILE_TYPES, TILE_SIZE*index);
            }
            else
            {
                 uniform_int_distribution<> dis(0, TILE_TYPES - 1); 
                // использовать случайную текстуру пола
                int mOrG = dis(gen);
                int verticalOffset = mOrG * TILE_SIZE;
                rVA[currentVertex + 0].texCoords =  Vector2f(static_cast<float>(verticalOffset), TILE_SIZE * (index - 1));
                rVA[currentVertex + 1].texCoords =  Vector2f(static_cast<float>(verticalOffset + TILE_SIZE), TILE_SIZE * (index - 1));
                rVA[currentVertex + 2].texCoords =  Vector2f(static_cast<float>(verticalOffset + TILE_SIZE), TILE_SIZE * index);
                rVA[currentVertex + 3].texCoords =  Vector2f(static_cast<float>(verticalOffset), TILE_SIZE * index);
            }

            // позиция готова для следующих четырех вершин
            currentVertex = currentVertex + VERTS_IN_QUAD;
        }
    }


    return TILE_SIZE;
}


int createHorde(int numMonster,  deque<Monster>& monster,  Vector2i type,  IntRect planet, int complexity)
{   
    auto min=  Vector2i(planet.left + 300, planet.top + 300);
	auto max=  Vector2i(planet.width - 300, planet.height - 300);
    int num = 0;
     random_device rd;
	 mt19937 gen(rd());
	 uniform_int_distribution<> rx(min.x, max.x);
	 uniform_int_distribution<> ry(min.y, max.y);
	 uniform_int_distribution<> rtype(type.x, type.y);
     Vector2f pos;
    int mtype;
	
	for (int i = 0; i < numMonster; i++){
		    
            mtype = rtype(gen);
		    pos.x = static_cast<float>(rx(gen));
			pos.y = static_cast<float>(ry(gen));
            monster.emplace_back();
            monster[i].spawn(pos.x, pos.y, mtype, complexity);
            num++;
	}
	
    return num;
}



