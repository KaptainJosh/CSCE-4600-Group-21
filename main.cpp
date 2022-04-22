#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "knot-detector.hpp"
#include "bfs.hpp"

int main(int argc, char *argv[])
{
    int processNum = 0, resourceNum = 0, lineNum = 1;
    std::string lineTxt;
    std::string data;
    std::stringstream ss;
    std::vector<std::vector<int> > matrix;
    std::vector<int> row;

    std::ifstream file("Project-2-input-example.txt");
    if (!file)
    {
        std::cout << "Error. File could not be opened\n";
        std::cout << "Please check if file exist or filename was entered correctly and try again";
        return 2;
    }
    else
        std::cout << "File opened\n";

    while(std::getline(file, lineTxt)){
        //IF LINE BEGIN WITH '%' OR IS BLANK, SKIP TO NEXT LINE.
        //std::cout << lineTxt << std::endl;
        if (lineTxt[0] == '%' || lineTxt[0] == '\n' || lineTxt[0] == '\r' )
            continue;

        else{
            if (lineTxt.find("num_processes") != std::string::npos){
                //std::cout << lineTxt.back() << std::endl;
                processNum = (int)lineTxt.back() - '0';
                std::cout << "Process Num: " << processNum << std::endl;
                lineNum++;
                continue;
            }else if (lineTxt.find("num_resources") != std::string::npos){
                resourceNum = (int)lineTxt.back() - '0';
                std::cout << "Resource Num: " << resourceNum << std::endl;
                lineNum++;
                continue;
            }else if (lineNum == 3) {
                //list the number of units of each resource part.
                std::vector<int> unitsPerResource;
                ss << lineTxt;
                int counter = 0;
                while(std::getline(ss, data, ',') && counter < resourceNum){
                    std::cout << "data: " << data << std::endl;
                    unitsPerResource.push_back(stoi(data));
                    std::cout << unitsPerResource[counter] << std::endl;
                    if (counter > resourceNum)
                        continue;
                    else{
                        counter++;
                    }
                }
                lineNum++;
            }else{
                ss.clear();
                ss << lineTxt;
                matrix.push_back(row);
                while(std::getline(ss,data, ',')){
                    std::cout << data << std::endl;;
                    matrix.back().push_back(stoi(data));
                }
                //std::cout << std::endl;
            }
            //std::cout << "Line: " << lineTxt << std::endl;
        }
    }

    //Testing printing out matrix.
    std::cout << "************************" << std::endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    file.close();
    std::cout << "File closed\n";

    //Perform BFS
    std::vector<std::set<int> > reachableSets;
    bfs(matrix, matrix.size(), reachableSets);

    //Check for knots
    bool hasKnot = checkForKnots(reachableSets);

    if (hasKnot)
        std::cout << "System is in a state of deadlock\n";
    else
        std::cout << "System is not in a state of deadlock\n";

    return 0;
}