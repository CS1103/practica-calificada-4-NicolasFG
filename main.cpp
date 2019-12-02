#include <iostream>
#include <thread>
#include "D_E.h"
#include "Rotate.h"
#include "red_filter.png.h"
#include "green_filter.png.h"
#include "blue_filter.png.h"

using namespace std;



int main()
{
    unsigned int w;
    unsigned int h;
    //Set de problemas
    //Problema 1

    auto image = decode("../logo_spiderman.png",w,h);

    Rotar("../logo_spiderman1.png",image,w,h);

    //encode("../logo_spiderman1.png",image,w,h);

//    auto image = decode("../in.png",w,h);
//    auto t1 = thread([&image, &w, &h]{red_filter(image,w,h);});
//    t1.join();
//    cout<<"Primer archivo modificado"<<endl;
//    auto image2 = decode("../in.png",w,h);
//    auto t2 = thread([&image, &w, &h]{green_filter(image,w,h);});
//    t2.join();
//    cout<<"Segundo archivo modificado"<<endl;
//    auto image3 = decode("../in.png",w,h);
//    auto t3 = thread([&image, &w, &h]{red_filter(image,w,h);});
//    t3.join();
//    cout<<"Tercer archivo modificado"<<endl;

//    //Problema 2
//    auto image2 = decode("../Pac_Man.png",w,h);
//    auto t2 = thread([&image2, &w, &h]{blue_filter(image2,w,h);});
//    t2.join();

    //Problema 3
//    auto image3 = decode("../logo_spiderman.png",w,h);
//    auto t3 = thread([&image3, &w, &h]{blue_filter(image3,w,h);});
//    t3.join();
    return 0;
}
