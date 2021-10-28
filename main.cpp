#include <bits/stdc++.h>
#define ll long long
using namespace std;
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);
}
char square[3][3] = {'1','2','3','4','5','6','7','8','9'},player = 'X';
int counter =0,in;
void board()
{
         cout<<endl<<"-------------------------------------"<<endl;

    for(int i=0;i<3;++i)
      {
         cout<<'|';
         for(int j=0;j<3;++j)
           {
            cout<<setw(6)<<square[i][j]<<setw(6)<<'|';
           }
         cout<<endl<<"-------------------------------------"<<endl;
      }

}
bool valid(int in)
{
    if (in==1&&square[0][0]-'0'!=1)
        return false;
    if (in==2&&square[0][1]-'0'!=2)
        return false;
    if (in==3&&square[0][2]-'0'!=3)
        return false;
    if (in==4&&square[1][0]-'0'!=4)
        return false;
    if (in==5&&square[1][1]-'0'!=5)
        return false;
    if (in==6&&square[1][2]-'0'!=6)
        return false;
    if (in==7&&square[2][0]-'0'!=7)
        return false;
    if (in==8&&square[2][1]-'0'!=8)
        return false;
    if (in==9&&square[2][2]-'0'!=9)
        return false;
    return true;
}
void input(int in)
{
     if (in==1)
        square[0][0]=player;
     else if (in==2)
        square[0][1]=player;
     else if (in==3)
        square[0][2]=player;
     else if (in==4)
        square[1][0]=player;
     else if (in==5)
        square[1][1]=player;
     else if (in==6)
        square[1][2]=player;
     else if (in==7)
        square[2][0]=player;
     else if (in==8)
        square[2][1]=player;
     else if (in==9)
        square[2][2]=player;
}
void YourTurn ()
{
    (player=='X')? player = 'O' : player = 'X';
}
bool winner()
{
    if (square[0][0]==square[0][1]&&square[0][1]==square[0][2])
        return 1;
    if (square[1][0]==square[1][1]&&square[1][1]==square[1][2])
        return 1;
    if (square[2][0]==square[2][1]&&square[2][1]==square[2][2])
        return 1;
    if (square[0][0]==square[1][0]&&square[1][0]==square[2][0])
        return 1;
    if (square[0][1]==square[1][1]&&square[1][1]==square[2][1])
        return 1;
    if (square[0][2]==square[1][2]&&square[1][2]==square[2][2])
        return 1;
    if (square[0][0]==square[1][1]&&square[0][0]==square[2][2])
        return 1;
    if (square[0][2]==square[1][1]&&square[1][1]==square[2][0])
        return 1;
    return 0;

}
int main ()
{
    fast();
    board();
    cout<<"    Player 1 (X) : Player 2 (O) "<<endl<<endl;
    while(true)
    {
        counter ++;
        cout<<"It is "<<player<<"'s turn"<<endl;
        cin>>in;
        while(!valid(in))
        {
            cout<<"Enter a number hasn't been entered before"<<endl;
            cin>>in;
        }
        input(in);
        if(winner())
            {
               board();
               cout<<player<<" wins "<<endl;
               return 0;
            }
        if(counter==9&&!winner())
            {
               board();
               cout << "        Draw       "<<endl;
               return 0;
            }
        YourTurn();
        board();
    }
}
