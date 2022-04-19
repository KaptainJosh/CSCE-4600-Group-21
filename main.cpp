#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    int processNum = 0, resourceNum = 0, lineNum = 1;
    std::string lineTxt;
    std::string data;
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
        if(lineTxt[0] == '%' || lineTxt[0] == 0 )
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
                std::stringstream ss;
                ss << lineTxt;
                int counter = 0;
                int i = 1;
                while(std::getline(ss, data, ',') && counter < resourceNum){
                    std::cout << "R" << i << ": " << data << std::endl;
                    if (counter > resourceNum)
                        continue;
                    else{
                        counter++;
                        i++;
                    }
                }
                lineNum++;
            }



            //std::cout << "Line: " << lineTxt << std::endl;
        }
    }








    file.close();
    std::cout << "File closed\n";
    return 0;
}