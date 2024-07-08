#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class Shape
{
public:
	void Print(ostream& stm) const {
		for (string s : m_vLines) {
			stm << s << endl;
		}		
	}

private:
	vector<string> m_vLines;
	void AddLine(string s) {
		m_vLines.push_back(s);
	}
	

public:
	static void LoadShapes(vector<Shape*>& shapes) {
 
		int status = 0;
		string line;
		ifstream myfile("hangman.txt");		
		Shape* pcurrent = new Shape();
		if (myfile.is_open())
		{
			while (getline(myfile, line)) {				
				if (status == 0) { // source of ASCII ART
					status = 1;
					continue;
				}

				if (line == "END") {
					shapes.push_back(pcurrent);
					pcurrent = new Shape();
					continue;
				} if (line == "END-FILE") {
					shapes.push_back(pcurrent);
					break;
				}
				else {
					pcurrent->AddLine(line);
				}
											
			}
			myfile.close();
		}
		else cout << "Unable to open file with shapes (hangman.txt)";
		/*
		for (auto s : shapes) {			 
			s->Print(cout);			
		}
		*/
	}
};

