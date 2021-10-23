cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Game main.cpp Floor/Cell/Cell.cpp Floor/Cell/Cell.h Floor/Floor.cpp Floor/Floor.h Floor/FloorBuilder.h Floor/FloorBuilderTree.cpp Floor/FloorBuilderTree.h Floor/FloorDirector.cpp Floor/FloorDirector.h GameEng/GameStart.cpp GameEng/GameStart.h Elem/IElem.h MyTexture/MyTexture.cpp MyTexture/MyTexture.h Elem/Person/IPerson.h Elem/Person/Enemy/Enemy.cpp Elem/Person/Enemy/Enemy.h Elem/Person/Enemy/Wizard/Wizard.cpp Elem/Person/Enemy/Wizard/Wizard.h Elem/Person/Enemy/Tank/Tank.cpp Elem/Person/Enemy/Tank/Tank.h Elem/Person/Enemy/Solder/Solder.cpp Elem/Person/Enemy/Solder/Solder.h Elem/Person/Player/Player.cpp Elem/Person/Player/Player.h Elem/Item/HP.cpp Elem/Item/HP.h Elem/Item/ATC.cpp Elem/Item/ATC.h Elem/Item/MP.cpp Elem/Item/MP.h)

target_link_libraries(Game sfml-graphics sfml-audio)