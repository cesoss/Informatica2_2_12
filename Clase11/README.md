# Práctica con Archivos

En la Práctica de esta clase, planteamos el ABM en archivos Secuenciales.
Se tiene un programa que guarda en un archivo a la estructura de caracteres 8x5 formada por 5 variables de 8 bits, es decir, utilizando manejo de bits para almacenar cada uno de los caracteres.

La estructura de los caracteres es:
```c
typedef struct {
  char ascii;
  char draw[5];
  char flag;
}letra_t;

```
El programa tiene un control de usuarios con contraseña, con su ABM, para usarlo de ejemplo.

Ejemplo: [Acceder al código de Ejemplo](https://github.com/DamRCorba/Informatica2_2_12/tree/master/Clase11/Ejemplo/usuarios)


## Práctica Propuesta

__Ejercicio 31__: Ampliar el código de ejemplo con el alta de un caracter.

__Ejercicio 32__: Ampliar el código de ejemplo con la modificación de un caracter.

__Ejercicio 33__: Ampliar el código de ejemplo con la baja de un caracter.

__Ejericio 34__: Hacer un programa que emule al comando copy de Windows. __copy archivo_original nuevo_arhivo_copiado__
