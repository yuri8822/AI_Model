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
    vector<Matrix> matrices;

    //////////////////////////////////////////

    ModelManager()
    {
        cout << "Model Manager created\n";
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
    void FlattenImage()
    {
        cout << "Flattening images\n";
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
    }
    void LoadModel()
    {
        cout << "Loading model\n";
    }
    void ReadMatrixFiles(int numOfFiles = 2)
    {
        char option = 'A';
        string fileName;
        string line;

        for (int i = 0; i < numOfFiles; i++)
        {
            option += i;
            fileName = option;
            fileName += ".matrix";
            cout << "\nFile: " << fileName << " :-\n";

            ifstream File(fileName);

            vector<vector<double>> data;
            int rows = 0;
            int cols = 0;

            while (getline(File, line))
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

            Matrix newMatrix(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    newMatrix.data[i][j] = data[i][j];
                }
            }

            cout << "rows: " << rows << ", cols: " << cols << "\n";
            matrices.push_back(newMatrix);
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