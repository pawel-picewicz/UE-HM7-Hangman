// HM7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
 

#include "Game.h"


void Initialize();
void GetInput();
void Update(float deltaTime);
void Render();
void Shutdown();


bool g_exitGame = false;
Game g_game;


 

int main()
{
	 
	Initialize();

	while (!g_exitGame)
	{
		GetInput();
		Update(0.0f);
		Render();
	}

	Shutdown();

	return 0;
}

void Initialize()
{
	g_game.OnInit();
}

void GetInput()
{
	g_game.OnInput();
}

void Update(float deltaTime)
{
	g_exitGame = g_game.OnUpdate(deltaTime);	
}

void Render()
{
	g_game.OnRender();
}

void Shutdown()
{
	g_game.OnShutdown();
}



 