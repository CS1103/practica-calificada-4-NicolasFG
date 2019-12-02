#ifndef PC4_ROTATE_H
#define PC4_ROTATE_H
#include <iostream>
#include <vector>
#include <string_view>
#include <cmath>
#include "D_E.h"

void Rotar(std::vector<unsigned char> &vec, unsigned w, unsigned h) {

    vector<unsigned char>temp;

    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w * 4; j += 4) {
            temp.push_back(vec[(i * w * 4 + j + 0)*cos(45)]);
            temp.push_back(vec[(i * w * 4 + j + 1)*cos(45)]);
            temp.push_back(vec[(i * w * 4 + j + 2)*cos(45)]);
            temp.push_back(vec[(i * w * 4 + j + 3)*sin(45)]);
        }
    }
    encode("../rotated.png",temp,w,h);
}






#endif //PC4_ROTATE_H
