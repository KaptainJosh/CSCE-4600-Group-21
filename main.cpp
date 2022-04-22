#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(int agrc, char *argv[])
{
	if (agrc == 1){
		std::cout << "ERROR! PLEASE ENTER A VALID COMMAND LINE INPUT" << std::endl;
		std::cout << "Example: ./main Project-2-input-example.txt" << std::endl;
		return 1;
	}
    int processNum = 0, resourceNum = 0, lineNum = 1;
    std::string lineTxt, data;
    std::vector<int> unitsPerResource;
    std::vector<std::vector<int> > matrix;
    std::vector<int> row;
	std::vector<std::string> result;
	
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
        if (lineTxt[0] == '%' || lineTxt.length() == 0)
            continue;
        else{
            if (lineTxt.find("num_processes") != std::string::npos){
				std::stringstream ss(lineTxt);
				while(std::getline(ss, data, '=')){
					result.push_back(data);
				}
				processNum = stoi(result[1]);
                std::cout << "Process Num: " << processNum << std::endl;
                lineNum++;
                continue;

            }else if (lineTxt.find("num_resources") != std::string::npos){
                result.clear();
				std::stringstream ss(lineTxt);
				while(std::getline(ss, data, '=')){
					result.push_back(data);
				}
				resourceNum = stoi(result[1]);
                std::cout << "Resource Num: " << resourceNum << std::endl;
                lineNum++;
                continue;
            }else if (lineNum == 3) {
				//std::cout << "Line# " << lineNum << std::endl;
                //list the number of units of each resource part.
                //std::vector<int> unitsPerResource;
				std::stringstream ss(lineTxt);
				//std::cout << "line: " << lineTxt << std::endl;
                int counter = 0;
				//std::cout << "Counter: " << counter << std::endl;
                while(std::getline(ss, data, ',') && counter < resourceNum){
                    unitsPerResource.push_back(stoi(data));
                    //std::cout << "Data: " << unitsPerResource[counter] << std::endl;
                    counter++;
					//std::cout << "Counter: " << counter << std::endl;
                }
                lineNum++;
            }else{
				std::stringstream ss(lineTxt);
                matrix.push_back(row);
                while(std::getline(ss,data, ',')){
                    //std::cout << data << std::endl;;
                    matrix.back().push_back(stoi(data));
                }
            }
            //std::cout << "Line: " << lineTxt << std::endl;
        }
    }
	
	std::cout << std::endl;
	//Testing printing units per resource
	std::cout << "PRINTING UNITS PER RESOURCE" << std::endl;
	for(auto i : unitsPerResource){
		std::cout << i << std::endl;
	}

    //Testing printing out matrix.
    std::cout << "PRINTING MATRIX" << std::endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    file.close();
    std::cout << "File closed\n";
    return 0;
}