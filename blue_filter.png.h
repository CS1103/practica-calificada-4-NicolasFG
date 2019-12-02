#ifndef PC4_BLUE_FILTER_PNG_H
#define PC4_BLUE_FILTER_PNG_H
#include <iostream>
#include <thread>
#include <vector>
#include <string_view>
#include "lodepng.h"
#include "D_E.h"
#include "red_filter.png.h"
#include "green_filter.png.h"
#include "blue_filter.png.h"

void blue_filter( vector<unsigned char> vec ,  unsigned int w, unsigned int h)
{
    vector<unsigned char> image2;
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w * 4; j += 4)
        {
                int r = vec[0];
                int g = vec[0];
                int b = vec[i * w * 4 + j + 2];
                int a = vec[i * w * 4 + j + 3];
                image2.push_back(r);
                image2.push_back(g);
                image2.push_back(b);
                image2.push_back(a);
        }

    }
    encode("../Blue_filter.png", image2, w, h);
}

#endif //PC4_BLUE_FILTER_PNG_H
