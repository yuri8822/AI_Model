#include <iostream>
#include <vector>

using namespace std;

// the model wiil contain a 256 input layer followed by 2 16 hidden layers and a 10 output layer.

struct neuron
{
    double value;
    double bias;
    vector<double> weights;
};

struct Model
{

};