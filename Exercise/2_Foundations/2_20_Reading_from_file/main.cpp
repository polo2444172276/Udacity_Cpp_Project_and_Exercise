#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(const std::string & path){
    std::ifstream file;
    file.open(path);
    std::string line;
    if (!file){
        cout << "error opening the file!" << endl;
        return;
    }
    while(getline(file, line)){
        cout << line << endl;
    }
}

// PrintBoard not used in this exercise
void PrintBoard(const std::vector<std::vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

int main()
{
    // TODO: Call the ReadBoardFile function here.
    std::string path = "files/1.board";
    ReadBoardFile(path);
    // Leave the following line commented out.
    //PrintBoard(board);

    return 0;
}