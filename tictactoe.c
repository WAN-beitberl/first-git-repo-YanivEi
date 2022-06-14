#include <stdio.h>

void win(int player, int winner, int pos[]){
    printf("\n");
    printf("%c|%c|%c\n", pos[0],pos[1],pos[2]);
    printf("-----\n");
    printf("%c|%c|%c\n", pos[3],pos[4],pos[5]);
    printf("-----\n");
    printf("%c|%c|%c\n", pos[6],pos[7],pos[8]);
    if(winner==1){
        printf("Player %d is the winner!\n", player);
    }
    else{
        printf("Draw!\n");
    }
}
//WOAAAAHH THIS TEXT IS DIFFERENT

int main(){
    int winner = 0; //bool
    int count = 0;
    int pos[9];
    int ID;
    int sign;
    int player;
    int flag;
    int i;
    int k;

    printf("Welcome to tic tac toe! (very original)\nhere is the board, good luck:");
    printf("\n");
    printf("1|2|3\n");
    printf("-----\n");
    printf("4|5|6\n");
    printf("-----\n");
    printf("7|8|9\n");

    for (i=0; i<9; i++){
        pos[i] = ' ';
    }

    while(count < 9 && winner == 0){
        flag = 0;
        printf("\n");
        printf("%c|%c|%c\n", pos[0],pos[1],pos[2]);
        printf("-----\n");
        printf("%c|%c|%c\n", pos[3],pos[4],pos[5]);
        printf("-----\n");
        printf("%c|%c|%c\n", pos[6],pos[7],pos[8]);

        if (count % 2 == 0){
            sign = 'X';
            player = 1;
        }
        else{
            sign = 'O';
            player = 2;
        }

        printf("Move for player %d(1-9)", player);
        scanf("%d", &ID);
        if(ID<1 || ID>9){
            printf("Invalid Number, Allowed index is 1 to 9!\n");
            continue;
        }
        if(pos[ID-1] == 'X' || pos[ID-1] == 'O'){
            printf("Position is occupied!\n");
            continue;
        }

        pos[ID-1] = sign;
        count++;

        for(i=0; i<9; i++){
            if(i%3==0){
                flag = 0;
            }
            if(pos[i] == sign){
                flag++;
            }
            if(flag==3){
                winner = 1;
                win(player, winner, pos);
            }
        }

        flag = 0;

        for(i=0; i<3; i++){
            for(k=i; k<=i + 6; k +=3){
                if(pos[k] == sign){
                    flag++;
                }
            }

            if(flag==3){
                winner = 1;
                win(player, winner, pos);
            }
             flag = 0;
        }

       
        if((pos[0] == sign && pos[4] == sign && pos[8] == sign) || (pos[2] == sign && pos[4] == sign && pos[6] == sign)){
            winner = 1;
            win(player, winner, pos);
        }
    }
}

