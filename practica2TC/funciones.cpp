#include "header.h"

void menu () {
    cout << "\n|---------------------------------------|";
    cout << "\n|       - INTRODUCE TU ALFABETO -       |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. PROBLEMA 1      | 2. PROBLEMA 2    |";
    cout << "\n| 3. PROBLEMA 3      | 4. PROBLEMA 4    |";
    cout << "\n| 5. SALIR           |                  |";
    cout << "\n|--------------------|------------------|";
    cout << "\n";
    puts ("\nSelecciona una opcion:");

} 

void problema1(){

 vector<string> CadenaValida={"+23.25E-3","-3.1416","1234","256.1244E4","-34.65e2","0.1423e-12","-45.2E+3"};
 vector<string> CandenaInvalida={"12.231.345","45.6E+-4","3.14E2E3","513.12E","3K45.1E-2","34+12e2","12.45E+1.2"};   
 vector<string> Cadenas;
 string aux;
 int num_cad, opcion;

 system("clear");
 cout<<"Descripcion del problema; ";
 cout<<"AFD que acepte notacion exponencial."<<endl<<endl;

 cout<<"Cadenas validas"<<endl;
    
for(auto i:CadenaValida){
 cout<<i<<endl;
}

cout<<endl<<"Cadenas invalidas"<<endl;
for(auto i:CandenaInvalida){
 cout<<i<<endl;
}

 cout<<endl<<"Deseas usar las cadenas validas e invalidas de los ejemplos para comprobar?";
 cout<<endl<<"(1)Si (2)No"<<endl;
 cin>>opcion;

  if(opcion == 1)
  {
     for(int i=0;i<7;i++){

    if(AFD1(CadenaValida[i])){
      cout<<"La cadena "<<i+1<<" "<<CadenaValida[i]<<": es valida"<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<CadenaValida[i]<<": es invalida"<<endl;
    }
    }
     
     cout<<endl<<endl; 
     for(int i=0;i<7;i++){

    if(AFD1(CandenaInvalida[i])){
      cout<<"La cadena "<<i+1<<" "<<CandenaInvalida[i]<<": es valida"<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<CandenaInvalida[i]<<": es invalida"<<endl;
    }

   }


  }else{
    cout<<endl<<"Cuantas cadenas desea ingresar? ";
    cin>>num_cad;
    cout<<endl;
    
    for(int i=0;i<num_cad;i++){
    cout<<endl<<endl<<"Ingrese la cadena "<<i+1<<": ";
    cin>>aux;
    Cadenas.push_back(aux);
    }
   
   for(int i=0;i<num_cad;i++){

    if(AFD1(Cadenas[i])){
      cout<<"La cadena "<<i+1<<" "<<Cadenas[i]<<": es valida"<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<Cadenas[i]<<": es invalida"<<endl;
    }

   }
  }

}

bool AFD1(string c){

    for(int i = 0; i < c.size();i++)
    {
        if(c[0] == '+' || c[0] == '-')
        {
            //valido  23
            c.erase(0,1);
            if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
            {
                c.erase(0,1);
              
               do{
                if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                    c.erase(0,1);
                }
                }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                
                if(c.size() == 0)
                {
                    return true;
                }

                if(c[0] == 'E' || c[0]=='e'){
                    c.erase(0,1);
                if(c[0] == '+' || c[0] == '-'){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                     {
                       c.erase(0,1);
                       do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                       }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                       if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                     }else{
                        return false;
                     }        
                    }
                else if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                        c.erase(0,1);
                    do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                    }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                    if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                }else{
                        return false;
                }

                }else if(c[0] == '.' ){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9'){
                        c.erase(0,1);
                        do{
                       if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                       {
                       c.erase(0,1);
                       }
                      }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                 if(c.size() == 0)
                {
                    return true;
                }

                if(c[0] == 'E' || c[0]=='e'){
                    c.erase(0,1);
                if(c[0] == '+' || c[0] == '-'){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                     {
                       c.erase(0,1);
                       do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                       }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                       if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                     }else{
                        return false;
                     }        
                    }
                else if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                        c.erase(0,1);
                    do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                    }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                    if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                }else{
                        return false;
                }

                }

                     }else{
                        return false;
                     }
                     
                }
                else{
                    return false;
                }

            }else{
                return false;
            }
        }else if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9'){
            //valido
            c.erase(0,1);
            do{
                if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                    c.erase(0,1);
                }
                }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                
                if(c.size() == 0)
                {
                    return true;
                }

                if(c[0] == 'E' || c[0]=='e'){
                    c.erase(0,1);
                if(c[0] == '+' || c[0] == '-'){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                     {
                       c.erase(0,1);
                       do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                       }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                       if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                     }else{
                        return false;
                     }        
                    }
                else if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                        c.erase(0,1);
                    do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                    }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                    if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                }else{
                        return false;
                }

                }else if(c[0] == '.' ){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9'){
                        c.erase(0,1);
                        do{
                       if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                       {
                       c.erase(0,1);
                       }
                      }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                 if(c.size() == 0)
                {
                    return true;
                }

                if(c[0] == 'E' || c[0]=='e'){
                    c.erase(0,1);
                if(c[0] == '+' || c[0] == '-'){
                     c.erase(0,1);
                     if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                     {
                       c.erase(0,1);
                       do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                       }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                       if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                     }else{
                        return false;
                     }        
                    }
                else if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                {
                        c.erase(0,1);
                    do{
                          if(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9')
                          {
                            c.erase(0,1);
                          }
                    }while(c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9');
                    if(c.size() == 0)
                       {
                           return true;
                     }else{
                        return false;
                     }


                }else{
                        return false;
                }

                }

                     }else{
                        return false;
                     }
                     
                }
                else{
                    return false;
                }

        }else
        {
            return false;
        }
       
      

    }
    //+123E-1  -1234e+2134   +123.123e-123  -123134.2134  -2134214  



    return false; 

}

void problema2(){
    system("clear");
    int opcion; 
    cout<<endl<<"Definicion del problema: AFD que valide cadenas con numero de 0 par y sin 1 adyacentes (considerar 0 par)"<<endl;
    cout<<"Deseas introducir varias cadenas a la vez?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opcion;

   if(opcion == 1){
    vector<string> cadenas;
    cadena_validar cade; 
    cout<<"Cuantas cadenas deseas verificar? (si quieres cadena vacia escribe << / >> )"<<endl;
    cin>>opcion;
    for(int i = 0; i < opcion; i++){
        string cadena;
        cout<<"Cadena "<<i+1<<": ";
        cin>>cadena;
        cadenas.push_back(cadena);
    }

    for(int i = 0; i < cadenas.size(); i++){
        string aux;
        aux = cadenas[i];
        for(int j = 0; j< aux.size(); j++){
           string aux2;
            aux2 = aux[j];
            cade.insert(aux2);
        }
        prueba(cade,aux); 
    }


   }else{
     cout<<"Ingrese la cadena a evaluar (si es vacia, solo escribe << / >>: ";
    string c;
    cadena_validar cadena;
    cin>>c;

    //almacenamos la cadena en un multiset
    for(int i=0;i<c.size();i++){
        string aux;
        aux.push_back(c[i]);
        cadena.insert(aux);
    }
   cout<<endl;
    prueba(cadena, c);
   }

   

}


void prueba(cadena_validar cadena, string c){
    //verificamos que la cadena tenga 0 par
    if(cadena.count("0")%2 == 0 || cadena.count("/") == 1){
        //verificamos que no tenga 1 adyacentes
        for(int i=0;i<c.size();i++){
            if(c[i] == '1'){
                if(c[i+1] == '1'){
                    cout<<"La cadena "<<c<<" es invalida"<<endl;
                    return;
                }
            }
        }
        cout<<"La cadena "<<c<<" es valida"<<endl;
    }else
        cout<<"La cadena "<<c<<" es invalida"<<endl;


}