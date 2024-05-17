#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Image.h"
#include "Model.h"

using namespace std;

class ModelManager
{
private:
    int counter = 1;
    int label = 0;


public:
    Model model;
    vector<Image> images;

    //////////////////////////////////////////

    ModelManager()
    {
        cout << "Model Manager Started\n";
    }
    void TrainModel()
    {
        // Load the saved state of the model:
        LoadModel();
        // Read the dataset into memory (vector of images):
        ReadMatrixFile("trainingSet.matrix");

        for (int i = 0; i < images.size(); i++)
        {
            for (int j = 0; j < model.inputLayer.size(); j++)
            {
                model.inputLayer[j].activation = images[i].data[j][0];
            }

            // training begins here:
            
        }
    }
    void UseModel()
    {
    }
    void ForwardPropogation()
    {
    }
    void CalculateError()
    {
    }
    void BackPropogation()
    {
    }
    void RelU()
    {
    }
    // Functions to save and load the model:
    void SaveModel()
    {
        cout << "Saving model\n";

        ofstream Save("Model.dat");

        // Save input layer:
        for (int i = 0; i < model.inputLayer.size(); i++)
        {
            Save << model.inputLayer[i].activation << "\n"
                 << model.inputLayer[i].bias << "\n";
        }
        // Save hidden layer 1:
        for (int i = 0; i < model.hiddenLayer1.size(); i++)
        {
            Save << model.hiddenLayer1[i].activation << "\n"
                 << model.hiddenLayer1[i].bias << "\n";

            for (int j = 0; j < model.hiddenLayer1[i].weights.size(); j++)
            {
                Save << model.hiddenLayer1[i].weights[j] << "\n";
            }
        }
        // Save hidden layer 2:
        for (int i = 0; i < model.hiddenLayer2.size(); i++)
        {
            Save << model.hiddenLayer2[i].activation << "\n"
                 << model.hiddenLayer2[i].bias << "\n";

            for (int j = 0; j < model.hiddenLayer2[i].weights.size(); j++)
            {
                Save << model.hiddenLayer2[i].weights[j] << "\n";
            }
        }
        // Save output layer:
        for (int i = 0; i < model.outputLayer.size(); i++)
        {
            Save << model.outputLayer[i].activation << "\n"
                 << model.outputLayer[i].bias << "\n";

            for (int j = 0; j < model.outputLayer[i].weights.size(); j++)
            {
                Save << model.outputLayer[i].weights[j] << "\n";
            }
        }

        Save.close();

        cout << "Model saved\n";
    }
    void LoadModel()
    {
        cout << "Loading model\n";

        ifstream Load("Model.dat");
        string line;

        // clearing the model:
        model.inputLayer.clear();
        model.hiddenLayer1.clear();
        model.hiddenLayer2.clear();
        model.outputLayer.clear();

        // resizing the model:
        model.inputLayer.resize(784);
        model.hiddenLayer1.resize(16);
        model.hiddenLayer2.resize(16);
        model.outputLayer.resize(10);

        // Load input layer:
        for (int i = 0; i < model.inputLayer.size(); i++)
        {
            getline(Load, line);
            model.inputLayer[i].activation = stod(line);
            getline(Load, line);
            model.inputLayer[i].bias = stod(line);
        }
        // Load hidden layer 1:
        for (int i = 0; i < model.hiddenLayer1.size(); i++)
        {
            getline(Load, line);
            model.hiddenLayer1[i].activation = stod(line);
            getline(Load, line);
            model.hiddenLayer1[i].bias = stod(line);

            for (int j = 0; j < model.hiddenLayer1[i].weights.size(); j++)
            {
                getline(Load, line);
                model.hiddenLayer1[i].weights[j] = stod(line);
            }
        }
        // Load hidden layer 2:
        for (int i = 0; i < model.hiddenLayer2.size(); i++)
        {
            getline(Load, line);
            model.hiddenLayer2[i].activation = stod(line);
            getline(Load, line);
            model.hiddenLayer2[i].bias = stod(line);

            for (int j = 0; j < model.hiddenLayer2[i].weights.size(); j++)
            {
                getline(Load, line);
                model.hiddenLayer2[i].weights[j] = stod(line);
            }
        }
        // Load output layer:
        for (int i = 0; i < model.outputLayer.size(); i++)
        {
            getline(Load, line);
            model.outputLayer[i].activation = stod(line);
            getline(Load, line);
            model.outputLayer[i].bias = stod(line);

            for (int j = 0; j < model.outputLayer[i].weights.size(); j++)
            {
                getline(Load, line);
                model.outputLayer[i].weights[j] = stod(line);
            }
        }

        Load.close();

        cout << "Model loaded\n";
    }
    void ReadMatrixFile(string fileName = "A.matrix")
    {
        ifstream Read(fileName);
        string line;

        vector<double> elements;
        bool isLabel = true;
        int label;

        while(!Read.eof())
        {
            getline(Read, line);

            if (!line.empty())
            {
                if (isLabel)
                {
                    label = stoi(line);
                    isLabel = false;
                }
                else
                {
                    elements.push_back(stod(line));
                }
            }
            else
            {
                isLabel = true;
                Image newImage(elements.size(), 1, label);
                for (int i = 0; i < newImage.rows; i++)
                {
                    newImage.data[i][0] = elements[i];
                }
                // newImage.Display();
                elements.clear();
                images.push_back(newImage);
            }
        }
        Read.close();
    }
};