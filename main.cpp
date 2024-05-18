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

    MM.TrainModel(); // there is an issue when loading and then saving!

    // Display the number of Images stored in memory:
    // cout << MM.images.size() << endl;
}