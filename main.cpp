#include <iostream>
#include <cstdlib> //srand
#include <ctime>   //for srand
#include "cpoint.h"

void ShowPoints(const CPoint* const szPoints, const int& iCount)
{
    for (int i = 0; i < iCount; i++)
    {
        szPoints[i].ShowCoordinates();
    }
}

void PointsSwap(CPoint* const pPoint1, CPoint* const pPoint2)
{
    const double dPoint1X = pPoint1->GetX();
    const double dPoint1Y = pPoint2->GetY();
    pPoint1->SetX(pPoint2->GetX());
    pPoint1->SetY(pPoint1->GetY());

    pPoint2->SetX(dPoint1X);
    pPoint2->SetY(dPoint1Y);
}

void SortPoints(CPoint* const szPoints, const int& iCount)
{
    for (int i = 0; i < iCount; i++)
    {
        CPoint* pMinimum = &szPoints[i];
        for (int j = i; j < iCount; j++)
        {
            if (szPoints[j].GetX() < pMinimum->GetX())
                pMinimum = &szPoints[j];
        }
        if (&szPoints[i] != pMinimum)
            PointsSwap(&szPoints[i], pMinimum);
    }
}

void Exercise5()
{
    //Exercise5: отсортировать набор случайных точек по координате х и
    //вывести ту, которая находится по середине

    std::srand(std::time(NULL));

    const int iPointsCount = 11;

    CPoint* szPoints = new CPoint[iPointsCount];

    for (int i = 0; i < iPointsCount; i++)
    {
        const double dRandomX = (double (rand()%1000))/10.;
        const double dRandomY = (double (rand()%1000))/10.;
        szPoints[i].SetCoordinates(dRandomX, dRandomY);
    }

    ShowPoints(szPoints, iPointsCount);

    std::cout << std::endl << "Sorted:" << std::endl;
    SortPoints(szPoints, iPointsCount);

    ShowPoints(szPoints, iPointsCount);

    int iCenterPos = iPointsCount / 2;

    if (!(iPointsCount%2))
    {
        std::cout << std::endl << "There is two center points: " << std::endl;
        szPoints[iCenterPos - 1].ShowCoordinates();
        szPoints[iCenterPos].ShowCoordinates();
    }
    else
    {
        std::cout << std::endl << "Center point: " << std::endl;
        szPoints[iCenterPos].ShowCoordinates();
    }

    delete[] szPoints;
}

void ShowArray(const int* const szArray, const int& iSize)
{
    const int* pCurLastElement = szArray + iSize - 1;
    const int* const pPreFirstElement = szArray - 1;

    while (pCurLastElement != pPreFirstElement)
    {
        std::cout << *pCurLastElement << " ";
        --pCurLastElement;
    }

    std::cout << std::endl;
}

void Exercise4()
{
    //Exercise4: написать цикл, который в обратном порядке выводит
    //элементы массива без использования обращения к элементам
    //через оператор "[]" (с помощью указателей)

    const int iElementsCount = 10;
    int* const szIntArray = new int[iElementsCount];

    for (int i = 0; i < iElementsCount; i++)
    {
        *(szIntArray + i) = i;
    }

    ShowArray(szIntArray, iElementsCount);

    delete[] szIntArray;
}

int steps(int n)
{
    if (n == 1)
        return 0;

    if (!(n%2))
        return (steps(n/2) + 1);
    else
        return (steps(3*n + 1) + 1);
}

void Exercise3()
{
    /*Exercise3: написать рекурсивную функцию, которая определяет, за сколько операций
    от заданного пользователем числа получится число 1, если:
    1) если текущее число чётное, то n = n/2;
    2) иначе n = 3n + 1
    int steps (int n)
    Пример: 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1*/

    std::cout << "Enter number (>0) to find way to 1" << std::endl;
    int iBaseNumber(0);
    std::cin >> iBaseNumber;

    if (iBaseNumber <= 0)
    {
        std::cout << "Wrong input" << std::endl;
        return;
    }
    std::cout << "Steps: " << steps(iBaseNumber) << std::endl;
}

int* minIter(int* first, int* last)
{
    int* pMinimumInt = first;
    int* pCurrentPos = first + 1;

    while (pCurrentPos != last)
    {
        if (*pMinimumInt > *pCurrentPos)
            pMinimumInt = pCurrentPos;

        ++pCurrentPos;
    }

    return pMinimumInt;
}

void Exercise2()
{
    //Exercise2: написать функцию, которая находит позицию минимального элемента из переданного диапазона.
    //Функция принимает на вход два указателя.
    //int* minIter(int* first, int* last)

    const int iCount = 10;
    int szArray[iCount] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Minimum is " << *minIter(&szArray[0], &szArray[iCount]) << std::endl;
}

int CalculateDividersCount(const int& iNumber)
{
    int iDividers(2);

    if (iNumber == 0)
        return 0;
    else if (iNumber == 1)
        return 1;

    for (int i = 2; i <= iNumber / 2; i++)
    {
        if (!(iNumber%i))
            ++iDividers;
    }

    return iDividers;
}

void Exercise1()
{
    //Exercise1: в массиве целых случайных чисел (размер задаётся пользователем) найти такое число,
    //которое имеет наибольшее число делителей

    int iCount(0);
    int iMaxDividers(0);
    int iIndexWithMaximum(0);
    std::cout << "Enter how many numbers will be in random array" << std::endl;

    std::cin >> iCount;

    if (iCount <= 0)
    {
        std::cout << "Count should be > 0" << std::endl;
        return;
    }

    std::srand(time(NULL));

    int* szRandomArray = new int[iCount];

    std::cout << "Array:";

    for (int i = 0; i < iCount; i++)
    {
        szRandomArray[i] = std::rand() % 100;
        std::cout << " " << szRandomArray[i];
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < iCount; i++)
    {
        int iCurrentDividers = CalculateDividersCount(szRandomArray[i]);

        if (iCurrentDividers > iMaxDividers)
        {
            iMaxDividers      = iCurrentDividers;
            iIndexWithMaximum = i;
        }
    }

    std::cout << "Number " << szRandomArray[iIndexWithMaximum] << " has max dividers count (" << iMaxDividers << ")" << std::endl;

    delete[] szRandomArray;
}

int main()
{
//    Exercise1();
//    Exercise2();
//    Exercise3();
//    Exercise4();
//    Exercise5();

    return 0;
}
