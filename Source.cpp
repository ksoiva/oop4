
//Створити базовий клас СПОРТИВНА УНІВЕРСІАДА(задаються назва і дата проведення).
//Створити похідні класи ЗМАГАННЯ МІЖ 2 КОМАНДАМИ(задаються дані про двох суперників, кількість очок(голів), набраних кожним з них проти іншого) 
//Для введених даних про різні змагання визначити загальну кількість перемог учасників від кожного університету
//і відсортувати університети за зростанням цієї кількості.

#include <iostream>
#include <string>
#define N 20
using namespace std;

struct Team {
	string uni;
	int wins = 0;
}*teams;

class Universiada {
protected:
	string name;
	string date;
public:
	Universiada() {
		name = {};
		date = {};
	}
	Universiada(string vname, string vdata) {
		name = vname;
		date = vdata;
	}
	void InputInfo() {
		cout << "Input name of universiade:  ";
		getline(cin, name);
		cout << "Input date of the event:  ";
		cin >> date;
	}
};

class Competition : Universiada {
private:
	string team1;
	string team2;
	int score1;
	int score2;
public:

	Competition(){
		team1 = {};
		team2 = {};
		score1 = 0;
		score2 = 0;
	}

	void Input(string t1, string t2) {
		team1 = t1;
		team2 = t2;
		cout << "Score of " << team1 << ":  ";
		cin >> score1;
		cout << "Score of " << team2 << ":  ";
		cin >> score2;
	}

	int Compare() {
		if (score1 > score2) {
			return 1;
		}
		if (score2 > score1) {
			return 2;
		}
		if (score1 = score2) {
			return 0;
		}
	}

	string AddWin(int id1, int id2) {
		int result = Compare();
		if (result == 1) {
			teams[id1].wins++;
			return (teams[id1].uni + " wins");
		}
		if (result == 2) {
			teams[id2].wins++;
			return (teams[id2].uni + " wins");
		}
		if (result == 0) {
			return "Draw";
		}
	}

	string Info(){
		InputInfo();
		return name + "  " + date;

	}
};

void InputTeams(int size) {
	for (int i = 0; i < size; i++) {
		cout << "Team " << i + 1 << ":  ";
		cin >> teams[i].uni;
	}
}

void Winner(Competition comp[], int size) {
	int k;
	int n = 0;
	for (int i = 0; i < size - 1; i++) {
		for (k = i + 1; k < size; k++) {
			cout << endl << "Competition between " << teams[i].uni << " and " << teams[k].uni << endl;
			comp[n].Input(teams[i].uni, teams[k].uni);
			cout << "Result:  " << comp[n].AddWin(i, k) << endl;
		}
	}
}

void OutputRes(int size) {
	cout << "\n\t\t  Team\t\tScore" << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << "\t\t  " << teams[i].uni << "\t\t  " << teams[i].wins << endl;
	}
}

void Sort(int size) {
	Team temp;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (teams[i].wins > teams[j].wins) {
				temp = teams[j];
				teams[j] = teams[i];
				teams[i] = temp;
			}
		}
	}
}

int main() {
	int size = 3;
	Competition* comp;
	comp = new Competition[size * 2];
	string info = comp->Info();
	cout << "Number of teams:  ";
	cin >> size;
	teams = new Team[size];
	InputTeams(size);
	Winner(comp, size);
	cout << endl << "\tFinal results of " << info << endl;
	OutputRes(size);
	Sort(size);
	cout << endl << "\tSorted results of " << info << endl;
	OutputRes(size);
	delete[] comp;
	delete[] teams;
	return 0;
}