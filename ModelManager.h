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
public:
    Model model;
    vector<Matrix> matrices;
    int counter = 0;

    //////////////////////////////////////////

    ModelManager()
    {
        cout << "Model Manager created\n";
    }
    void FlattenImage()
    {
        cout << "Flattening images\n";
    }
    // Functions to save and load the model:
    void SaveModel()
    {
        cout << "Saving model\n";
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