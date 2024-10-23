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
    char* Wand;
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
struct BegginningEquipment{
    char* PaladinSet[4];
    char* SorcererSet[4];
    char* DruidSet[4];
    char* KnightSet[4];
};
struct Player initializePlayer() {
    struct Player player;
    player.PlayerName = malloc(16 * sizeof(char));
    player.PlayerLevel = 1;

    printf("Welcome in the game! As for beginning, please type your nickname (15 character maximum!):\n");
    scanf("%15s", player.PlayerName);

    if (strlen(player.PlayerName) > 15) {
        printf("You're not allowed to have that long character!\n");
        free(player.PlayerName);
        player.PlayerName = NULL;
        return player;
    }

    player.PlayerVocation = malloc(20 * sizeof(char));
    return player;
}
void selectVocation(struct Player* player, struct Weapons* weapon, struct Vocations* vocation) {
    vocation->vocationList[0] = "Paladin";
    vocation->vocationList[1] = "Sorcerer";
    vocation->vocationList[2] = "Druid";
    vocation->vocationList[3] = "Knight";

    weapon->Rod = "Rod";
    weapon->Wand = "Wand";
    weapon->Bow = "Bow";
    weapon->Sword = "Sword";
    weapon->Axe = "Axe";
    weapon->Hammer = "Hammer";

    char* uniqueWeapon = NULL;

    printf("Welcome %s! You have four vocations to select: Paladin, Sorcerer, Druid, Knight. Please type your choice:\n", player->PlayerName);
    scanf("%19s", player->PlayerVocation);

    int isSelectedCharValid = 0;
    for (int i = 0; i < 4; i++) {
        if (strcmp(player->PlayerVocation, vocation->vocationList[i]) == 0) {
            switch (i) {
                case 0:
                    uniqueWeapon = weapon->Bow;
                    break;
                case 1: 
                    uniqueWeapon = weapon->Wand;
                    break;
                case 2:
                    uniqueWeapon = weapon->Rod;
                    break;
                case 3:
                    printf("The knight vocation has three weapon choices: %s, %s, %s. Choose by typing 's', 'a', or 'h':\n", weapon->Sword, weapon->Axe, weapon->Hammer);
                    char tempWeaponChoice;
                    scanf(" %c", &tempWeaponChoice);
                    switch (tempWeaponChoice) {
                        case 's':
                            uniqueWeapon = weapon->Sword;
                            break;
                        case 'a':
                            uniqueWeapon = weapon->Axe;
                            break;
                        case 'h':
                            uniqueWeapon = weapon->Hammer;
                            break;
                        default:
                            printf("Invalid weapon selection!\n");
                            return;
                    }
                    break;
            }

            if (uniqueWeapon != NULL) {
                printf("You've selected %s.\n", player->PlayerVocation);
                printf("Your unique weapon is: %s.\n", uniqueWeapon);
                isSelectedCharValid = 1;
            }
            break;
        }
    }

    if (!isSelectedCharValid) {
        printf("Invalid character selected. Please restart the game to play.\n");
        free(player->PlayerName);
        free(player->PlayerVocation);
        return;
    }

    printf("Well, let's continue our journey...\n");
}
int main(){
    struct Player player = initializePlayer();
    struct Weapons weapon;
    struct Vocations vocation;
    selectVocation(&player,&weapon,&vocation);

    free(player.PlayerName);
    free(player.PlayerVocation);
}