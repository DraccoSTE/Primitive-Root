# Primitive-Root

Este algoritmo halla la raiz primitiva de un numero "p" a ingresar, primero determinando si es primo o no, si no es primo no se puede continuar.

Posteriormente crea una lista de valores anteriores y menores a p, los cuales son potencias de la posible raiz yendo desde exponente 0 a p-1, los cuales luego seran sometidos a un modulo p, finalmente, se revisa mediante una iteracion si se repite algun numero dentro de esa lista, dado caso que se repita el numero no será raiz y se continuará hasta el siguiente, si cumple todas estas pruebas el numero es la raiz primitiva mas pequeña de p.
