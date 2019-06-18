//
//  Example.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "Example.h"

void Example::setup()
{
    lastTime = clock();
}

void Example::render()
{
    clock_t newTime = clock();
    double timeDelta = (newTime-lastTime)/100000.0;
    if (timeDelta>1)
    {
        timeDelta = 1;
    }
    lastTime = newTime;
    totalTime += timeDelta;
}

void Example::release()
{

}
