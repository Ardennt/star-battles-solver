#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>


/*
This is just class declaration for the grid with no comments,
for commens of what each function does, please refer to .cpp file
for grid.
*/

class grid{
private:
    int row;
    int col;
    int numstars;
    std::vector<std::vector<int> > board;
    std::vector<std::vector<int> > boardTrack;
    std::vector<std::string> strrep;
    std::vector<std::vector<int> > coords;
    std::vector<int> star_loc;
    std::vector<std::vector<int> > allresults; 


public:
    grid(std::ifstream& myfile, const int& numS);

    void readFile(std::ifstream& file);

    int getRow() const{
        return row;
    }

    int getCol() const{
        return col;
    }

    void clearBoard();
    void blockSurrounding(const int& x, const int& y, std::vector<std::vector<int> >& boardT);
    void place(const int& x, const int& y, std::vector<std::vector<int> >& boardT);
    void tryplace(int x, int y);
    void printStarLoc();
    void printResult();
    void printSolutions(std::ofstream& outfile);
    void printBoard(std::ofstream& outfile);
    void printZoneTrack();
    void printBoardTrack();
    bool all_valid(const std::vector<int>& starLOC);
    void solveBoard(int zoneI, std::vector<int>& starPlacements, 
        std::vector<std::vector<int> >& result, const bool& one_or_all);
    void callRecursion(const std::string& solutions);
    
};

bool sortByVecSize(std::vector<int>& a, std::vector<int>& b);

std::vector<std::vector<int> >groupVector(const std::vector<int>& yourVec);

#endif