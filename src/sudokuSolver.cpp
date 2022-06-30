

#include <iostream>
#include <fstream>
#include <string>

int drawBoard();

using namespace std;

int grid[9][9];

int main(int argc, char* argv[]){

	fstream inputFile;
	inputFile.open("sudoku.txt");
	string line;
	
	for(int i = 0; i < 9 ; i++){
		getline(inputFile, line);
		for(int j = 0; j < 9; j++){
			grid[i][j] = line[j] - 48;
		}
	}
	inputFile.close();

	drawBoard();

	return 0;
}

int drawBoard(){

	string topBottomLine = " ------- ------- ------- ";
	string left = "| ";
	string middle = " | ";
	string right = " |";
	string innerDivider = "|-------|-------|-------|";

	cout << topBottomLine << endl;
	cout << left << grid[0][0] << " " << grid[0][1] << " " << grid[0][2] << middle << grid[0][3] << " " << grid[0][4] << " " << grid[0][5] << middle << grid[0][6] << " " << grid[0][7] << " " << grid[0][8] << right << endl;
	cout << left << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << middle << grid[1][3] << " " << grid[1][4] << " " << grid[1][5] << middle << grid[1][6] << " " << grid[1][7] << " " << grid[1][8] << right << endl;
	cout << left << grid[2][0] << " " << grid[2][1] << " " << grid[2][2] << middle << grid[2][3] << " " << grid[2][4] << " " << grid[2][5] << middle << grid[2][6] << " " << grid[2][7] << " " << grid[2][8] << right << endl;
	cout << innerDivider << endl;
	cout << left << grid[3][0] << " " << grid[3][1] << " " << grid[3][2] << middle << grid[3][3] << " " << grid[3][4] << " " << grid[3][5] << middle << grid[3][6] << " " << grid[3][7] << " " << grid[3][8] << right << endl;
	cout << left << grid[4][0] << " " << grid[4][1] << " " << grid[4][2] << middle << grid[4][3] << " " << grid[4][4] << " " << grid[4][5] << middle << grid[4][6] << " " << grid[4][7] << " " << grid[4][8] << right << endl;
	cout << left << grid[5][0] << " " << grid[5][1] << " " << grid[5][2] << middle << grid[5][3] << " " << grid[5][4] << " " << grid[5][5] << middle << grid[5][6] << " " << grid[5][7] << " " << grid[5][8] << right << endl;
	cout << innerDivider << endl;
	cout << left << grid[6][0] << " " << grid[6][1] << " " << grid[6][2] << middle << grid[6][3] << " " << grid[6][4] << " " << grid[6][5] << middle << grid[6][6] << " " << grid[6][7] << " " << grid[6][8] << right << endl;
	cout << left << grid[7][0] << " " << grid[7][1] << " " << grid[7][2] << middle << grid[7][3] << " " << grid[7][4] << " " << grid[7][5] << middle << grid[7][6] << " " << grid[7][7] << " " << grid[7][8] << right << endl;
	cout << left << grid[8][0] << " " << grid[8][1] << " " << grid[8][2] << middle << grid[8][3] << " " << grid[8][4] << " " << grid[8][5] << middle << grid[8][6] << " " << grid[8][7] << " " << grid[8][8] << right << endl;
	cout << topBottomLine << endl;

	return 0;
}
