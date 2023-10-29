# include<iostream>
# include<cstdlib>
# include<cstring>


using namespace std;


void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Jugador{
private:
    int DNI, claustro, idDeporte, idEquipo;
    char nombre[25], apellido[30];
    char email[30];
    int telefono;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIDdeporte(){return idDeporte;}
   int getIDequipo(){return idEquipo;}
   const char *getNombre(){return nombre;}
   const char *getApellido(){return apellido;}
   bool getEstado(){return estado;}
   Fecha getFechaInscirpcion(){return inscripcion;}

   void setEstado(bool e){estado=e;}

   void Mostrar(){

   }
} ;

class Deporte{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
   int getIDdeporte(){return idDeporte;}
   int getIDcategoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}

   void setEstado(bool e){estado=e;}

   //Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte.
   // Debe devolver verdadero cuando coinciden los Id de deporte


   bool operator==( Deporte &obj){
    if(this->idDeporte==obj.getIDdeporte()) return true;
    return false;
}

   void Mostrar(){

   }

};


class Equipo{
private:
    int IdEquipo, nivel;
    char nombre[30];
    bool estado;
public:
    int getIDequipo(){return IdEquipo;}
    int getNivel(){return nivel;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setEstado(bool e){estado=e;}
    void Mostrar(){

   }
};


class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *n){
        strcpy(nombre, n);
    }
    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }
    bool grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
        strcpy(nombre, n);
    }
    Equipo leerRegistro(int pos){
        Equipo reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

//A-Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
//Cada registro debe tener el ID de equipo, el nombre del equipo, y la categoría del deporte al que pertenece el equipo.


class PuntoA {


private:
   int  _idEquipo,_categoriaDeporte;
   char _nombreEquipo[30];
   bool _estado;

public:
    void setIdequipo(int id){_idEquipo=id;}
    void setCategoriaDeporte(int d){_categoriaDeporte=d;}
   void setNombre(const char *n){strcpy(_nombreEquipo,n);}
   void SetEstado(bool estado){_estado=estado;}
   void Mostrar(){

   cout<<"El nombre del equipo es: "<<_nombreEquipo<<endl;
   cout<<"El id del equipo es: "<<_idEquipo<<endl;
   cout<<"La categoria del deporte es: "<<_categoriaDeporte<<endl;



   }

};

class archivPuntoA{

private: char _nombre[30];

public:

    archivPuntoA(const char *n){
    strcpy(_nombre,n);
    }


    PuntoA LeerRegistro(int pos){

    PuntoA reg;

    reg.SetEstado(false);

     FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;



    }

    int contarRegistros(){

       FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoA);


    }


    bool grabarRegistros (PuntoA reg){

        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;




    }




};

//A-Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
//Cada registro debe tener el ID de equipo, el nombre del equipo, y la categoría del deporte al que pertenece el equipo.


void ResolucionA(){

Equipo objEqui;
ArchivoEquipos archEqui("equipos.dat");

int contarEquipos= archEqui.contarRegistros();

Jugador objJuga;
ArchivoJugadores archJugador("jugadores.dat");

int contarJugadores= archJugador.contarRegistros();

archivPuntoA archiA("puntoA.dat");

int contador=0;

for(int x=0;x<contarEquipos;x++){

   objEqui=archEqui.leerRegistro(x);

    for(int y=0;y<contarJugadores;y++){

            contador=0;

        objJuga=archJugador.leerRegistro(y);


        if(objEqui.getIDequipo()==objJuga.getIDequipo()){

            contador++;

        }
        if(contador>10){

          PuntoA registro; // Crear una instancia de PuntoA para el registro
            registro.setIdequipo(objEqui.getIDequipo());
            registro.setNombre(objEqui.getNombre());
            registro.setCategoriaDeporte(objEqui.getNivel());

            // Escribir el registro en el archivo de salida
            archiA.grabarRegistros(registro);
        }

    }

}

}

void PuntoB(){

//Hacer un vector dinámico para listar el archivo del punto anterior.

PuntoA *p;/// creo el puntero

archivPuntoA archA("puntoA.dat");/// creo un objeto de la clase  archivos punto a para poder leer los registros

int can= archA.contarRegistros(); /// creo variable auxiliar para poder iterar el for


if(can==0){
    cout<<"No hay nada guardado"<<endl;
}

else{


    p=new PuntoA[can];//creo el vector dinamico

    if(p==NULL){
        cout<<"Error al crear vector dinamico"<<endl;
    }

    for(int x=0;x<can;x++){

        p[x]=archA.LeerRegistro(x);//almaceno en el vector dinamico lo que se encuentra en el archivo


    }

    for(int y=0;y<can;y++){


        p[y].Mostrar();//listo el vector dinamico
    }
}


delete p;






}







int main()
{





    return 0;
}
