#include<iostream>
#include <cstdlib>
using namespace std;
int t_cash = 200000;
int systempswd = 1917; 
typedef struct node
{
int account_no;
int pswd;
int cash;
int bill;
int phn_no;
node *link;
}d;
d *start, *loc, *loc1;
    create(){
    d *ptr,*ptr1;
    char ch ,dec;
    cout<<"\n\n                               WELCOME TO LOK SEWA BANK                   \n\n \n\n      "    ;
    ptr=(d*)malloc(sizeof(d));
    cout<<"  SIZE OF ACCOUNT NUMBER MAX 4 DIGITS, PASSWORD 4 DIGITS .";
    cout<<" \n\n\n ENTER THE ACCOUNT NUMBER :  ";
    cin>>ptr->account_no;
    cout<<" \n ENTER THE PASSWORD :  ";
    cin>>ptr->pswd;
	cout<<" \n ENTER THE FIRST THREE AND LAST THREE DIGITS OF PHONE NUMBER :  ";
    cin>>ptr->phn_no;
	cout<<" \n ENTER THE CASH IN THE ACCOUNT :  ";
    cin>>ptr->cash;
    cout<<" \n\n\n PRESS Y IF ANY BILL AMOUNT IS PENDING OR PRESS N : ";
    cin>>dec;
    if(dec=='y')
    {
	cout<<" ENTER  BILL AMOUNT  : ";
    cin>>ptr->bill;
    }
    else
   {
	ptr->bill = 0;
   }
    
    start=ptr;
    do{
    ptr1=(d*)malloc(sizeof(d));
    ch='n';
	cout<<" \n ENTER THE ACCOUNT NUMBER :  ";
    cin>>ptr1->account_no;
    cout<<" \n ENTER THE PASSWORD :  ";
    cin>>ptr1->pswd;
	cout<<" \n ENTER THE FIRST THREE AND LAST THREE DIGITS OF UR PHONE NUMBER :  ";
    cin>>ptr1->phn_no;
	cout<<" \n ENTER THE CASH AVAILABLE IN ACCOUNT :  ";
    cin>>ptr1->cash;
      cout<<" \n\n\n PRESS Y IF ANY BILL AMOUNT IS PENDING OR PRESS N : ";
    cin>>dec;
    if(dec=='y')
    {
	cout<<" ENTER  BILL AMOUNT  : ";
    cin>>ptr1->bill;
}   
else
{
	ptr->bill = 0;
}
    
    ptr->link=ptr1;
      ptr=ptr1;
      cout<<" \n\n  TYPE y IF U WANT TO MAKE MORE ACCOUNTS ELSE   n  :  ";
      cin>>ch;
    }
    while(ch=='y');
    ptr->link=NULL;
}


void search(int item)
{
	d *ptr;
	ptr=start;
	while(ptr != NULL)
{
	if(ptr->account_no==item )
	{
	loc = ptr;
	return;
	}
	ptr = ptr->link;
	}
	loc = NULL;
	cout<<"\n\n\n                              SORRY !! UR ACCOUNT NUMBER IS INVALID  .                                ";  	
	return ;	
}
void search1(int item)
{
	d *ptr;
	ptr=start;
	while(ptr != NULL)
{
	if(ptr->account_no==item )
	{
	loc1 = ptr;
	return;
	}
	ptr = ptr->link;
	}
	loc1 = NULL;
	cout<<"\n\n\n                              SORRY !! UR ACCOUNT NUMBER IS INVALID .                                 ";  	
	return ;	
}
int password(int item)
{ 
if(loc->pswd==item)
{
	return 1;
	}	
	else
	{
		return 0;
	}
}
void password1(int item)
{
int e,g;
int j=1; 
if(loc->pswd==item)
{    
while(j!=0)  
	{
	cout<<" \n ENTER UR NEW PASSWORD : ";
	cin>>e;
	cout<<" \n ENTER UR NEW PASSWORD AGAIN FOR CONFIRMATION : ";
	cin>>g;
	if(e==g)
	{	
	cout <<"\n\n PASSWORD UPDATED .";
	j=0;
	}
	}
	return;
}
	else
	{
		return ;
	}
}
void phone1(int item)
{
int e,g;
int j=1; 
if(loc->phn_no == item)
{    
while(j!=0)  
	{
	cout<<" \n ENTER UR NEW PHONE NUMBER : ";
	cin>>e;
	cout<<" \n ENTER UR NEW PHONE NUMBER AGAIN FOR CONFIRMATION : ";
	cin>>g;
	if(e==g)
	{
	cout <<"\n\n PHONE NUMBER UPDATED. ";
	j=0;
	}
	}
	return;
}
	else
	{
		return ;
	}
}
void transfer(int item)
{   
 if( t_cash>=item )
	{
	loc->cash = loc->cash - item;
	cout<<" \n UR ACCOUNT BALANCE : "<< loc->cash;
    loc1->cash = loc1->cash + item;	 
	cout<<" \n\n  CASH TRANSFERED  ";
	t_cash = t_cash - item;
	}
	else
	{
		cout<<"\n\n\n\n  SORRY  ATM IS SHORT OF CASH  ";
	}
}
void yocash(int item)
{
	if ( loc->cash >= item && t_cash >= item)
	{
		cout<<"\n\n RECIEVE UR CASH BEFORE U LEAVE.   ";
		loc->cash = loc->cash - item;
		t_cash = t_cash - item; 
		return; 
	}
	if(item >= loc->cash)
	{
		cout<<" \n\n  UR ACCOUNT DOES NOT HAVE ENOUGH BALANCE .   ";
		return;
	}
	else
	{
		cout<<"     \n\n  ATM  IS SHORT OF MONEY   ";
		return;
	}
	
	}	
	int yesgo(int item)
	{
		if(loc->cash>= item)
		{
			return 2;
		}
		else
		{ cout<<" \n\n           UR ACCOUNT DOES NOT HAVE ENOUGH BALANCE  .             ";
			return 0;
		}
	}
	void detail()
	{
		cout<<"\n\n UR ACCOUNT BALANCE IS : " << loc->cash;
		cout<<" \n UR REGISTERD MOBILE NUMBER IS : "<< loc->phn_no;
		cout<<"\n UR BILL AMOUNT UP TO THE DATE IS : "<<loc->bill;
		cout<<" \n\n\n\n\n                           LOK SEWA BANK                                                   " ;
		cout<<"\n\n                                  HAVE A NICE DAY                                                 " ;
	}
	int bdelete()
{
	if( loc->cash > t_cash )
	{
		cout<<"\n\n   ATM IS SHORT OF CASH    ";
		return 0;
	}
	if(loc->cash==0)
	{ 
	cout<<" \n\n  ZERO BALANCE . ";
	return 1;
	}
	else 
	cout<<" \n\n COLLECT UR AMOUNT BEFORE LEAVING . ";
	cout<<" \n  AMOUNT RECEIEVED : "<< loc->cash;
	return 2;
}
 void cdelete(int item)
{    int count=0;
	d *ptr;
	ptr=start;
	while (ptr->link != NULL)
	{
	     count++;
		if (ptr->account_no==item)
		{
			loc = ptr->link;
			break;
		}
		loc1=ptr;
		ptr=ptr->link;
	}
	if(count>1)
	{
	loc1->link = loc;
	cout<<"\n  ACCOUNT DELETED .";
    }
 else 
   {
	start=start->link;
	cout<<"\n  ACCOUNT DELETED .";
   } 
}
void billdone()
{
	loc->cash = loc->cash - loc->bill;
	if(loc->cash < 0)
	{
		loc->cash=0;
	}
	cout<<" \n  YOUR BALANCE IS : "<<loc->cash;
	t_cash = t_cash - loc->bill;
	if(t_cash < 0)
	{
		t_cash = 0;
	}
	cout<<" \n\n  PAYMENT IS DONE , HAVE A NICE DAY  ";
	loc->bill=0;
	
	return;
}
 void rtu()
{    
	if(loc->cash >= loc->bill && t_cash >= loc->bill )	
	{
		billdone();
		return;
		}	
		else if( loc->bill >= loc->cash )
		{
			cout<<" \n\n  UR ACCOUNT NOT HAVE SUFFICIENT MONEY . ";
			return;
		}
		else{
			cout<<"\n\n ATM IS SHORT OF CASH ";
			return;
		}
}

 void yosystem(int item)
{
if (item==systempswd)
    {
	cout<<" \n\n AMOUNT OF CASH IN THE BANK IS : "<<t_cash;
	return;
	}	
	else
	{
		cout<<" \n\n  Wrong password. NOT For General Purpose . ";
		return;
	}
	
}

 void work(int b)
{
switch(b)
{
case 1: {
	int c,x;
	d *ptr1;
	cout<<" \n\n ENTER UR ACCOUNT NUMBER : \n ";
    cin>>c;
	search(c);
	 if(loc!= NULL)
	 {
	 	cout<<" \nENTER UR PASSWORD : ";
	 	cin>>c;
	 	x=password(c);
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
		 if(x==1)
		 {
		 	cout<<"\n\n ENTER THE CASH U WANT TO WITHDRAW :  ";
		 	cin>>c;
		 	yocash(c);
		 }
		 return;
	
	break;
}	
case 2:{
		int c;
	cout<<" \n\nENTER UR ACCOUNT NUMBER : ";
    cin>>c; 
		search(c);
	 if(loc!= NULL)
	 {
	 	cout<<" \nENTER UR PASSWORD : ";
	 	cin>>c;
	 	password1(c);
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
	
	break;
}
case 3:{
		int c,x;
	cout<<" \n\n ENTER UR ACCOUNT NUMBER :  ";
    cin>>c; 
    search(c);
    cout<< "\n ENTER THE PASSWORD OF UR ACCOUNT  ";
    cin>>c;
    x=password(c);
	 if(loc!= NULL && x==1)
	 {
	 	cout<<" \nENTER UR PHONE NUMBER : ";
	 	cin>>c;
	 	phone1(c);
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
	
	
	break;
}
case 4:{
	cout<<" \n\n MAKE SURE THAT ACCOUNT U WANT TO TRANFER AMOUNT HAS A ACCOUNT IN LOK SEWA BANK ";
		int c,n,x;
	cout<<" \n\n ENTER UR ACCOUNT NUMBER : ";
    cin>>c; 
    search(c);
    cout<< "\n ENTER THE PASSWORD OF UR ACCOUNT  ";
    cin>>c;
    x=password(c);
	 if(loc!= NULL && x==1)
	 {
	 	cout<<" \nENTER ACCOUNT U WANT TO TRANSFER CASH : ";
	 	cin>>c;
	 	search1(c);
	 	if(loc1!= NULL)
	 	{
	 		cout<<" \n\n ENTER THE AMOUNT U WANT TO TRANFER : ";
	 		cin>>c;
	 		n = yesgo(c);
		 }
		 else 
		 {
		 	cout<<" \n\n THIS ACCOUNT NUMBER IS INVALID ";
		 }
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
		 if(n==2)
		 {
		 	transfer(c);
		 }	
	break;
}
case 5:{
		int c,q,x,o;
	cout<<" \n\nENTER UR ACCOUNT NUMBER : ";
    cin>>c;
    q=c;
		search(c);
		cout<< "\n ENTER THE PASSWORD OF UR ACCOUNT  ";
    cin>>c;
    x=password(c);
	 if(loc!= NULL && x==1)
	 {
	 	cout<<" BEFORE DELETING UR ACCOUNT WITHDRAW ALL THE CASH ";
	 	o=bdelete();
	 	if(o!=0)
	 	{
		 cdelete(q);
        }
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
	 
	
	
	break;
}
case 6:{
		int c,x;
	cout<<" \n\n  ENTER UR ACCOUNT NUMBER  : ";
    cin>>c; 
     search(c);
     cout<< "\n ENTER THE PASSWORD OF UR ACCOUNT  ";
    cin>>c;
    x=password(c);
	 if(loc!= NULL&& x==1 )
	 {
	 	 detail();
		 }	
		 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
    
	break;
}	
case 7:{
	int c,x;
	cout<<" \n\n  ENTER UR ACCOUNT NUMBER  : ";
    cin>>c; 
    search(c);
    cout<< "\n ENTER THE PASSWORD OF UR ACCOUNT  ";
    cin>>c;
     x=password(c);
     if(loc!= NULL&& x==1 )
	{  
	if(loc->bill != 0)
	{
		rtu();
		}	
		else
		{
			cout<<" \n\n U HAVE NO BILL TILL THE DATE  ";
		}
	}
	 else
		 {
		 	cout<<"\n\n\n\n                                    THANKS ! HAVE A NICE DAY                           ";
		 	return;
		 }
		 break;	
}
case 8:{
int c;
cout<<" \n\n ENTER THE SYSTEM PASSWORD :\n \n ";
cin>>c;
yosystem(c);
cout<<"\n \n ";
	break;
}
case 9:{
	//int b
	//if(b==9)
cout<<"\n \n  endl"	;
	exit(0);
	break;
	
}
	
}
}

void choose()
{   cout<<"          \n\n\n\n\n                                    *LOK SEWA BANK*                                   ";
    int a;  
    cout<<"\n\n\n\n\n";
	cout<<"1 : "<< " Cash Withdrawl "<<"\n";
	cout<<"2 : "<< " Change Password "<<"\n";
	cout<<"3 : "<< " Change Phone Number "<<"\n";
	cout<<"4 : "<< " Tranfer Cash "<<"\n";
    cout<<"5 : "<< " Delete Account "<<"\n";
    cout<<"6 : "<< " Check Account Details  "<<"\n";
    cout<<"7 :"<<  " Bill Pendings   "<<"\n";
    cout<<"8 :"<<  " System Information  ";
    cout<<"9 :"<<  " exit                ";
     cout<<"\n\n\n    ENTER THE NUMBER U WANT TO SELECT   ";
    cin>>a;
    if (a<=9)
    {
    	work(a);
    	choose();
	}
	return;
}
	
	int main()
	{
	int a;
	system("color 3a"); 

	
	create();
	choose();
	
	}
	
