#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
/* STRUCTURE FOR DATE OF CRIME */
struct dateoc
{
int doc; //DATE OF CRIME
int moc; //MONTH OF CRIME
int yoc; //YEAR OF CRIME
};
/* STRUCTURE FOR DATE OF SENTENCE*/
struct dateos
{
int dos; //DATE OF SENTENCE
int mos; //MONTH OF SENTENCE
int yos; //YEAR OF SENTENCE
};
/* STRUCTURE FOR DESCRIPTION OF CRIMINAL */
struct descp
{
int colour;//FACE COLOUR(WHITE/WHEATISH/BLACK)
int body;//BODY TYPE(SLIM/AVERAGE/FAT)
char bmark[20];//BIRTH MARK
int height;//HEIGHT IN CM
};
/* CLASS CRIMINAL (FOR ALL DETAILS OF THE CRIMINAL) */
class criminal
{
private:
char name[20];//NAME OF THE CRIMINAL
char sex[1];//GENDER OF THE CRIMINAL
int age;//AGE OF THE CRIMINAL
char add[20];//ADDRESS OF THE CRIMINAL (BEFORE CRIME)
int cid;//CRIMINAL ID
int ctype;//TYPE OF CRIME(MURDER/RAPE/THEFT)
int sent;//DURATION OF SENTENCE(LIFE/10yr/DEATH)
dateoc doc;//OBJECT OF STRUCTURE DATEOC
dateos dos;//OBJECT OF STRUCTURE DATEOS
descp des;//OBJECT OF STRUCTURE DESCP
public:
void getdata()
{
cout<<"ENTER CRIMINAL NAME";
gets(name);
cout<<"ENTER GENDER OF CRIMINAL";
cin>>sex;
cout<<"ENTER AGE OF CRIMINAL";
cin>>age;
cout<<"ENTER THE PHYSICAL DESCRIPTION OF THE CRIMINAL:\n";
cout<<"ENTER THE FACE COLOUR\n1.WHITE\n2.WHEATISH\n3.BLACK\n";
cin>>des.colour;
cout<<"ENTER THE CRIMINAL BODY TYPE\n1.SLIM\n2.AVERAGE\n3.FAT\n";
cin>>des.body;
cout<<"ENTER THE BIRTH MARK LOCATION ON CRIMINAL'S BODY";
gets(des.bmark);
cout<<"ENTER HEIGHT OF CRIMINAL(IN CMS)";
cin>>des.height;
cout<<"ENTER CRIMINAL ID";
cin>>cid;
cout<<"ENTER THE CRIME TYPE \n1.MURDER\n2.RAPE\n3.THEFT\n";
cin>>ctype;
cout<<"ENTER DATE OF CRIME(DD/MM/YY)";
cin>>doc.doc>>doc.moc>>doc.yoc;
cout<<"ENTER DATE OF SENTENCE";
cin>>dos.dos>>dos.mos>>dos.yos;
cout<<"ENTER THE DURATION OF SENTENCE \n1.LIFETIME\n2.10yrs\n3.HANG TO DEATH";
cin>>sent;
}
void showdata()
{
cout<<"\nCRIMINAL NAME - "<<name<<'\n';
cout<<"\nCRIMINAL GENDER - "<<sex<<'\n';
cout<<"\nCRIMINAL AGE - "<<age<<'\n';
cout<<"\nPHYSICAL DESCRIPTION:-\n";
cout<<"\nFACE COLOUR - ";
if(des.colour==1)
cout<<"WHITE";
else if(des.colour==2)
cout<<"WHEATISH";
else cout<<"BLACK";
cout<<"\nBODY TYPE - ";
if(des.body==1)
cout<<"SLIM";
else if(des.body==2)
cout<<"AVERAGE";
else cout<<"FAT";
cout<<"\nBIRTH MARK LOCATION - ";
puts(des.bmark);
cout<<"\nHEIGHT - "<<des.height;
cout<<"\nCRIMINAL ID - "<<cid;
cout<<"\nCRIME TYPE - ";
if(ctype==1)
cout<<"MURDER";
else if(ctype==2)
cout<<"RAPE";
else cout<<"THEFT";
cout<<"\nDATE OF CRIME (DD/MM/YY) - ";
cout<<doc.doc<<doc.moc<<doc.yoc;
cout<<"\nDATE OS SENTENCE (DD/MM/YY) - ";
cout<<dos.dos<<dos.mos<<dos.yos;
cout<<"\nDURATION OF SENTENCE - ";
if(sent==1)
cout<<"LIFETIME";
else if(sent==2)
cout<<"10yr";
else cout<<"HANG TO DEATH";
}
char* retname()
{
return name;
}
char* retsex()
{
return sex;
}
int retage()
{
return age;
}
char* retadd()
{
return add;
}
int retcid()
{
return cid;
}
int retctype()
{
return ctype;
}
int retsent()
{
return sent;
}
dateoc retdateoc()
{
return doc;
}
dateos retdateos()
{
return dos;
}
};
//END OF CLASS CRIMINAL
char ans;
criminal c1,c2;
fstream file,temp;//FSTREAM OBJECTS CREATED FOR FILE MANIPULATION
/* FUNCTION TO CREATE BINARY FILE "CRIMINAL" */
void create()
{
file.open("criminal.dat",ios::out|ios::binary);
do
{
c1.getdata();//TO GET DATA FROM THE USER
file.write((char*)&c1,sizeof(c1)); //C1 WRITTEN INTO THE FILE
cout<<"DO YOU WANT TO CONTINUE?";
cin>>ans;
}
while ( ans=='y'|| ans=='Y');
file.close();
}
/*FUNCTION TO READ THE FILE "CRIMINAL"*/
void showfile()
{
file.open("criminal.dat",ios::in|ios::binary);
while(file.read((char*)&c1,sizeof(c1)))
{
c1.showdata();
}
file.close();
}
/*FUNCTIONS TO SEARCH ON DIFFERENT CRITERION*/
/*FUNCION TO SEARCH ON THE BASIS OF CRIMINAL ID*/
void searchcid()
{
int scid;
cout<<"ENTER THE CRIMINAL ID TO BE SEARCHED - ";
cin>>scid;
while(file.read((char*)&c1,sizeof(c1)))
{
if(c1.retcid()==scid)
{
c1.showdata();
break;
}}}
/*FUNCTION TO SEARCH ON THE BASIS OF CRIMINAL NAME*/
void searchname()
{
char sname[20];
cout<<"ENTER NAME OF THE CRIMINAL TO BE SEARCHED";
gets(sname);
while(file.read((char*)&c1,sizeof(c1)))
{
if(strcmp(sname,c1.retname())==0)
{
c1.showdata();
break;
}}}
/*FUNCTION TOP SEARCH ON THE BASIS OF TYPE OF CRIME*/
void searchcrime()
{
int ch;
cout<<"ENTER TYPE OF CRIME:-\n1.MURDER\n2.RAPE\n3.THEFT";
cin>>ch;
while(file.read((char*)&c1,sizeof(c1)))
{
if(c1.retctype()==ch)
{
c1.showdata();
break;
}}}
/*FUNCTION TO SEARCH ON THE BASIS OF GENDER*/
void searchsex()
{
char ssex[1];
cout<<"ENTER GENDER OF CRIMINAL TO BE SEARCHED - ";
gets(ssex);
while(file.read((char*)&c1,sizeof(c1)))
{
if(strcmp(c1.retsex(),ssex)==0)
{
c1.showdata();
break;
}}}
/*FUNCTIONS TO COUNT ON THE BASIS OF DIFFRENT CRITERION*/
/*FUNTION TO COUNT ALL RECORDS*/
void countallrec()
{
file.open("criminal.dat",ios::in|ios::binary);
file.seekg(0,ios::end);
int lp=file.tellg();
int s=sizeof(c1);
int lr=lp/s;
cout<<"NUMBER OF RECORDS - ";
cout<<lr;
file.close();
}
/*FUNCTION TO COUNT ON THE BASIS OF TYPE OF CRIME*/
void countctype()
{
int r=0,ch;
cout<<"ENTER TYPE OF CRIME:-\n1.MURDER\n2.RAPE\n3.THEFT";
cin>>ch;
file.open("criminal.dat",ios::in|ios::binary);
while(file.read((char*)&c1,sizeof(c1)))
{
if(c1.retctype()==ch)
++r;
}
file.close();
cout<<"NUMBER OF RECORDS - ";
cout<<r;
}
/*FUNCTION TO COUNT ON THE BASIS OF DURATION OF SENTENCE*/
void countsent()
{
int r=0,ch;
cout<<"ENTER DURATION OF SENTENCE -\n1.LIFETIME\n2.10yr\n3.HANG TO DEATH";
cin>>ch;
file.open("criminal.dat",ios::in|ios::binary);
while(file.read((char*)&c1,sizeof(c1)))
{
if(c1.retsent()==ch)
++r;
}
file.close();
cout<<"NUMBER OF RECORDS - ";
cout<<r;
}
/*FUNCTION TO COUNT ON THE BASIS OF GENDER*/
void countsex()
{
int r=0;
char csex[1];
cout<<"ENTER GENDER OF CRIMINAL TO BE SEARCHED - ";
gets(csex);
file.open("criminal.dat",ios::in|ios::binary);
while(file.read((char*)&c1,sizeof(c1)))
{
if(strcmp(c1.retsex(),csex)==0)
++r;
}
file.close();
cout<<"NUMBER OF RECORDS - ";
cout<<r;
}
/*FUNCTION TO COUNT OF THE BASIS OF CID
/*FUNCTIONS TO EDIT RECORDS OVER DIFFRENT CRITIRION*/
/*FUNCTION TO EDIT RECORD AT nth POSITION USING A TEMPORARY FILE*/
void editrec()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int r=0,er;
cout<<"ENTER THE RECORD NUMBER TO BE EDITED";
cin>>er;
while(file.read((char*)&c2,sizeof(c2)))
{
r++;
if(r==er)
{
cout<<"ENTER NEW DATA\n";
c2.getdata();
}
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO EDIT ON THE BASIS OF CRIMINAL ID*/
void editcid()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int er;
cout<<"ENTER CRIMINAL ID - ";
cin>>er;
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
if(er==c2.retcid())
{
cout<<"ENTER NEW DATA\n";
c2.getdata();
}
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO EDIT ON THE BASIS OF CRIMINAL NAME*/
void editname()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
char ename[20];
cout<<"ENTER NAME - ";
gets(ename);
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
if(strcmp(ename,c2.retname())==0)
{
cout<<"ENTER NEW DATA\n";
c2.getdata();
}
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTIONS TO INSERT NEW DATA AT DIFFERENT LOCATIONS*/
/*FUNCTION TO INSERT AT 1ST POSITION*/
void insfst()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
temp.write((char*)&c1,sizeof(c1));
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO INSERT AT LAST POSITION*/
void inslst()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out,ios::binary);
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
}
temp.write((char*)&c1,sizeof(c1));
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO INSERT AT nth POSITION*/
void insnth()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int r=0;
int ir;
cout<<"ENTER THE RECORD NUMBER AFTER WHICH NEW RECORD WILL BE INSERTED - ";
cin>>ir;
while(file.read((char*)&c2,sizeof(c2)))
{
r++;
if(r==ir)
temp.write((char*)&c1,sizeof(c1));
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO INSERT AFTER A CRIMINAL ID*/
void inscid()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int icid;
cout<<"ENTER CRIMINALID - ";
cin>>icid;
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
if(c2.retcid()==icid)
temp.write((char*)&c1,sizeof(c1));
}
file.close();
temp.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO INSERT AFTER A CRIMINAL NAME*/
void insname()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
char iname[20];
cout<<"ENTER NAME - ";
gets(iname);
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
if(strcmp(iname,c2.retname())==0)
temp.write((char*)&c1,sizeof(c1));
}
file.close();
temp.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTIONS TO DELETE RECORDS AT DIFFERENT LOCATIONS*/
/*FUNCTION TO DELETE RECORD AT 1ST POSITION*/
void delfst()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
file.read((char*)c2,sizeof(c2));
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO DELETE FROM LAST POSITION*/
void dellst()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
file.seekg(0,ios::end);
int lp=file.tellg();
int s=sizeof(c1);
int lr=lp/s;
int r=1;
cout<<"NUMBER OF RECORDS"<<lr;
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
if (r!=lr)
temp.write((char*)&c2,sizeof(c2));
r++;
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO DELETE FROM nth POSITION*/
void delnth()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int r=1;
int dr;
cout<<"ENTER RECORD NUMBER TO BE DELETED";
cin>>dr;
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
if(r!=dr)
temp.write((char*)&c2,sizeof(c2));
r++;
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO DELETE A CRIMINAL ID*/
void delcid()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
int dcid;
cout<<"ENTER CRIMINALID - ";
cin>>dcid;
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
if(c2.retcid()!=dcid)
temp.write((char*)&c2,sizeof(c2));
}
temp.close();
file.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*FUNCTION TO DELETE A CRIMINAL NAME*/
void delname()
{
file.open("criminal.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
char dname[20];
cout<<"ENTER NAME - ";
gets(dname);
file.seekg(0);
while(file.read((char*)&c2,sizeof(c2)))
{
temp.write((char*)&c2,sizeof(c2));
if(strcmp(dname,c2.retname())!=0)
temp.write((char*)&c1,sizeof(c1));
}
file.close();
temp.close();
remove("criminal.dat");
rename("new.dat","criminal.dat");
}
/*MAIN FUNCTION*/
void main()
{
clrscr();
cout<<"WELCOME#";
int ch;
char ch1;
do
{
clrscr();
cout<<"\t\t\t\n\n\nFILE OPERRATION MENU\n\n\n\t\t\t";
cout<<"\t\t\t\n\n\n1.CREATE FILE\n2.SHOW FILE\n3.SEARCH(CRIMINAL
NAME)\n4.SEARCH(CRIMETYPE)\n5.SEARCH(GENDER)\n6.COUNT(ALL)\n7.COUNT(ID)\n8.COUNT
(SENTENCE)\n9.COUNT(GENDER)\n10.EDIT(nth)\n11.EDIT(ID)\n12.EDIT(NAME)\n13.INSERT
(1ST)\n14.INSERT(LAST)\n15.INSERT(nth)\n16.INSERT(ID)\n17.INSERT(NAME)\n18.DELET
E(1ST)\n19.DELETE(LAST)\n20.DELETE(nth)\n21.DELETE(ID)\n22.DELETE(NAME)\n";
cout<<"ENTER CHOICE";
cin>>ch;
switch(ch)
{
case 1: create();
break;
case 2: showfile();
break;
case 3: searchcid();
break;
case 4: searchname();
break;
case 5: searchcrime();
break;
case 6: searchsex();
break;
case 7: countallrec();
break;
case 8: countsent();
break;
case 9: countsex();
break;
case 10: editrec();
break;
case 11: editcid();
break;
case 12: editname();
break;
case 13: insfst();
break;
case 14: inslst();
break;
case 15: insnth();
break;
case 16: inscid();
break;
case 17: insname();
break;
case 18: delfst();
break;
case 19: dellst();
break;
case 20: delnth();
break;
case 21: delcid();
break;
case 22: delname();
break;
default: cout<<"WRONG CHOICE#";
}
cout<<"WANT TO CONTINUE?";
cin>>ch1;
}while(ch1=='y'|| ch1=='Y');
getch();
}