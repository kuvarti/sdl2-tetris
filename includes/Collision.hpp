#include <vector>
#include "Vector2.hpp"

class Collision
{
public:
	enum conflict
	{
		up,
		down,
		right,
		left,
		none
	};
	Collision();
	Collision(Vector2 size, Vector2 *pos);
	void setSize(Vector2 size);
	//conflict IsConflict(std::vector<GameObject *> *OtherObjets);
	//bool IsConflict(std::vector<GameObject *> *OtherObjets, conflict direction); // TODO
	~Collision();

private:
	Vector2 size;
	Vector2 *pos;
};
