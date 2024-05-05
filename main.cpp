#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "ModelManager.h"

using namespace std;

// Matrix function testing:
// int main()
// {
//     Model M;
//     cout << "Starting:";
//     M.ReadMatrixFiles(2);
//     cout << "Read all files\n";
//     for (int i = 0; i < M.matrices.size(); i++)
//     {
//         M.matrices[i].Display();
//     }
//     Matrix C = M.matrices[0] + M.matrices[1];
//     M.WriteMatrixFile(C);
// }



int main()
{
    ModelManager MM;

    int choose;
        while(1)
        {
            system("CLS");
            cout
                << "~~~~~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~~~~\n\n"
                << "1.Convert Images into .Matrix file\n"
                << "2.Start Training\n"
                << "3.\n"
                << "4.Exit\n\n";
            cin >> choose;
            switch(choose)
            {
                case 1:
                    
                    system("PAUSE");
                    break;
    
                case 2:
                    
                    system("PAUSE");
                    break;
    
                case 3:
                    
                    system("PAUSE");
                    break;
    
                case 4:
                    return 0;
                    break;
    
                default:
                    cout << "Please choose a valid option!\n";
                    system("PAUSE");
                    break;
            }
        }
}