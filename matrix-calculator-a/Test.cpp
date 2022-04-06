#include <iostream>
#include "Matrix.hpp"
#include "doctest.h"
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace zich;

TEST_CASE("Making matrix")
{

    for (int i = -50; i < 50; i++)
    {
        if (i <= 0)
        {
            CHECK_THROWS(Matrix(i, i));
        }
        else
        {
            CHECK_NOTHROW(Matrix(i, i));
        }
    }

    
    for (uint i = 1; i < 100; i++)
    {
        vector<double> initilaizer;
        initilaizer.resize(i*i);
        for (uint j = 0; j < i*i; j++)
        {
            initilaizer[j] = rand() * 100;
        }
        CHECK_NOTHROW(Matrix(initilaizer, (int)i, (int)i));
    }


}

TEST_CASE("Checking equallity"){
    int r1;
    int l1;
    int r2;
    int l2;
    bool check;
    for (uint i = 0; i < 500; i++)
    {
        r1 = rand() %10 + 1;
        l1 = rand() %10 + 1;
        r2 = rand() %10 + 1;
        l2 = rand() %10 + 1;
        vector<double> initilaizer1;
        initilaizer1.resize((uint)r1*(uint)l1);
        for (uint j = 0; j < r1*l1; j++)
        {
            initilaizer1[j] = rand() * 100;
        }
        vector<double> initilaizer2;
        initilaizer2.resize((uint)r2*(uint)l2);
        for (uint j = 0; j < r2*l2; j++)
        {
            initilaizer2[j] = rand() * 100;
        }
        Matrix m1(initilaizer1, (int)r1, (int)l1);
        Matrix m2(initilaizer2, (int)r2, (int)l2);

        if (r1 == r2 && l1 == l2)
        {
            CHECK(m1 == m2);
        }
        else
        {
            CHECK_THROWS(check =(m1 == m2));
            CHECK_THROWS(check =(m1 != m2));
        }


    }
    
}

TEST_CASE("Checking inequality"){
    int r1;
    int l1;
    int r2;
    int l2;
    bool check;
    for (uint i = 0; i < 500; i++)

    {
        r1 = rand() %10 + 1;
        l1 = rand() %10 + 1;
        r2 = rand() %10 + 1;
        l2 = rand() %10 + 1;
        vector<double> initilaizer1;
        initilaizer1.resize((uint)r1*(uint)l1);
        for (uint j = 0; j < r1*l1; j++)
        {
            initilaizer1[j] = rand() % 10;
        }
        vector<double> initilaizer2;
        initilaizer2.resize((uint)r2*(uint)l2);
        for (uint j = 0; j < r2*l2; j++)
        {
            initilaizer2[j] = (rand() % 100)+10;
        }
        Matrix m1(initilaizer1, (int)r1, (int)l1);
        Matrix m2(initilaizer2, (int)r2, (int)l2);

        if (r1 == r2 && l1 == l2)
        {

            CHECK_FALSE(m1 > m2);
            CHECK_NOTHROW(check =(m1 < m2));
            CHECK_FALSE(m1 >= m2);
            CHECK_NOTHROW(check =(m1 <= m2));
        }
        else
        {
            CHECK_THROWS(check =(m1 < m2));
            CHECK_THROWS(check =(m1 > m2));
            CHECK_THROWS(check =(m1 <= m2));
            CHECK_THROWS(check =(m1 >= m2));
        }

    }
}

TEST_CASE("Checking + || - || -= || +="){
    int r1;
    int l1;
    int r2;
    int l2;
    bool check;
    for (uint i = 0; i < 100; i++)
    {
        r1 = rand() %10 + 1;
        l1 = rand() %10 + 1;
        r2 = rand() %10 + 1;
        l2 = rand() %10 + 1;
        vector<double> initilaizer1;
        initilaizer1.resize((uint)r1*(uint)l1);
        for (uint j = 0; j < r1*l1; j++)
        {
            initilaizer1[j] = rand() % 10;
        }
        vector<double> initilaizer2;
        initilaizer2.resize((uint)r2*(uint)l2);
        for (uint j = 0; j < r2*l2; j++)
        {
            initilaizer2[j] = (rand() % 100)+10;
        }
        Matrix m1(initilaizer1, (int)r1, (int)l1);
        Matrix m2(initilaizer2, (int)r2, (int)l2);

        if (r1 == r2 && l1 == l2)
        {
            vector<double> resultMat;
            resultMat.resize((uint)r1*(uint)l1);
            for (uint i = 0; i < r1*l1; i++)
            {
                resultMat[i] = initilaizer1[i] + initilaizer2[i];
            }
            CHECK_NOTHROW(m1 + m2);
            CHECK_EQ(m1 + m2, Matrix(resultMat, (int)r1, (int)l1));

            for (uint i = 0; i < r1*l1; i++)
            {
                resultMat[i] = initilaizer1[i] - initilaizer2[i];
            }
            CHECK_EQ(m1 - m2 , Matrix(resultMat, (int)r1, (int)l1));

            CHECK_NOTHROW(m1 - m2);
        }
        else
        {
            CHECK_THROWS(m1 + m2);
            CHECK_THROWS(m1 - m2);
            CHECK_THROWS(m1 += m2);
            CHECK_THROWS(m1 -= m2);
        }
    }
}

TEST_CASE("Multiple matrices"){
    int r1;
    int l1;
    int r2;
    int l2;

    for (uint i = 0; i < 500; i++)
    {
        r1 = rand() %10 + 1;
        l1 = rand() %10 + 1;
        r2 = l1;
        l2 = rand() %10 + 1;

        vector<double> initilaizer1;
        initilaizer1.resize((uint)r1*(uint)l1);
        for (uint j = 0; j < r1*l1; j++)
        {
            initilaizer1[j] = rand() % 10;
        }
        vector<double> initilaizer2;
        initilaizer2.resize((uint)r2*(uint)l2);
        for (uint j = 0; j < r2*l2; j++)
        {
            initilaizer2[j] = rand() % 10;
        }
        Matrix m1(initilaizer1, (int)r1, (int)l1);
        Matrix m2(initilaizer2, (int)r2, (int)l2);

        vector<double> resultMat;
        resultMat.resize((uint)r1*(uint)l2);

        for (uint i = 0; i < r1*l2; i++) // Multiplication
        {
            resultMat[i] = 0;
            for (uint j = 0; j < l1; j++)
            {
                resultMat[i] += initilaizer1[i] * initilaizer2[j];
            }
        }
        CHECK_NOTHROW(m1 * m2);
        CHECK_EQ(m1 * m2, Matrix(resultMat, (int)r1, (int)l2));

        r2 = (rand() %10) + 11; //Illiegal multiplication
        initilaizer2.resize((uint)r2*(uint)l2);
        for (uint i = 0; i < r2*l2; i++)
        {
            initilaizer2[i] = rand() % 10;
        }
        m2 = Matrix(initilaizer2, (int)r2, (int)l2);
        
        CHECK_THROWS(m1 * m2);

    }
}

    TEST_CASE("Scalar adding || Multiple || submition to matrix"){
        int r;
        int l;

        for (int i = 0; i < 500; i++)
        {
            r = rand()%10+1;
            l = rand()%10+1;
            vector<double> initilaizer;
            initilaizer.resize((uint)r*(uint)l);
            for (uint j = 0; j < r*l; j++)
            {
                initilaizer[j] = rand() % 10;
            }
            Matrix m1(initilaizer, (int)r, (int)l);
            double scalar = rand() % 10;
            vector<double> resultMat;

            resultMat.resize((uint)r*(uint)l);
            for (uint i = 0; i < r*l; i++)
            {
                resultMat[i] = initilaizer[i] * scalar;
            }
            CHECK(m1 * scalar == Matrix(resultMat, (int)r, (int)l));
            CHECK(scalar * m1 == Matrix(resultMat, (int)r, (int)l));
        }
    }