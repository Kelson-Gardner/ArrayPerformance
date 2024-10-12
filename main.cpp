//
//  main.cpp
//  ArrayPerformance
//
//  Created by Kelson on 10/7/24.
//

#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>
#include "sortutils.hpp"

int main(int argc, const char * argv[]) {
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist(-10000000, 10000000);
    SourceArray randomStdArray = {};
    SourceArray sortedStdArray = {};
    SourceArray reversedStdArray = {};
    SourceArray organPipeStdArrayVal = {};
    SourceArray rotatedStdArray = {};
    for(int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        randomStdArray[i] = dist(engine);
        sortedStdArray[i] = i;
        organPipeStdArrayVal[i] = i;
        reversedStdArray[i] = i;
        rotatedStdArray[i] = i;
        // if(i < HOW_MANY_ELEMENTS - 1)
        // {
        //     rotatedStdArray[i] = i + 1;
        // }
        // else
        // {
        //     rotatedStdArray[i] = 0;
        // }
    }
    std::reverse(reversedStdArray.begin(), reversedStdArray.end());
    std::rotate(rotatedStdArray.begin(), rotatedStdArray.begin() + 1, rotatedStdArray.end());
    organPipeStdArray(organPipeStdArrayVal);

    evaluateStdArray(randomStdArray, sortedStdArray, reversedStdArray, organPipeStdArrayVal, rotatedStdArray);
    return 0;
}
