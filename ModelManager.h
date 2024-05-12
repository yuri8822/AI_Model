#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Matrix.h"
#include "Model.h"

using namespace std;

class ModelManager
{
private:
    int counter = 0;

public:
    Model model;
    vector<Matrix> images;

    //////////////////////////////////////////

    ModelManager()
    {
        cout << "Model Manager Started\n";
    }
    void TrainModel()
    {
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
        string line;

        ifstream File(fileName);
        vector<vector<double>> data;
        int rows = 0;
        int cols = 0;

        while (getline(File, line))
        {
            // If a blank line is encountered, treat it as the end of a matrix
            if (!line.empty())
            {
                stringstream ss(line);
                string element;
                vector<double> row;
                while (getline(ss, element, ','))
                {
                    row.push_back(stod(element));
                }
                data.push_back(row);
                rows++;
                cols = row.size();
            }
            else
            {
                Matrix newImage(rows, cols);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        newImage.data[i][j] = data[i][j];
                    }
                }

                cout << "rows: " << rows << ", cols: " << cols << "\n";
                images.push_back(newImage);

                // Reset data, rows, and cols for the next matrix
                data.clear();
                rows = 0;
                cols = 0;
            }
        }

        // Handle the last matrix in the file
        if (!data.empty())
        {
            Matrix newImage(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    newImage.data[i][j] = data[i][j];
                }
            }

            cout << "rows: " << rows << ", cols: " << cols << "\n";
            images.push_back(newImage);
        }
    }
    void WriteMatrixFile(const Matrix &matrix)
    {
        counter++;
        string filename = to_string(counter) + ".matrix";
        ofstream Write(filename);

        for (int i = 0; i < matrix.rows; i++)
        {
            for (int j = 0; j < matrix.cols; j++)
            {
                if (j == matrix.cols - 1)
                {
                    Write << matrix.data[i][j];
                }
                else
                {
                    Write << matrix.data[i][j] << ",";
                }
            }
            if (i != matrix.rows - 1)
            {
                Write << "\n";
            }
        }
    }
};