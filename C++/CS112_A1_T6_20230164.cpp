/* 
Program: This game has a 4x4 board representing each cell with a number. 
Each player should choose two numbers to obtain a rectangle of this board 
and the last player to get the last obtainable rectangle wins
Author:  Ziad Walid Mohamed 20230164
Version: 2
Date: 3 March 2024
*/

#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'

// Function to check if the selected numbers form a valid rectangle and if they have been selected before
bool check( vector<vector<string>> &v,vector<string> &selected , string &choice1 ,
         string &choice2, bool a1 = false , bool a2 = false){

    int row1 , col1 , row2 , col2 , rowDiff , colDiff;
    // Check if the two choices are the same
    if( choice1 == choice2){
        cout<< "INVALID INPUT!" << endl << "Choose two different numbers."<< endl;
        return false;
    }
    // Check if one of the choices has been selected before
    if(!selected.empty()){
        for (int i = 0; i < selected.size(); ++i){
            if(choice1 == selected[i] or choice2 == selected[i]) {
                cout <<"INVALID INPUT!" <<endl << "One of the choices was seleceted before." << endl;
                return false;
            }
        } 
    }
    // Find the row and column indices of the choices
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if(v[i][j] == choice1){
                a1 = true;
                row1 = i, col1 = j;
            }
            else if(v[i][j] == choice2){
                a2 = true;
                row2 = i, col2 = j;
            }
        }
    }
    // Check the distane between the two choices
    if(a1 and a2) {
        rowDiff = abs(row1 - row2);
        colDiff = abs(col1 - col2);
        // Check if the choices are adjacent to each other and form a valid rectangle
        if ((rowDiff == 1 && colDiff == 0) || (rowDiff == 0 && colDiff == 1)) return true;
        else {
            cout << "INVALID INPUT!" << endl << "The two numbers weren't adjacent (didn't form a rectangle)." <<endl;
            return false;
        }
    }
    else{
        cout << "INVALID INPUT!" << endl;
        return false;
    }
}
// Function to check if there's a winner
bool winner(vector <vector<string>> &v){
    // Check for adjacent numbers in the 4x4 matrix
    for (int i = 0; i < 3; ++i){
       for (int j = 0; j < 3; ++j){
            if(v[i][j] != "X" and (v[i+1][j] != "X" or v[i][j+1] != "X")) return false;
       }
    }
    // Check for adjacent numbers in the last row and column
    for (int i = 0; i < 3; ++i)
    {
        if(v[3][i] != "X" and (v[2][i] != "X" or v[3][i+1] != "X")) return false;
        else if(v[i][3] != "X" and (v[i][2] != "X" or v[i+1][3] != "X")) return false;
    }
    
    return true; // If no adjacent numbers found, return true (winner)
}
// Function to handle player 1's turn
void menu1(vector <vector<string>> &v, vector<string> &selected, string &choice1 , string &choice2 ){
    while(true){
        cout << "Player 1" << endl;
        cout << "+------+------+------+------+" << endl;
        for (int i = 0; i < 4; ++i){
            cout << "| ";
            for (int j = 0; j < 4; ++j){
                cout << setw(4) << v[i][j] << " | ";
            }
            cout << endl << "+------+------+------+------+" << endl;
        }
        cout << "Please choose two numbers that represent a rectangle (adjacent to each other) from this matrix: ";
        cin >> choice1 >> choice2;
        if(!check(v,selected , choice1 ,choice2)) continue;
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                if(v[i][j] == choice1 or v[i][j] == choice2){
                    selected.push_back(v[i][j]);
                    v[i][j] = "X";
                }
            }  
        }
        return;
    }
}
// Function to handle player 2's turn
void menu2(vector <vector<string>> &v, vector<string> &selected, string &choice1 , string &choice2 ){
    while(true){
        cout << "Player 2" << endl;
        cout << "+------+------+------+------+" << endl;
        for (int i = 0; i < 4; ++i){
            cout << "| ";
            for (int j = 0; j < 4; ++j){
                cout << setw(4) << v[i][j] << " | ";
            }
            cout << endl << "+------+------+------+------+" << endl;
        }
        cout << "Please choose two numbers that represent a rectangle (adjacent to each other) from this matrix: ";
        cin >> choice1 >> choice2;
        if(!check(v,selected , choice1 ,choice2)) continue;
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                if(v[i][j] == choice1 or v[i][j] == choice2){
                    selected.push_back(v[i][j]);
                    v[i][j] = "X";
                }
            }   
        }
        return;
    }
}
int main(){
    vector <vector <string>> v = {{"1","2","3","4"} , {"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"}};
    vector <string> selected;
    cout << "Welcome to Two Squares game!" << endl;
    string choice1,choice2;
    while (true){
        menu1(v,selected,choice1,choice2);
        if(winner(v)){
            cout << "Player 1 wins!" << endl;
            break;
        }
        menu2(v,selected,choice1,choice2);
        if(winner(v)){
            cout << "Player 2 wins!" << endl;
            break;
        }
    }
    return 0;
}