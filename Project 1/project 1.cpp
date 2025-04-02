#include <iostream>
#include <string>

#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;



string stringGenerator() {

    int MAX_LENGTH = 100;
    srand(time(0));

    
    string Finished = "";
    string NonFinished = "E";

    

    int choice;

    std::cout << NonFinished << "\n";

    while (!NonFinished.empty()) {     



        if (NonFinished[0] == 'E') {
            Finished.append("(");
            NonFinished.erase(0, 1);
            NonFinished.insert(0, "Y)");
        }
        else if (NonFinished[0] == 'Y') {
            NonFinished.erase(0, 1);
            NonFinished.insert(0, "AB");
        }
        else if (NonFinished[0] == 'A') {
            if (Finished.length() + NonFinished.length() < MAX_LENGTH) {

                choice = (rand() % 2); //   random number 0 or 1

                if (choice) {
                    NonFinished.erase(0, 1);
                    Finished.append("v");
                }
                else {
                    NonFinished[0] = 'E';
                }
            }
            else {
                NonFinished.erase(0, 1);
                Finished.append("v");
            }
        }
        else if (NonFinished[0] == 'B') {

            if (Finished.length() + NonFinished.length() < MAX_LENGTH) {

                choice = (rand() % 3); ////   random number 0 or 1 ορ 2

                if (choice == 0) {
                    Finished.append("-");
                    NonFinished[0] = 'Y';
                }
                else if (choice == 1) {
                    Finished.append("+");
                    NonFinished[0] = 'Y';
                }
                else {
                    NonFinished.erase(0, 1);
                }

            }
            else {
                NonFinished.erase(0, 1);
            }
            


        }
        else if (NonFinished[0] == ')') {
            NonFinished.erase(0, 1);
            Finished.append(")");
        }



        if (NonFinished[0] != ')') {
            //  when first symbol of NonFinished is ) , we just move it to Finished
            //  no changes will be made to the string
            //  We print the string only when first letter of NonFinished != )
            std::cout << Finished << NonFinished << "\n";
        }



    }
    


    return Finished;
}










int main()
{
    std::cout << stringGenerator();    
}