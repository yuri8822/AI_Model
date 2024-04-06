#pragma once

using namespace std;

struct Matrix
{
    int rows;
    int cols;
    double **data;

    // Default constructor:
    Matrix()
    {
        rows = 0;
        cols = 0;
        data = nullptr;
    }
    // Copy constructor:
    Matrix(const Matrix &B)
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
    Matrix(int rows, int cols)
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
    Matrix operator=(const Matrix &B)
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
    Matrix operator*(const Matrix &B)
    {
        if (cols != B.rows)
        {
            cout << "Invalid dimensions for matrix multiplication.\n";
            return *this;
        }

        Matrix Result(rows, B.cols);

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
    Matrix operator+(const Matrix &B)
    {
        if (rows != B.rows || cols != B.cols)
        {
            cout << "Invalid dimensions for matrix addition.\n";
            return *this;
        }

        Matrix Result(rows, cols);

        for (int R = 0; R < rows; R++)
        {
            for (int C = 0; C < cols; C++)
            {
                Result.data[R][C] = data[R][C] + B.data[R][C];
            }
        }
        return Result;
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
};