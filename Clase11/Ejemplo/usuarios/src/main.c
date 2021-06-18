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
  char draw[5][8];
  char flag;
}letra;
/*Prototipos de funciones*/
void listarCaracteres(void);
void nuevoCaracter(void);
void modificarCaracter(void);
void eliminarCaracter(void);
void enviarCaracter(void);
void nuevoUsuario(void);
void ListarUsuarios(void);
void modificarUsuario(void);
void eliminarUsuario(void);
void findeprograma(void);
void bajaFisica(void);
int login(usuario);
int bienvenida(void);
int Opciones(void);


/*Vector a punteros a funciones para el Menu*/
void (*menu[])(void)= {listarCaracteres       //Opcion 0
  ,nuevoCaracter          //Opcion 1
  ,modificarCaracter      //Opcion 2
  ,eliminarCaracter       //Opcion 3
  ,enviarCaracter         //Opcion 4
  ,ListarUsuarios         //Opcion 5
  ,nuevoUsuario           //Opcion 6
  ,modificarUsuario       //Opcion 7
  ,eliminarUsuario        //Opcion 8
  ,findeprograma          //Opcion 9
};

/*Fin de declaraciones y definciones, Comienzan los codigos fuente.*/
/*Programa Principal*/
int main(void){
  char opc;
  if(bienvenida()){
    do{
    opc = Opciones();
    (*menu[opc])();
  }while(opc != 9); // Valor que devuelve Bienvenido en caso se apretar ESC
  }
  else printf("Usuario Desconocido.... Adios\n");
  return 0;
}
/*Funcion Bienvenido
Resumen: Muestra el mensaje inicial del programa en pantalla, pide al usuario el Usuario y Pass. Y llama a login
Si todo esta bien, da la bienvenida al usuario y devuelve 1, sino devuelve 0.
*/
int bienvenida(void){
  usuario user;
  char intentos =0,a;
  printf("Bienvenido, por favor ingrese sus credenciales para acceder al sistema\r\n");
  printf("\n\rUsuario: ");
  scanf("%s", &user.nombre);
  fflush(stdin);
  printf("\r\npassword:");
  scanf("%s",&user.password);
  while(intentos < 3){
    if(login(user)){
      printf("\n\rBienvenido %s\n\r",user.nombre);
      return 1;
    }
    else
    intentos++;
  }
  return 0;
}
/*Funcion login
buscara en el archivo userfile si existe el usuario ingresado, si esta dado de alta y en caso de que el pass
sea correcto devolvera 1.
*/
int login(usuario userdata){
  FILE *userFile;
  usuario uleido;

  userFile=fopen("userfile.dat","r+");
  if(!userFile)/*No existe archivo de usuario*/
  {
    userFile=fopen("userfile.dat","w+");
    if(!userFile){
      printf("No hay espacio en disco\n");
      return 0;
    }
    userdata.usercode = 0;
    userdata.flag = 'A';
    if(fwrite(&userdata,sizeof(usuario),1,userFile)){
      fclose(userFile);
      return 1;
    }
    else {
      printf("Error de escritura\n");
      return 0;
    }
  }
  else{
    do{
      fread(&uleido,sizeof(usuario),1,userFile);
      printf("%s\n",uleido.password);
      printf("%s\n",userdata.password);
      if(!strcmp(uleido.nombre,userdata.nombre)){
        if(uleido.flag=='A'){
          fclose(userFile);
          return (!strcmp(uleido.password,userdata.password))?1:0;
        }
      }
    }while(!feof(userFile));
    printf("No se encotro usuario\n" );
    fclose(userFile);
    return 0;
  }
}
/*Funcion Opciones
Resumen: Muestra en pantalla el menu del programa y lee la opcion elegida por el usuario.
El orden del Menu esta dado por la ubicacion de las funciones en el vector de punteros a funciones.
El usuario solo puede elegir de 1 a 9 (caracter) pero el vector empieza en 0
por lo que se le resta el valor de '1' de manera que '1'-'1' = 0 y '2' - '1' = 1.
El unico caso particular se da con la opcion de salir en la que el programa devolvera 9, la ubicacion de la funciones
fin de programa.
*/
int Opciones(void){
  char opc;
  printf("Que desea hacer hoy?\n\r");
  printf("1-Listar Letras\n\r");
  printf("2-Nueva Letra\n\r");
  printf("3-Modificar Letras\n\r");
  printf("4-Eliminar Letras\n\r");
  printf("5-Enviar una Letra\n\r");
  printf("6-Listar Usuarios\n\r");
  printf("7-Nuevo Usuario\n\r");
  printf("8-Modificar Usuario\n\r");
  printf("9-Eliminar usuario\n\r");
  printf("Precione Esc para salir.\n\r");
  do{
    scanf("%c",&opc); //Se lee el caracter
    if(opc == 27)
    return 9;
    if(opc< '1' || opc > '9'){
      printf("Opcion no valida, elija una opcion valida\n\r");
    }
  }while(opc< '1' || opc > '9');
  return opc - '1';
}

/*Leera del archivo de Caracteres los datos dados de alta.*/
void listarCaracteres(void){}

/*Permitira al usuario ingresar los datos de un nuevo caracter en el archivo*/
void nuevoCaracter(void){}

/*Permitira al usuario modifica los datos de un caracter en el archivo*/
void modificarCaracter(void){}

/*Permitira elimiar un registro del archivo*/
void eliminarCaracter(void){}

/*Mostrara un Caracter especifico en Pantalla*/
void enviarCaracter(void){}

/*Permitira Crear un Usuario*/
void nuevoUsuario(void){
  FILE *userFile;
  usuario unuevo,uleido,*ptr;
  char aux =0, temp[20];
  ptr = &unuevo;
  userFile=fopen("userfile.dat","r+");
  if(!userFile)/*No existe archivo de usuario*/
  {
    printf("\n\rNo hay Archivo de Usuarios.");
  }
  else{
    do{
      userFile = fopen("userfile.dat","r");
      printf("Ingrese Nombre de Usuario: ");
      scanf("%s",&unuevo.nombre);
          do{
        fread(&uleido,sizeof(usuario),1,userFile);
        if(strcmp(unuevo.nombre,uleido.nombre)==0){
          aux = 0;
          rewind(userFile);
          break;
        }else{ aux = 1;
          unuevo.usercode = uleido.usercode+1;
        }
      }while(!feof(userFile));
    }while(!aux);
    fclose(userFile);
    do{
      printf("\n\rIngrese el Password");
      fflush(stdin);
      scanf("%s",&unuevo.password);
      printf("\n\rReingrese el Password");
      scanf("%s",&temp);
      fflush(stdin);
    }while(strcmp(unuevo.password,temp)!=0);

    unuevo.flag = 'A';
    userFile=fopen("userfile.dat","a");
    if(userFile == NULL){
      printf("No se pudo abrir");
    }
    if(fwrite(ptr,sizeof(usuario),1,userFile)){
      fclose(userFile);
      printf("Nuevo Usuario Creado");
      ListarUsuarios();
    }
    else {
      printf("Error de escritura\n");
    }
  }

}

/*Listara los usuarios habilitados
typedef struct {
  char nombre[20];
  char password[20];
  int usercode;
  char flag;
}usuario;
*/
void ListarUsuarios(void){
  FILE *userFile;
  usuario uleido;
    userFile=fopen("userfile.dat","rb");
  if(!userFile)/*No existe archivo de usuario*/
  {
  printf("\n\rNo se pudo abrir Archivo de Usuarios.");
  }
  else{
    printf("\tCodigo\t\t  Nombre\t\t  Password\t\tEstado\n");
    fread(&uleido,sizeof(usuario),1,userFile);
    while(!feof(userFile)){
      if(uleido.flag == 'A'){
        printf("\n\r%10d\t",uleido.usercode);
        printf("%20s\t",uleido.nombre);
        printf("%20s\t",uleido.password);
        printf("\t%c\n\r", uleido.flag );
      }
      fread(&uleido,sizeof(usuario),1,userFile);
    }
      fclose(userFile);

  }

}

/*Permitira Modificar un Usuario
Se permitira modificar el nombre y el password

*/
void modificarUsuario(void){
  usuario udataold,udatanew,aux;
  long ubicacion;
  FILE *userFile;
  char opcion = 0;
  printf("\n\rIngrese el Usuario a Modificar" );
  scanf("%s",&udatanew.nombre);

  userFile=fopen("userfile.dat","rb+");
  if(!userFile)/*No existe archivo de usuario*/
  {
    printf("\n\rNo se pudo abrir Archivo de Usuarios.");
  }
  else{
      fread(&udataold,sizeof(usuario),1,userFile);
      while(!feof(userFile)){
        if(!strcmp(udataold.nombre,udatanew.nombre)){ // Si el nombre ingresado es igual al nombre leido en el archivo
          ubicacion = (long)udataold.usercode;
          strcpy(aux.nombre,udataold.nombre);
          strcpy(aux.password,udataold.password);
          aux.flag = udataold.flag;
          aux.usercode = ubicacion;
          break;
        }
        else fread(&udataold,sizeof(usuario),1,userFile);
      }
      if(feof(userFile)){ // Si el ciclo anterior termino por Fin de Archivo fue porque el registro no fue encontrado
        printf("No se encotro registro");
        return;
      }
      while(opcion != 's' && opcion != 'S' && opcion !='n' && opcion !='N'){
        printf("Desea Modificar el nombre?s/n");
        scanf("%c",&opcion);
      }
      //Si elijo modificar el nombre de usuario debo verificar que el nuevo no exista.
      if(opcion == 's' || opcion == 'S'){
        printf("Ingrese el nuevo nombre del usuario\n");
        scanf("%s",&udatanew.nombre);
        rewind(userFile); // vuelvo al inicio del archivo
        fread(&udataold,sizeof(usuario),1,userFile);
        while(!feof(userFile)){
          if(!strcmp(udataold.nombre,udatanew.nombre)) // Si el nombre ingresado es igual al nombre leido en el archivo
          {
            // Si existe el nuevo, entonces debo pedir que ingrese uno diferente.
            printf("El nombre de usuario ya esta siendo usado. Ingrese otro:\n");
            scanf("%s",&udatanew.nombre );
            fread(&udataold,sizeof(usuario),1,userFile);
          }
          else fread(&udataold,sizeof(usuario),1,userFile);
        }
        /*Si llego al final del archivo sin encontrarlo, entonces la modificacion del nombre se puede hacer.
        En este caso deberia consultar si se puede modificar el pass y volver a ubicar al puntero en el registro para modifciarlo.*/

      }
    // Una vez concluida la pregunta del cambio de nombre de usuario se verifica si se quiere cambiar password
      opcion = 0; //Es necesario vaciar opcion.
      fseek(userFile,(ubicacion)*(long)sizeof(usuario),0);
      while(opcion != 's' && opcion != 'S' && opcion !='n' && opcion !='N'){
      printf("Desea Modificar el Password?s/n" );
       scanf("%c",&opcion);
      }
      if(opcion == 's' || opcion == 'S'){
          printf("Ingrese el password viejo\n" );//Por seguridad se pregunta por el password viejo antes de admitir cambio
          scanf("%s",&udatanew.password);
          if(!strcmp(aux.password,udatanew.password)){
            printf("Ingrese el nuevo password\n" );
            scanf("%s",&udatanew.password);
            udatanew.flag = aux.flag; // Mismo estado
            udatanew.usercode = aux.usercode; //Mismo codigo o Id.
            if(fwrite(&udatanew,sizeof(usuario),1,userFile))
            {
              printf("Usuario Modificado");
            }
            else   printf("Error en Archivo");
          }
          else printf("Password viejo no coincide\n");
        }
        else{
          strcpy(udatanew.password,aux.password);
          udatanew.flag = aux.flag; // Mismo estado
          udatanew.usercode = aux.usercode; //Mismo codigo o Id.
          if(fwrite(&udatanew,sizeof(usuario),1,userFile))
          {
            printf("Usuario Modificado");
          }
          else   printf("Error en Archivo");


        }
      }
      fclose(userFile);
  }

/*Permitira Elimiar un usuario*/
void eliminarUsuario(void){
  usuario uleido,uaborrar;
  FILE *userFile;
  char borrar = 0;

  printf("Ingrese el Usuario a Eliminar\n");
  scanf("%s", &uaborrar.nombre);
  userFile=fopen("userfile.dat","rb+");
  if(userFile==NULL){
    printf("Error al abrir archivo\n");
    return;
  }
  printf("Abierto\n" );
  fread(&uleido,sizeof(usuario),1,userFile);
  while(!feof(userFile)){
  //printf("%s\n",uleido.nombre );
    if(!strcmp(uleido.nombre,uaborrar.nombre)){ // Si el nombre ingresado es igual al nombre leido en el archivo
      uaborrar.usercode = uleido.usercode;
      uaborrar.flag = uleido.flag;
      strcpy(uaborrar.password,uleido.password);
      uaborrar.flag = 'B';
      break;
    }
    else fread(&uleido,sizeof(usuario),1,userFile);
  }
  printf("Esta seguro que quiere borrar a:\n\r");
  printf("Usuario: %s\n\r",uaborrar.nombre );
  printf("Password: %s\n\r",uaborrar.password );
  printf("usercode: %d\n\r",uaborrar.usercode );
  printf("1-si, 2-no");
  scanf("%d",&borrar);
  printf("\n%d",borrar );
  if(borrar == 1){
    printf("Se dio baja logica\n");
    fseek(userFile,((long)uaborrar.usercode)*(long)sizeof(usuario),0);
    fwrite(&uaborrar,sizeof(usuario),1,userFile);
  }
  fclose(userFile);
}

/*Solo imprime el saludo de despedida*/
void findeprograma(void){
  printf("Gracias por usar nuestro programa.\n");
  bajaFisica();

}

/*Buscara los registros de baja y los ubicara en un nuevo archivo de historicos
Modificara al archivo userfile con solo los usuarios dados de alta.*/
void bajaFisica(void)  {
  FILE *historico, *userFile, *newuserFile;
  usuario uleido;
  int activo = 0, baja = 0;
  historico=fopen("historico.dat","ab+");
  if(historico==NULL){
    printf("\n\rError de lectura de archivo historico");
    return;
  }
  newuserFile=fopen("newuserFile.dat","wb+");
  if(newuserFile==NULL){
    printf("\n\rError abriendo newuserFile");
    return;
  }
  userFile=fopen("userfile.dat","rb+");
  if(userFile==NULL){
    printf("\n\rError abriendo userfile");
    return;
  }
  fread(&uleido,sizeof(usuario),1,userFile);
  while (!feof(userFile)) {
    printf("%s",uleido.nombre );
      if(uleido.flag == 'A'){
        uleido.usercode = activo;
        fwrite(&uleido,sizeof(usuario),1,newuserFile);
        activo++;
      }
      else{
        uleido.usercode = baja;
        fwrite(&uleido,sizeof(usuario),1,historico);
        baja++;
      }
    fread(&uleido,sizeof(usuario),1,userFile);
  }
  fclose(historico);
  fclose(userFile);
  fclose(newuserFile);
  rename("newuserFile.dat","userfile.dat");
}
