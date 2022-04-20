/*
    Nombre del Programa: N-ésimo Primo
    Autor: Leandro Licari
    Fecha: 20/04/2022

    Descripción: Programa que dado un número natural n, me devuelve el n-ésimo primo.
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

bool esPrimo(vector<int>& primos, int num){
    double raizNum = sqrt(num);
    for (int i = 0; i < primos.size(); i++){   
        if (primos[i] > raizNum){
            return true;
        }
        
        if (num%primos[i] == 0){
            return false;
        }
    }
    return true;    
}


void mostrarPrimos(vector<int>& primos){
    cout << "Primos = [";
    for (int i = 0; i < primos.size(); i++){
        if (i != primos.size()-1){
            cout << primos[i] << " ";
        }else{
            cout << primos[i] << "]" << endl;
        }  
    }
}


int nEsimoPrimo(int n){
    vector<int> primos = {};
    int num = 2;
    while (primos.size() < n){
        if(esPrimo(primos, num)){
            primos.push_back(num);
        }
        num++;
    } 
    //Puedo mostrar todos los primos hasta el n-ésimo primo, descomentar siguiente línea
    //mostrarPrimos(primos);

    return primos[primos.size()-1];
}


int main(){
    int n;
    cout << "Calcular el nEsimo primo, introduzca n (Mayor a 0): ";
    unsigned t0, t1;
    cin >> n;
    t0 = clock();
    cout << "Primo n = " << nEsimoPrimo(n) << endl;
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo transcurrido: " << time << endl;
    return 0;
}