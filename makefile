all:
	g++ ./Controller/Controller.cpp ./main.cpp ./View/SdlHelper.cpp ./View/View.cpp ./View/Assets.cpp ./Model/Herbivore.cpp ./Model/Model.cpp ./Model/Attributes.cpp ./Model/Trait.cpp ./Model/SituationTraits.cpp ./Model/Animal.cpp ./Model/Carnivore.cpp -std=c++11 -o gra_w_zycie -lSDL2 -lSDL2_image 
