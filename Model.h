#include <iostream>
#include <vector>

using namespace std;

// the model wiil contain a 784 input layer followed by 2 16 hidden layers and a 10 output layer.

struct Neuron
{
    double activation;
    double bias;
    vector<double> weights;
};

struct Model
{
    // input layer has 784 neurons
    vector<Neuron> inputLayer;
    // hidden layer 1 has 16 neurons
    vector<Neuron> hiddenLayer1;
    // hidden layer 2 has 16 neurons
    vector<Neuron> hiddenLayer2;
    // output layer has 10 neurons
    vector<Neuron> outputLayer;

    Model()
    {
        // Initialize input layer with biases
        for (int i = 0; i < 784; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            inputLayer.push_back(n);
        }

        // Initialize hidden layer 1 with weights and biases
        for (int i = 0; i < 16; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            for (int j = 0; j < inputLayer.size(); j++)
            {
                n.weights.push_back(rand() % 1000 / 1000.0);
            }
            hiddenLayer1.push_back(n);
        }

        // Initialize hidden layer 2 with weights and biases
        for (int i = 0; i < 16; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            for (int j = 0; j < hiddenLayer1.size(); j++)
            {
                n.weights.push_back(rand() % 1000 / 1000.0);
            }
            hiddenLayer2.push_back(n);
        }

        // Initialize output layer with weights and biases
        for (int i = 0; i < 10; i++)
        {
            Neuron n;
            n.bias = rand() % 1000 / 1000.0;
            n.activation = rand() % 1000 / 1000.0;
            for (int j = 0; j < hiddenLayer2.size(); j++)
            {
                n.weights.push_back(rand() % 1000 / 1000.0);
            }
            outputLayer.push_back(n);
        }
    }
};