#pragma once

// My Library for image handeling in C++ (Matrix library)

using namespace std;

struct Image
{
    int label;
    int rows;
    int cols;
    double **data;

    // Default constructor:
    Image()
    {
        rows = 0;
        cols = 0;
        data = nullptr;
    }
    // Copy constructor:
    Image(const Image &B)
    {
        rows = B.rows;
        cols = B.cols;
        data = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = B.data[i][j];
            }
        }
    }
    Image(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        data = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
    Image operator=(const Image &B)
    {
        if (this != &B)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;

            rows = B.rows;
            cols = B.cols;
            data = new double *[rows];
            for (int i = 0; i < rows; i++)
            {
                data[i] = new double[cols];
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = B.data[i][j];
                }
            }
        }
        return *this;
    }
    Image operator*(const Image &B)
    {
        if (cols != B.rows)
        {
            cout << "Invalid dimensions for matrix multiplication.\n";
            return *this;
        }

        Image Result(rows, B.cols);

        for (int R = 0; R < rows; R++)
        {
            for (int C = 0; C < B.cols; C++)
            {
                for (int i = 0; i < cols; i++)
                {
                    Result.data[R][C] += data[R][i] * B.data[i][C];
                }
            }
        }
        return Result;
    }
    Image operator+(const Image &B)
    {
        if (rows != B.rows || cols != B.cols)
        {
            cout << "Invalid dimensions for matrix addition.\n";
            return *this;
        }

        Image Result(rows, cols);

        for (int R = 0; R < rows; R++)
        {
            for (int C = 0; C < cols; C++)
            {
                Result.data[R][C] = data[R][C] + B.data[R][C];
            }
        }
        return Result;
    }
    ~Image()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
};