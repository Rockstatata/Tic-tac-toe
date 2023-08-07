#include <stdio.h>
#include <stdlib.h>


void playername();
void makeboard(char name1[15],char name2[15]);
void board(char name1[15],char name2[15]);
void inputboard(char name1[15],char name2[15], char index[10]);
int checkforwin(char name1[15],char name2[15],char index[10]);
void drawboard(char index[10]);

int main(){
    system("cls");
    printf(" Welcome to the game of TIC TAC TOE");
    playername();

    return 0;
}


































void playername(void){
    char name1[15], name2[15];
    printf("\n"); printf("\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", &name1);
    printf("\n");
    printf("Player 2, please enter your name: ");
    scanf("%s", &name2);
    printf("\n");
    printf("Welcome %s and %s to this game. Have fun & make sure to get a treat from the one who loses :)", name1, name2);
    printf("\n");
    printf("\n");
    makeboard(name1,name2);
}

void makeboard(char name1[15],char name2[15]){
    printf("       TIC TAC TOE\n");
    printf("\n");
    printf("%s (X)  -  %s (O)", name1, name2);
    printf("\n");
    printf("\n");
    
    board(name1,name2);
    printf("\n");
}

void board(char name1[15],char name2[15]){
    char index[10] ={'0','1','2','3','4','5','6','7','8','9'};

    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[1], index[2], index[3]);
    printf("    _____|_____|_____\n");
    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[4], index[5], index[6]);
    printf("    _____|_____|_____\n");
    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[7], index[8], index[9]);
    printf("         |     |     \n");
    printf("\n");
    inputboard(name1,name2,index);
}

void inputboard(char name1[15],char name2[15], char index[10]){
    int num,T=1,i = 1,result;
    A:
        if(T % 2 != 0){
            C:
            printf("%s, enter a number: ", name1);
            scanf("%d", &num);
            for(i = 1;i<10;i++){
                if(i == num){
                    if(index[i] != 'X' && index[i] != 'O'){
                        index[i] = 'X';
                        drawboard(index);
                        result = checkforwin(name1,name2,index);
                        if(result != 9){
                            goto B;
                        }
                    T++;
                    }
                    else if(index[i] == 'X' || index[i] == 'O'){
                        printf("\nInvalid move.\n");
                        goto C;
                    }
                }
            }
        }
        if(T % 2 == 0 && T < 10){
            D:
            printf("%s, enter a number: ", name2);
            scanf("%d", &num);
            for(i = 1;i<10;i++){
                if(i == num){
                    if(index[i] != 'X' && index[i] != 'O'){
                        index[i] = 'O';
                        drawboard(index);
                        result = checkforwin(name1,name2,index);
                        if(result != 9){
                            goto B;
                        }
                    T++;
                    goto A;
                    }
                    else if(index[i] == 'X' || index[i] == 'O'){
                        printf("\nInvalid move.\n\n");
                        goto D;
                    }
                }
            }
        }

        if(T>9){
            printf("\nThe game has been finished by draw!!!\n");
        }

        B:
        printf("\n        THE END!\n");   
}

void drawboard(char index[10]){
    printf("\n");
    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[1], index[2], index[3]);
    printf("    _____|_____|_____\n");
    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[4], index[5], index[6]);
    printf("    _____|_____|_____\n");
    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c  \n",index[7], index[8], index[9]);
    printf("         |     |     \n");
    printf("\n");

}

int checkforwin(char name1[15],char name2[15],char index[10]){
    int i;
    for(i = 1;i<=8;){
        while(i == 1){
            if(index[1] == index[2] && index[2] == index[3]){
                if(index[1] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[1] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }

        while(i == 2){
            if(index[4] == index[5] && index[5] == index[6]){
                if(index[4] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[4] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }

        while(i == 3){
            if(index[7] == index[8] && index[8] == index[9]){
                if(index[7] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[7] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }
        
        while(i == 4){
            if(index[3] == index[5] && index[5] == index[7]){
                if(index[3] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[3] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }

        while(i == 5){
            if(index[1] == index[4] && index[4] == index[7]){
                if(index[1] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[1] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }

        while(i == 6){
            if(index[2] == index[5] && index[5] == index[8]){
                if(index[2] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[2] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;  
            }
            i++;
        }

        while(i == 7){
            if(index[3] == index[6] && index[6] == index[9]){
                if(index[3] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[3] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;  
            }
            i++;
        }

        while(i == 8){
            if(index[1] == index[5] && index[5] == index[9]){
                if(index[1] == 'X'){
                    printf("%s has won the match!!!\n", name1);
                }
                else if(index[1] =='O'){
                    printf("%s has won the match!!!\n", name2);
                }
                break;   
            }
            i++;
        }
        return i;              
    }
}


