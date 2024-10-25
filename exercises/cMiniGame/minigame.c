#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Player{
    char* PlayerName;
    char* PlayerVocation;

    int PlayerLevel;
};
struct PlayerEquipment{
    char* playerWeapon;
    char* playerHelmet;
    char* playerArmor;
    char* playerLegs;
    char* playerBoots;

    char* playerRing;
    char* playerBackpack[10];
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
void printPlayerInfo(struct Player* player)
{
    printf("Name: %s\n",player->PlayerName);
    printf("Vocation: %s\n",player->PlayerVocation);
    printf("Current level: %d\n",player->PlayerLevel);
};
void printPlayerEquipment(struct PlayerEquipment* equipment){
    char* equipmentContainer[] = {
        equipment->playerWeapon,
        equipment->playerHelmet,
        equipment->playerArmor,
        equipment->playerLegs,
        equipment->playerBoots,
        equipment->playerRing
    };
        const char* equipmentLabels[] = {
        "Weapon",
        "Helmet",
        "Armor",
        "Legs",
        "Boots",
        "Ring"
    };
    for (int i = 0; i < sizeof(equipmentContainer)/sizeof(equipmentContainer[0]); i++)
    {
        printf("%s: %s\n",equipmentLabels[i],equipmentContainer[i]);
    }
    

}
void printPlayerBackpack(struct PlayerEquipment* equipment) {
    //will be implemented as the minigame expand
};

void freeAnyTakenMemory(struct PlayerEquipment* equipment,struct Player* player){
free(player->PlayerName);
free(player->PlayerVocation);


free(equipment->playerWeapon);

printf("Memory: MASLO !!!");


free(equipment->playerHelmet);
free(equipment->playerArmor);
free(equipment->playerLegs);
free(equipment->playerBoots);
free(equipment->playerRing);


}

int InitializeAvailableMemory(struct PlayerEquipment* equipment,struct Player *player){
    player->PlayerVocation = malloc(20 * sizeof(char));
    player->PlayerName = malloc(16 * sizeof(char));

    equipment->playerWeapon = malloc(30 * sizeof(char));
    equipment->playerHelmet = malloc(30 * sizeof(char));
    equipment->playerArmor= malloc(30 * sizeof(char));
    equipment->playerLegs= malloc(30 * sizeof(char));
    equipment->playerBoots = malloc(30 * sizeof(char));
    equipment->playerRing = malloc(30 * sizeof(char));
    if (!equipment->playerWeapon || !equipment->playerHelmet || 
        !equipment->playerArmor || !equipment->playerLegs || 
        !equipment->playerBoots || !equipment->playerRing ||
        !player->PlayerVocation || !player->PlayerName) {
        printf("Memory allocation failed \n");
        return 0;
    };
    return 1;
};

void initializeBeginningEquipment(char* chosenCharacter,struct PlayerEquipment* equipment){
    char* characterList[4] = {"Paladin","Sorcerer","Druid","Knight"};
    for (int i = 0; i < sizeof(characterList)/sizeof(characterList[0]); i++)
    {
        if (strcmp(chosenCharacter,characterList[i])==0)
        {
            sprintf(equipment->playerHelmet,"%s helmet",chosenCharacter);
            sprintf(equipment->playerArmor,"%s Armor",chosenCharacter);
            sprintf(equipment->playerLegs,"%s Legs",chosenCharacter);
            sprintf(equipment->playerBoots,"%s Boots",chosenCharacter);
        }
        
    }
    
};

int initializePlayer(struct PlayerEquipment* equipment,struct Player* player) {
    InitializeAvailableMemory(equipment,player);
    player->PlayerLevel = 1;
    printf("Welcome in the game! As for beginning, please type your nickname (15 character maximum!):\n");
    scanf("%s", player->PlayerName);

    if (strlen(player->PlayerName) > 15) {
        printf("You're not allowed to have that long character!\n");
        //freeAnyTakenMemory(equipment,player);
        return 0;
        
    }
        return 1;
}

int selectVocation(struct Player* player, struct Weapons* weapon, struct Vocations* vocation, struct PlayerEquipment* equipment) {
    
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

    for (int i = 0; i < 4; i++) {
        if (strcmp(player->PlayerVocation, vocation->vocationList[i]) == 0) {
            initializeBeginningEquipment(player->PlayerVocation,equipment);
            switch (i) {
                case 0: uniqueWeapon = weapon->Bow; break;
                case 1: uniqueWeapon = weapon->Wand; break;
                case 2: uniqueWeapon = weapon->Rod; break;
                case 3:
                    printf("The knight vocation has three weapon choices: %s, %s, %s. Choose by typing 's', 'a', or 'h':\n", weapon->Sword, weapon->Axe, weapon->Hammer);
                    char tempWeaponChoice;
                    scanf(" %c", &tempWeaponChoice);
                    switch (tempWeaponChoice) {
                        case 's': uniqueWeapon = weapon->Sword; break;
                        case 'a': uniqueWeapon = weapon->Axe; break;
                        case 'h': uniqueWeapon = weapon->Hammer; break;
                        default:
                            printf("Invalid weapon selection!\n");
                            return 0;
                    }
                    break;
            }

            if (uniqueWeapon != NULL) {
                printf("You've selected %s.\n", player->PlayerVocation);
                printf("Your unique weapon is: %s.\n", uniqueWeapon);
                strcpy(equipment->playerWeapon,uniqueWeapon);
                return 1;
            }
        }
    }   
    printf("Invalid character selected. Restart the game in order to play again.");
    return 0;
}
void playerMenu(struct Player* player,struct PlayerEquipment* equipment){
    char temp[3];
    do
    {
    printf("Before your adventure begin, feel free to check your !s (status), !e (equipment), !b (backpack), or type !c to proceed further! \n");
    scanf("%s",temp);
    if(strcmp(temp,"!s") == 0){
        printPlayerInfo(player);
    }else if (strcmp(temp,"!e") == 0){
        printPlayerEquipment(equipment);
    }
    if (!(strcmp(temp, "!c") == 0 || strcmp(temp,"!s") == 0 || strcmp(temp,"!e") ==0 || strcmp(temp,"!b") ==0)) {
            printf("You've misstyped the command you baka... don't worry there's another chance to enter it properly :) \n\n");
        }

    } while (strcmp(temp,"!c")!=0);
}
int main(){
    struct PlayerEquipment equipment;
    struct Player player;
    struct Weapons weapon;
    struct Vocations vocation;
    if(initializePlayer(&equipment,&player)){
     if(selectVocation(&player,&weapon,&vocation,&equipment)){
       playerMenu(&player,&equipment);
     }
    }
    freeAnyTakenMemory(&equipment,&player);
    return 0;
}