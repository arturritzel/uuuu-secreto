/*

Entre o valor de resistência desejado.
Uma função lhe responderá com o resistor da série E-12 mais próximo.

*/

#include <iostream>
#include <math.h>
using namespace std;

int e12[13] = {10,12,15,18,22,27,33,39,47,56,68,82,100};

float modulo(float valor){
    if(valor < 0) valor *= -1;
    return valor;
}

int menose12(float desejado){
    int multiplicador = 0;
    int escolhido;
    while(desejado > 100){
        multiplicador++;
        desejado /= 10;
    }

    for(int i = 0; i < 13; i++){
        if(e12[i] < desejado){
            escolhido = e12[i];
        }
    }

    return escolhido * pow(10, multiplicador);
}

int maise12(float desejado){
    int multiplicador = 0;
    int escolhido;
    while(desejado > 100){
        multiplicador++;
        desejado /= 10;
    }

    int i = 0;
    while(e12[i] < desejado) i++;
    escolhido = e12[i];

    return escolhido * pow(10, multiplicador);
}

int melhore12(float desejado){
    int menor = menose12(desejado);
    int maior = maise12(desejado);

    int difmenor = modulo(desejado - menor);
    int difmaior = modulo(desejado - maior);

    if(difmenor < difmaior) return menor;
    return maior;
}

void diferenca(float v1, float v2){
    float diferenca = ((v2/v1)*100) - 100;
    cout << " // taxa de erro: ";
    if(diferenca > 0) cout << "+";
    cout << diferenca << "%";
}

int main()
{
    float resistor;
    cout << "Entre o resistor desejado: ";
    cin >> resistor;
    cout << endl;

    cout << "valor abaixo: " << menose12(resistor);
    diferenca(resistor, menose12(resistor));
    cout << endl;

    cout << "valor acima: " << maise12(resistor);
    diferenca(resistor, maise12(resistor));
    cout << endl;

    cout << "melhor escolha: " << melhore12(resistor);
    diferenca(resistor, melhore12(resistor));
    cout << endl;
}
