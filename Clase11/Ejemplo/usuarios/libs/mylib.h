#ifndef __MY_LIB_H__
#define __MY_LIB_H__

/*Incluimos la librerias*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Definicion de Tipos de Variables*/
typedef struct {
  char nombre[20];
  char password[20];
  int usercode;
  char flag;
}usuario;

typedef struct {
  char ascii;
  char draw[5];
  char flag;
}letra;

/*Prototipos de funciones a resolver en Caracteres.c*/
void listarCaracteres(void);
void nuevoCaracter(void);
void modificarCaracter(void);
void eliminarCaracter(void);
void enviarCaracter(void);

/*Prototipos de funciones a en users.c*/
void nuevoUsuario(void);
void ListarUsuarios(void);
void modificarUsuario(void);
void eliminarUsuario(void);
void findeprograma(void);
void bajaFisica(void);
int login(usuario);
int bienvenida(void);
int Opciones(void);

#endif
