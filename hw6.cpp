#include "grid.h"

int main(int argc, char* argv[]){
    
    // utilize command line inputs
    std::string inputfile = argv[1];
    std::string outputfile = argv[2];
    std::string parse = argv[3];
    int numstars_zone = atoi(parse.c_str());
    std::string outputMode = argv[4];
    std::string solutionMode = argv[5];


    // initialize files will be read from and outputted to
    std::ifstream myfile (inputfile);
    std::ofstream outfile(outputfile);
    // error checking
    if (!myfile.good()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    // error checking
    if (!outfile.good()){
        std::cerr << "Error writing to file" << std::endl;
        return 1;
    }

    // initialize grid
    grid myGrid(myfile, numstars_zone);
    myGrid.callRecursion(solutionMode);
    myGrid.printSolutions(outfile);
    if (outputMode == "print")
        myGrid.printBoard(outfile);

    return 0;
}

