#include<iostream>
using namespace std;

char space[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie;
string s1="";
string s2="a";

void intro()
{
    

    cout<<"    |         |   \n ";
    cout<<"  "<<space[0][0]<<"  |   "<<space[0][1]<<"   |  "<<space[0][2]<<"   \n";
    cout<<"___|__________|____\n";
    cout<<"    |         |   \n ";
    cout<<"  "<<space[1][0]<<"  |   "<<space[1][1]<<"   |  "<<space[1][2]<<"   \n";
    cout<<"___|__________|____\n";
    cout<<"    |         |   \n ";
    cout<<"  "<<space[2][0]<<"  |   "<<space[2][1]<<"   |  "<<space[2][2]<<"   \n";
    cout<<"___|__________|____\n";
}

void dev()
{
    int digit;
    if(token=='x')
    {
        cout<<s1<<" please enter";
        cin>>digit;
    }
    if(token=='0')
    {
        cout<<s2<<" please enter";
        cin>>digit;
    }
    if(digit==1)
    {
        row=0;
        column=0;
    }
    if(digit==2)
    {
        row=0;
        column=1;
    }
    if(digit==3)
    {
        row=0;
        column=2;
    }
    if(digit==4)
    {
        row=1;
        column=0;
    }
    if(digit==5)
    {
        row=1;
        column=1;
    }
    if(digit==6)
    {
        row=1;
        column=2;
    }
    if(digit==7)
    {
        row=2;
        column=0;
    }
    if(digit==8)
    {
        row=2;
        column=1;
    }
    if(digit==9)
    {
        row=2;
        column=2;
    }
    else
    {
        cout<<"Invalid :-("<<endl;
    }
    if(token=='x' && space[row][column]!='x' && space[row][column]!='0')
    {
        space[row][column]='x';
        token='0';
    }
    else if(token=='0' && space[row][column]!='x' && space[row][column]!='0')
    {
        space[row][column]='0';
        token='x';
    }
    else
    {
        cout<<"No empty space!"<<endl;
        dev();
    }
    intro();
}

bool res()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
            return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
        return true;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='0' && space[i][j]!='x')
                return false;
        }
    }
    tie =true;
    
}

int main()
{

    cout<<"Enter player 1 name: \n";
    getline(cin, s1);
    cout<<"Enter player 2 name: \n";
    getline(cin, s2);

    cout<<s1<<" is player 1? play first \n";
    cout<<s2<<" is player 2? play second \n";
    while(!res())
    {
        intro();
        dev();
        res();
    }
    if(token=='x' && tie==false)
      cout<<s2<<" wins ;)"<<endl;

    else if(token=='0'&& tie==false)
      cout<<s1<<" wins ;)"<<endl;

    else
      cout<<"Draw :|"<<endl;
    return 0;
    
}