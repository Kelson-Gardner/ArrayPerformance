//
//  main.cpp
//  ArrayPerformance
//
//  Created by Kelson on 10/7/24.
//

#include "sortutils.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main()
{
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist(-10000000, 10000000);
    SourceArray randomStdArray = {};
    SourceArray sortedStdArray = {};
    SourceArray reversedStdArray = {};
    SourceArray organPipeStdArrayVal = {};
    SourceArray rotatedStdArray = {};
    for (int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        randomStdArray[i] = dist(engine);
        sortedStdArray[i] = i;
        organPipeStdArrayVal[i] = i;
        reversedStdArray[i] = i;
        rotatedStdArray[i] = i;
    }
    std::reverse(reversedStdArray.begin(), reversedStdArray.end());
    std::rotate(rotatedStdArray.begin(), rotatedStdArray.begin() + 1,
                rotatedStdArray.end());
    organPipeStdArray(organPipeStdArrayVal);

    evaluateStdArray(randomStdArray, sortedStdArray, reversedStdArray,
                     organPipeStdArrayVal, rotatedStdArray);

    evaluateRawArray(randomStdArray, sortedStdArray, reversedStdArray,
                     organPipeStdArrayVal, rotatedStdArray);

    evaluateStdVector(randomStdArray, sortedStdArray, reversedStdArray,
                      organPipeStdArrayVal, rotatedStdArray);

    return 0;
}
