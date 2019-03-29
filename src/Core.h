#include "stdafx.h"
#include "Plane.h"
#include "Pickup.h"

//Allows the use of point
using namespace System::Drawing;

//
public ref class Globals{
    public:
		//Constructor for Globals Class
		Globals();
		
		//Stores the score
		static int Score = 0;

		//Stores all the information about the player's player
		static Plane^ Player;/// = gcnew Plane;
		static array<Plane^>^ Enemies;// = gcnew array<Plane^>(5);

		//Allows the usage of pickups
		static Pickup^ PickupItem;

		//Stores the star locations
		static array<Point^>^StarLocations = gcnew array<Point^>(100);
		static array<int>^StarAlpha = gcnew array<int>(100);
		//Stores how fast the objects move
		static int ScrollingSpeed = 300;
		static int PlaneSpeed = 300;
		static const int MaxHealth = 1000;

		//Stores the numbers of planes on the screen
		static int NumberEnemies = 0;

		//Stores the size of the grid...
		static Size^ DisplayGrid = Size(16,12);
		static Size^ DisplayGridUnits = Size(16000, 12000);
		static int DisplayUnit = 1000;

		//Stores the graphicial display
		static Bitmap^ Canvas;
		//Stores whether the plane has crashed
		static bool IsPlayerCrashed = false;
		//Stores whether the user is playing survival or leveled game
		static bool IsPlayingLeveledGame = false;
		//Stores the file path for the leveled game
		static System::String^ GameFilePath = "";

		//Stores the leveled game data
		static int gLevelsCompleted;
		static int gTotalScore;
		static int gUpgradePoints;
		static int gBulletSpeed;
		static int gBulletDamage;
		static int gRateOfFire;
		static int gMaxHealth;
		static int gRegenerateHealth;

		//Stores the colours for the game
		static Color cPlayer = Color::Cyan;
		static Color cSprayer = Color::Yellow;
		static Color cSmasher = Color::FromArgb(255, 128, 0);
		static Color cStriker = Color::Red;
		static Color cPickup = Color::Green;
		static Color cBackground = Color::Black;
		static Color cMisc = Color::White;
		
};

void intialiseStars();

void moveStars();

void intialiseEnemy();

void moveEnemies();

void crashEnemy(int pIndex);

void updatePickup();


//Statistics file
void updateDataFile();

void readStatFile(int& pHigh, int& pAverage, int& pCount);

void writeStatFile(int pHigh, int pAverage, int pCount);

	//Leveled Game
void newLeveledGame();

void openLeveledGame();

void saveLeveledGame();

void startSurvialGame();

void startLeveledGame();

void playerCrash();

bool IsLevelCompleted();

void clearCurrentGame();

void explodeEnemies();

void readOptionFile();

void writeOptionFile();