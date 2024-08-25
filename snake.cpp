#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01
#MADE BY Aleziz01

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;
using system;
string x[11][22];
int main(){
    srand(time(0));
    int n=4,m=9,length=2,nmove=0,mmove=0,c=0,xaxis=rand()%10,yaxis=rand()%20;
    for(int i=0; i<10; ++i){
        for(int j=0; j<20; ++j){
            x[i][j]="N";
        }
    }
    x[xaxis][yaxis]="F";
    x[4][9]="*";
    for(int i=0; i<10; ++i){
        for(int j=0; j<20; ++j){
            cout << x[i][j];
        }
        cout << endl;
    }
    string move;
    bool alive=true,ok=true,ok2=true;
    int p[2000],i=1,i2=0;
    while(alive){
        system("stty raw"); //this makes it so that you dont have to press enter after each input(only works in onlinegdb i think???)
        move=getchar();
        while(move!="a" && move!="s" && move!="w" && move!="d"){
            move=getchar();
        }
        system("stty cooked"); //this resets the terminal to input output processing(meaning you have to press enter after each thing)
        if(move=="w"){
            n--;
            if(x[n][m]=="*" || n<0){
                alive=false;
            }
            nmove--;
            p[i]=1;
            cout << "p[" << i << "] is " << p[i]<<endl;
        }
        if(move=="s"){
            n++;
            if(x[n][m]=="*" || n>=10){
                alive=false;
            }
            nmove++;
            p[i]=2;
            cout << "p[" << i << "] is " << p[i]<<endl;
        }
        if(move=="d"){
            m++;
            if(x[n][m]=="*" || m>=20){
                alive=false;
            }
            mmove++;
            p[i]=3;
            cout << "p[" << i << "] is " << p[i]<<endl;
        }
        if(move=="a"){
            m--;
            if(x[n][m]=="*" || m<0){
                alive=false;
            }
            mmove--;
            p[i]=4;
            cout << "p[" << i << "] is " << p[i]<<endl;
        }
        ok=true;
        if(x[n][m]=="F"){
            xaxis=rand()%10;
            yaxis=rand()%20;
            while(x[xaxis][yaxis]!="N")
            {
                xaxis=rand()%10;
                yaxis=rand()%20;
            }
            x[xaxis][yaxis]="F";
            ok=false;
            ok2=false;
            i2++;
        }
        x[n][m]="*";
        int i3=i;
        if(c>=length && ok==true){
            x[n-nmove][m-mmove]="N";
                if(p[i-length-i2]==1){
                    nmove++;
                }
                if(p[i-length-i2]==2){
                    nmove--;
                }
                if(p[i-length-i2]==3){
                    mmove--;
                }
                if(p[i-length-i2]==4){
                    mmove++;
                }
                cout << "this is case i-length " << i << "yo" << i-length <<endl << x[n-nmove][m-mmove] << endl << n-nmove << " coords " << m-mmove<< "length" << length << endl <<  "p is" << p[i-length] << endl;
        }
        for(int i=0; i<10; ++i){
            for(int j=0; j<20; ++j){
                cout << x[i][j];
            }
            cout << endl;
        }
        c++;
        i++;
    }
    cout << "GAME OVER!!";
}