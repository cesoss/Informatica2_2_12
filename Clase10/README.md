# Archivos de Configuración

Los archivos de configuración se utilizan para cargar valores iniciales para la ejecución de un programa.

Pueden tener diferentes estructuras y formas, dependiendo del lenguaje, la estructura del código y la decisión del programador.

En el caso de "C" tenemos dos formas básicas:

1-. __Como archivo binario__

Contienen una estructura definida por el programador con un único registro que contiene a todos los campos configurables.


2-. __Como archivo de Texto__

Contienen Claves y valores separados por un caracter definido por el programador.

## Ventajas y diferencias

En el caso de un archivo de configuración binario, el programa debe poder iniciar con una configuración genérica y darle al usuario la interfaz necesaria para poder modificar sus campos. Esto puede funcionar en aplicaciones de escritorio pero no tan bien si se desea usar en un sistema embebido. En un microcontrolador sería necesario un segundo programa de escritorio, para la generación del archivo de configuración lo cual resulta poco práctico para el usuario.

En el caso de los archivos de texto, el programa podría no iniciar en caso de no tener configuración, ya que no debería ser necesario para la generación del mismo. Al ser texto, puede ser generado con cualquier editor, lo que resulta muy práctico para el usuario.
La lectura del archivo puede ser difícil de realizar, porque se deben interpretar las claves y los valores en cualquier orden de ingreso.
El costo de la simplicidad para el usuario es la dificultad para el programador.

## Ejemplo

Se tiene el siguiente archivo *config.conf* que contiene la configuración inicial para un sensor de temperatura.

```bash
# Nombre del Sensor
Nombre sensorTemp01
# Limite Superior de temperatura
tempMax 10
# Limite inferior de temperatura
tempMin 2

```
El programa lee al arhivo de configuración, busca los campos y carga el valor en las variables.

[Ver Video Explicación](https://youtu.be/mGLjVItbHDY)


## Práctica Propuesta

__Ejercicio 28__: Hacer un archivo de configuración de texto, para el ejercicio de Telemetría en el cual se encuentren los datos necesarios para un único sensor.

__Ejercicio 29__: Hacer un programa que genere un archivo de configuración binario para un sensor de Telemetría.

__Ejercicio 30__: Hacer un archivo de configuración que contenga el nombre de un archivo binario de organización secuencial en el cual se cargarán nombres de películas según la siguiente estructura: 
```c
typedef struct {
    char pelicula[40];
    int año;
    char genero[20];
} peliculas_t;
```
Una vez ingresadas las películas mostrar en pantalla los datos cargados.
