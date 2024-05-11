#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <time.h>

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
    srand(time(NULL));
    
    ModelManager MM;

    MM.SaveModel();
    // MM.LoadModel();
}