#include <iostream>
#include<cstdlib>
#define p2 'O'
#define p1 'X'
/*
 ___ ___ ___
|   |   |   |
| 1 | 2 | 3 |
|___|___|___|
|   |   |   |
| 4 | 5 | 6 |
|___|___|___|
|   |   |   |
| 7 | 8 | 9 |
|___|___|___|

*/

using namespace std;
/** Global Variable */
char Square_num[10]={'0','1','2','3','4','5','6','7','8','9'};

/** Drawing the Game Board */
void GameBoard()
{

    system("cls");
    cout<<"\n\n\t\tTic Tac Toe\n\n";
    cout<<"\tPlayer 1 ("<<p1<<") vs Player 2 ("<<p2<<") \n\n";
    int k=1;
    cout<<"\t\t ___ ___ ___ \n";
    for(int i=0;i<3;i++)
    {
        cout<<"\t\t|   |   |   |\n";
        cout<<"\t\t| "<<Square_num[k]<<" | "<<Square_num[k+1]<<" | "<<Square_num[k+2]<<" |"<<endl;
        cout<<"\t\t|___|___|___|\n";
        k+=3;
    }

}
/** To check the consquence of the Move whether it's a Win Move or a Mere Move or a Stalemate */

int Check_Move()
{
    if(Square_num[1]==Square_num[2]&&Square_num[2]==Square_num[3]) { return 1; }

    else if(Square_num[4]==Square_num[5]&&Square_num[5]==Square_num[6]) { return 1; }

    else if(Square_num[7]==Square_num[8]&&Square_num[8]==Square_num[9]) { return 1; }

    else if(Square_num[1]==Square_num[4]&&Square_num[4]==Square_num[7]) { return 1; }

    else if(Square_num[2]==Square_num[5]&&Square_num[5]==Square_num[8]) { return 1; }

    else if(Square_num[3]==Square_num[6]&&Square_num[6]==Square_num[9]) { return 1; }

    else if(Square_num[1]==Square_num[5]&&Square_num[5]==Square_num[9]) { return 1; }

    else if(Square_num[3]==Square_num[5]&&Square_num[5]==Square_num[7]) { return 1; }

    else if(Square_num[1]!='1'&&Square_num[2]!='2'&&Square_num[3]!='3'&&Square_num[4]!='4'&&Square_num[5]!='5'&&
            Square_num[6]!='6'&&Square_num[7]!='7'&&Square_num[8]!='8'&&Square_num[9]!='9'){ return 2;}

    else{ return 0;}
}


/**The Main Function Code */


int main()
{
    /***/
    int move_counter=0,Game_goes_on,End_of_Game;
    char input_move,player_move;
    do
    {
        GameBoard();
        cout<<"\n\t\tPlayer";
        if(move_counter%2==0) { cout<<"1 turn : "; }
        else if(move_counter%2!=0) { cout<<"2 turn : "; }
        cin>>input_move;
        move_counter++;
        player_move=(move_counter%2==0) ? p2:p1;
        for(int i=1;i<10;i++)
        {
           if(input_move==Square_num[i]){ Square_num[i]=player_move; }
        }

        Game_goes_on=Check_Move();
        End_of_Game=Check_Move();


    }while(Game_goes_on==0);
    //cout<<Check_Move()<<endl;

    if(End_of_Game==2)
    {
        GameBoard();
        cout<<"\n\t\tIt's a tie ! \n\t\tHard Luck"<<endl;
    }
    else
    {
        if(move_counter%2==0)
        {
            GameBoard();
            cout<<"\n\t\tPlayer 2 wins !"<<endl;
        }
        else
        {
            GameBoard();
            cout<<"\n\t\tPlayer 1 wins !"<<endl;
        }
        cout<<"\n\t\tCongratzz ^_^ "<<endl;
    }

   return 0;
}

//Customizable GameBoard

/*
void GameBoard_Manual()
{
    system("cls");
    cout<<"\n\n\tTic Tac Toe Egyptian Style\n\n";
    cout<<"\tPlayer 1 (X) vs Player 2 (O) \n\n";
    int k=1;
    for(int i=0;i<10;i++)
    {
        if(i==0){ cout<<"\t\t ___ ___ ___ "<<endl;}
        else
        {
            for(int j=0;j<10;j++)
            {
                if(j==0) { cout<<"\t\t|"; }
                else
                {
                    if(i==1||i==4||i==7)
                    {
                        for(int c=0;c<3;c++){ cout<<"   |" ;}
                        cout<<endl;
                        break;
                    }
                    else if(i==2||i==5||i==8)
                    {
                        for(int c=0;c<3;c++)
                        {
                            cout<<" "<<Square_num[k]<<" "<<"|";
                            k++;
                        }
                        cout<<endl;
                        break;
                    }
                    else if(i==3||i==6||i==9)
                    {
                        for(int c=0;c<3;c++){ cout<<"___|"; }
                        cout<<endl;
                        break;
                    }

                }
            }
        }
    }
}
*/
