#include "header.h"

int main(){

  int opcion;

  do{
   
  menu();
  cin>>opcion;

  if(opcion==1){
    problema1();
  }
  else if(opcion==2){
    problema2();
  }
  else if(opcion==3){
    //problema3();
  }
  else if(opcion==4){
    //problema4();
  }
  else if(opcion==5){
    cout<<"Saliendo del programa"<<endl;
  }
  else{
    cout<<"Opcion no valida"<<endl;
  }

  
  }while(opcion != 5);
  

    return 0;
}
