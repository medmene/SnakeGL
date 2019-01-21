#pragma once
#include "CustomTypes.h"

bool inline Hover(int x, int y, Rect r) {
	if (x >= r.X)
		if (x < (r.X + r.width))
			if (y >= r.Y)
				if (y < (r.Y + r.height))
					return true;
	return false;
}
