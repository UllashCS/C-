#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if (dynamic_cast<Fireball*> (spell)) {
        dynamic_cast<Fireball*> (spell)->revealFirepower();
    } else if (dynamic_cast<Frostbite*> (spell)) {
        dynamic_cast<Frostbite*> (spell)->revealFrostpower();
    } else if (dynamic_cast<Thunderstorm*> (spell)) {
        dynamic_cast<Thunderstorm*> (spell)->revealThunderpower();
    } else if (dynamic_cast<Waterbolt*> (spell)) {
        dynamic_cast<Waterbolt*> (spell)->revealWaterpower();
    } else {

        string scrollName = spell->revealScrollName();
        string journal = SpellJournal::read();
   
        vector<vector<int>> LCS = vector<vector<int>>(scrollName.size()+1);

        for (int i = 0; i <= scrollName.size(); i++) {
            LCS[i] = vector<int>(journal.size()+1);

            for (int j = 0; j <= journal.size(); j++) {
                if (i == 0 || j == 0) {
                    LCS[i][j] = 0;
                }
                else if (scrollName[i - 1] == journal[j - 1]) {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                }
                else{
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
                }
            }
        }
        cout << LCS[scrollName.size()][journal.size()] <<endl;
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}