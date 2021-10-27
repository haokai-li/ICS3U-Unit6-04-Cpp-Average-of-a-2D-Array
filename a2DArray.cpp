// Copyright (c) 2021 haokai All rights reserved
//
// Created by: Haokai
// Created on: Sept 2021
// This Program calculate smallest number

#include <iostream>
#include <random>
#include <iomanip>

template <int rows, int cols>
float calculatedaverageNumber(int (&calculateA2DArray)[rows][cols]) {
    // This function calculate smallest number
    float totalNumber = 0;
    int rowsLen = sizeof(calculateA2DArray)/sizeof(calculateA2DArray[0]);
    int colsLen = sizeof(calculateA2DArray[0])/sizeof(calculateA2DArray[0][0]);

    // process
    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement) {
            totalNumber += calculateA2DArray[rowElement][columnElement];
        }
    }

    totalNumber = totalNumber / (rowsLen * colsLen);

    return totalNumber;
}

int main() {
    // This Program calculate average
    int calculateNumber;
    const int userRowNumber = 3;
    const int userColumnsNumber = 4;
    float averageNumber;
    int a2DArray[userRowNumber][userColumnsNumber];

    // process
    for (int loopNumberFirst = 0;
             loopNumberFirst < userRowNumber;
             loopNumberFirst++) {
        for (int loopNumberSecond = 0;
                 loopNumberSecond < userColumnsNumber;
                 loopNumberSecond++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(1, 50);
            calculateNumber = idist(rgen);
            a2DArray[loopNumberFirst][loopNumberSecond]
            = calculateNumber;
            std::cout << calculateNumber << " ";
        }
        std::cout << "" << std::endl;
    }

    // call functions
    averageNumber = calculatedaverageNumber(a2DArray);

    // output
    std::cout << "" << std::endl;
    std::cout << std::fixed << std::setprecision(2)
    << averageNumber << " " << std::endl;

    std::cout << "\nDone." << std::endl;
}
