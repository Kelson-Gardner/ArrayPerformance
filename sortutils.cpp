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

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::cout << "I am the raw array\n";
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds totalRandomSortTimeSequential {0};
    std::chrono::milliseconds totalRandomSortTimeParallel {0};
    std::chrono::milliseconds totalSortedSortTimeSequential {0};
    std::chrono::milliseconds totalSortedSortTimeParallel {0};
    std::chrono::milliseconds totalReversedSortTimeSequential {0};
    std::chrono::milliseconds totalReversedSortTimeParallel {0};
    std::chrono::milliseconds totalOrganPipeSortTimeSequential {0};
    std::chrono::milliseconds totalOrganPipeSortTimeParallel {0};
    std::chrono::milliseconds totalRotatedSortTimeSequential {0};
    std::chrono::milliseconds totalRotatedSortTimeParallel {0};

    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray randomSeq = random;
        auto beginRandomSeq = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, randomSeq.begin(), randomSeq.end());
        auto endRandomSeq = std::chrono::high_resolution_clock::now();
        totalRandomSortTimeSequential += std::chrono::duration_cast<std::chrono::milliseconds>(endRandomSeq - beginRandomSeq);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray randomPar = random;
        auto beginRandomPar = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, randomPar.begin(), randomPar.end());
        auto endRandomPar = std::chrono::high_resolution_clock::now();
        totalRandomSortTimeParallel += std::chrono::duration_cast<std::chrono::milliseconds>(endRandomPar - beginRandomPar);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray sortedSeq = sorted;
        auto beginSortedSeq = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, sortedSeq.begin(), sortedSeq.end());
        auto endSortedSeq = std::chrono::high_resolution_clock::now();
        totalSortedSortTimeSequential += std::chrono::duration_cast<std::chrono::milliseconds>(endSortedSeq - beginSortedSeq);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray sortedPar = sorted;
        auto beginSortedPar = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, sortedPar.begin(), sortedPar.end());
        auto endSortedPar = std::chrono::high_resolution_clock::now();
        totalSortedSortTimeParallel += std::chrono::duration_cast<std::chrono::milliseconds>(endSortedPar - beginSortedPar);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray reversedSeq = reversed;
        auto beginReversedSeq = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, reversedSeq.begin(), reversedSeq.end());
        auto endReversedSeq = std::chrono::high_resolution_clock::now();
        totalReversedSortTimeSequential += std::chrono::duration_cast<std::chrono::milliseconds>(endReversedSeq - beginReversedSeq);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray reversedPar = reversed;
        auto beginReversedPar = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, reversedPar.begin(), reversedPar.end());
        auto endReversedPar = std::chrono::high_resolution_clock::now();
        totalReversedSortTimeParallel += std::chrono::duration_cast<std::chrono::milliseconds>(endReversedPar - beginReversedPar);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray organPipeSeq = organPipe;
        auto beginOrganPipeSeq = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, organPipeSeq.begin(), organPipeSeq.end());
        auto endOrganPipeSeq = std::chrono::high_resolution_clock::now();
        totalOrganPipeSortTimeSequential += std::chrono::duration_cast<std::chrono::milliseconds>(endOrganPipeSeq - beginOrganPipeSeq);
    }
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray organPipePar = organPipe;
        auto beginOrganPipePar = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, organPipePar.begin(), organPipePar.end());
        auto endOrganPipePar = std::chrono::high_resolution_clock::now();
        totalOrganPipeSortTimeParallel += std::chrono::duration_cast<std::chrono::milliseconds>(endOrganPipePar - beginOrganPipePar);
    }
        for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray rotatedSeq = rotated;
        auto beginRotatedSeq = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::seq, rotatedSeq.begin(), rotatedSeq.end());
        auto endRotatedSeq = std::chrono::high_resolution_clock::now();
        totalRotatedSortTimeSequential += std::chrono::duration_cast<std::chrono::milliseconds>(endRotatedSeq - beginRotatedSeq);
    }
    
    for(int i = 0; i < HOW_MANY_TIMES; i++)
    {
        SourceArray rotatedPar = rotated;
        auto beginRotatedPar = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, rotatedPar.begin(), rotatedPar.end());
        auto endRotatedPar = std::chrono::high_resolution_clock::now();
        totalRotatedSortTimeParallel += std::chrono::duration_cast<std::chrono::milliseconds>(endRotatedPar - beginRotatedPar);
    }

    std::cout << "Sequential\n";
    std::cout << "Random: " << totalRandomSortTimeSequential.count() << std::endl;
    std::cout << "Sorted: " << totalSortedSortTimeSequential.count() << std::endl;
    std::cout << "Reversed: " << totalReversedSortTimeSequential.count() << std::endl;
    std::cout << "Organ Pipe: " << totalOrganPipeSortTimeSequential.count() << std::endl;
    std::cout << "Rotated: " << totalRotatedSortTimeSequential.count() << std::endl;

    std::cout << "Parallel\n";
    std::cout << "Random: " << totalRandomSortTimeParallel.count() << std::endl;
    std::cout << "Sorted: " << totalSortedSortTimeParallel.count() << std::endl;
    std::cout << "Reversed: " << totalReversedSortTimeParallel.count() << std::endl;
    std::cout << "Organ Pipe: " << totalOrganPipeSortTimeParallel.count() << std::endl;
    std::cout << "Rotated: " << totalRotatedSortTimeParallel.count() << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::cout << "I am the vector\n";
}
