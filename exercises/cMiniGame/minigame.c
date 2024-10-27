#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player{

    char* Name;
    char* Vocation;
    int Level;
};
struct ItemType{
    char* assignCategory;
    char* assignRarity;
};
struct Item{
    char* name;
    char* itemAttributes[5];
    struct ItemType* type;
};
struct Backpack{
    char* Name;
    struct Item Items[10];
    };
struct PlayerEquipment{
    char* Weapon;
    char* Helmet;
    char* Armor;
    char* Legs;
    char* Boots;
    char* Ring;

    struct Backpack backpack;
};

struct Vocations{
    char* available[4];
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
    printf("Name: %s\n",player->Name);
    printf("Vocation: %s\n",player->Vocation);
    printf("Current level: %d\n",player->Level);
};
void initializeBackpack(struct Backpack* backpack,const char* name){
    backpack->Name = strdup(name);
}
int traverseInputToDigit(char* string) {
    int num = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            num = num * 10 + (string[i] - '0');
        } else {
            break;
        }
    }
    return num;
}

void printPlayerEquipment(struct PlayerEquipment* equipment){
    char* equipmentContainer[] = {
        equipment->Weapon,
        equipment->Helmet,
        equipment->Armor,
        equipment->Legs,
        equipment->Boots,
        equipment->Ring
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
for(int i = 0; i < 10; i++){
    if(equipment->backpack.Items[i].name == NULL){
        printf("%d : your slot is empty\n",i + 1);
    }else{
        printf("%d : %s",i+1,equipment->backpack.Items[i].name);
    }
}   
};
void interractWithBackpack(struct PlayerEquipment* equipment)
{
        printf("Type corresponding number index in order to interact with item or type !e to exit \n");
    char temp[10];
    scanf("%s",temp);
    while (strcmp(temp,"!e") != 0)
    {
        int index = traverseInputToDigit(temp);
        if(index >= 1 && index <=10){
          if(equipment->backpack.Items[index - 1].name != NULL){
            printf("Interracting with item: %d\n",index);
          }else{
            printf("Slot %d is empty\n",index);
          }
        }else{
            printf("Invalid index, enter a valid number between 1 and 10\n");
        }
        
    }
};


void freeAnyTakenMemory(struct PlayerEquipment* equipment,struct Player* player){
free(player->Name);
free(player->Vocation);

free(equipment->Weapon);
free(equipment->Helmet);
free(equipment->Armor);
free(equipment->Legs);
free(equipment->Boots);
free(equipment->Ring);
}
void preventDanglingPointers(struct PlayerEquipment* equipment,struct Player* player){
    equipment->Armor = NULL;
    equipment->Boots = NULL;
    equipment->Helmet = NULL;
    equipment->Ring = NULL;
    equipment->Legs = NULL;
    equipment->Weapon = NULL;
    equipment->backpack.Name = NULL;

    for (int i = 0; i < 10; i++) {
        equipment->backpack.Items[i].name = NULL;
        equipment->backpack.Items[i].type = NULL;
        for (int j = 0; j < 5; j++) {
            equipment->backpack.Items[i].itemAttributes[j] = NULL;
        }
    }
    player->Name = NULL;
    player->Vocation = NULL;
}
int InitializeAvailableMemory(struct PlayerEquipment* equipment,struct Player *player){
    player->Vocation = malloc(20 * sizeof(char));
    player->Name = malloc(16 * sizeof(char));

    equipment->Weapon = malloc(30 * sizeof(char));
    equipment->Helmet = malloc(30 * sizeof(char));
    equipment->Armor= malloc(30 * sizeof(char));
    equipment->Legs= malloc(30 * sizeof(char));
    equipment->Boots = malloc(30 * sizeof(char));
    equipment->Ring = malloc(30 * sizeof(char));

    for (int i = 0; i < 10; i++) {
    equipment->backpack.Items[i].name = malloc(30 * sizeof(char));
    equipment->backpack.Items[i].type = malloc(sizeof(struct ItemType));
    }

    if (!equipment->Weapon || !equipment->Helmet || 
        !equipment->Armor || !equipment->Legs || 
        !equipment->Boots || !equipment->Ring ||
        !player->Vocation || !player->Name) {
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
            sprintf(equipment->Helmet,"%s helmet",chosenCharacter);
            sprintf(equipment->Armor,"%s Armor",chosenCharacter);
            sprintf(equipment->Legs,"%s Legs",chosenCharacter);
            sprintf(equipment->Boots,"%s Boots",chosenCharacter);
        }
        
    }
    
};

int initializePlayer(struct PlayerEquipment* equipment,struct Player* player) {
    InitializeAvailableMemory(equipment,player);
    player->Level = 1;
    printf("Welcome in the game! As for beginning, please type your nickname (15 character maximum!):\n");
    scanf("%s", player->Name);

    if (strlen(player->Name) > 15) {
        printf("You're not allowed to have that long character!\n");
        //freeAnyTakenMemory(equipment,player);
        return 0;
        
    }
        return 1;
}

int selectVocation(struct Player* player, struct Weapons* weapon, struct Vocations* vocation, struct PlayerEquipment* equipment) {
    
    vocation->available[0] = "Paladin";
    vocation->available[1] = "Sorcerer";
    vocation->available[2] = "Druid";
    vocation->available[3] = "Knight";

    weapon->Rod = "Rod";
    weapon->Wand = "Wand";
    weapon->Bow = "Bow";
    weapon->Sword = "Sword";
    weapon->Axe = "Axe";
    weapon->Hammer = "Hammer";

    char* uniqueWeapon = NULL;

    printf("Welcome %s! You have four vocations to select: Paladin, Sorcerer, Druid, Knight. Please type your choice:\n", player->Name);
    scanf("%19s", player->Vocation);

    for (int i = 0; i < 4; i++) {
        if (strcmp(player->Vocation, vocation->available[i]) == 0) {
            initializeBeginningEquipment(player->Vocation,equipment);
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
                printf("You've selected %s.\n", player->Vocation);
                printf("Your unique weapon is: %s.\n", uniqueWeapon);
                strcpy(equipment->Weapon,uniqueWeapon);
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
    }else if(strcmp(temp,"!b") == 0){
        printPlayerBackpack(equipment);
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
    initializeBackpack(&equipment.backpack,"Adventurer's Bag");
    if(initializePlayer(&equipment,&player)){
     if(selectVocation(&player,&weapon,&vocation,&equipment)){
       playerMenu(&player,&equipment);
     }
    }
    freeAnyTakenMemory(&equipment,&player);
    preventDanglingPointers(&equipment,&player);
    return 0;
}