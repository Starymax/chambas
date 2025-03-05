

struct nodo{
    int valor;
    nodo *sig;
};

int main(){
    // cabeza
    nodo *head = NULL;
    nodo *p = NULL;
    p = new nodo; //puede ser new nodo();
    p -> valor = 2;
    p -> sig = NULL;
    head = p;
    // delete p; delete head;

    //posicion 2
    p = new nodo;
    p -> valor = 3;
    p -> sig = NULL;
    head -> sig = p;

    // posicion 3
    ap = new nodo;
    ap -> valor = 8;
    ap -> sig = NULL;
    p -> sig = ap;
}