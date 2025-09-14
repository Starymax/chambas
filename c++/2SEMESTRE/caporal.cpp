#include <iostream>
using namespace std;

bool compararPalabras(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        char ca = a[i];
        char cb = b[i];
        if (ca >= 'A' && ca <= 'Z') {
            ca += 'a' - 'A';
        }
        if (cb >= 'A' && cb <= 'Z') {
            cb += 'a' - 'A';
        }
        if (ca != cb) {
            return false;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int main() {
    const int MAX_LONG = 200; 
    char frase[MAX_LONG];
    cout << "Ingrese una frase: ";
    cin.getline(frase, MAX_LONG);

    char *palabras[MAX_LONG]; 
    int totalPalabras = 0;

    bool enPalabra = false;
    for (int i = 0; frase[i] != '\0'; ++i) {
        if (frase[i] != ' ' && !enPalabra) {
            palabras[totalPalabras++] = &frase[i];
            enPalabra = true;
        }
        if (frase[i] == ' ') {
            frase[i] = '\0';  
            enPalabra = false;
        }
    }

    char *distintas[MAX_LONG]; 
    int frecuencia[MAX_LONG];
    int totalDistintas = 0;

    for (int i = 0; i < totalPalabras; ++i) {
        if (*palabras[i] == '\0') {
            continue;
        }
        bool yaContada = false;
        for (int j = 0; j < totalDistintas; ++j) {
            if (compararPalabras(palabras[i], distintas[j])) {
                frecuencia[j]++;
                yaContada = true;
                break;
            }
        }
        if (!yaContada) {
            distintas[totalDistintas] = palabras[i];
            frecuencia[totalDistintas] = 1;
            totalDistintas++;
        }
    }

    cout << "\nNúmero total de palabras: " << totalPalabras << endl;
    cout << "Número de palabras distintas: " << totalDistintas << endl;
    cout << "Lista de palabras con su frecuencia:\n";
    for (int k = 0; k < totalDistintas; ++k) {
        cout << distintas[k] << ": " << frecuencia[k] << endl;
    }
    
    return 0;
}