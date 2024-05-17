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

    // Display all stored Images of the dataset:
    // for (int i = 0; i < MM.images.size(); i++)
    // {
    //     MM.images[i].Display();
    // }

    // Display the number of Images stored in memory:
    cout << MM.images.size() << endl;

    // MM.SaveModel();
    // MM.LoadModel();
}