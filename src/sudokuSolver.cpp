

#include <iostream>
#include <fstream>
#include <string>

int drawBoard();
int updateSectors();
bool ruleVertical();
bool ruleHorizontal();
bool ruleSector();
int placeNum();

using namespace std;

int gridPos[9][9];
int tempGridPos[9][9];
int sectorPos[9][9];
int tempSectorPos[9][9];


int main(int argc, char* argv[]){

	

	fstream inputFile;
	inputFile.open("sudoku.txt");
	string line;
	
	for(int i = 0; i < 9 ; i++){
		getline(inputFile, line);
		for(int j = 0; j < 9; j++){
			gridPos[i][j] = line[j] - 48;
			tempGridPos[i][j] = gridPos[i][j];
		}
	}
	inputFile.close();

	drawBoard();

	if(ruleHorizontal){
		cout << "Horizontal rule success!" << endl;
	}
	else{
		cout << "Horizontal rule failed!" << endl;
	}
	if(ruleVertical){
		cout << "Vertical rule success!" << endl;
	}
	else{
		cout << "Vertical rule failed!" << endl;
	}
	if(ruleSector){
		cout << "Sector rule success!" << endl;
	}
	else{
		cout << "Sector rule failed!" << endl;
	}

	return 0;
}

int updateSectors(){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			int gridRow, gridCol;
			if(i == 0){
				gridRow = (j/3)+0;
				gridCol = j-((j/3)+0)*3;
			}
			if(i == 1){
				gridRow = (j/3)+0;
				gridCol = -3*((((j/3)+0)-1))+j;
			}
			if(i == 2){
				gridRow = (j/3)+0;
				gridCol = (2-((j/3)+0))*3+j;
			}

			if(i == 3){
				gridRow = (j/3)+3;
				gridCol = j-((j/3)+0)*3;
			}
			if(i == 4){
				gridRow = (j/3)+3;
				gridCol = -3*((((j/3)+0)-1))+j;
			}
			if(i == 5){
				gridRow = (j/3)+3;
				gridCol = (2-((j/3)+0))*3+j;
			}

			if(i == 6){
				gridRow = (j/3)+6;
				gridCol = j-((j/3)+0)*3;
			}
			if(i == 7){
				gridRow = (j/3)+6;
				gridCol = -3*((((j/3)+0)-1))+j;
			}
			if(i == 8){
				gridRow = (j/3)+6;
				gridCol = (2-((j/3)+0))*3+j;
			}
			
			sectorPos[i][j] = gridPos[gridRow][gridCol];
			//cout << "[" << i << "][" << j << "] -> [" << gridRow << "][" << gridCol << "]" << endl;
		}
		/*
		for(int j = 0; j < 9; j++){
			cout << sectorPos[i][j] << " "; 
		}
		cout << endl;
		*/
	}

/*

gridPos[(j/3)+0][(2-((j/3)+0))*3+j]
					2 - 1*3 +4

sectorPos[3][0] == gridPos[3][0];
sectorPos[3][1] == gridPos[3][1];
sectorPos[3][2] == gridPos[3][2];
sectorPos[3][3] == gridPos[4][0];
sectorPos[3][4] == gridPos[4][1];
sectorPos[3][5] == gridPos[4][2];
sectorPos[3][6] == gridPos[5][0];
sectorPos[3][7] == gridPos[5][1];
sectorPos[3][8] == gridPos[5][2];
*/


	return 0;
}

int drawBoard(){

	string topBottomLine = " ------- ------- ------- ";
	string left = "| ";
	string middle = " | ";
	string right = " |";
	string innerDivider = "|-------|-------|-------|";

	cout << topBottomLine << endl;
	cout << left << gridPos[0][0] << " " << gridPos[0][1] << " " << gridPos[0][2] << middle << gridPos[0][3] << " " << gridPos[0][4] << " " << gridPos[0][5] << middle << gridPos[0][6] << " " << gridPos[0][7] << " " << gridPos[0][8] << right << endl;
	cout << left << gridPos[1][0] << " " << gridPos[1][1] << " " << gridPos[1][2] << middle << gridPos[1][3] << " " << gridPos[1][4] << " " << gridPos[1][5] << middle << gridPos[1][6] << " " << gridPos[1][7] << " " << gridPos[1][8] << right << endl;
	cout << left << gridPos[2][0] << " " << gridPos[2][1] << " " << gridPos[2][2] << middle << gridPos[2][3] << " " << gridPos[2][4] << " " << gridPos[2][5] << middle << gridPos[2][6] << " " << gridPos[2][7] << " " << gridPos[2][8] << right << endl;
	cout << innerDivider << endl;
	cout << left << gridPos[3][0] << " " << gridPos[3][1] << " " << gridPos[3][2] << middle << gridPos[3][3] << " " << gridPos[3][4] << " " << gridPos[3][5] << middle << gridPos[3][6] << " " << gridPos[3][7] << " " << gridPos[3][8] << right << endl;
	cout << left << gridPos[4][0] << " " << gridPos[4][1] << " " << gridPos[4][2] << middle << gridPos[4][3] << " " << gridPos[4][4] << " " << gridPos[4][5] << middle << gridPos[4][6] << " " << gridPos[4][7] << " " << gridPos[4][8] << right << endl;
	cout << left << gridPos[5][0] << " " << gridPos[5][1] << " " << gridPos[5][2] << middle << gridPos[5][3] << " " << gridPos[5][4] << " " << gridPos[5][5] << middle << gridPos[5][6] << " " << gridPos[5][7] << " " << gridPos[5][8] << right << endl;
	cout << innerDivider << endl;
	cout << left << gridPos[6][0] << " " << gridPos[6][1] << " " << gridPos[6][2] << middle << gridPos[6][3] << " " << gridPos[6][4] << " " << gridPos[6][5] << middle << gridPos[6][6] << " " << gridPos[6][7] << " " << gridPos[6][8] << right << endl;
	cout << left << gridPos[7][0] << " " << gridPos[7][1] << " " << gridPos[7][2] << middle << gridPos[7][3] << " " << gridPos[7][4] << " " << gridPos[7][5] << middle << gridPos[7][6] << " " << gridPos[7][7] << " " << gridPos[7][8] << right << endl;
	cout << left << gridPos[8][0] << " " << gridPos[8][1] << " " << gridPos[8][2] << middle << gridPos[8][3] << " " << gridPos[8][4] << " " << gridPos[8][5] << middle << gridPos[8][6] << " " << gridPos[8][7] << " " << gridPos[8][8] << right << endl;
	cout << topBottomLine << endl;

	return 0;
}

bool ruleVertical(){

	int sum = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			sum += gridPos[j][i];
		}
	}
	if(sum > 45)
		return false;

	return true;
}

bool ruleHorizontal(){

	int sum = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			sum += gridPos[i][j];
		}
	}
	if(sum > 45)
		return false;

	return true;
}

bool ruleSector(){

	updateSectors();

	int sum = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			sum += sectorPos[i][j];
		}
	}
	if(sum != 45)
		return false;

	return true;
}

int placeNum(){

	

	return 0;
}

int solve(){

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(gridPos[i][j] == -16){
				placeNum();
			}
		}
	}

	return 0;
}