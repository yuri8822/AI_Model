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

    MM.TrainModel();

    // Display the number of Images stored in memory:
    // cout << MM.images.size() << endl;
}