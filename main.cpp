#include <iostream>

void inputCoeficients(int *aux, const char* vectorName)
{
    std::cout << "---------------------------> " << vectorName << std::endl;
    for(int i = 0 ; i< 3 ; i++)
    {
        std::cout << "Input coefficient " << vectorName << "[" << i+1 << "] : ";
        std::cin >> *aux;
        aux ++;
    }
    std::cout << std::endl;
}

displayEqSys(int *x, int *y, int *z, int *r)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        std::cout << "(" << *x << ")x + " << "(" << *y << ")y + " << "(" << *z << ")z + " << " = " << *r << std::endl;
        x++; y++; z++; r++;
    }
}

int solveMatrix(int x[3], int y[3], int z[3])
{
    return ((x[0] * y[1] * z[2]) + (x[1] * y[2] * z[0]) + (x[2] * y[0] * z[1])) - ((x[1] * y[0] * z[2]) + (x[0] * y[2] * z[1]) + (x[2] * y[1] * z[0])) ;
}


int main()
{
    int x[3];
    int y[3];
    int z[3];
    int r[3];

    //data input
    std::cout << "=== Equation Solving system Using Cramer's And Sarrus's methods === " << std::endl << std::endl;
    inputCoeficients(&x[0], "x");
    inputCoeficients(&y[0], "y");
    inputCoeficients(&z[0], "z");
    inputCoeficients(&r[0], "independent term");

    // display entry equations system
    std::cout << std::endl << "=== Equation System === " << std::endl;
    displayEqSys(&x[0],&y[0],&z[0],&r[0]);

    //Solving assembling
    int deltaS = solveMatrix(x,y,z);
    int deltaX = solveMatrix(r,y,z);
    int deltaY = solveMatrix(x,r,z);
    int deltaZ = solveMatrix(x,y,r);

    std::cout << std::endl << "=== Determinants === " << std::endl;
    std::cout << "Delta s = " << deltaS << std::endl;
    std::cout << "Delta x = " << deltaX << std::endl;
    std::cout << "Delta y = " << deltaY << std::endl;
    std::cout << "Delta z = " << deltaZ << std::endl;

    //Getting Solutions
    int solveX = 0;
    int solveY = 0;
    int solveZ = 0;

    if(deltaS != 0)
    {
        solveX = deltaX / deltaS;
        solveY = deltaY / deltaS;
        solveZ = deltaZ / deltaS;
    }
    else
        std::cout << std::endl << "Delta S has a value equal to 0, division can't be performed" << std::endl;

    std::cout << std::endl << "=== Solutions === " << std::endl;
    std::cout << "x = " << solveX << std::endl;
    std::cout << "y = " << solveY << std::endl;
    std::cout << "z = " << solveZ << std::endl;

    return 0;
}
