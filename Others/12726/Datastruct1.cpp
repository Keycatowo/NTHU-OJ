// Datastruct1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void try_block();
void block_addition(int, int, int, vector<vector<string>>block, vector<vector<string>>objective);
void print_objective(vector<vector<string>>objective);


int main(int argc, const char* argv[]) {
	int number_blocks, height, width;
	int num_sol, h2, w2;
	int j = 0, m = 0;
	string temp;
	cin >> number_blocks;
	vector<vector<string>> block;
	vector<vector<string>> objective;
	//-----------------input--------------
	block.resize(number_blocks);
	while (number_blocks--) {
		cin >> width >> height;
		while (height--) {
			cin >> temp;
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == 'O')
					temp[i] = '1' ;//change to character 1 to perform addition
				else
					temp[i] = '0' ;
			}	
			block[j].push_back(temp);
		}
		j++;
	}
	cin >> num_sol;
	objective.resize(num_sol);
	while (num_sol--) {
		cin >> w2 >> h2;
		while (h2--) {
			cin >> temp;
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == 'O')
					temp[i] = '1'-48 ; //change to character 1 to perform addition
				else
					temp[i] = '0' ;
			}
			objective[m].push_back(temp);
		}
		m++;
	}

	//--------- try puzzle------
	int i1 = 0, j1 = 0, k1 = 0;//to determine objective for blocks to perform addition
	//---------start adding objective with block, if 2 appears,then the block is occupied
	//---------stuck block1 in and see if fit, then put block2 in. if block2 doesn't fit, put block1 back to check for other spots
	block_addition(i1, j1, k1, block, objective);
	print_objective(objective);

	return 0;
}
void block_addition(int i1, int j1, int k1, vector<vector<string>>block, vector<vector<string>>objective) {
	for (int i = 0; i < block.size(); i++) {
		for (int j = 0; j < block[i].size(); j++) {
			for (int k = 0; k < block[i][j].size(); k++) {
				objective[i1][j + j1][k + k1] = block[i][j][k] + objective[i1][j + j1][k + k1];
			}
		}
	}
}
void print_objective(vector<vector<string>>objective) {
	for (int i = 0; i < objective.size(); i++) {
		cout << "objective" << i + 1 << endl;
		for (int k = 0; k < objective[i].size(); k++) {
			cout << objective[i][k] << endl;
		}
		cout << "---------------------" << endl;
	}
}

//----------------test input-------------------
/*for (int i=0; i<block.size();i++){
	cout << "block"<< i+1 << endl;
	for(int k =0; k<block[i].size(); k++){
		cout << block[i][k] << endl;
	}
	cout <<"---------------------"<<endl;
	}
	for (int i=0; i<objective.size();i++){
		cout << "objective"<< i+1 << endl;
		for(int k =0; k<objective[i].size(); k++){
			cout << objective[i][k] << endl;
		}
		cout <<"---------------------"<<endl;
	}*/

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
