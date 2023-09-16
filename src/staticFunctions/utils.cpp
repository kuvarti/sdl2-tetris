#include "utils.hpp"

int getFixedScreenRatio(int w, int h)
{
	int fixedw = w / 20;
	int fixedh = h / 20;
	if (fixedw < fixedh)
		return fixedw;
	else
		return fixedh;
}

Vector2 adjustCanvasSizeToAspectRatio(int width, int height, double targetAspectRatio)
{
	double currentAspectRatio = width / height;
	Vector2 newSize;

	if (currentAspectRatio > targetAspectRatio) {
		double newWidth = height * targetAspectRatio;
		newSize = Vector2(newWidth, height);
	} else {
		double newHeight = width / targetAspectRatio;
		newSize = Vector2(width, newHeight);
	}
	return newSize;
}
