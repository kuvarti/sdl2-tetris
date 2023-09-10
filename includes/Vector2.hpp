#pragma once

class Vector2
{
public:
	Vector2()
	{
		_x = 0;
		_y = 0;
	};
	Vector2(int x, int y)
	{
		_x = x;
		_y = y;
	};
	Vector2(const Vector2 &v)
	{
		_x = v._x;
		_y = v._y;
	}
	Vector2 operator=(const Vector2 &v)
	{
		_x = v.getX();
		_y = v.getY();
		return *this;
	}

	int getX(void) const { return _x; };
	int getY(void) const { return _y; };

	void setX(int v) { _x = v; };
	void setY(int v) { _y = v; };
	void setVector(int x, int y)
	{
		_x = x;
		_y = y;
	};

private:
	int _x;
	int _y;
};
