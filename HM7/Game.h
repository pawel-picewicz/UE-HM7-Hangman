#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Shape.h"

using namespace std;

class Game
{
public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltaTime);
	void OnRender();
	void OnShutdown();

	~Game();

private: 
	vector<Shape*> m_vpShapes;
	vector<string> m_vWordsPool;
	string m_sCurrentWord;
	vector<bool> m_bGuessedLetters;
	char m_lastLetter;
	int m_iFails = 0;
	bool m_bWin = false;
};

