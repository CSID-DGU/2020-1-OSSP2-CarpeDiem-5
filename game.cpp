#include "game.h"

int map[LENGTH][WIDTH];
int cnt;

void MapShow::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void MapShow::Move(int m, int x, int y)
{
	if (m == UP)
	{
		swap = map[y][x];
		map[y][x] = map[y - 1][x];
		map[y - 1][x] = swap;
	}
	else if (m == DOWN)
	{
		swap = map[y][x];
		map[y][x] = map[y + 1][x];
		map[y + 1][x] = swap;
	}
	else if (m == LEFT)
	{
		swap = map[y][x];
		map[y][x] = map[y][x - 1];
		map[y][x - 1] = swap;
	}
	else if (m == RIGHT)
	{
		swap = map[y][x];
		map[y][x] = map[y][x + 1];
		map[y][x + 1] = swap;
	}
}

void MapShow::MapBase()
{
	for (int j = 0; j < LENGTH; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			if (j == 0 || j == LENGTH - 1)
			{
				map[j][i] = WAL;
			}
			else if (i == 0 || i == WIDTH - 1)
			{
				map[j][i] = WAL;
			}
		}
	}
}

void MapShow::Mapping()
{
	for (int j = 0; j < LENGTH; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			if (map[j][i] == BLK)
			{
				cout << "  ";
			}
			else if (map[j][i] == WAL)
			{
				cout << "��";
			}
			else if (map[j][i] == PHD)
			{
				cout << "��";
			}
			else if (map[j][i] == PBD)
			{
				cout << "��";
			}
			else if (map[j][i] == PLW)
			{
				cout << "��";
			}
			else if (map[j][i] == PRW)
			{
				cout << "��";
			}
			else if (map[j][i] == BLT)
			{
				cout << "��";
			}
			else if (map[j][i] == MTR)
			{
				cout << "��";
			}
		}
		cout << endl;
	}
}

void MapShow::OperationKey()
{
	GotoXY(55, 10);
	cout << "         ���� �̵� : a";
	GotoXY(55, 11);
	cout << "       ������ �̵� : d";
	GotoXY(55, 12);
	cout << "         �Ѿ� �߻� : k";
	GotoXY(55, 13);
	cout << "              ���� : " << cnt;
	GotoXY(0, 0);
}

void MapShow::StartScreen()
{
	GotoXY(35, 28);
	cout << "������ �����Ϸ��� [n] Ű�� �����ÿ�" << endl;
}

void MapShow::EndScreen()
{
	MapBase();
	for (int j = 1; j < LENGTH - 1; j++)
	{
		for (int i = 1; i < WIDTH - 1; i++)
		{
			map[j][i] = BLK;
		}
	}
	Mapping();

	GotoXY(19, 11);
	cout << "GAME OVER !";
	GotoXY(19, 12);
	cout << "SCORE : " << cnt;
	GotoXY(35, 28);
	cout << "������ ����� �Ͻ÷��� [n] Ű�� �����ÿ�.";
	GotoXY(35, 29);
	cout << "������ ���� �Ͻ÷��� [m] Ű�� �����ÿ�.";
}

void MapShow::ClearMessage()
{
	GotoXY(0, 0);
	for (int i = 0; i < 40; i++)
		cout << "                                                                                        " << endl;
}

Meteor::Meteor(int mx, int my) : meteorX(mx), meteorY(my)
{
	map[my][mx] = MTR;
}

void Meteor::Move()
{
	if (map[meteorY + 1][meteorX] == BLK)
	{
		mapshow.Move(DOWN, meteorX, meteorY);
		meteorY++;
	}
	else if (map[meteorY + 1][meteorX] == WAL)
	{
		map[meteorY][meteorX] = BLK;
	}
	else if (map[meteorY + 1][meteorX] == PHD)
	{
		map[meteorY][meteorX] = BLK;
		map[meteorY + 1][meteorX] = BLK;
		map[meteorY + 2][meteorX] = BLK;
		map[meteorY + 2][meteorX - 1] = BLK;
		map[meteorY + 2][meteorX + 1] = BLK;
	}
	else if (map[meteorY + 1][meteorX] == PLW)
	{
		map[meteorY][meteorX] = BLK;
		map[meteorY + 1][meteorX] = BLK;
	}
	else if (map[meteorY + 1][meteorX] == PRW)
	{
		map[meteorY][meteorX] = BLK;
		map[meteorY + 1][meteorX] = BLK;
	}
	else
	{
		map[meteorY][meteorX] = BLK;
		map[meteorY + 1][meteorX] = BLK;
	}
}
int Meteor::GetMeteorX()
{
	return meteorX;
}
int Meteor::GetMeteorY()
{
	return meteorY;
}

MoveMeteor::MoveMeteor() : mCnt(0)
{
	for (int n = 0; n < METEORCOUNT; n++) meteor[n] = 0;
}

void MoveMeteor::MeteorDrop()
{
	int mt = rand() % 2;
	if (mt == 0)
	{
		int ex = rand() % (WIDTH - 2) + 1;

		if (map[1][ex] == BLK && map[2][ex] == BLK && mCnt < METEORCOUNT&&meteor[mCnt] == 0)
		{
			Meteor *_meteor = new Meteor(ex, 1);
			meteor[mCnt] = _meteor;
			mCnt++;
		}
		else if (mCnt == METEORCOUNT) mCnt = 0;
	}
}
void MoveMeteor::MeteorMove()
{
	for (int i = 0; i < METEORCOUNT; i++)
	{
		if (meteor[i] != 0)
		{
			meteor[i]->Move();
		}
		if (meteor[i] != 0 && map[meteor[i]->GetMeteorY()][meteor[i]->GetMeteorX()] == BLK)
		{
			delete meteor[i];
			meteor[i] = 0;
		}
	}
}

Bullet::Bullet(int bX, int bY) :bulletX(bX), bulletY(bY) {};

void Bullet::Move()
{

	if (map[bulletY - 1][bulletX] == BLK)
	{
		mapshow.Move(UP, bulletX, bulletY);
		bulletY--;
	}

	else if (map[bulletY - 1][bulletX] == WAL)
	{
		map[bulletY][bulletX] = BLK;
	}

	else if (map[bulletY - 1][bulletX] == MTR)
	{
		cnt += 100;
		map[bulletY][bulletX] = BLK;
		map[bulletY - 1][bulletX] = BLK;
	}
}

int Bullet::GetBulletX()
{
	return bulletX;
}
int Bullet::GetBulletY()
{
	return bulletY;
}

Projectile::Projectile() : bulletCount(0), reloadTime(1)
{
	for (int i = 0; i < BULLETCOUNT; i++)
	{
		b[i] = 0;
	}
}

void Projectile::BulletShot(int px, int py)
{
	if (bulletCount < BULLETCOUNT)
	{
		Bullet *bullet = new Bullet(px, py);
		map[py][px] = BLT;
		b[bulletCount] = bullet;
		bulletCount++;
	}
}
void Projectile::Move()
{
	for (int i = 0; i < BULLETCOUNT; i++)
	{
		if (b[i] != 0)
		{
			b[i]->Move();
			if (map[b[i]->GetBulletY()][b[i]->GetBulletX()] == BLK)
			{
				delete b[i];
				b[i] = 0;
			}
		}
	}
}
void Projectile::Reloading()
{
	if (bulletCount == BULLETCOUNT) reloadTime++;
	if (bulletCount == BULLETCOUNT && b[bulletCount - 1] == 0 && reloadTime % 25 == 0)
	{
		bulletCount = 0;
		reloadTime = 1;
	}
}
void Projectile::ProjectileCount()
{
	cout << endl; cout << "       Bullet Count : ";
	if (BULLETCOUNT - bulletCount == 5) cout << "������                              ";
	else if (BULLETCOUNT - bulletCount == 4) cout << "�����                                ";
	else if (BULLETCOUNT - bulletCount == 3) cout << "����                                  ";
	else if (BULLETCOUNT - bulletCount == 2) cout << "���                                    ";
	else if (BULLETCOUNT - bulletCount == 1) cout << "��                                      ";
	else if (BULLETCOUNT - bulletCount == 0) cout << "                                        ";
}

Plane::Plane(int px = 3, int py = 23) : planeX(px), PlaneY(py)
{
	map[PlaneY][planeX] = PBD;
	map[PlaneY - 1][planeX] = PHD;
	map[PlaneY][planeX - 1] = PLW;
	map[PlaneY][planeX + 1] = PRW;
}

void Plane::MovePlane(char m)
{
	if (m == 'a'&&map[PlaneY][planeX - 1] == PLW && map[PlaneY][planeX - 2] == BLK)
	{
		if (map[PlaneY][planeX - 1] == PLW) mapshow.Move(LEFT, planeX - 1, PlaneY);
		if (map[PlaneY][planeX] == PBD) mapshow.Move(LEFT, planeX, PlaneY);
		if (map[PlaneY - 1][planeX] == PHD) mapshow.Move(LEFT, planeX, PlaneY - 1);
		if (map[PlaneY][planeX + 1] == PRW) mapshow.Move(LEFT, planeX + 1, PlaneY);
		planeX--;
	}

	else if (m == 'd'&&map[PlaneY][planeX + 1] == PRW && map[PlaneY][planeX + 2] == BLK)
	{
		if (map[PlaneY][planeX + 1] == PRW) mapshow.Move(RIGHT, planeX + 1, PlaneY);
		if (map[PlaneY][planeX] == PBD) mapshow.Move(RIGHT, planeX, PlaneY);
		if (map[PlaneY - 1][planeX] == PHD) mapshow.Move(RIGHT, planeX, PlaneY - 1);
		if (map[PlaneY][planeX - 1] == PLW) mapshow.Move(RIGHT, planeX - 1, PlaneY);
		planeX++;
	}

	else if (m == 'a'&&map[PlaneY][planeX - 1] == BLK && map[PlaneY][planeX - 1] == BLK)
	{
		if (map[PlaneY][planeX - 1] == PLW) mapshow.Move(LEFT, planeX - 1, PlaneY);
		if (map[PlaneY][planeX] == PBD) mapshow.Move(LEFT, planeX, PlaneY);
		if (map[PlaneY - 1][planeX] == PHD) mapshow.Move(LEFT, planeX, PlaneY - 1);
		if (map[PlaneY][planeX + 1] == PRW) mapshow.Move(LEFT, planeX + 1, PlaneY);
		planeX--;
	}

	else if (m == 'd'&&map[PlaneY][planeX + 1] == BLK && map[PlaneY][planeX + 1] == BLK)
	{
		if (map[PlaneY][planeX + 1] == PRW) mapshow.Move(RIGHT, planeX + 1, PlaneY);
		if (map[PlaneY][planeX] == PBD) mapshow.Move(RIGHT, planeX, PlaneY);
		if (map[PlaneY - 1][planeX] == PHD) mapshow.Move(RIGHT, planeX, PlaneY - 1);
		if (map[PlaneY][planeX - 1] == PLW) mapshow.Move(RIGHT, planeX - 1, PlaneY);
		planeX++;
	}

	else if (m == 'k')
	{
		projectile.BulletShot(planeX, PlaneY - 2);
		MapShow::GotoXY(0, 0);
		mapshow.Mapping();
		projectile.ProjectileCount();
	}
}

void Plane::MoveProjectile()
{
	projectile.Move();
}
void Plane::CountProjectile()
{
	projectile.ProjectileCount();
}
void Plane::ReloadProjectile()
{
	projectile.Reloading();
}
int Plane::GetPlaneX()
{
	return planeX;
}
int Plane::GetPlaneY()
{
	return PlaneY;
}

ShootingGame::ShootingGame() : turn(true)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void ShootingGame::Start()
{
	mapshow.ClearMessage();
	mapshow.StartScreen();

	while (key != 'n')
	{
		key = _getch();

		if (key == 'n')
		{
			mapshow.ClearMessage();
			MapShow::GotoXY(0, 0);
			srand((unsigned)time(NULL));
			GameStart();
			break;
		}
	}
}

void ShootingGame::GameStart()
{
	mapshow.MapBase();
	mapshow.Mapping();
	plane.CountProjectile();
	mapshow.OperationKey();
	int time = 1;
	while (turn)
	{
		if (_kbhit())
		{
			char ch = _getch();
			plane.MovePlane(ch);
		}
		plane.MoveProjectile();
		plane.ReloadProjectile();
		if (time % 3 == 0) meteor.MeteorDrop();
		if (time % 2 == 0) meteor.MeteorMove();
		MapShow::GotoXY(0, 0);
		mapshow.Mapping();
		plane.CountProjectile();
		mapshow.OperationKey();
		GameOver();
		if (!turn)
		{
			End();
		}
		time++;
	}
}

void ShootingGame::GameOver()
{
	if (map[plane.GetPlaneY()][plane.GetPlaneX()] == BLK)
	{
		turn = false;
	}
	if (map[plane.GetPlaneY() - 1][plane.GetPlaneX()] == BLK)
	{
		turn = false;
	}
}

void ShootingGame::End()
{
	mapshow.EndScreen();

	while (1)
	{
		key = _getch();

		if (key == 'n')
		{
			Restart();
		}
		else if (key == 'm')
		{
			return;
		}
	}
}

void ShootingGame::Restart()
{
	cnt = 0;
	turn = true;
	PlayGame();
}

void PlayGame()
{
	ShootingGame shootingGame;
	shootingGame.Start();
}