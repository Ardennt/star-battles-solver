#include "grid.cpp"

int main(){
    
    // collect input and output file names
    std::string inputfile;
    std::cout << "input file name: ";
    std::cin >> inputfile;

    std::string outputfile;
    std::cout << "output file name: ";
    std::cin >> outputfile;
    
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
    grid myGrid(myfile);
    myGrid.callRecursion();
    myGrid.printSolutions(outfile);
    myGrid.printBoard(outfile);

    return 0;
}

