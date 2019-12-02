#include <iostream>
#include "Picture_con.h"

using namespace std;

int main()
{

    //Set de problemas

    //Problema 1
    Imagen_concurrente obj1;
    obj1.decode("../in.png");
    obj1.modifica();
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
