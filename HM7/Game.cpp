
#include <iostream>
#include <vector>

#include "Game.h"

 
#include "Shape.h"


using namespace std;

 


void Game::OnInit() { 
	Shape::LoadShapes(m_vpShapes);
	string line;
	ifstream myfile("words.txt");	
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			m_vWordsPool.push_back(line);
			cout << line << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file with shapes (hangman.txt)";
	srand(time(NULL));
	m_sCurrentWord = m_vWordsPool[rand() % m_vWordsPool.size()];
	for (int i = 0; i < m_sCurrentWord.size(); i++) {
		m_bGuessedLetters.push_back(false);
	}
	OnRender();
}
void Game::OnInput() {	
	cin >> m_lastLetter;
}

bool Game::OnUpdate(float deltaTime) 
{ 
	if (m_lastLetter == '0') return true; // exit game
	bool guessed = false;
	for (int i = 0; i < m_sCurrentWord.size(); i++) {		
		if (m_sCurrentWord[i] == m_lastLetter) {
			m_bGuessedLetters[i] = true;
			guessed = true;
		}		
	}

	if (guessed == false) {
		m_iFails++;
		if (m_iFails == 5) return true;
	}
	else {
		bool win = true;
		for (bool b : m_bGuessedLetters) {
			if (b == false) {
				win = false;
				break;
			}
		}
		if (win) {
			m_bWin = true;
			return true;
		}
	}
	return false;
}
void Game::OnRender() 
{ 
	system("cls");
	m_vpShapes[m_iFails]->Print(cout);
	cout << "Current word: "; 
	for (int i = 0; i < m_bGuessedLetters.size(); i++) {
		if (m_bGuessedLetters[i]) {
			cout << m_sCurrentWord[i];			
		}
		else {
			cout << "_";
		}
	}
	cout << endl;
	if (m_bWin) cout << "You win!" << endl << endl;
	else {
		if (m_iFails == 5) cout << "You lose! The word is: " << m_sCurrentWord << endl << endl;
		else cout << "Enter a letter (0 - quit): ";
	}
	
}
void Game::OnShutdown() { }


Game::~Game() {
	for (auto s : m_vpShapes) {
		delete s;
	}	
}