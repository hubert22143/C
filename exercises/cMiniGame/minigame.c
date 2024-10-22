#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Player{
    char* PlayerName;
    char* PlayerVocation;
    int PlayerLevel;
};

struct Vocations{
    char* vocationList[4];
};
struct Weapons{
    char* Rod;
    char* Bow;
    char* Sword;
    char* Axe;
    char* Hammer;
};
struct BeginningLocation{
    char* Thais;
    char* Venore;
    char* Kazordoon;
    char* Carlin;
};
struct Player startGame(){
    struct Player player;
    struct Vocations vocation;
    vocation.vocationList[0] = "Paladin";
    vocation.vocationList[1] = "Sorcerer";
    vocation.vocationList[2] = "Druid";
    vocation.vocationList[3] = "Knight";
    
    player.PlayerName = malloc(50 * sizeof(char));
    player.PlayerVocation = malloc(50 * sizeof(char)); 
    int beginGame;
    int beginValue = 1;
    int isSelectedCharValid = 0;
    printf("Welcome in text-based Tibia! Are you ready to start the game? Type 1 for yes 0 for quit\n");
    scanf("%d",&beginGame);
    if(beginGame == beginValue){
        printf("Welcome in the game! For beginning, please type your nickname:\n");
        scanf("%s",player.PlayerName);
        printf("Welcome %s you have four vocations to select, those are Paladin, Sorcerer, Druid, Knight please type your choose!\n",player.PlayerName);
        scanf("%s",player.PlayerVocation);
        for(int i = 0; i<4 ; i++){
            printf("%d loop made ",i);
            printf("%s is your chosen character\n",player.PlayerVocation);
            printf("%s is the comparing value\n",vocation.vocationList[i]);
            if(strcmp(player.PlayerVocation,vocation.vocationList[i]) == 0){
                printf("You've selected %s \n", player.PlayerVocation);
                isSelectedCharValid = 1;
                break;
            }
        }
        if(!isSelectedCharValid){
            printf("Invalid character selected, begin the game from beginning in order to play\n");
            free(player.PlayerName);
            free(player.PlayerVocation);
            return (struct Player){NULL,NULL,0};
        }
        printf("Well well. lets continue our journey....\n");
        return player;
    } 
    else{
        printf("Thank you for passing by! Have a nice day.\n");
        free(player.PlayerName);
        free(player.PlayerVocation);
        return (struct Player){NULL,NULL,0};
    }
}
int main(){
    startGame();
}