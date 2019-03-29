#include "stdafx.h"
#include "Plane.h"

//Allows the type Bitmap to be used
using namespace System::Drawing;

using namespace System::Windows::Forms;

Bitmap^ drawDisplay(Size pDisplaySize);

void drawPlayer(Graphics^ pPaint, Size pDisplaySize);

void drawPlayerBullets(Graphics^ pPaint, Size pDisplaySize);

void drawStars(Graphics^ pPaint, Size pDisplaySize);

void drawEnemies(Graphics^ pPaint, Size pDisplaySize);

void drawEnemiesBullets(Graphics^ pPaint, Size pDisplaySize);

void drawText(Graphics^ pPaint, Size pDisplaySize);

void drawGameOver(Graphics^ pPaint, Size pDisplaySize);

void drawHealth(Graphics^ pPaint, Size pDisplaySize);

void drawGradient(Graphics^ pPaint, Size pDisplaySize);

void drawPickup(Graphics^ pPaint, Size pDisplaySize);