#include "header.h"



//AUTOMATA 1
unordered_set<string> transicion_numeros = {"0","1","2","3","4","5","6","7","8","9"};
unordered_set<string> transicion_signos = {"+","-"};
unordered_set<string> transicion_punto = {"."};
unordered_set<string> transicion_e = {"e","E"};

// AUTOMATA 2
unordered_set<string> transicion_uno = {"1"};
unordered_set<string> transicion_cero = {"0"};

//AUTOMATA 3
unordered_set<string> transicion_a= {"a"};
unordered_set<string> transicion_b= {"b"};
unordered_set<string> transicion_c= {"c"};
unordered_set<string> transicion_d= {"d"};
set<string> transicion_abcd = {"a","b","c","d"};

//recorrido
unordered_multiset<string> recorrido; 
vt<string> recorrido2;


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
      cout<<"La cadena "<<i+1<<" "<<CadenaValida[i]<<": es valida"<<endl<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<CadenaValida[i]<<": es invalida"<<endl<<endl;
    }
    }
     
     cout<<endl<<endl; 
     for(int i=0;i<7;i++){

    if(AFD1(CandenaInvalida[i])){
      cout<<"La cadena "<<i+1<<" "<<CandenaInvalida[i]<<": es valida"<<endl<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<CandenaInvalida[i]<<": es invalida"<<endl<<endl;
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
    cout<<endl<<endl;
   
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

    bool validacion;
    int n = 0;
    //Iniciamos en el estado Q0
    recorrido.insert("Q0"); 
    validacion = ESTADO_Q0(c); 


     vt<string> recorrido_aux;
    for(auto i:recorrido){
        recorrido_aux.push_back(i);
    }
    reverse(recorrido_aux.begin(), recorrido_aux.end());
    //recorremos los estados
    cout<<"Recorrido: "; 
    for(auto i:recorrido_aux){
       n++;
         if(n==recorrido_aux.size()){
          cout<<i;
            }else{
                cout<<i<<"->";
            }
    }
    cout<<endl;
     
    recorrido.clear();
    recorrido_aux.clear(); 
    return validacion;
}

//AUTOMATA 1

bool ESTADO_Q0(string c){
   bool q0_AC = false;    
    string aux; 
    aux = c[0];
//23
   if(transicion_signos.count(aux))
   {
       //Estado QO -> Q1
       c.erase(0,1);
       recorrido.insert("Q1");

       // Verificamos si la cadena es vacía 
        if(c.size()!=0)
            return ESTADO_Q1(c);
        else
           return q0_AC;


   }else if(transicion_numeros.count(aux))
   {
       //Estado QO -> Q2
       c.erase(0,1);
       recorrido.insert("Q2");
       //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q2(c);
        else
           return true;

    }else{
        return false;
    }


}

bool ESTADO_Q1(string c){
    bool q1_AC = false;
    string aux; 
    aux = c[0];


    if(transicion_numeros.count(aux)){
        //Estado Q1 -> Q2
        recorrido.insert("Q2");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q2(c);
        else
           return true; 

    }else{
        return q1_AC;
    }
}

bool ESTADO_Q2(string c){
    bool q2_AC = true;
    string aux; 
    aux = c[0];

/// 
    if(transicion_numeros.count(aux)){
        //Estado Q2 -> Q2
        recorrido.insert("Q2");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q2(c);
        else
           return q2_AC;

    }else if(transicion_punto.count(aux)){
        //Estado Q2 -> Q3
        recorrido.insert("Q3");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q3(c);
        else
           return false;

    }else if(transicion_e.count(aux)){
        //Estado Q2 -> Q4
        recorrido.insert("Q4");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q4(c);
        else
           return false;

    }else{
        return false;
    }
}

bool ESTADO_Q3(string c){
    bool q3_AC = false;
    string aux; 
    aux = c[0];

    if(transicion_numeros.count(aux)){
        //Estado Q3 -> Q5
        recorrido.insert("Q5");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q5(c);
        else
           return true;

    }else{
        return q3_AC;
    }
}

bool ESTADO_Q4(string c){
    bool q4_AC = false;
    string aux; 
    aux = c[0];

    if(transicion_numeros.count(aux)){
        //Estado Q4 -> Q7
        recorrido.insert("Q7");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q7(c);
        else
           return true;

    }else if(transicion_signos.count(aux)){
        //Estado Q4 -> Q6
        recorrido.insert("Q6");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q6(c);
        else
           return false;

    }else{
        return q4_AC;
    }
}

bool ESTADO_Q5(string c){
    bool q5_AC = true;
    string aux; 
    aux = c[0];

    if(transicion_numeros.count(aux)){
        //Estado Q5 -> Q5
        recorrido.insert("Q5");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q5(c);
        else
           return q5_AC;

    }else if(transicion_e.count(aux)){
        //Estado Q5 -> Q4
        recorrido.insert("Q4");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q4(c);
        else
           return false;

    }else{
        return false;
    }
}

bool ESTADO_Q6(string c){
    bool q6_AC = false;
    string aux; 
    aux = c[0];

    if(transicion_numeros.count(aux)){
        //Estado Q6 -> Q7
        recorrido.insert("Q7");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q7(c);
        else
           return true;

    }else{
        return q6_AC;
    }
}

bool ESTADO_Q7(string c){
    bool q7_AC = true;
    string aux; 
    aux = c[0];

    if(transicion_numeros.count(aux)){
        //Estado Q7 -> Q7
        recorrido.insert("Q7");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q7(c);
        else
           return q7_AC;

    }else{
        return false;
    }
}


//AUTOMATA 2

void problema2(){
    system("clear");
    recorrido.clear();
    int opcion;
    vt<string> validas ={"00","0101010","0000001010","00100100","010101000",""};
    vt<string> invalidas ={"01","0101011","0000001011","00100101","010101001","1","0011","01010"}; 
    vt<string> cadenas;
    cout<<"Cadenas validas: "<<endl;
    for(int i=0;i<validas.size();i++){
        cout<<validas[i]<<endl;
    }
    cout<<"Cadenas invalidas: "<<endl;
    for(int i=0;i<invalidas.size();i++){
        cout<<invalidas[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<endl<<"Definicion del problema: AFD que valide cadenas con numero de 0 par y sin 1 adyacentes (considerar 0 par)"<<endl;
    cout<<"Deseas probar con las cadenas validas e invalidas?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opcion;
    cout<<endl;

    if(opcion == 1){

    for(int i=0;i<validas.size();i++){

    if(AFD2(validas[i])){
      cout<<"La cadena "<<i+1<<" "<<validas[i]<<": es valida"<<endl<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<validas[i]<<": es invalida"<<endl<<endl;
    }
    }
     
     cout<<endl<<endl; 
    for(int i=0;i<invalidas.size();i++){

    if(AFD2(invalidas[i]))
      cout<<"La cadena "<<i+1<<" "<<invalidas[i]<<": es valida"<<endl<<endl;
    else
      cout<<"La cadena "<<i+1<<" "<<invalidas[i]<<": es invalida"<<endl<<endl;
    

     }


    }else{
      
      cout<<"Cuantas cadenas deseas validar?: "<<endl;
      cin>>opcion;
        for(int i=0;i<opcion;i++){
            string aux;
            cout<<"Cadena "<<i+1<<": ";
            cin>>aux;
            cadenas.push_back(aux);
        } 
        cout<<endl<<endl;

        for(int i=0;i<cadenas.size();i++){

            if(AFD2(cadenas[i]))
               cout<<"La cadena "<<i+1<<" "<<cadenas[i]<<": es valida"<<endl;
            else
                cout<<"La cadena "<<i+1<<" "<<cadenas[i]<<": es invalida"<<endl;
            
        }
        cout<<endl<<endl;


    }

   
   

}

bool AFD2(string c){
    recorrido.clear();
    recorrido2.clear();

    bool validacion;
    int n = 0;
    //Iniciamos en el estado Q0
    recorrido2.push_back("Q0"); 

    validacion = ESTADO_Q0_2(c); 

    //recorremos los estados
    cout<<"Recorrido: "; 
    for(auto i:recorrido2){
       n++;
         if(n==recorrido2.size()){
          cout<<i;
            }else{
                cout<<i<<"->";
            }
    }
    cout<<endl;
     
    recorrido2.clear(); 
    return validacion;
}


bool ESTADO_Q0_2(string c){
    bool q0_AC = true;
    string aux;
    aux = c[0];
    if(c.size()==0){
        return q0_AC;
    }else if(transicion_cero.count(aux)){
        //Estado Q0 -> Q1
        recorrido2.push_back("Q1");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q1_2(c);
        else
           return false;

    }else if(transicion_uno.count(aux)){
        //Estado Q0 -> Q3
        recorrido2.push_back("Q3");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q3_2(c);
        else
           return true;
    }else{
        return false;
    }
}

bool ESTADO_Q1_2(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];
    if(transicion_cero.count(aux)){
        //Estado Q1-> Q0
        recorrido2.push_back("Q0");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q0_2(c);
        else
           return true;

    }else if(transicion_uno.count(aux)){
        //Estado Q1 -> Q2
        recorrido2.push_back("Q2");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q2_2(c);
        else
           return q1_AC;
    }
    else{
        return false;
    }
}

bool ESTADO_Q2_2(string c){
    bool q2_AC = false;
    string aux;
    aux = c[0];
    if(transicion_cero.count(aux)){
        //Estado Q2->Q0
        recorrido2.push_back("Q0");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q0_2(c);
        else
           return true;

    }else if(transicion_uno.count(aux)){
        //Estado Q2->Q4
        recorrido2.push_back("Q4");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q4_2(c);
        else
           return q2_AC;
    }else{
        return false;
    }

}

bool ESTADO_Q3_2(string c){
    bool q3_AC = true;
    string aux;
    aux = c[0];
    if(transicion_cero.count(aux)){
        //Estado Q3->Q1
        recorrido2.push_back("Q1");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q1_2(c);
        else
           return false;
    }else if(transicion_uno.count(aux)){
        //Estado Q3->Q4
        recorrido2.push_back("Q4");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q4_2(c);
        else
           return false;
    }else{
        return false;
    }
    //
}

bool ESTADO_Q4_2(string c){
    bool q4_AC = false;
    string aux;
    aux = c[0];
    if(transicion_cero.count(aux) || transicion_uno.count(aux)){
        //Estado Q4->Q4
        recorrido2.push_back("Q4");
        c.erase(0,1);
        //Verificamos si la cadena es vacía, si no es vacía, pasa al siguiente estado
        if(c.size()!=0)
            return ESTADO_Q4_2(c);
        else
           return q4_AC;
    }else{
        return false;
    }
}


//AUTOMATA 3

void problema3(){
 cout<<"AFD que acepte cadena que contengan 2 o más símbolos consecutivos iguales, para el alfabeti {a, b, c, d}"<<endl;
 vector<string> validas={"abbc","caadab","bbbadcc","bbbbadcc","cc","abcdddd","ababaccabab","bbbbbb"};
 vector<string> invalidas={"ab","abc","abcd","ac","acd","abd","bcd","abcabc"};
 int opcion; 
 cout<<endl<<"CADENAS VALIDAS: "<<endl;
 for(int i = 0; i < validas.size(); i++){
    cout<<validas[i]<<endl;
 }

    vt<string> cadenas;
    cout<<"Cadenas validas: "<<endl;
    for(int i=0;i<validas.size();i++){
        cout<<validas[i]<<endl;
    }
    cout<<"Cadenas invalidas: "<<endl;
    for(int i=0;i<invalidas.size();i++){
        cout<<invalidas[i]<<endl;
    }

    cout<<endl<<endl;
    cout<<endl<<"Definicion del problema: AFD que valide cadenas con numero de 0 par y sin 1 adyacentes (considerar 0 par)"<<endl;
    cout<<"Deseas probar con las cadenas validas e invalidas?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opcion;
    cout<<endl;

    if(opcion == 1){

    for(int i=0;i<validas.size();i++){

    if(AFD3(validas[i])){
      cout<<"La cadena "<<i+1<<" "<<validas[i]<<": es valida"<<endl<<endl;
    }else{
        cout<<"La cadena "<<i+1<<" "<<validas[i]<<": es invalida"<<endl<<endl;
    }
    }
     
     cout<<endl<<endl; 
    for(int i=0;i<invalidas.size();i++){

    if(AFD3(invalidas[i]))
      cout<<"La cadena "<<i+1<<" "<<invalidas[i]<<": es valida"<<endl<<endl;
    else
      cout<<"La cadena "<<i+1<<" "<<invalidas[i]<<": es invalida"<<endl<<endl;
    

     }


    }else{
      
      cout<<"Cuantas cadenas deseas validar?: "<<endl;
      cin>>opcion;
        for(int i=0;i<opcion;i++){
            string aux;
            cout<<"Cadena "<<i+1<<": ";
            cin>>aux;
            cadenas.push_back(aux);
        } 
        cout<<endl<<endl;

        for(int i=0;i<cadenas.size();i++){

            if(AFD3(cadenas[i]))
               cout<<"La cadena "<<i+1<<" "<<cadenas[i]<<": es valida"<<endl;
            else
                cout<<"La cadena "<<i+1<<" "<<cadenas[i]<<": es invalida"<<endl;
            
        }
        cout<<endl<<endl;


    }

   
 
}

bool AFD3(string c){
    recorrido2.clear();

    bool validacion;
    int n = 0;
    //Iniciamos en el estado Q0
    recorrido2.push_back("Q0"); 

    validacion = ESTADO_Q0_3(c); 

    //recorremos los estados
    cout<<"Recorrido: "; 
    for(auto i:recorrido2){
       n++;
         if(n==recorrido2.size()){
          cout<<i;
            }else{
                cout<<i<<"->";
            }
    }
    cout<<endl;
     
    recorrido2.clear(); 
    return validacion;
}

bool ESTADO_Q0_3(string c){
    bool q0_AC = false;
    string aux;
    aux = c[0];
    if(transicion_a.count(aux)){
        recorrido2.push_back("Q1");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q1_3(c);
        else
           return q0_AC;
    }else if(transicion_b.count(aux)){

        recorrido2.push_back("Q2");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q2_3(c);
        else
           return q0_AC;

    }else if(transicion_c.count(aux)){
            
            recorrido2.push_back("Q3");
            c.erase(0,1);
            if(c.size()!=0)
                return ESTADO_Q3_3(c);
            else
            return q0_AC;
    }else if(transicion_d.count(aux)){
            
            recorrido2.push_back("Q4");
            c.erase(0,1);
            if(c.size()!=0)
                return ESTADO_Q4_3(c);
            else
            return q0_AC;
    }else{
        return false;
    }
}

bool ESTADO_Q1_3(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];
    if(transicion_a.count(aux)){
        recorrido2.push_back("Q5");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q5_3(c);
        else
           return !q1_AC;
    }else if(transicion_b.count(aux)){
        recorrido2.push_back("Q2");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q2_3(c);
        else
           return q1_AC;
    }else if(transicion_c.count(aux)){
        recorrido2.push_back("Q3");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q3_3(c);
        else
           return q1_AC;
    }else if(transicion_d.count(aux)){
        recorrido2.push_back("Q4");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q4_3(c);
        else
           return q1_AC;
    }else{
        return false;
    }             

}

bool ESTADO_Q2_3(string c){
    bool q2_AC = false;
    string aux;
    aux = c[0];

    if(transicion_a.count(aux)){
        recorrido2.push_back("Q1");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q1_3(c);
        else
           return q2_AC;
    }else if(transicion_b.count(aux)){
        recorrido2.push_back("Q5");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q5_3(c);
        else
           return !q2_AC;
    }else if(transicion_c.count(aux)){
        recorrido2.push_back("Q3");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q3_3(c);
        else
           return q2_AC;
    }else if(transicion_d.count(aux)){
        recorrido2.push_back("Q4");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q4_3(c);
        else
           return q2_AC;
    }else{
        return false;
    }      

}

bool ESTADO_Q3_3(string c){
    bool q3_AC = false;
    string aux;
    aux = c[0];

    if(transicion_a.count(aux)){
        recorrido2.push_back("Q1");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q1_3(c);
        else
           return q3_AC;
    }else if(transicion_b.count(aux)){
        recorrido2.push_back("Q2");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q2_3(c);
        else
           return q3_AC;
    }else if(transicion_c.count(aux)){
        recorrido2.push_back("Q5");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q5_3(c);
        else
           return !q3_AC;
    }
    else if(transicion_d.count(aux)){
        recorrido2.push_back("Q4");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q4_3(c);
        else
           return q3_AC;
    }else{
        return false;
    }

}

bool ESTADO_Q4_3(string c){
    bool q4_AC = false;
    string aux;
    aux = c[0];

    if(transicion_a.count(aux)){
        recorrido2.push_back("Q1");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q1_3(c);
        else
           return q4_AC;
    }else if(transicion_b.count(aux)){
        recorrido2.push_back("Q2");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q2_3(c);
        else
           return q4_AC;
    }else if(transicion_c.count(aux)){
        recorrido2.push_back("Q3");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q3_3(c);
        else
           return q4_AC;
    }else if(transicion_d.count(aux)){
        recorrido2.push_back("Q5");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q5_3(c);
        else
           return !q4_AC;
    }else{
        return false;
    }

}

bool ESTADO_Q5_3(string c){
    bool q5_AC = true;
    string aux;
    aux = c[0];

    if(c.size()==0)
        return q5_AC;
    else if(transicion_abcd.count(aux)){
        recorrido2.push_back("Q5");
        c.erase(0,1);
        if(c.size()!=0)
            return ESTADO_Q5_3(c);
        else
           return q5_AC;
    }else{
        return false;
    }      
        
}




