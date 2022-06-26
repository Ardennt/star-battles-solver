#include "grid.h"

// declaration of grid which takes in an input file
grid::grid(std::ifstream& myfile, const int& numS){
    // the first two inputs are the row and column
    myfile >> row;
    myfile >> col;
    numstars = numS;
    // board representation, board will contain -1 for stars
    board = std::vector<std::vector<int> >(col, std::vector<int>(row, 0));
    // tracks where in the board a star may be placed: board will be -1 
    // if a place cannot be placed
    boardTrack = std::vector<std::vector<int> >(col, std::vector<int>(row, 0));
    // call helper function to read the file and place zone locations
    readFile(myfile);
}

// reads the file and places zones in the board
void grid::readFile(std::ifstream& myfile){
    
    int tilnext = 0; // this will track how many more coordinates it will take until the next zone
    int numrep = -1; // this will represent the zone with an integer
    std::string input;
    std::vector<int> tmp;
    while (myfile >> input){
        // every input will be placed twice

        // input will always be an even number since the first number is always
        // either a zone string or x coord for the board

        // if tilnext is 0, we reach a zone string followed by # of coords in the zone
        if (tilnext == 0){
            // pushback all existing coords in tmp into coords
            if (tmp.size() != 0){
                coords.push_back(tmp);
                tmp.clear();
            }

            // strrep represents the string of the zone, since our board is made of
            // numbers
            strrep.push_back(input);
            // tilnext resembles how many more times until it 
            // encounters another zone
            myfile >> tilnext;
            numrep += 1;
        }
        else{
            int y;
            int x = atoi(input.c_str());
            myfile >> y;
            tmp.push_back(x);
            tmp.push_back(y);
            // numrep is the integer that represents the zone in the board
            board[x][y] = numrep;
            tilnext -= 1;
        }
    }
    // all the last ones in tmp
    if (tmp.size() != 0){
        coords.push_back(tmp);
        tmp.clear();
    }
    // sort the zones by vector size
    sort(coords.begin(), coords.end(), sortByVecSize);
}

// helper function for blockCoords, this blocks the adjacent 
// spaces to the star
void grid::blockSurrounding(const int& x, const int& y, 
std::vector<std::vector<int> >& boardT){
    // place a star
    boardT[x][y] = -1;
    // block left
    if (x != 0) boardT[x-1][y] = -1; 
    // block right
    if (x+1 != col) boardT[x+1][y] = -1;
    // block up
    if (y+1 != row) boardT[x][y+1] = -1;
    // block down
    if (y != 0) boardT[x][y-1] = -1;
    // block up left
    if (x != 0 && y+1 != row) boardT[x-1][y+1] = -1;
    // block up right
    if (y+1 != row && x+1 != col) boardT[x+1][y+1] = -1;
    // block down left
    if (y != 0 && x != 0) boardT[x-1][y-1] = -1;
    // block down right
    if (y != 0 && x+1 != col) boardT[x+1][y-1] = -1;
}

// this function takes a col and a row of a star placed and blocks
// off the board
void grid::place(const int& x, const int& y, 
std::vector<std::vector<int> >& boardT){

    // block off surroundings
    blockSurrounding(x, y, boardT);

    // blocks the columns
    for (int i = 0; i < col; i++){
        if (boardT[i][y] != -1) boardT[i][y] += 1;
    }

    // blocks the rows
    for (int i = 0 ; i < row; i++){
        if (boardT[x][i] != -1) boardT[x][i] += 1;
    }

    // blocks the current spot the star is placed in
    boardT[x][y] = -1;
}

// function used for debugging
void grid::tryplace(int x, int y){
    place(x, y, boardTrack);
    board[x][y] = -1;
}
// function used to see where all the star locations are
void grid::printStarLoc(){
    for (int i = 0; i < star_loc.size(); i+=2){
        std::cout << star_loc[i] << ' ' << star_loc[i+1] << std::endl;
    }
}
// function used to print where all the stars are
void grid::printResult(){
    for (int i = 0; i < allresults.size(); i++){
        for (int j = 0; j < allresults[i].size(); j+=2){
            std::cout << allresults[i][j] << ' ' 
            << allresults[i][j+1] << std::endl;
        }
    }
}

// function to print out how many solutions there are
void grid::printSolutions(std::ofstream& outfile){
    outfile << "Number of solutions: " << allresults.size() << std::endl;
}

// prints out the whole board with all the solutions
void grid::printBoard(std::ofstream& outfile){
    // loops through all the solutions
    for (int i = 0; i < allresults.size(); i++){
        outfile << std::endl << "Solution " << i + 1 << ":" << std::endl;
        // make a copy of the board
        std::vector<std::vector<int> > boardx = board;
        // access every star location
        for (int j = 0; j < allresults[i].size(); j+=2){
            // make every star location = -1
            int x = allresults[i][j];
            int y = allresults[i][j+1];
            boardx[x][y] = -1;
        }
        // print out the board
        for (int k = 0; k < row; k++){
            for (int f = 0; f < col; f++){
                // if that star location is -1, print out a @
                if (boardx[f][k] == -1) outfile << "@";
                // else, print out the zone
                else outfile << strrep[board[f][k]];
            }
            outfile << std::endl;
        }
    }
}

// function to print out all the coords within a 
// zone in order of smallest to largest
void grid::printZoneTrack(){
    for (int i = 0; i < coords.size(); i++){
        for (int j = 0; j < coords[i].size(); j++){
            std::cout << coords[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// prints out the boardtrack of the class
void grid::printBoardTrack(){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (boardTrack[j][i] == -1) std::cout << 'X';
            else std::cout << boardTrack[j][i];
        }
        std::cout << std::endl;
    }
}

// checks all star locations to see if they are valid
bool grid::all_valid(const std::vector<int>& starLOC){
    std::vector<std::vector<int> > boardx = boardTrack;

    for (int i = 0; i < starLOC.size(); i+=2){
        int x = starLOC[i];
        int y = starLOC[i+1];
        if (boardx[x][y] != 0 || boardx[x][y] >= numstars){
            return false;
        }
        place(x, y, boardx);
    }
    return true;
}

// the BIG BOSS: recursive function
void grid::solveBoard(int zoneI, std::vector<int>& starPlacements, 
    std::vector<std::vector<int> >& result, const bool& one_or_all){
    // BASE CASE: if we get to the last zone, those stars work.
    if (zoneI == strrep.size()){
        result.push_back(starPlacements);
    }
    else{
        // Loops through every single coord at the current zone
        for (int i = 0; i < coords[zoneI].size(); i+=2){
            int x = coords[zoneI][i];
            int y = coords[zoneI][i+1];
            starPlacements.push_back(x);
            starPlacements.push_back(y);
            // after putting the stars with push_back, check if all
            // the stars currently are valid
            if (all_valid(starPlacements)){
                // if they're valid, then adance to the next zone
                solveBoard(zoneI + 1, starPlacements, result, one_or_all);
                // if we only want one solution, break when we find one
                if (one_or_all)
                    break;
            }
            // reset if not good or move towards the next solution
            starPlacements.pop_back();
            starPlacements.pop_back();
        }
    }
}

// used in main, solveBoard uses many member variables,
// makes a function to call solveBoard
void grid::callRecursion(const std::string& solutions){
    if (solutions == "one_solution")
        solveBoard(0, star_loc, allresults, true);
    else if (solutions == "all_solutions")
        solveBoard(0, star_loc, allresults, false);
    else
        std::cerr << "solution type not recognizes" << std::endl;
}

// sorts a vector by its size
bool sortByVecSize(std::vector<int>& a, std::vector<int>& b){
    return a.size() < b.size();
}

// groups a vector, making it a vector<vector<int> >
std::vector<std::vector<int> >groupVector(const std::vector<int>& yourVec){
    std::vector<std::vector<int> > newVec;
    for (int i = 0; i < yourVec.size(); i+=2){
        std::vector<int> tmp;
        tmp.push_back(yourVec[i]);
        tmp.push_back(yourVec[i+1]);
        newVec.push_back(tmp);
    }
    return newVec;
}