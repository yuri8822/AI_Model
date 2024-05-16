#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <time.h>

#include "ModelManager.h"

using namespace std;

int main()
{
    srand(time(NULL));
    
    ModelManager MM;
    MM.ReadMatrixFile();

    for (int i = 0; i < MM.images.size(); i++)
    {
        MM.images[i].Display();
    }
    // MM.SaveModel();
    // MM.LoadModel();
}