#include <iostream>
#include <string>
#include <vector>

struct Move {
    std::string name;
    int power;
};

class Pokemon {
public:
    std::string name;
    int hp;
    std::vector<Move> moves;

    Pokemon(std::string n, int h) : name(n), hp(h) {}

    void learnMove(std::string moveName, int power) {
        moves.push_back({moveName, power}); 
    }

    void attack(int moveIndex, Pokemon &target) {
        Move &selectedMove = moves[moveIndex];
        std::cout << name << " は " << selectedMove.name << " を くりだした!" << std:: endl;

        target.hp -= selectedMove.power; // 相手のHPを減らす
        std::cout << target.name << " に " << selectedMove.power << " の ダメージ!" << std::endl;
    }

    bool isFainted() {  // 倒れたかの判定
        return hp <= 0;
    }

};

int main() {
    // ポケモンの準備
    Pokemon p1("ピカチュウ", 100);

    // 技を覚えさせる
    p1.learnMove("10まんボルト", 90);
    p1.learnMove("でんこうせっか", 40);

    Pokemon p2("ヒトカゲ", 100);
    p2.learnMove("ひのこ", 40);

    std::cout << p2.name << " が あらわれた!" << std::endl;

    // --- バトルループ ---
    while (!p1.isFainted() && !p2.isFainted()) {
        // プレイヤーのターン
        std::cout << "\n------------------------" << std::endl;
        std::cout << p1.name << " の HP :" << p1.hp << std::endl;
        std::cout << p2.name << " の HP :" << p2.hp << std::endl;
        std::cout << p1.name << " は どうする？ \n";
        for(int i = 0; i < (int)p1.moves.size(); i++) {
            std::cout << (i + 1) << ": " << p1.moves[i].name << " (威力)" << p1.moves[i].power << "\n";    
        }

        int choice;
        std::cin >> choice; // キーボード入力を受け取る

        if (choice >= 1 && choice <= (int)p1.moves.size()) {
        p1.attack(choice - 1, p2); // 選択された技で攻撃
        } else {
            std::cout << "しかし うまく きまらなかった!" << std::endl;
        }

        // 相手が倒れたか
        if(p2.isFainted()) {
            std::cout << p2.name << " は たおれた！" << std::endl;
            break;
        }

        // 相手のターン
        p2.attack(0, p1); // 自動で０番目の技を使う

        // プレイヤーが倒れたか
        if(p1.isFainted()) {
            std::cout << p1.name << " は たおれた！" << std::endl;
            break;
        }
    }

    std::cout << "対戦ありがとうございました！" << std::endl;
    return 0;
}