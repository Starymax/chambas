#include <iostream>
using namespace std;

void menu(){
    cout<<"HELADOS GSUS"<<"\n"<<"\n";
    cout<<"1. Alta del producto."<<"\n";
    cout<<"2. Modificacion de un producto"<<"\n";
    cout<<"3. Mostrar catalogo de productos"<<"\n";
    cout<<"4. Productos cuya cantidad sea menor a un numero determinado por el usuario"<<"\n";
    cout<<"5. Productos que pertenezcan a una marca en especifico"<<"\n";
    cout<<"6. Productos que cuesten mas de un precio determinado por el usuario"<<"\n";
    cout<<"7. Salir"<<"\n";
}

int longitud(string a){
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}

struct Helados{
    string marca;
    string sabor;
    int litros;
    float precio;
    string clave;
};

void convertirEntero(int numero, char cadena[]) { 
    numero = numero + 1;
    if (numero > 9) { 
        cadena[0] = (numero / 10) + '0';
        cadena[1] = (numero % 10) + '0';
    }
    else{
    cadena[0] = '0';
    cadena[1] = numero + '0';
    }
}

string generar_clave(Helados a[], int contador){
    string clave = "";
    char k[3] = "00";
    char marca1 = a[contador].marca[0]; 
    char marca2 = a[contador].marca[1];
    if (marca1 >= 'a' && marca1 <= 'z')
        marca1 = marca1 - 'a' + 'A';
    if (marca2 >= 'a' && marca2 <= 'z')
        marca2 = marca2 - 'a' + 'A';
    clave = clave + marca1;
    clave = clave + marca2;
    clave = clave + '0';
    convertirEntero(contador, k);
    clave = clave + k; 

    return clave;
}

void alta_producto(Helados a[], int &contador){
    int suma = 0;
    string respuesta;
    string clave;
    bool band = false;
    while(band == false){
        bool band2 = false, band3 = false, band4 = false, band5 = false, band6 = false;
        cout<<"Marca: ";
        while(band2 == false){
            cin>>a[contador].marca;
            if(longitud(a[contador].marca) > 1){
                if((a[contador].marca[0] >= 'a' && a[contador].marca[0] <= 'z') || (a[contador].marca[0] >= 'A' && a[contador].marca[0] <= 'Z')){
                    if((a[contador].marca[1] >= 'a' && a[contador].marca[1] <= 'z') || (a[contador].marca[1] >= 'A' && a[contador].marca[1] <= 'Z')){
                        band2 = true;
                    }
                    else
                        cout<<"Ingrese una marca valida."<<"\n";
                }
                else
                    cout<<"Ingrese una marca valida."<<"\n";
            }
            else
                cout<<"Ingrese una marca valida."<<"\n";
        }
        cout<<"Sabor: ";
        while(band4 == false){
            cin>>a[contador].sabor;
            if(longitud(a[contador].sabor) != '\0')
                band4 = true;
            else
                cout<<"Introduce un sabor valido. ";
        }
        cout<<"Litros: ";
        while(band5 == false){
            cin>>a[contador].litros;
            if(a[contador].litros > - 1)
                band5 = true;
            else
                cout<<"Introduce una cantidad valida. ";
        }
        cout<<"Precio: $";
        while(band6 == false){
            cin>>a[contador].precio;
            if(a[contador].precio > -1)
                band6 = true;
            else
                cout<<"Introduce un precio valido. ";
        }
        cout<<"\n";
        a[contador].clave = generar_clave(a, contador);
        
        cout<<"Es correcta la informacion?"<<"\n"<<"\n";
        cout<<"Marca: "<<a[contador].marca<<"\n";
        cout<<"Sabor: "<<a[contador].sabor<<"\n";
        cout<<"Litros: "<<a[contador].litros<<"\n";
        cout<<"Precio: $"<<a[contador].precio<<"\n";
        cout<<"Clave autogenerada: "<<a[contador].clave<<"\n";
        cout<<"[Y/N]: ";
        while(band3 == false){
            cin>>respuesta;
            if(respuesta[0] == 'Y' || respuesta[0] == 'y'){
                contador = contador + 1;
                band = true, band3 = true;
            }
            else{
                if((respuesta[0] == 'N') || (respuesta[0] == 'n')){
                    band3 = true;
                }
                else
                cout<<"Ingrese una respuesta valida."; 
            }
        }
    }
}

void modificacion(Helados a[]){
    string clave;
    string respuesta;
    int num;
    int suma = 0;
    char n;
    bool band = false, band2 = false, band3 = false, band4 = false, band5 = false, band6 = false;
    cout<<"Ingrese el codigo del producto a modificar: ";
    while(band == false){
        cin>>clave;
        n = clave[4];
        num = n - '0';
        num = num - 1;
        if(clave == a[num].clave){
            while(band2 == false){
                cout<<"Helado "<<a[num].clave<<" de la marca "<<a[num].marca<<"\n"<<"\n";
                cout<<"Sabor: ";
                while(band4 == false){
                    cin>>a[num].sabor;
                    if(longitud(a[num].sabor) > 0)
                        band4 = true;
                    else
                        cout<<"Introduce un sabor valido. ";
                }
                cout<<"Litros: ";
                while(band5 == false){
                    cin>>a[num].litros;
                    if(a[num].litros > - 1)
                        band5 = true;
                    else
                        cout<<"Introduce una cantidad valida. ";
                }
                cout<<"Precio: $";
                while(band6 == false){
                    cin>>a[num].precio;
                    if(a[num].precio > -1)
                        band6 = true;
                    else
                        cout<<"Introduce un precio valido. ";
                }
                cout<<"\n";
                
                cout<<"Es correcta la informacion?"<<"\n"<<"\n";
                cout<<"Marca: "<<a[num].marca<<"\n";
                cout<<"Sabor: "<<a[num].sabor<<"\n";
                cout<<"Litros: "<<a[num].litros<<"\n";
                cout<<"Precio: $"<<a[num].precio<<"\n";
                cout<<"Clave: "<<a[num].clave<<"\n";
                cout<<"[Y/N]: ";
                while(band3 == false){
                    cin>>respuesta;
                    if(respuesta[0] == 'Y' || respuesta[0] == 'y'){
                        band2 = true, band3 = true;
                    }
                    else{
                        if((respuesta[0] == 'N') || (respuesta[0] == 'n')){
                            band3 = true;
                        }
                        else
                        cout<<"Ingrese una respuesta valida. "; 
                    }
                }
            }
            band = true;
        }
        else{
            cout<<"Clave incorrecta, volviendo al menu principal. "<<"\n"<<"\n";
            band = true;
        }
    }
}


void catalogo(Helados a[], int contador){
    string k;
    cout<<"CATALOGO"<<"\n"<<"\n";
    if(contador > 0){
        for(int i = 0; i<(contador); i++){
            cout<<"Helado "<<a[i].clave<<"\n"<<"\n";
            cout<<"Marca: "<<a[i].marca<<"\n";
            cout<<"Sabor: "<<a[i].sabor<<"\n";
            cout<<"Litros: "<<a[i].litros<<"\n";
            cout<<"Precio: $"<<a[i].precio<<"\n"<<"\n";
        }
        cout<<"Presione cualquier tecla y enter para volver. "<<"\n";
        cin>>k;
    }
    else{
        cout<<"Inventario vacio..."<<"\n"<<"\n";
        cout<<"Presione cualquier tecla y enter para volver. "<<"\n";
        cin>>k;
        }
}

void existencias(Helados a[], int contador){
    int cantidad;
    string k;
    bool band = false;
    cout<<"Ingrese la cantidad en litros: ";
    cin>>cantidad;
    if(cantidad > -1){
        cout<<"Helados con menos de "<<cantidad<<" litros:"<<"\n"<<"\n";
        for(int i = 0; i < contador; i++){
            if(a[i].litros < cantidad){
                cout<<"Helado "<<a[i].clave<<" de la marca "<<a[i].marca<<"\n";
                cout<<"Litros disponibles: "<<a[i].litros<<"\n";
                cout<<"Sabor: "<<a[i].sabor<<"\n";
                cout<<"Precio: $"<<a[i].precio<<"\n"<<"\n";
                band = true;
            }
        }
        if(band == false)
            cout<<"No hay helados con menos de "<<cantidad<<" litros."<<"\n";
    }
    else{
        cout<<"Valor de cantidad incorrecto, volviendo al menu pricipal. "<<"\n";
    }
    cout<<"Presione cualquier tecla y enter para volver. "<<"\n";
        cin>>k;
}

void mismamarca(Helados a[], int contador){
    string marca;
    string k;
    bool band = false;
    cout<<"Ingrese la marca buscada: ";
    cin>>marca;
    if(contador > 0){
        cout<<"Helados de la marca "<<marca<<": "<<"\n"<<"\n";
        for(int i = 0; i < contador; i++){
            if(a[i].marca == marca){
                cout<<"Helado "<<a[i].clave<<"\n";
                cout<<"Litros disponibles: "<<a[i].litros<<"\n";
                cout<<"Sabor: "<<a[i].sabor<<"\n";
                cout<<"Precio: $"<<a[i].precio<<"\n"<<"\n";
                band = true;
            }
        }
        if(band == false)
            cout<<"No hay helados de la marca "<<marca<<". "<<"\n"<<"\n";
    }
    else{
        cout<<"Sin existencias, volviendo al menu pricipal. "<<"\n";
    }
    cout<<"Presione cualquier tecla y enter para volver. "<<"\n";
        cin>>k;
}

void precio(Helados a[], int contador){
    float precio;
    string k;
    bool band = false;
    cout<<"Ingrese el precio minimo buscado: ";
    cin>>precio;
    if(precio > -1){
        cout<<"Helados con un costo minimo de $"<<precio<<": "<<"\n"<<"\n";
        for(int i = 0; i < contador; i++){
            if(a[i].precio > precio){
                cout<<"Helado "<<a[i].clave<<" de la marca "<<a[i].marca<<"\n";
                cout<<"Litros disponibles: "<<a[i].litros<<"\n";
                cout<<"Sabor: "<<a[i].sabor<<"\n";
                cout<<"Precio: $"<<a[i].precio<<"\n"<<"\n";
                band = true;
            }
        }
        if(band == false)
            cout<<"No hay helados con un precio mayor a $"<<precio<<". "<<"\n";
    }
    else{
        cout<<"Precio incorrecto, volviendo al menu pricipal. "<<"\n";
    }
    cout<<"Presione cualquier tecla y enter para volver. "<<"\n";
        cin>>k;
}

void menu_eleccion(Helados a[], int &contador){
    int opcion;
    bool opcion_valida = false;
    while(opcion_valida == false){
        menu();
        cin>>opcion;
        switch (opcion){
            case 1:{
                cout<<"ALTA DEL PRODUCTO."<<"\n"<<"\n";
                alta_producto(a, contador);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 2:{
                modificacion(a);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 3:{
                catalogo(a, contador);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 4:{
                existencias(a, contador);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 5:{
                mismamarca(a, contador);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 6:{
                precio(a, contador);
                menu_eleccion(a, contador);
                opcion_valida = true;
                break;
            }
            case 7:{
                opcion_valida = true;
                break;
            }
            default:{
                cout<<"Opcion invalida, elija nuevamente."<<"\n";
                break;
            }
        }
    }
}

int main(){
    Helados a[50];
    int contador = 0;
    menu_eleccion(a, contador);
    return 0;
}