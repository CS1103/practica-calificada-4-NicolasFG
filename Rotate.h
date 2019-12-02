#ifndef PC4_ROTATE_H
#define PC4_ROTATE_H
#include <iostream>
#include <vector>
#include <string_view>
#include <cmath>
#include "D_E.h"
#include "lodepng.h"

void Rotar(string_view filename,std::vector<unsigned char> &vec, unsigned int w, unsigned int h) {

    vector<unsigned char> temp;

    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w * 4; j += 4) {
            double a=i*cos(45)-j*sin(45);
            double b=j*cos(45)+i*sin(45);
            temp[a * w * 4 + b + 0]=vec[i * w * 4 + j + 0];
            temp[a * w * 4 + b + 1]=vec[i * w * 4 + j + 1];
            temp[a * w * 4 + b + 2]=vec[i * w * 4 + j + 2];

        }
        cout << endl;
    }
    encode(filename.data(),temp,w,h);
}

#endif //PC4_ROTATE_H
