#include <iostream>
#include <string>

class Pokemon {
public:
    std::string name;
    int hp;

    Pokemon(std::string n, int h) : name(n), hp(h) {}

    void greet() {
        std::cout << name << " が あらわれた！ (HP: " << hp << ")" << std::endl;
    }
};

int main() {
    Pokemon myPokemon("ピカチュウ", 100);
    myPokemon.greet();

    // 2匹目
    Pokemon enemyPokemon("ヒトカゲ", 120);
    enemyPokemon.greet();
    return 0;
}