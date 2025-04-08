#include <isotream>
using namespace std;

struct Poli{
    int coeficiente;
    int exponente;
    Poli *sig;
}

void insertar(Poli *head, int exponente, int coeficiente){
    if(head == NULL || head -> exponente < exponente){
        Poli *nuevo = new Poli;
        nuevo -> exponente = head -> exponente;
        if(head -> siguiente == NULL)
            nuevo -> siguiente = NULL;
        else
            nuevo -> siguiente = head -> siguiente;
        head -> siguiente = nuevo;
        head -> exponente = exponente;
        head -> coeficiente = coeficiente;
    }
    else{
        if(head -> exponente < exponente && head -> siguiente == NULL){
            Poli *nuevo = new Poli;
            nuevo -> exponente = head -> exponente;
            nuevo -> siguiente = NULL;
            head -> siguiente = nuevo;
            head -> exponente = exponente;
            head -> coeficiente = coeficiente;
        }
        else{
            if(head -> exponente <= exponente && (head -> siguiente == NULL || head -> siguiente -> exponente > exponente)){
                Poli *nuevo = new Poli;
                nuevo -> exponente = exponente;
                if(head -> siguiente == NULL)
                    nuevo -> siguiente = NULL;
                else
                    nuevo -> siguiente = head -> siguiente;
                head -> siguiente = nuevo;
            }
            else
                insertarOrdenado(head -> siguiente, exponente);
        }
    }
}

int main(){
    return 0;
}