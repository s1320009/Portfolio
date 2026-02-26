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

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0; 
    }

    bool isFainted() const {  // 倒れたかの判定
        return hp <= 0;
    }

};

class BattleManager { 
public:
    // バトルの管理クラス
    void startBattle(Pokemon &p1, Pokemon &p2) {
        std::cout << "あ、やせいの " << p2.name << " が とびだしてきた！" << std::endl;
        std::cout << "ゆけっ！ " << p1.name << "!" << std::endl;

        while (!p1.isFainted() && !p2.isFainted()) {
            showStatus(p1,p2);

            int choice = getPlayerInput(p1);
            if (choice != -1) {
                processAttack(p1, choice, p2);
            } else {
                std::cout << "しかし うまく きまらなかった！" << std::endl;
            }

            if(p2.isFainted()) break;

            // 相手の攻撃
            processAttack(p2, 0, p1);
        }

        finishBattle(p1, p2);
    }

private:
    void showStatus(Pokemon &p1, Pokemon &p2) {
        std::cout << "\n------------------------" << std::endl;
        std::cout << p1.name << " の HP :" << p1.hp << " | " << p2.name << " の HP :" << p2.hp << std::endl;
    }  

    int getPlayerInput(Pokemon &p) {
        std::cout << p.name << " は どうする？ \n";
        for(int i = 0; i < (int)p.moves.size(); i++) {
            std::cout << (i + 1) << ": " << p.moves[i].name << " (威力)" << p.moves[i].power << "\n";
        }
        std::cout <<  "番号を入力\n";

        int choice;
        if(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            return -1; // エラー処理
        }
        return choice -1; // ０ベースのインデックスに変換
    }

    void processAttack(Pokemon &attacker, int moveIndex, Pokemon &target) {
        Move &selectedMove = attacker.moves[moveIndex];
        std::cout << attacker.name << " は " << selectedMove.name << " を くりだした！" << std::endl;
        target.takeDamage(selectedMove.power);
        std::cout << target.name << " に " << selectedMove.power << " の ダメージ!" << std::endl;
    }

    void finishBattle(Pokemon &p1, Pokemon &p2) {
        if(p1.isFainted()) {
            std::cout << p1.name << " は たおれた！" << std::endl;
        } else {
            std::cout << p2.name << " は たおれた！" << std::endl;
        }
        std::cout << "対戦ありがとうございました！" << std::endl;
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

   // バトル
   BattleManager manager;
   manager.startBattle(p1, p2);

   return 0;
}