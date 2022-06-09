#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include<ctype.h>
#include <fstream>

using namespace std;
/* Definicija cvora liste*/

struct cvor
{
char slovo;
cvor* sledeci;
};

cvor* addListToTheBeginning (char x,cvor* novi,cvor* start_ptr)
 { cvor *pom;  // pomocni pokazivaci
 novi->slovo=x;
 novi->sledeci = NULL;
 // Ubacivanje cvora u listu
 if (start_ptr == NULL){
    start_ptr = novi;
 }
 else
 {
 novi->sledeci = start_ptr;
 start_ptr = novi;
 }
 return start_ptr;
 }
 
 cvor* addListToEnd (char x,cvor* novi,cvor* start_ptr)
 { cvor *pom; // pomocni pokazivaci
 novi->slovo=x;
 novi->sledeci = NULL;
 // Ubacivanje cvora u listu
 if (start_ptr == NULL){
    start_ptr = novi;
 }
 else
 {
 pom = start_ptr;
 // postavljamo pom na pocetak liste
 while (pom->sledeci != NULL)
 {
 pom = pom->sledeci; // pomjeranje na slijedeci cvor
 }
 pom->sledeci = novi; // pokazivac zadnjeg cvora u listi postavljamo da pokazuje na novi cvor
 }
 return start_ptr;
 }
 
 void displayList(cvor* start_ptr2){
 cout<<"Output of the linked list with the function"<<endl;
 while(start_ptr2 !=NULL){
    cout<<start_ptr2->slovo;
    start_ptr2=start_ptr2->sledeci;
}
 }

cvor* deleteFirstList(cvor* start_ptr)
 { cvor *pom;
 pom = start_ptr;
 start_ptr = start_ptr->sledeci;
 delete pom;
 return start_ptr;
 }
 
 cvor* deleteLastList(cvor* start_ptr)
{
 cvor *pom1, *pom2;
 if (start_ptr == NULL)
 cout << "The list is empty!" << endl;
 else
 {
 pom1 = start_ptr;
 if (pom1->sledeci == NULL)
 {
 delete pom1;
 start_ptr = NULL;
 }
 else
 {
 while (pom1->sledeci != NULL)
 {
 pom2 = pom1;
 pom1 = pom1->sledeci;
 }
 delete pom1;
 pom2->sledeci = NULL;
 }
 }
 return start_ptr;
}




void saveList (cvor* start_ptr){
cvor* pom =start_ptr;
ofstream Izlaz;
Izlaz.open("c:\\**User**\\vezaneliste.txt");//instead of User put ur own destination
if(start_ptr==NULL)
cout<<"The List is Empty"<<endl;
else{
  do{
    if(pom !=start_ptr)Izlaz<<endl;
    Izlaz<<pom->slovo<<" ";
    pom=pom->sledeci;
  }  while (pom !=NULL);
    cout<<"The Linked list saved in the file"<<endl;

}
Izlaz.close();
}






cvor* readList (){

ifstream Ulaz;
Ulaz.open("c:\\**User**\\vezaneliste.txt");//instead of User put ur own destination
cvor *novi, *predhodni, *start_ptr;
start_ptr=NULL;
while(!Ulaz.eof()){
   novi= new cvor();
   Ulaz>>novi->slovo;
  // cout<<"ns: "<<novi->slovo<<endl;
   novi->sledeci=NULL;
   if(start_ptr==NULL){
        start_ptr=novi;
   }
   else
    predhodni->sledeci=novi;
   predhodni=novi;
}
cout<<"The Linked list loaded from the file"<<start_ptr<<endl;
Ulaz.close();
return start_ptr;
}

int main()
{

cvor *startpokazivac,*zadnji,*novi,*pomocni2;
string rijec;
cout<<"ENTER A WORD:";
cin>>rijec;
//formiramo listu od ucitane rijeci
int i=0;
startpokazivac=NULL;
cout<<startpokazivac<<endl;
while(rijec[i] !='\0'){
  novi= new cvor;
  if(isalpha(rijec[i])){
    startpokazivac = addListToBeginning(rijec[i],novi,startpokazivac);
  } else{
  startpokazivac = addListToEnd(rijec[i],novi,startpokazivac);

  }

// cout<<"start: "<<startpokazivac<<endl;
   //zadnji=novi;
   i++;
}
cout<<"Output of the data of the linked list:"<<endl;
zadnji=startpokazivac;

while(zadnji !=NULL){
    cout<<zadnji->slovo;
    zadnji=zadnji->sledeci;
}
cout<<endl;

ispisilistu(startpokazivac);
cout<<endl;
if(isalpha(startpokazivac->slovo)){
   startpokazivac = deleteFirstList(startpokazivac);
}else{
startpokazivac = deleteLastList(startpokazivac);

}
cout<<"Output of the data of the linked lists after deleting the first list:"<<endl;
displayList(startpokazivac);
cout<<endl;
saveList(startpokazivac);
pomocni2= readList();
cout<<"Output of the data from the .txt file:"<<endl;
displayList(pomocni2);
return 0;
}
