#pragma once
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define LENGTH 25 
#define WIDTH 25
#define SPACE 32
#define BULLETCOUNT 5
#define METEORCOUNT 30

using namespace std;

enum { BLK, WAL, PHD, PBD, PLW, PRW, BLT, MTR };
enum { UP, DOWN, LEFT, RIGHT };

class MapShow
{
private:
	int swap;
public:
	static void GotoXY(int, int);
	void Move(int, int, int);

	void MapBase();
	void Mapping();
	void OperationKey();
	void StartScreen();
	void EndScreen();
	void ClearMessage();
};

class Meteor
{
private:
	int meteorX, meteorY;
	MapShow mapshow;
public:
	Meteor(int, int);

	void Move();
	int GetMeteorX();
	int GetMeteorY();
};

class MoveMeteor
{
private:
	int mCnt;
	Meteor *meteor[METEORCOUNT];
public:
	MoveMeteor();

	void MeteorDrop();
	void MeteorMove();
};

class Bullet
{
private:
	int bulletX, bulletY;
	MapShow mapshow;
public:
	Bullet(int, int);

	void Move();
	int GetBulletX();
	int GetBulletY();
};

class Projectile
{
private:
	int bulletCount, reloadTime;
	Bullet *b[BULLETCOUNT];
public:
	Projectile();

	void BulletShot(int, int);
	void Move();
	void Reloading();
	void ProjectileCount();
};

class Plane
{
private:
	int planeX, PlaneY;
	MapShow mapshow;
	Projectile projectile;
public:
	Plane(int, int);

	void MovePlane(char);
	void MoveProjectile();
	void CountProjectile();
	void ReloadProjectile();
	int GetPlaneX();
	int GetPlaneY();
};

class ShootingGame
{
private:
	char key;
	bool turn;
	MapShow mapshow;
	Plane plane;
	MoveMeteor meteor;
public:
	ShootingGame();

	void Start();
	void GameStart();
	void GameOver();
	void End();
	void Restart();
};

void PlayGame();