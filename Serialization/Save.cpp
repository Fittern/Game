//
// Created by denis on 27.12.2021.
//

#include "Save.h"
#include "../Floor/FloorBuilderTree.h"
#include "../Floor/FloorDirector.h"

void Save::SaveG(Floor *floor, int rule1, int rule2, VecOfItem* vecI, VecOfPerson* vecP, const std::string& filename)/*: floor(floor), filename(filename), rule1(rule1), rule2(rule2)*/{
    std::ofstream save_data(filename);
    save_data  << rule1 << "\n" << rule2 << "\n" << vecI->getQuantity() << "\n" << vecP->getQuantity() << "\n" << floor->height <<
                  "\n" << floor->width << "\n" << CHANCE_OF_ENEMY << "\n" << CHANCE_OF_ITEM << "\n" << MIN_SIZE_OF_FLOOR << "\n";
    for (int i = 0; i < vecI->getQuantity(); ++i) {
        save_data << /*"Type_of_item: " << */(int)vecI->items[i]->getItem() << "\n" <<
                 /*"ID: " <<*/ vecI->items[i]->getIdSt() << "\n\n";
    }
    for (int i = 0; i < vecP->getQuantity(); ++i) {
        if (i == 0){
            save_data << /*"Player" << "\n" << "Coord(x_y): " <<*/ vecP->persons[i]->getPosition().x << " " <<
                        vecP->persons[i]->getPosition().y << "\n" << /*"HP: " <<*/ vecP->persons[i]->getHp() << "\n" << /*"MP: " <<*/
                        ((Player*)vecP->persons[i])->mp << "\n" << /*"ATC: " <<*/ ((Player*)vecP->persons[i])->atc << "\n\n";
        } else {
            save_data << /*"Type_of_item: " <<*/ (int)vecP->persons[i]->getType() << "\n" << ((Enemy*)vecP->persons[i])->getIdSt() << "\n" << /*"Coord(x_y): " <<*/
                      vecP->persons[i]->getPosition().x << " " << vecP->persons[i]->getPosition().y << "\n" << /*"HP: " <<*/
                      vecP->persons[i]->getHp() << "\n" << /*"MP: " <<*/ ((Enemy*)vecP->persons[i])->mp << "\n" << /*"ATC: " <<*/
                      ((Enemy*)vecP->persons[i])->atc << "\n\n";
        }
    }
}

enum BeginOfFile{
    RULE1,
    RULE2,
    VECIQ,
    VECPQ,
    H,
    W,
    C_O_E,
    C_O_I,
    M_S_O_F
};

int Save::WriteG(Floor *floor_en, int rule1, int rule2, VecOfItem* vecI, VecOfPerson* vecP, const std::string &filename) {
    std::string const_s[9] /*rule1, rule2, vecIG, vecPQ, H, W, C_O_E, C_O_I, M_S_O_F*/; // буфер промежуточного хранения считываемого из файла текста
    int const_i[9]/*irule1, irule2, ivecIG, ivecPQ, iH, iW, iC_O_E, iC_O_I, iM_S_O_F*/;
    std::ifstream fin(filename); // открыли файл для чтения

    for (int i = 0; i < 9; ++i) fin >> const_s[i];
//    fin >>  >> rule2 >> vecIG >> vecPQ >> H >> W >> C_O_E >> C_O_I >> M_S_O_F; // считали первое слово из файла
    for (int i = 0; i < 9; ++i) {
        try {
            // Wrap up code in try-catch block if string is not validated
            const_i[i] = stoi(const_s[i]);
        }
        catch (std::invalid_argument e) {
            std::cout << "Invalid file\n";
            return 1;
        }
    }

    srand(static_cast<unsigned int>(rule1));
    FloorBuilder* builder;
    MyTexture game_texture;
    builder = new FloorBuilderTree(game_texture);
    auto director = FloorDirector(builder);
    director.Builder_FloorBuilderTree();
    Floor* floor_new = builder->getFloor();
    delete builder;


    if(!(const_i[RULE1] == rule1 && const_i[RULE2] == rule2 && const_i[VECIQ] <= vecI->getQuantity() && const_i[VECPQ] <= vecP->getQuantity() &&
       const_i[H] == floor_new->height && const_i[W] == floor_new->width && const_i[C_O_E] == CHANCE_OF_ENEMY &&
       const_i[C_O_I] == CHANCE_OF_ITEM && const_i[M_S_O_F] == MIN_SIZE_OF_FLOOR)){
        std::cout << "Invalid const\n";
        return 1;
    }
    std::string now_item_s[const_i[VECIQ]][2];
    int now_item_i[const_i[VECIQ]][2];
    for (int i = 0; i < const_i[VECIQ]; ++i) {
        fin >> now_item_s[i][0] >> now_item_s[i][1];
        try {
            // Wrap up code in try-catch block if string is not validated
            now_item_i[i][0] = stoi(now_item_s[i][0]);
            now_item_i[i][1] = stoi(now_item_s[i][1]);
            if(now_item_i[i][0] > 2 || now_item_i[i][0] < 0 || now_item_i[i][1] < 0 || now_item_i[i][1] > vecI->getQuantity()){
                std::cout << "Invalid file\n";
                return 1;
            };
        }
        catch (std::invalid_argument e) {
            std::cout << "Invalid file\n";
            return 1;
        }
    }

    std::string now_per_s[const_i[VECIQ]][7];
    int now_per_i[const_i[VECIQ]][7];
    for (int i = 0; i < 5; ++i) {
        fin >> now_per_s[0][i+2];
    }
    try {
        // Wrap up code in try-catch block if string is not validated
        now_per_i[0][0+2] = stoi(now_per_s[0][0+2]);
        now_per_i[0][1+2] = stoi(now_per_s[0][1+2]);
        now_per_i[0][2+2] = stoi(now_per_s[0][2+2]);
        now_per_i[0][3+2] = stoi(now_per_s[0][3+2]);
        now_per_i[0][4+2] = stoi(now_per_s[0][4+2]);
        if(now_per_i[0][2] <= 1 || now_per_i[0][3] <= 1 || now_per_i[0][4] <= 0 || now_per_i[0][5] <= 0 || now_per_i[0][6] <= 0){
            std::cout << "Invalid file\n";
            return 1;
        };
    }
    catch (std::invalid_argument e) {
        std::cout << "Invalid file\n";
        return 1;
    }
    for (int i = 1; i < const_i[VECIQ]; ++i) {
        fin >> now_per_s[i][0] >> now_per_s[i][1];
        try {
            // Wrap up code in try-catch block if string is not validated
            now_per_i[i][0] = stoi(now_per_s[i][0]);
            now_per_i[i][1] = stoi(now_per_s[i][1]);
            now_per_i[i][0+2] = stoi(now_per_s[i][0+2]);
            now_per_i[i][1+2] = stoi(now_per_s[i][1+2]);
            now_per_i[i][2+2] = stoi(now_per_s[i][2+2]);
            now_per_i[i][3+2] = stoi(now_per_s[i][3+2]);
            now_per_i[i][4+2] = stoi(now_per_s[i][4+2]);
            if(now_per_i[i][0] > 3 || now_per_i[i][0] < 1 || now_per_i[i][1] < 0 || now_per_i[i][1] > vecI->getQuantity() ||
               now_per_i[0][2] <= 1 || now_per_i[0][3] <= 1 || now_per_i[i][4] <= 0 || now_per_i[i][5] <= 0 ||
               now_per_i[i][6] <= 0){
                std::cout << "Invalid file\n";
                return 1;
            };
        }
        catch (std::invalid_argument e) {
            std::cout << "Invalid file\n";
            return 1;
        }
    }

    for (int i = 0; i < vecI->getQuantity();) {
        int flag = 0;
        for (int j = 0; j < const_i[VECIQ]; ++j) {
            if (vecI->items[i]->getIdSt() == now_item_i[j][1]){
                flag = 1;
            }
        }
        if (flag == 0){
            floor_new->cells[vecI->items[i]->getPosition().x][vecI->items[i]->getPosition().y]->setElem(nullptr);
            floor_new->cells[vecI->items[i]->getPosition().x][vecI->items[i]->getPosition().y]->setType(Type::NORMAL);
            vecI->del(i);
        }
    }



    ((Player*)vecP->persons[0])->hp = now_per_i[0][4];
    ((Player*)vecP->persons[0])->mp = now_per_i[0][5];
    ((Player*)vecP->persons[0])->atc = now_per_i[0][6];
    Coords pos(now_per_i[0][2], now_per_i[0][3]);
    ((Player*)vecP->persons[0])->position = pos;

    for (int i = 1; i < vecI->getQuantity();) {
        int flag = 0;
        for (int j = 1; j < const_i[VECIQ]; ++j) {
            if (vecI->items[i]->getIdSt() == now_per_i[j][1]){
                ((Enemy*)vecP->persons[i])->hp = now_per_i[j][4];
                ((Enemy*)vecP->persons[i])->mp = now_per_i[j][5];
                ((Enemy*)vecP->persons[i])->atc = now_per_i[j][6];
                Coords pos(now_per_i[j][2], now_per_i[j][3]);
                ((Enemy*)vecP->persons[i])->position = pos;
                flag = 1;
            }
        }
        if (flag == 0){
            floor_new->cells[vecI->items[i]->getPosition().x][vecI->items[i]->getPosition().y]->setElem(nullptr);
            floor_new->cells[vecI->items[i]->getPosition().x][vecI->items[i]->getPosition().y]->setType(Type::NORMAL);
            vecI->del(i);
        }
    }
    floor_en = floor_new;
    return 0;
}

