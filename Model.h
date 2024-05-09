#include <iostream>
#include <vector>

using namespace std;

// the model wiil contain a 256 input layer followed by 2 16 hidden layers and a 10 output layer.

struct Neuron
{
    double activation;
    double bias;
    vector<double> weights;
};

struct Model
{
    // input layer has 256 neurons
    vector<Neuron> inputLayer;
    // hidden layer 1 has 16 neurons
    vector<Neuron> hiddenLayer1;
    // hidden layer 2 has 16 neurons
    vector<Neuron> hiddenLayer2;
    // output layer has 10 neurons
    vector<Neuron> outputLayer;

    Model()
    {
        // Initialize input layer
        for (int i = 0; i < 256; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            inputLayer.push_back(n);
        }

        // Initialize hidden layer 1 with weights
        for (int i = 0; i < 16; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            n.weights.resize(inputLayer.size());
            for (int j = 0; j < inputLayer.size(); j++)
            {
                n.weights[j] = rand() % 1000 / 1000.0;
            }
            hiddenLayer1.push_back(n);
        }

        // Initialize hidden layer 2 with weights
        for (int i = 0; i < 16; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            n.weights.resize(hiddenLayer1.size());
            for (int j = 0; j < hiddenLayer1.size(); j++)
            {
                n.weights[j] = rand() % 1000 / 1000.0;
            }
            hiddenLayer2.push_back(n);
        }

        // Initialize output layer with weights
        for (int i = 0; i < 10; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            n.weights.resize(hiddenLayer2.size());
            for (int j = 0; j < hiddenLayer2.size(); j++)
            {
                n.weights[j] = rand() % 1000 / 1000.0;
            }
            outputLayer.push_back(n);
        }
    }
};