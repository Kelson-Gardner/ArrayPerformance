//
//  sortutils.cpp
//  ArrayPerformance
//
//  Created by Kelson on 10/7/24.
//

#include "sortutils.hpp"
#include <iostream>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <execution>
#include <vector>

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[])
{
    for(int i = 0; i < source.size(); i++)
    {
        dest[i] = source[i];
    }
}

void organPipeStdArray(SourceArray& data)
{
    auto half = data.size() / 2;
    if(half % 2 == 0)
    {
        int leftIndex = static_cast<int>(half - 1);
        int rightIndex = static_cast<int>(half);
        while(leftIndex >= 0 && rightIndex < data.size())
        {
            data[rightIndex] = data[leftIndex];
            leftIndex--;
            rightIndex++;
        }
    }
    else
    {
        int leftIndex = static_cast<int>(floor(half) - 1);
        int rightIndex = static_cast<int>(floor(half + 1));
        while(leftIndex >= 0 && rightIndex < data.size())
        {
            data[rightIndex] = data[leftIndex];
            leftIndex--;
            rightIndex++;
        }
    }
}

std::chrono::milliseconds measureSortTimeRawArraySeq(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        int temp[HOW_MANY_ELEMENTS];
        initializeRawArrayFromStdArray(array, temp);
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, std::begin(temp), std::end(temp));
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

std::chrono::milliseconds measureSortTimeRawArrayPar(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        int temp[HOW_MANY_ELEMENTS];
        initializeRawArrayFromStdArray(array, temp);
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, std::begin(temp), std::end(temp));
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds totalRandomSortTimeSequential = measureSortTimeRawArraySeq(random);
    std::chrono::milliseconds totalRandomSortTimeParallel = measureSortTimeRawArrayPar(random);
    std::chrono::milliseconds totalSortedSortTimeSequential = measureSortTimeRawArraySeq(sorted);
    std::chrono::milliseconds totalSortedSortTimeParallel = measureSortTimeRawArrayPar(sorted);
    std::chrono::milliseconds totalReversedSortTimeSequential = measureSortTimeRawArraySeq(reversed);
    std::chrono::milliseconds totalReversedSortTimeParallel = measureSortTimeRawArrayPar(reversed);
    std::chrono::milliseconds totalOrganPipeSortTimeSequential = measureSortTimeRawArraySeq(organPipe);
    std::chrono::milliseconds totalOrganPipeSortTimeParallel = measureSortTimeRawArrayPar(organPipe);
    std::chrono::milliseconds totalRotatedSortTimeSequential = measureSortTimeRawArraySeq(rotated);
    std::chrono::milliseconds totalRotatedSortTimeParallel = measureSortTimeRawArrayPar(rotated);

    std::cout << "--- Raw Array Performance ---   \n\n";

    std::cout << "Sequential\n";
    std::cout << "      Random: " << totalRandomSortTimeSequential.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeSequential.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeSequential.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeSequential.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeSequential.count() << std::endl;

    std::cout << "Parallel\n";
    std::cout << "      Random: " << totalRandomSortTimeParallel.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeParallel.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeParallel.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeParallel.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeParallel.count() << std::endl;
}

std::chrono::milliseconds measureSortTimeStdArraySeq(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        SourceArray temp = array;
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, temp.begin(), temp.end());
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

std::chrono::milliseconds measureSortTimeStdArrayPar(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        SourceArray temp = array;
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, temp.begin(), temp.end());
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds totalRandomSortTimeSequential = measureSortTimeStdArraySeq(random);
    std::chrono::milliseconds totalRandomSortTimeParallel = measureSortTimeStdArrayPar(random);
    std::chrono::milliseconds totalSortedSortTimeSequential = measureSortTimeStdArraySeq(sorted);
    std::chrono::milliseconds totalSortedSortTimeParallel = measureSortTimeStdArrayPar(sorted);
    std::chrono::milliseconds totalReversedSortTimeSequential = measureSortTimeStdArraySeq(reversed);
    std::chrono::milliseconds totalReversedSortTimeParallel = measureSortTimeStdArrayPar(reversed);
    std::chrono::milliseconds totalOrganPipeSortTimeSequential = measureSortTimeStdArraySeq(organPipe);
    std::chrono::milliseconds totalOrganPipeSortTimeParallel = measureSortTimeStdArrayPar(organPipe);
    std::chrono::milliseconds totalRotatedSortTimeSequential = measureSortTimeStdArraySeq(rotated);
    std::chrono::milliseconds totalRotatedSortTimeParallel = measureSortTimeStdArrayPar(rotated);

    std::cout << "\n--- std::array Performance ---   \n\n";

    std::cout << "Sequential\n";
    std::cout << "      Random: " << totalRandomSortTimeSequential.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeSequential.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeSequential.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeSequential.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeSequential.count() << std::endl;

    std::cout << "Parallel\n";
    std::cout << "      Random: " << totalRandomSortTimeParallel.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeParallel.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeParallel.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeParallel.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeParallel.count() << std::endl;
}

std::chrono::milliseconds measureSortTimeVectorSeq(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        std::vector<int> temp(array.begin(), array.end());
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, temp.begin(), temp.end());
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

std::chrono::milliseconds measureSortTimeVectorPar(const SourceArray& array) {
    std::chrono::milliseconds totalSortTime{ 0 };
    for (int i = 0; i < HOW_MANY_TIMES; ++i) {
        std::vector<int> temp(array.begin(), array.end());
        auto begin = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, temp.begin(), temp.end());
        auto end = std::chrono::high_resolution_clock::now();
        totalSortTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    }
    return totalSortTime;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds totalRandomSortTimeSequential = measureSortTimeVectorSeq(random);
    std::chrono::milliseconds totalRandomSortTimeParallel = measureSortTimeVectorPar(random);
    std::chrono::milliseconds totalSortedSortTimeSequential = measureSortTimeVectorSeq(sorted);
    std::chrono::milliseconds totalSortedSortTimeParallel = measureSortTimeVectorPar(sorted);
    std::chrono::milliseconds totalReversedSortTimeSequential = measureSortTimeVectorSeq(reversed);
    std::chrono::milliseconds totalReversedSortTimeParallel = measureSortTimeVectorPar(reversed);
    std::chrono::milliseconds totalOrganPipeSortTimeSequential = measureSortTimeVectorSeq(organPipe);
    std::chrono::milliseconds totalOrganPipeSortTimeParallel = measureSortTimeVectorPar(organPipe);
    std::chrono::milliseconds totalRotatedSortTimeSequential = measureSortTimeVectorSeq(rotated);
    std::chrono::milliseconds totalRotatedSortTimeParallel = measureSortTimeVectorPar(rotated);

    std::cout << "\n--- std::vector Performance ---   \n\n";

    std::cout << "Sequential\n";
    std::cout << "      Random: " << totalRandomSortTimeSequential.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeSequential.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeSequential.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeSequential.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeSequential.count() << std::endl;

    std::cout << "Parallel\n";
    std::cout << "      Random: " << totalRandomSortTimeParallel.count() << std::endl;
    std::cout << "      Sorted: " << totalSortedSortTimeParallel.count() << std::endl;
    std::cout << "      Reversed: " << totalReversedSortTimeParallel.count() << std::endl;
    std::cout << "      Organ Pipe: " << totalOrganPipeSortTimeParallel.count() << std::endl;
    std::cout << "      Rotated: " << totalRotatedSortTimeParallel.count() << std::endl;
}
