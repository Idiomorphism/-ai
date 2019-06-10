/*
    project:五子棋
    作者：杨千睿 
*/
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h> 
using namespace std;
#define MAX_SIZE 14
int flag1=0;
char a[MAX_SIZE][MAX_SIZE],ai1,ai2;
unsigned long b[MAX_SIZE][MAX_SIZE]={0};

void gotoxy(int x, int y)
{
    COORD coord; 
    HANDLE hscr; 
    coord.X = x; 
    coord.Y = y;
    hscr = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hscr, coord); 
}
void gotoqp(int x, int y)
{
    gotoxy(4*x+7,2*y);
}
//-----------------------------------------------------------------------ai

int Random(int start, int end){
    int dis = end - start;
    return rand()%dis + start;
}

int setplayer2(unsigned long &s, int &ps,int step=2)
{
    ps+=step;
    if(ps==2)
        s+=10;
    if(ps==3)
        s+=20;  
    if(ps==4)
        s+=50;
    if(ps==5)
        s+=70;  
    if(ps==6)
        s+=100;
    if(ps==7)
        s+=200; 
    if(ps==8)
        s+=1000;
    if(ps==10)
        s+=10000;   
}

int setplayer1(unsigned long &s, int &ps,int step=2)
{
    ps+=step;
    if(ps==2)
        s+=11;
    if(ps==3)
        s+=21;      
    if(ps==4)
        s+=51;
    if(ps==5)
        s+=71;  
    if(ps==6)
        s+=101;     
    if(ps==7)
        s+=201;     
    if(ps==8)
        s+=2001;
    if(ps==10)
        s+=10001;
}

void point(unsigned long &s,int x,int y,int player,int dir,int ps){
    int oldps;

    if(dir==0){

            if(x+1<MAX_SIZE&&a[x+1][y]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x+1,y,2,1,ps);
                ps=oldps;
            }
            if(y+1<MAX_SIZE&&a[x][y+1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x,y+1,2,2,ps);
                ps=oldps;
            }
            if(x-1>0&&a[x-1][y]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x-1,y,2,3,ps);
                ps=oldps;
            }
            if(y-1>0&&a[x][y-1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x,y-1,2,4,ps);
                ps=oldps;
            }
            if(x+1<MAX_SIZE&&y+1<MAX_SIZE&&a[x+1][y+1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x+1,y+1,2,5,ps);
                ps=oldps;
            }
            if(x-1>0&&y-1>0&&a[x-1][y-1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x-1,y-1,2,6,ps);
                ps=oldps;
            }
            if(x+1<MAX_SIZE&&y-1>0&&a[x+1][y-1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x+1,y-1,2,7,ps);
                ps=oldps;
            }
            if(y+1<MAX_SIZE&&x-1>0&&a[x-1][y+1]=='O'){
                oldps=ps;
                setplayer2(s,ps);
                point(s,x-1,y+1,2,8,ps);
                ps=oldps;
            }//连自己 

            if(x+1<MAX_SIZE&&a[x+1][y]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x+1,y,1,1,ps);
                ps=oldps;
            }
            if(y+1<MAX_SIZE&&a[x][y+1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x,y+1,1,2,ps);
                ps=oldps;
            }
            if(x-1>0&&a[x-1][y]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x-1,y,1,3,ps);
                ps=oldps;
            }
            if(y-1>0&&a[x][y-1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x,y-1,1,4,ps);
                ps=oldps;
            }
            if(x+1<MAX_SIZE&&y+1<MAX_SIZE&&a[x+1][y+1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x+1,y+1,1,5,ps);
                ps=oldps;
            }
            if(x-1>0&&y-1>0&&a[x-1][y-1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x-1,y-1,1,6,ps);
                ps=oldps;
            }
            if(x+1<MAX_SIZE&&y-1>0&&a[x+1][y-1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x+1,y-1,1,7,ps);
                ps=oldps;
            }
            if(y+1<MAX_SIZE&&x-1>0&&a[x-1][y+1]=='X'){
                oldps=ps;
                setplayer1(s,ps);
                point(s,x-1,y+1,1,8,ps);
                ps=oldps;
            }//防守 

    }

    if(player==2)//进攻 
    {

        if(x+1<MAX_SIZE&&a[x+1][y]!='X'&&dir==1){
            oldps=ps;

            if(a[x+1][y]=='O') 
            {
                setplayer2(s,ps);
                point(s,x+1,y,player,dir,ps);
            }else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x+1,y,player,dir,ps);
            }
            ps=oldps;
        }
        if(y+1<MAX_SIZE&&a[x][y+1]!='X'&&dir==2){
            oldps=ps;

            if(a[x][y+1]=='O') 
            {
                setplayer2(s,ps);
                point(s,x,y+1,player,dir,ps);
            }else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x,y+1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x-1>0&&a[x-1][y]!='X'&&dir==3){
            oldps=ps;

            if(a[x-1][y]=='O') 
            {
                setplayer2(s,ps);
                point(s,x-1,y,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x-1,y,player,dir,ps);
            }
            ps=oldps;
        }
        if(y-1>0&&a[x][y-1]!='X'&&dir==4){
            oldps=ps;

            if(a[x][y-1]=='O') {
                setplayer2(s,ps);
                point(s,x,y-1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x,y-1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x+1<MAX_SIZE&&y+1<MAX_SIZE&&a[x+1][y+1]!='X'&&dir==5){
            oldps=ps;

            if(a[x+1][y+1]=='O') {
                setplayer2(s,ps);
                point(s,x+1,y+1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x+1,y+1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x-1>0&&y-1>0&&a[x-1][y-1]!='X'&&dir==6){
            oldps=ps;

            if(a[x-1][y-1]=='O') 
            {
                setplayer2(s,ps);
                point(s,x-1,y-1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x-1,y-1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x+1<MAX_SIZE&&y-1>0&&a[x+1][y-1]!='X'&&dir==7){
            oldps=ps;

            if(a[x+1][y-1]=='O'){
                setplayer2(s,ps);
                point(s,x+1,y-1,player,dir,ps);
            } 
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x+1,y-1,player,dir,ps);
            }
            ps=oldps;
        }
        if(y+1<MAX_SIZE&&x-1>0&&a[x-1][y+1]!='X'&&dir==8){
            oldps=ps;

            if(a[x-1][y+1]=='O') {
                setplayer2(s,ps);
                point(s,x-1,y+1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer2(s,ps,1);
                point(s,x-1,y+1,player,dir,ps);
            }
            ps=oldps;
        }
    }
    else if(player==1)//防守 
    {

        if(x+1<MAX_SIZE&&a[x+1][y]!='O'&&dir==1){
            oldps=ps;

            if(a[x+1][y]=='X') {
                setplayer1(s,ps);
                point(s,x+1,y,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x+1,y,player,dir,ps);
            }
            ps=oldps;
        }
        if(y+1<MAX_SIZE&&a[x][y+1]!='O'&&dir==2){
            oldps=ps;

            if(a[x][y+1]=='X')  {
                setplayer1(s,ps);
                point(s,x,y+1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x,y+1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x-1>0&&a[x-1][y]!='O'&&dir==3){
            oldps=ps;

            if(a[x-1][y]=='X')  {
                setplayer1(s,ps);
                point(s,x-1,y,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x-1,y,player,dir,ps);
            }

            ps=oldps;
        }
        if(y-1>0&&a[x][y-1]!='O'&&dir==4){
            oldps=ps;

            if(a[x][y-1]=='X')  {
                setplayer1(s,ps);
                point(s,x,y-1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x,y-1,player,dir,ps);
            }
            ps=oldps;
        }
        if(x+1<MAX_SIZE&&y+1<MAX_SIZE&&a[x+1][y+1]!='O'&&dir==5){
            oldps=ps;

            if(a[x+1][y+1]=='X')  {
                setplayer1(s,ps);
                point(s,x+1,y+1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x+1,y+1,player,dir,ps);
            }

            ps=oldps;
        }
        if(x-1>0&&y-1>0&&a[x-1][y-1]!='O'&&dir==6){
            oldps=ps;

            if(a[x-1][y-1]=='X') {
                setplayer1(s,ps);
                point(s,x-1,y-1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x-1,y-1,player,dir,ps);
            }

            ps=oldps;
        }
        if(x+1<MAX_SIZE&&y-1>0&&a[x+1][y-1]!='O'&&dir==7){
            oldps=ps;

            if(a[x+1][y-1]=='X') {
                setplayer1(s,ps);
                point(s,x+1,y-1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x+1,y-1,player,dir,ps);
            }

            ps=oldps;
        }
        if(y+1<MAX_SIZE&&x-1>0&&a[x-1][y+1]!='O'&&dir==8){
            oldps=ps;

            if(a[x-1][y+1]=='X') {
                setplayer1(s,ps);
                point(s,x-1,y+1,player,dir,ps);
            }
            else if(0==ps%2)
            {
                setplayer1(s,ps,1);
                point(s,x-1,y+1,player,dir,ps);
            }

            ps=oldps;
        }
    }
}

void ai(){
    int max=0,m,n;
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            b[i][j]=0;
        }
    }
    ai1=0;ai2=0;

    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(a[i][j]==' '){
                point(b[i][j],i,j,0,0,0);       
            }
        }
    }
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(b[i][j]>max&&a[i][j]==' '){
                max=b[i][j];
                ai1=i;
                ai2=j;
            }
            else if(b[i][j]==max&&a[i][j]==' '){
                if(Random(0,2)==1)
                {
                    max=b[i][j];
                    ai1=i;
                    ai2=j;
                }

            }
        }
        cout<<endl;
    }
}

//-----------------------------------------------------------------------ai

int panduan(char player){
    //是否下满
    int flag=0;
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(a[i][j]==' '){
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        return 2;

    //是否获胜
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(a[i][j]==player){
                if(i-5>=0){
                    if(a[i-1][j]==player&&a[i-2][j]==player&&a[i-3][j]==player&&a[i-4][j]==player)
                        return 1;
                }
                if(j-5>=0){
                    if(a[i][j-1]==player&&a[i][j-2]==player&&a[i][j-3]==player&&a[i][j-4]==player)
                        return 1;
                }
                if(i<=6){
                    if(a[i+1][j]==player&&a[i+2][j]==player&&a[i+3][j]==player&&a[i+4][j]==player)
                        return 1;
                }
                if(j<=6){
                    if(a[i][j+1]==player&&a[i][j+2]==player&&a[i][j+3]==player&&a[i][j+4]==player)
                        return 1;
                }
                if(i-5>=0&&j-5>0){
                    if(a[i-1][j-1]==player&&a[i-2][j-2]==player&&a[i-3][j-3]==player&&a[i-4][j-4]==player)
                        return 1;
                }
                if(i-5>=0&&j<=6){
                    if(a[i-1][j+1]==player&&a[i-2][j+2]==player&&a[i-3][j+3]==player&&a[i-4][j+4]==player)
                        return 1;
                }
                if(i<=6&&j<=6){
                    if(a[i+1][j+1]==player&&a[i+2][j+2]==player&&a[i+3][j+3]==player&&a[i+4][j+4]==player)
                        return 1;
                }
                if(i<=6&&j-5>=0){
                    if(a[i+1][j-1]==player&&a[i+2][j-2]==player&&a[i+3][j-3]==player&&a[i+4][j-4]==player)
                        return 1;
                }
            }
        }
    }
    return 0;
}

void qipan(int x,int y,int flag){ 
    cout<<"           "<<1<<"   "<<2<<"   "<<3<<"   "<<4<<"   "<<5<<"   "<<6<<"   "<<7<<"   "<<8<<"   "<<9<<"   "<<10<<"  "<<11<<"  "<<12<<"  "<<13<<endl;
    for(int i=1;i<MAX_SIZE;i++){
        cout<<"\t  ";
        for(int m=5;m<4*MAX_SIZE;m++)
            cout<<"-";
        cout<<endl<<i<<"\t";
        cout<<" | ";
        for(int j=1;j<MAX_SIZE;j++){
            if(i==x&&j==y&&flag==1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
                cout<<a[i][j];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
                cout<<" | ";
            }
            else
                cout<<a[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<"          ";
    for(int m=5;m<4*MAX_SIZE;m++)
        cout<<"-";
}//画棋盘 

int jisuan(){ 
    int aa[MAX_SIZE][MAX_SIZE],result=0;
    unsigned long bb[MAX_SIZE][MAX_SIZE];

    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            aa[i][j]=a[i][j];
            bb[i][j]=b[i][j];
        }
    }//初始化 

    while(1){   

            ai();
            int x=ai1,y=ai2;

            a[x][y]='X';                

            if(panduan('X')==1){
                result=1;
            }
            if(panduan('X')==2){
                result=2;
            }

            ai();
            x=ai1;y=ai2;

            a[x][y]='O';

            if(panduan('O')==1){
                result=0;
            }
            if(panduan('O')==2){
                result=2;
            }
    }

    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            a[i][j]=aa[i][j];
            b[i][j]=bb[i][j];
        }
    }

    return result;
}

int newai()
{
    int max=0,m,n;

    ai1=0;ai2=0;
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            b[i][j]=0;
        }
    }

    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(a[i][j]==' '){
                point(b[i][j],i,j,0,0,0);       
            }
        }
    }
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            if(b[i][j]>max&&a[i][j]==' '){
                max=b[i][j];
                ai1=i;
                ai2=j;
            }
            else if(b[i][j]==max&&a[i][j]==' '){
                if(Random(0,2)==1)
                {
                    max=b[i][j];
                    ai1=i;
                    ai2=j;
                }

            }
        }

    }
}

int main(){ 
    srand( (unsigned)time( NULL ) );
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);

    int x=8,y=8,caidan=0;

    system("Color A");

    for(int i=1;i<MAX_SIZE;i++){
        for(int j=1;j<MAX_SIZE;j++){
            a[i][j]=' ';
        }
    }//初始化 

    qipan(0,0,0);
    gotoqp(x,y);
    while(1){
        //x:
            gotoqp(1,MAX_SIZE);
            cout<<endl<<"请按方向键控制光标位置，按空格键确定下棋"<<endl<<"作者：杨千睿"<<endl;
            gotoqp(y,x);
            int ch;
            ch=getch();

            if(ch==224) 
                ch=getch();

            while (ch!=32)
            {
                if(ch==75)//left 
                {
                    if(y>1)y--;             
                    gotoqp(y,x);
                }
                if(ch==77)//right
                {
                    if(y<MAX_SIZE-1)y++;
                    gotoqp(y,x);
                }
                if(ch==72)//up
                {
                    if(x>1)x--;
                    gotoqp(y,x);

                }
                if(ch==80)//down
                {
                    if(x<MAX_SIZE-1)x++;
                    gotoqp(y,x);

                }
                ch=getch();
                if(ch==224) 
                    ch=getch();
            }

            /*ai();
            x=ai1;y=ai2;*/
            if(a[x][y]!=' '||x>MAX_SIZE||x<1||y>MAX_SIZE||y<1){
                caidan++;
                if(caidan==5){
                    gotoqp(1,MAX_SIZE);
                    cout<<"这里有棋，别点了"<<endl; 
                    gotoqp(y,x);
                }
                continue;
            }
            else{
                caidan=0;
                a[x][y]='X';
                gotoqp(y,x);
                cout<<a[x][y];
                gotoqp(y,x);

            }

            if(panduan('X')==1){
                gotoqp(1,MAX_SIZE);
                cout<<endl<<endl<<endl<<"您赢了"<<endl;
                flag1=1;
                break;
            }
            if(panduan('X')==2){
                gotoqp(1,MAX_SIZE);
                cout<<endl<<endl<<endl<<"平局"<<endl;
                flag1=1;
                break;
            }

        o:  
            ai();
            x=ai1;y=ai2;
            if(a[x][y]!=' '||x>MAX_SIZE||x<1||y>MAX_SIZE||y<1){
                goto o;
            }
            else{
                a[x][y]='O';
                gotoqp(y,x);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
                cout<<a[x][y];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
                gotoqp(y,x);
            }

            if(panduan('O')==1){
                gotoqp(1,MAX_SIZE);
                cout<<endl<<endl<<endl<<"电脑赢了"<<endl;
                flag1=1;
                break;
            }
            if(panduan('O')==2){
                gotoqp(1,MAX_SIZE);
                cout<<endl<<endl<<endl<<"平局"<<endl;
                flag1=1;
                break;
            }
    }
    system("pause");
    return 0;
}
