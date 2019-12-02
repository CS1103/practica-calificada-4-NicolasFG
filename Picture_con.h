#ifndef PC4_PICTURE_CON_H
#define PC4_PICTURE_CON_H

#include <iostream>
#include <vector>
#include <string_view>
#include <thread>
#include "lodepng.h"

#define NUM_HILOS 3

using namespace std;

class Imagen_concurrente {

public:
    vector< unsigned char> img;
    unsigned int w;
    unsigned int h;

    //Funciones
    void decode (string_view filename);
    void encode(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height);
    vector<unsigned char> red_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h);
    vector<unsigned char> blue_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h);
    vector<unsigned char> green_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h);
    vector<unsigned char> rotar(vector<unsigned char> vec ,  unsigned int w, unsigned int h);

    void modifica();

    void *cambia (void *arg);
};

void Imagen_concurrente::decode(string_view filename)
{
    vector<unsigned char> result;
    unsigned int width;
    unsigned int height;
    width = w;
    height = h;
    unsigned error = lodepng::decode(result, width, height, filename.data());
    if (error)
    {
        cerr << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
    img =  result;
}

void Imagen_concurrente::encode(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error)
    {
        cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

vector<unsigned char> Imagen_concurrente::red_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h)
{
    vector<unsigned char> image2;
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            int r = vec[i * w * 4 + j + 0];
            int g = vec[0];
            int b = vec[0];
            int a = vec[i * w * 4 + j + 3];
            image2.push_back(r);
            image2.push_back(g);
            image2.push_back(b);
            image2.push_back(a);
        }
    }
    return image2;
}

vector<unsigned char> Imagen_concurrente::blue_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h)
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
    return image2;
}

vector<unsigned char> Imagen_concurrente::green_filter(vector<unsigned char> vec ,  unsigned int w, unsigned int h)
{
    vector<unsigned char> image2;
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w * 4; j += 4)
        {
            int r = vec[0];
            int g = vec[i * w * 4 + j + 1];
            int b = vec[0];
            int a = vec[i * w * 4 + j + 3];
            image2.push_back(r);
            image2.push_back(g);
            image2.push_back(b);
            image2.push_back(a);
        }
    }
    return image2;
}

vector<unsigned char> Imagen_concurrente::rotar(vector<unsigned char> vec ,  unsigned int w, unsigned int h)
{
    vector<unsigned char> image2;
    return image2;
}
void Imagen_concurrente:: *cambia (void *arg)
{
    vector<unsigned char> image;
    if (t==0)
    {
        image=red_filter(img,w,h);
        encode("../red_filter.png", img, w, h);
    }
    if (t==1)
    {
        image=green_filter(img,w,h);
        encode("../green_filter.png", img, w, h);
    }
    if (t==2)
    {
        image=blue_filter(img,w,h);
        encode("../blue_filter.png", img, w, h);
    }

}

void Imagen_concurrente::modifica ()
{
        int rc;
        long t;
        void* status;

        pthread_t hilos[ NUM_HILOS ];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        for (t = 0;t < NUM_HILOS; t++)
        {
            cout << "Creando el hilo" << t;

            rc = pthread_create (&hilos[t],&attr,cambia,(void *)t);
            if (rc)
            {
                cout << "ERROR codigo" << rc;
                exit(-1);
            }
        }

        pthread_attr_destroy(&attr);
        for(t=0;t<NUM_HILOS;t++)
        {
            rc = pthread_join(hilos[t],&status);
            if (rc)
            {
                cout << "ERROR,codigo" << rc;
                exit(-1);
            }
        }
        cout<<endl;
        pthread_exit(nullptr);
}
#endif //PC4_PICTURE_CON_H
