#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct contact{
 string fName;
 string lName;
 string No;
}c[250];
int Search(void)
{
    string a,b;
cout<<"enter the first name of contact: "<<endl;
cin>>a;
cout<<"enter the last name of contact: "<<endl;
cin>>b;
for(int i=0;i<250;i++)
{
    if(c[i].fName==a && c[i].lName==b){
        cout<<"the Number : "<<c[i].No<<endl;
        return i;
        };
};
system("CLS");
cout<<"not found"<<endl;
return -1;
}
int check(string x,string y)
{for(int i=0;i<250;i++)
{
    if(c[i].fName==x && c[i].lName==y){
        return 1;
        };
};
return 0;
}
void update(int y)
{
    if(y==-1)return;
remove("fileNo.txt");
remove("filefName.txt");
remove("filelName.txt");
fstream data1,data2,data3;
data1.open("filefName.txt", ios::in | ios::app |ios::out);
data2.open("filelName.txt", ios::in | ios::app |ios::out);
data3.open("fileNo.txt", ios::in | ios::app |ios::out);
int i=0;
     while (i<250)
  {
    if (c[i].fName!= c[y].fName)
    data1 << c[i].fName << endl;
    else{
        cout<<"Enter NEW First Name:";
        cin>>c[i].fName;
        data1 <<c[i].fName <<endl;
    }
    if (c[i].lName!= c[y].lName)
    data2 << c[i].lName << endl;
        else{
        cout<<"Enter NEW Last Name:";
        cin>>c[i].lName;
        data2 <<c[i].lName <<endl;}
    if (c[i].No!= c[y].No)
    data3 << c[i].No << endl;
        else{
        cout<<"Enter NEW Number:";
        cin>>c[i].No;
        data3 <<c[i].No <<endl;}
    i++;
    }



}
 void Delete(int y){
    if(y==-1)return;
     cout<<"Are u sure?? Y/N";
     char m;
     cin>>m;
     if(m=='N'||m=='n')return;
 remove("fileNo.txt");
 remove("filefName.txt");
 remove("filelName.txt");
fstream data1,data2,data3;
data1.open("filefName.txt", ios::in | ios::app |ios::out);
data2.open("filelName.txt", ios::in | ios::app |ios::out);
data3.open("fileNo.txt", ios::in | ios::app |ios::out);
int i=0;
     while (i<250)
  {
    if (c[i].fName!= c[y].fName)
    data1 << c[i].fName << endl;
    c[i].fName="";
    if (c[i].lName!= c[y].lName)
    data2 << c[i].lName << endl;
    c[i].lName="";
    if (c[i].No!= c[y].No)
    data3 << c[i].No << endl;
    c[i].No="";
     i++;
    }
    cout<<"Deleted"<<endl;
  }
void New(int i)
{
fstream data1,data2,data3;
string z,v,m;
data1.open("filefName.txt", ios::in | ios::app |ios::out);
data2.open("filelName.txt", ios::in | ios::app |ios::out);
data3.open("fileNo.txt", ios::in | ios::app |ios::out);
    cout<<"enter the frist name of contact: ";
    cin>> z;
    cout<<"enter the last name of contact: ";
    cin>> v;
    int x=check(z,v);
    if(x==1){
        cout<<"exist contact"<<endl;
            return;
    }
    data1 << z<<endl;
    data2<< v <<endl;
    cout<<"enter the number of contact: ";
    cin >> m;
    data3<<m<<endl;
    data1.close();
    data2.close();
    data3.close();

}
void read(void)
{
fstream data1,data2,data3,data4;
data1.open("filefName.txt", ios::in | ios::app |ios::out);
data2.open("filelName.txt", ios::in | ios::app |ios::out);
data3.open("fileNo.txt", ios::in | ios::app |ios::out);
if(data1.fail()||data2.fail()||data3.fail()) cerr <<"error"<<endl;
int i=0;
    while ( !data1.eof() )
    {
      data1 >> c[i].fName;
      i++;
    }
    data1.close();
    i=0;
        while ( !data2.eof()  )
    {
      data2 >> c[i].lName;
      i++;
    }
    data2.close();
    i=0;
        while ( !data3.eof()  )
    {
      data3 >> c[i].No;
      i++;
    }
    data3.close();
}
int main()
{  int x,z,i=0;
  char y;
  label:
read();
cout<<"For entering new contact Enter 1"<<endl;
cout<<"For searching for a contact Enter 2"<<endl;
cout<<"For Delete a contact Enter 3"<<endl;
cout<<"For update a contact Enter 4"<<endl;
cin>>x;
system("CLS");
    if(x==1) {
        New(i);
        };
        if(x==2)z=Search();
        if(x==3)
        {   z=Search();
            Delete(z);
        }
        if(x==4){
            z=Search();
            update(z);
        }

cout<<"You want to close Y/N"<<endl;
cin>>y;
system("CLS");
if(y=='y' || y=='Y')return 0;
 if (y=='n' || y=='N') goto label;

cout<<"error";
    return 0;
}
