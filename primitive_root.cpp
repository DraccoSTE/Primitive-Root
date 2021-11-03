#include<bits/stdc++.h>
#include <vector>
using namespace std;

// comprobamos si n es primo, ya que es necesario para que el 
//algoritmo funcione correctamente
bool isPrime(int num){
	// si n es menor o igual a 1 no es primo, devolvera false
	if (num <= 1) return false;
  // si n es menor o igual a p teniendo en cuenta que por la
  // anterior condicion es mayor a 1 sera primo y devuelve true
	if (num <= 3) return true;
	// Tendremos que si el numero es divisible entre 2 o 3 no es primo
	if (num%2 == 0 || num%3 == 0) return false;

	for (int i=5; i*i<=num; i=i+6)
		if (num%i == 0 || num%(i+2) == 0)
			return false;

	return true;
}

// funcion para hallar la potencia de la lista de numeros para comprobar la raiz
int ExpMod(int x, int y, int p){
	int res = 1;
	x = x % p; // sacamos modulo p de x

  //hacemos que y se convierta en impar
	while (y > 0){
		if (y & 1)
			res = (res*x) % p;

		y = y >> 1;
		x = (x*x) % p;
	}
	return res;
}

// con esta funcion calcularemos las potencias de los numeros previos
void Lista(unordered_set<int> &s, int n){
	// dividir n entre 2 hasta que sea impar
	while (n%2 == 0){
		s.insert(2);
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i+2){
		// si i es divisor es agregado a la lista y se divide n sobre el mismo
		while (n%i == 0){
			s.insert(i);
			n = n/i;
		}
	}
	if (n > 2)
		s.insert(n);
}

// en esta funcion hallamos la funcion primitiva mas pequena de n
int Proot(int n){
	unordered_set<int> s;
	// si n no es primo el algoritmo no puede continuar
	if (isPrime(n)==false)
		return -1;
	// hallaremos phi de euler de n, que al ser primo sera el numero menos 1
	int phi = n-1;
	// llamamos a la funcion para crear la lista de numeros
	Lista(s, phi);
	// iteramos mientras el numero sea menor que phi de euler
	for (int r=2; r<=phi; r++){
		// buscamos en la lista para hallar si existe 1
		bool exist = false;
		for (auto it = s.begin(); it != s.end(); it++){
			// si algun numero elevado a phi entre la cantidad de numeros modulo n es 1
      //el numero actual no es una raiz primitiva de n
			if (ExpMod(r, phi/(*it), n) == 1){
				exist = true;
				break;
			}
		}

		// si no se cumplen las condiciones el numero r es una raiz de n
		if (exist == false)
		return r;
	}

	cout<<"No se encontro una raiz primitiva para este numero";
	return -1;
}

int main(){
	int n = 100049;
	cout << " Menor Raiz Primitiva de " << n << " es: ";
  cout<< Proot(n);
}
