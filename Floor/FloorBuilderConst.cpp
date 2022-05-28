#include "FloorBuilderConst.h"

FloorBuilderConst::FloorBuilderConst(MyTexture texture): now_texture(texture){
    this->floor = new Floor(HEIGTH_OF_FLOOR, WIDTH_OF_FLOOR);
};

FloorBuilderConst::~FloorBuilderConst(){
    delete this->floor;
};

void FloorBuilderConst::GeneratNormalCells(){
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            this->floor->cells[i][j] = new Cell(now_texture.getTextureOfCellNormal(), Coords(i, j), nullptr, Type::NORMAL);
            // TODO:(Зачем?) nullptr в поле elem заменить на нормальное(пустое проходимое)
        }
    }
};

void FloorBuilderConst::GeneratWallCells(){
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            if (i == 0 || i == this->floor->height - 1 || j == 0 || j == this->floor->width - 1){
                this->floor->cells[i][j]->setElem(nullptr);
                // TODO:(Зачем?) nullptr в поле elem заменить на не проходимое
                this->floor->cells[i][j]->setType(Type::WALL);
                this->floor->cells[i][j]->setSprite(now_texture.getTextureOfCellWall());
            }
        }
    }
    int** mass = new int*[this->floor->height];
    for (int i = 0; i < this->floor->height; ++i) mass[i] = new int[this->floor->width];
    for (int i = 0; i < this->floor->height; ++i) {
        for (int j = 0; j < this->floor->width; ++j) {
            mass[i][j] = 0;
        }
    }
};

void FloorBuilderConst::GeneratEntryCell(){
    this->floor->cells[1][1]->setType(Type::ENTRY);
    this->floor->cells[1][1]->setSprite(now_texture.getTextureOfCellEntry());
};

void FloorBuilderConst::GeneratExitCell(){
    this->floor->cells[this->floor->height - 2][this->floor->width - 2]->setType(Type::EXIT);
    this->floor->cells[this->floor->height - 2][this->floor->width - 2]->setSprite(now_texture.getTextureOfCellExit());
};

void FloorBuilderConst::Reset(){
    this->floor = new Floor(this->floor->height, this->floor->width);
};

Floor* FloorBuilderConst::getFloor(){
    Floor* result;
    result = this->floor;
    this->Reset();
    return result;
}

void FloorBuilderConst::GeneratItems() {
    if (HEIGTH_OF_FLOOR > 5 && WIDTH_OF_FLOOR > 5){
        Coords pos(2,1);
        auto hp = new HP(now_texture.getTextureOfElemHp(), pos);
        floor->cells[pos.x][pos.y]->setElem(hp);
        floor->cells[pos.x][pos.y]->setType(Type::FULL);
        Coords pos1(2,2);
        auto mp = new MP(now_texture.getTextureOfElemMp(), pos1);
        floor->cells[pos1.x][pos1.y]->setElem(mp);
        floor->cells[pos1.x][pos1.y]->setType(Type::FULL);
        Coords pos2(1,2);
        auto atc = new ATC(now_texture.getTextureOfElemAtc(), pos2);
        floor->cells[pos2.x][pos2.y]->setElem(atc);
        floor->cells[pos2.x][pos2.y]->setType(Type::FULL);
    }
}

void FloorBuilderConst::GeneratPlayer() {
    Coords pos(1,1);
    auto player = new Player(now_texture.getTextureOfElemPlayer(), pos);
    floor->cells[1][1]->setElem(player);
}

void FloorBuilderConst::GeneratEnemy() {
                if (HEIGTH_OF_FLOOR > 7 && WIDTH_OF_FLOOR > 7){
                    Coords pos(HEIGTH_OF_FLOOR - 3, WIDTH_OF_FLOOR - 2);
                    auto tank = new Tank(now_texture.getTextureOfElemTank(), pos);
                    floor->cells[pos.x][pos.y]->setElem(tank);
                    floor->cells[pos.x][pos.y]->setType(Type::FULL);
                    Coords pos1(HEIGTH_OF_FLOOR - 3, WIDTH_OF_FLOOR - 3);
                    auto solder = new Solder(now_texture.getTextureOfElemSolder(), pos1);
                    floor->cells[pos1.x][pos1.y]->setElem(solder);
                    floor->cells[pos1.x][pos1.y]->setType(Type::FULL);
                    Coords pos2(HEIGTH_OF_FLOOR - 2, WIDTH_OF_FLOOR - 3);
                    auto wizard = new Wizard(now_texture.getTextureOfElemWizard(), pos2);
                    floor->cells[pos2.x][pos2.y]->setElem(wizard);
                    floor->cells[pos2.x][pos2.y]->setType(Type::FULL);
                }
}

/*void FloorBuilderTree::setNowTexture() {
    now_texture.setTextureOfCellEntry(ENTRY_TEXTURE_PATH);
    now_texture.setTextureOfCellExit(EXIT_TEXTURE_PATH);
    now_texture.setTextureOfCellNormal(NORMAL_TEXTURE_PATH);
    now_texture.setTextureOfCellWall(WALL_TEXTURE_PATH);

}*/;