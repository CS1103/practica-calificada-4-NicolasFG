#include <iostream>
#include <thread>
#include "D_E.h"
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

    auto image = decode("../in.png",w,h);
    auto t1 = thread([&image, &w, &h]{blue_filter(image,w,h);});
    t1.join();
    cout<<"Archivo modificado"<<endl;

    //Problema 2
    /*Imagen_concurrente obj2;
    obj2.modifica();
    cout<<"Archivo modificado"<<endl;*/

    //Problema 3
    /*Imagen_concurrente obj3;
    obj3.modifica();
    cout<<"Archivo modificado"<<endl;*/

    return 0;
}
