#pragma once

#define SAFE_DELETE(p) if (p != nullptr) {delete p; p = nullptr;}
#define MAP_WIDTH 6
#define MAP_HEIGHT 6