#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;

struct Player {
    string name;
    int HP, ATK, END;
    int baseATK, baseEND;      // base stats for toggle calculation
    double EP, EP_regen;
    bool g1Active = false;
    bool g2Active = false;
    bool chainLearned = false;
};

struct Boss {
    string name;
    int HP, ATK, END, phase;
};

struct Skill {
    string name;
    int EPcost;          // cast cost
    double ATKmultiplier;
    int cooldown;
    int currentCooldown;
    bool active = false; // for toggle skills like Gates
    int perTurnCost = 0; // EP cost per turn if active
};

// Globals
Player keigan;
Boss arlong;
vector<Skill> playerSkills;
int selfDiscoveryCount = 0; // tracks Self-Discovery skill unlocks
bool frontLotusUsed = false;

// Pause function
void pause() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Initialize player
void InitPlayer(Player &keigan) {
    keigan.name = "Keigan";
    keigan.HP = 50;
    keigan.ATK = 10;
    keigan.END = 15;
    keigan.EP = 5;
    keigan.EP_regen = 5;
}

// Initialize boss and starting skill
void InitBossAndSkills() {
    arlong.name = "Arlong";
    arlong.HP = 2500;
    arlong.ATK = 520;
    arlong.END = 600;
    arlong.phase = 1;
}

void title() {
    cout << endl << endl;
    cout << "     One Piece: The Cocoyashi Arc - Keigan's Journey     " << endl;
    cout << "       Based on OP_Naru Fanfic Idea - Cocoyashi Arc      " << endl << endl;
}

// End program
void endProgram() {
    exit(0);
}

// Menu
void menu() {
    string ans;
    cout << "                      Start    Exit\n";
    while (true) {
        cout << "\nEnter the Option: ";
        getline(cin, ans);

        if (ans == "Start" || ans == "start") {
            cout << "\nWelcome to One Piece: The Cocoyashi Arc - Keigan's Journey.\n";
            pause();
            cout << "Synopsis:\n\n";
            cout << "After surviving Arlong's invasion of Cocoyashi Village, Keigan 'Kei' Lee vows revenge. "
                    "Beaten and left for dead, he spends eight years training in isolation to surpass his limits.\n\n";
            cout << "When he finally returns, Luffy and the Straw Hat crew are about to face Arlong. "
                    "Kei joins their fight, wielding his newly learned Eight Gates techniques and refined taijutsu mastery.\n\n";
            cout << "This chapter follows Keigan's training and revenge against Arlong, introducing deeper stat systems, battle conditions, and skill progression.\n";
            pause();
            break;
        }
        else if (ans == "Exit" || ans == "exit") {
            cout << "\nThanks For Playing!\n";
            endProgram();
        }
        else {
            cout << "\nInvalid option. Try Again!\n";
        }
    }
}

void act1() {
    cout << "Act 1 — The Fall of Cocoyashi" << endl;
    pause();
    cout << "Cocoyashi Village, once peaceful and full of laughter, falls into despair the day Arlong and his crew arrive. Their demands are simple: every human must pay tribute for the right to live." << endl;
    pause();
    cout << "Arlong (smirking): Pay tribute, humans… or die." << endl;
    pause();
    cout << "Villager 1 (whispering): We have nothing left…" << endl;
    pause();
    cout << "Villager 2 (trembling): They'll kill us all if we refuse." << endl;
    pause();
    cout << "Bell-mère, unable to pay for herself and instead paid for her daughters, is executed in front of Nami, Nojiko, and Keigan, who stands powerless as Arlong's cruelty unfolds." << endl;
    pause();
    cout << "Nami (screaming, tears streaming): Mother! Don't… please!" << endl;
    pause();
    cout << "Nojiko (grabbing Nami, shouting): Stay back, Nami! Don't fight him!" << endl;
    pause();
    cout << "Keigan (clenching his fists, teeth grinding): I… I won't let this happen! I can't!" << endl;
    pause();
    cout << "Enraged, Keigan lunges at the Fishman captain. His blow connects — but it's meaningless." << endl;
    pause();
    cout << "Arlong (mocking, voice echoing): Pathetic. You humans… think you can fight us? You're nothing." << endl;
    pause();
    cout << "To make an example of him, Arlong throws Keigan into the open sea, declaring:" << endl;
    pause();
    cout << "Arlong (shouting): The weak belong to the deep!" << endl;
    pause();
    cout << "But Keigan survives. The sea does not claim him. He drifts unconscious for days until washing ashore on another island, battered yet alive — a miracle that becomes his hope and resolve." << endl;
    pause();
    cout << "Keigan (weakly, whispering, lips cracked): I… I survived… I must… grow stronger… I will… come back… and end this…" << endl;
    pause();
    cout << "The weakness and loss ignite a single purpose within him: to return strong enough to destroy Arlong's tyranny and return to Cocoyashi Village." << endl;
    pause();
    cout << "Keigan (clenching his fists, staring at the horizon): I swear… Cocoyashi will be free. Nami… I will save you.";
    pause();
}

void act2() {
    cout << endl;
    cout << "Act 2 — The Eight-Year Training Arc" << endl;
    pause();
    cout << "After drifting for days at sea, Keigan's unconscious body is discovered by the Good Heart Pirates, a small and kind-hearted crew sailing the East Blue." << endl;
    pause();
    cout << "Pirate Captain (gently): Easy… easy now, you're safe. Rest." << endl;
    pause();
    cout << "Keigan (barely opening his eyes, weakly): Where… am I…?" << endl;
    pause();
    cout << "Pirate Captain: You were cast adrift at sea… but you're alive. That's what matters." << endl;
    pause();
    cout << "They nurse him back to health and drop him off at a quiet, uninhabited island, where he can recover and start anew." << endl;
    pause();
    cout << "Captain (serious, voice firm): Remember, boy… live first. Then choose what to do with the life you still have." << endl;
    pause();
    cout << "Keigan (thinking, determination building): Live… then fight. That will be my path… I cannot waste this second chance." << endl;
    pause();
    cout << "Alone on the island, Keigan stumbles upon an old training scroll, half-worn and salt-damaged, titled The Eight Inner Gates. The scroll details an ancient form of body conditioning that channels life force into power, at the risk of one's own body." << endl;
    pause();
    cout << "Keigan (whispering, eyes wide): This… this can make me strong… if I survive it… I have no choice." << endl;
    pause();
    cout << "The technique fascinates him — and terrifies him. But he knows it's his only path forward." << endl;
    pause();
    cout << "Keigan (clenching fists, teeth grinding): No more weakness. No more running. I will master this… I must." << endl;
    pause();
    cout << "From that day on, training becomes his entire life." << endl;
    pause();
    cout << "Each day is a blur of sweat and strain:" << endl;
    pause();
    cout << "Mornings: striking trees until his knuckles bleed." << endl;
    pause();
    cout << "Keigan (panting, voice raw): Again… harder… push… push further!" << endl;
    pause();
    cout << "Afternoons: climbing cliffs or swimming against the island's currents." << endl;
    pause();
    cout << "Keigan (gritting teeth, muscles shaking): I won't be dragged down! Not by nature… not by anything!" << endl;
    pause();
    cout << "Nights: meditating under waterfalls to stabilize life energy." << endl;
    pause();
    cout << "Keigan (softly chanting): Flow… focus… control… strength… calm…" << endl;
    pause();
}

void gameplay() { // Helps the player before to play the game
    cout << "Gameplay Representation" << endl;
    cout << "- The eight-year regimen is divided into 48 turns (2 months = 1 turn)." << endl;
    cout << "- Each turn, the player chooses a training focus:" << endl;
        cout << "- HP, ATK, END, or EP for raw stats." << endl;
        cout << "- Self-Discovery for skill unlocks — including Gate of Opening, Chain Handling, Keigan Barrage, and Front Lotus." << endl;
    cout << "- No fatigue or rest is used — training is linear, symbolizing Keigan's relentless resolve." << endl;
    pause();
}

// Training loop
void trainingLoop(Player &keigan) {
    const int totalTurns = 48;
    int hpCount = 0, atkCount = 0, endCount = 0, epCount = 0;

    cin.ignore(9999, '\n'); // clears buffer before first getline

    for (int turn = 1; turn <= totalTurns; turn++) {
        cout << "Turn " << turn << " - Choose training (HP / ATK / END / EP / Self-Discovery): ";
        string choice;
        getline(cin, choice);

        if (choice == "HP") { hpCount++; keigan.HP += 21 + 4 * (hpCount - 1); }
        else if (choice == "ATK") { atkCount++; keigan.ATK += 11 + 2 * (atkCount - 1); keigan.baseATK = keigan.ATK; }
        else if (choice == "END") { endCount++; keigan.END += 15 + 3 * (endCount - 1); keigan.baseEND = keigan.END; }
        else if (choice == "EP") { epCount++; keigan.EP += 15 + 3 * (epCount - 1); }
        else if (choice == "Self-Discovery") {
            if (selfDiscoveryCount == 0) playerSkills.push_back({"Eight Gates – Gate of Opening (G1)", 35, 1.8, 3, 0, false, 7});
            else if (selfDiscoveryCount == 1) { playerSkills.push_back({"Chain Handling", 0, 0, 0, 0, false, 0}); keigan.chainLearned = true; }
            else if (selfDiscoveryCount == 2) playerSkills.push_back({"Kei-ga-n Barrage!", 12, 0.45, 2, 0, false, 0});
            else if (selfDiscoveryCount == 3) playerSkills.push_back({"Front Lotus (Omote Renge)", 13, 0.95, 3, 0, false, 0});
            else if (selfDiscoveryCount == 4) playerSkills.push_back({"Gate of Opening – Mastery", 0, 0, 0, 0, false, 0});
            else if (selfDiscoveryCount == 5) playerSkills.push_back({"Gate of Healing (G2)", 45, 2.2, 3, 0, false, 9});
            else if (selfDiscoveryCount == 6) playerSkills.push_back({"Chain Barrage", 14, 0.5, 3, 0, false, 0});
            else if (selfDiscoveryCount == 7) playerSkills.push_back({"Reverse Lotus (Ura Renge)", 25, 1.25, 5, 0, false, 0});
            else { cout << "No new skills discovered this turn.\n"; turn--; continue; }
            selfDiscoveryCount++;
        }
        else { cout << "Invalid choice, try again.\n"; turn--; continue; }

        cout << "Stats - HP: " << keigan.HP << ", ATK: " << keigan.ATK
             << ", END: " << keigan.END << ", EP: " << keigan.EP << "\n\n";
    }
}

void trainingafter() {
pause(); // Aftermath the training
    cout << "Days turn to months, months into years. The island changes with him — from a deserted shore to a battlefield of growth and self-discovery." << endl;
    pause();
    cout << "The Eight Gates become both a spiritual and physical journey, shaping him into a warrior who balances life, strength, and control."<< endl;
    pause();
    cout << "Keigan (staring at his reflection in a still pool): Eight years… every scar, every drop of blood… all of it… worth it." << endl;
    pause();
    cout << "By the eighth year, Keigan's transformation is complete. His once lean frame now carries the strength of countless battles with nature itself. The scroll lies torn and faded, but its lessons live within him." << endl;
    pause();
    cout << "Keigan (tightening his grip on Bell-mère's headband): I am ready. Cocoyashi… I am coming for you." << endl;
    pause();
    cout << "He sets out to sea, back to Cocoyashi Village. His first destination isn't Cocoyashi — but Baratie, where fate brings him face to face with Luffy and the Straw Hat Crew." << endl;
}

void act3() {
    pause();
    cout << "Act 3 — Return to Cocoyashi" << endl;
    pause();
    cout << "At Baratie, the lively chaos of the floating restaurant greets him. He notices a sharp-eyed navigator whose manner and guarded expression stir something deep within him. Recognition is an ache without a name." << endl;
    pause();
    cout << "Keigan (quietly, to himself): Nami… could it really be you?" << endl;
    pause();
    cout << "The peace is shattered when Don Krieg attacks. In the chaos, Dracule Mihawk appears, and Zoro challenges him. Zoro is defeated but unbroken. During the scramble, the navigator and her crew steal away aboard the Going Merry." << endl;
    pause();
    cout << "Keigan (gritting teeth, whispering): That's her… I can't lose her again. I have to follow." << endl;
    pause();
    cout << "The Straw Hats decide to pursue. Luffy and Sanji remain at Baratie for their own reasons, while Zoro, Usopp, Yosaku, and others give chase. Keigan volunteers to join them." << endl;
    pause();
    cout << "Keigan (to the crew, confidently): Follow me. I know the way… I won't let her fall again." << endl;
    pause();
    cout << "Arrival at Cocoyashi Village" << endl;
    pause();
    cout << "The group reaches Cocoyashi and finds a village hollowed by fear. They meet Nojiko, who — together with Luffy and Sanji — explains Nami's past: Bell-mère's death, the tribute, Arlong's rule, and Nami's forced servitude." << endl;
    pause();
    cout << "Nojiko (voice trembling): Keigan… you remember? The boy who survived the sea?" << endl;
    pause();
    cout << "Usopp (stunned): You—Keigan—the one Arlong tossed in the water?"<< endl;
    pause();
    cout << "Zoro (nodding solemnly): And you survived. Not many would."<< endl;
    cin.ignore();
    cout << "Luffy (smiling, energetic): So… you're here to help us?"<< endl;
    pause();
    cout << "Keigan (softly, resolute): I promised I would come back. I'm here to end it."<< endl;
    pause();
    cout << "Keigan still doesn't confront Nami immediately; the recognition comes later, in the heat of battle with Arlong. Nojiko's telling anchors the crew's purpose: this fight is about freeing Cocoyashi and saving Nami." << endl;
    pause();
    cout << "The March to Arlong Park" << endl;
    pause();
    cout << "United, the Straw Hats and Keigan move toward Arlong Park. Corrupt local Marines and Fishman sentries try to block them, but the crew cuts through bureaucracy with blunt force and blunt words." << endl;
    pause();
    cout << "Keigan (quietly, under his breath): This time… I bring what I should have had eight years ago." << endl;
    pause();
    cout << "They step into the arena where Arlong awaits, and the encounter begins." << endl;
    pause();
    cout << "Arlong (smirking, arms crossed): Well, well… look who finally decided to show up. The weak boy I tossed into the sea. You've grown… but is that all?" << endl;
    pause();
    cout << "Keigan tightens his grip on Bell-mère's headband, feeling the weight of years of training and loss." << endl;
    pause();
    cout << "Keigan (voice steady, eyes burning): I've grown enough to end your tyranny, Arlong. Eight years of weakness… are over." << endl;
    pause();
    cout << "Arlong (laughing, circling him): Eight years? You think that makes you strong? You're still just a human. Humans… will always crumble before Fishman strength." << endl;
    pause();
    cout << "Keigan (taking a deep breath, stepping forward): Maybe humans crumble… but some rise stronger than anyone expects. And I'm one of them." << endl;
    pause();
    cout << "Arlong's grin fades slightly, replaced by a snarl of irritation." << endl;
    pause();
    cout << "Arlong (mocking, flexing his claws): You talk big for a boy who barely survived the sea! You were nothing back then… and now?" << endl;
    pause();
    cout << "Keigan (fists glowing, aura flaring, recalling the Eight Gates): Now… I am the storm you never saw coming. Cocoyashi Village… and Nami… will finally be free." << endl;
    pause();
    cout << "Arlong (snarling, stepping closer, voice low and menacing): Free? HA! You think you can defeat me? I am the tide… the deep… the fear of every human!" << endl;
    pause();
    cout << "Keigan's eyes narrow, remembering every swing of the trees, every climb of the cliffs, every grueling meditation beneath the waterfalls." << endl;
    pause();
    cout << "Keigan (voice calm, unwavering): Then let the tide crash… I've faced storms far worse than you. I've trained, bled, and endured eight years for this moment. You're the last obstacle." << endl;
    pause();
    cout << "Arlong (leaning forward, claws glinting): Then come, boy. Show me how weak humans die." << endl;
    pause();
    cout << "Keigan (fists clenched, aura blazing): This time, the weak do not die. They rise." << endl;
    pause();
    cout << "The tension snaps. The air shivers around them, and the water from nearby fountains trembles as Keigan steps fully into the arena. The Straw Hats position themselves, ready to fight, their eyes locked on the confrontation that will decide the fate of Cocoyashi Village." << endl;
    pause();
    cout << "Narration: Every step, every heartbeat, carries the weight of eight years of loss, pain, and relentless training. This is the moment Keigan was forged for — and the last chance to reclaim his home." << endl;
    pause();
    cout << "The arena falls silent for a heartbeat, as predator and prey, student and tormentor, face each other at last. The battle for Cocoyashi begins." << endl;
    pause();
}

// Battle loop
void battleloop() {
    while (keigan.HP > 0 && arlong.HP > 0) {
        keigan.EP += keigan.EP_regen;

        for (auto &s : playerSkills) {
            if (s.active && s.perTurnCost > 0) {
                keigan.EP -= s.perTurnCost;
                if (keigan.EP < 0) { s.active = false; cout << s.name << " deactivated (No EP).\n"; }
            }
        }

        keigan.ATK = keigan.baseATK;
        keigan.END = keigan.baseEND;
        for (auto &s : playerSkills) {
            if (s.active) {
                if (s.name == "Eight Gates – Gate of Opening (G1)") keigan.ATK = keigan.baseATK * 1.8;
                if (s.name == "Gate of Healing (G2)") keigan.ATK = keigan.baseATK * 2.2;
            }
        }

        // Player action
        int action;
        cout << "Choose action: 1=Attack 2=Skill 3=Toggle Gate: ";
        while (!(cin >> action)) { cin.clear(); cin.ignore(9999, '\n'); cout << "Try again: "; }
        cin.ignore(9999, '\n');

        if (action == 1) { int dmg = max(0, (keigan.ATK - arlong.END) / 2); arlong.HP -= dmg; cout << "You dealt " << dmg << " damage!\n"; }
        else if (action == 2) {
            for (size_t i = 0; i < playerSkills.size(); i++)
                cout << i + 1 << ". " << playerSkills[i].name
                     << " (EP:" << playerSkills[i].EPcost
                     << ", CD:" << playerSkills[i].currentCooldown << ")\n";

            int skillChoice;
            while (!(cin >> skillChoice)) { cin.clear(); cin.ignore(9999, '\n'); cout << "Try again: "; }
            cin.ignore(9999, '\n');

            if (skillChoice < 1 || skillChoice > playerSkills.size()) { cout << "Invalid skill!\n"; continue; }
            Skill &s = playerSkills[skillChoice - 1];
            if (s.name == "Reverse Lotus (Ura Renge)" && !frontLotusUsed) { cout << "Cannot use Reverse Lotus yet!\n"; continue; }

            if (keigan.EP >= s.EPcost && s.currentCooldown == 0) {
                int dmg = max(0, (int)ceil((keigan.ATK * s.ATKmultiplier - arlong.END) / 2.0));
                arlong.HP -= dmg;
                keigan.EP -= s.EPcost;
                s.currentCooldown = s.cooldown;
                cout << "Used " << s.name << " → " << dmg << " dmg!\n";
                if (s.name == "Front Lotus (Omote Renge)") frontLotusUsed = true;
            } else cout << "Skill unavailable.\n";
        }
        else if (action == 3) {
            for (auto &s : playerSkills)
                if (s.name.find("Gate") != string::npos) { s.active = !s.active; cout << s.name << (s.active ? " activated.\n" : " deactivated.\n"); }
        }

        if (arlong.HP > 0) { int dmg = max(0, (arlong.ATK - keigan.END) / 2); keigan.HP -= dmg; cout << "Arlong hits you for " << dmg << "!\n"; }
        for (auto &s : playerSkills) if (s.currentCooldown > 0) s.currentCooldown--;

        if (arlong.HP < 1600 && arlong.phase == 1) { arlong.phase = 2; arlong.ATK = 550; cout << "Arlong enters Phase 2!\n"; }
        if (arlong.HP < 900 && arlong.phase == 2) { arlong.phase = 3; arlong.ATK = 600; arlong.END = 660; cout << "Arlong goes ENRAGED! Phase 3!\n"; }
    }

    if (keigan.HP <= 0) cout << "\nYou were defeated...\n";
    else cout << "\nArlong defeated! Cocoyashi is free!\n";

    pause();
}

void ending() {
    if(keigan.HP<=0) {
        cout << "Keigan is defeated by Arlong, he is thrown into the ocean. As he sinks, the world fades to black." << endl;
        pause();
        cout << "When his eyes open again, he's eight years old, standing in front of Bell-mère's house. The village is whole, Arlong never came, and yet… a heavy dread lingers." << endl;
        pause();
        cout << "Keigan (to himself, whispering): Was it… all a dream? Can I really defeat Arlong?" << endl;
        pause();
        cout << "The vision dissolves into silence." << endl;
        pause();
        cout << "[End Scene]" << endl;
        pause();
    }
    else {
        cout << "Act 4 — Cocoyashi's Freedom and Beyond" << endl;
        pause();
        cout << "Scene 1 — Nami and Keigan's Freedom" << endl;
        pause();
        cout << "Arlong Park crumbles as the dust clears. The villagers of Cocoyashi pour out, their chains broken, laughter and disbelief mixing with tears." << endl;
        pause();
        cout << "Villager 1 (crying with relief): It's over… it's finally over!" << endl;
        pause();
        cout << "Villager 2 (hugging their child): We can live freely again!" << endl;
        pause();
        cout << "Amid the wreckage, Keigan collapses, his body drained from the toll of battle and the burden of opening the Eight Gates." << endl;
        pause();
        cout << "Keigan (gasping, whispering to himself): I… did it… I finally did it…" << endl;
        pause();
        cout << "Nami rushes to him, her voice trembling between relief and worry." << endl;
        pause();
        cout << "Nami: Keigan! Are you hurt? Tell me if you're okay!" << endl;
        pause();
        cout << "Keigan (weakly smiling): I… I'll be fine. Cocoyashi is safe… thanks to you all." << endl;
        pause();
        cout << "Luffy, grinning as always, pulls Keigan out from the debris, brushing off his own injuries." << endl;
        pause();
        cout << "Luffy (laughing loudly): Oi! You were amazing out there! Whoa, those punches of yours… crazy!" << endl;
        pause();
        cout << "Keigan (chuckling faintly, exhaustion evident): I've trained for this… eight years. It's enough… for now." << endl;
        pause();
        cout << "The victory feels surreal — Arlong's tyranny is finally over. Genzo and the villagers begin their three-day celebration of freedom while the Straw Hats rest." << endl;
        pause();
        cout << "Keigan (looking up at the sky, softly): Thank you, Bell-mère… I've kept my promise." << endl;
        pause();
        cout << "Scene 2 — Nami and Keigan's Reunion" << endl;
        pause();
        cout << "Cocoyashi Village wakes to laughter again. At Bell-mère's grave, Nami and Keigan stand side by side, the weight of eight long years between them." << endl;
        pause();
        cout << "Nami (placing a bouquet of tangerine blossoms carefully): She would be proud of us… proud of you." << endl;
        pause();
        cout << "Keigan (bowing deeply, hand on chest): I swear… the village's freedom will never be stolen again." << endl;
        pause();
        cout << "Nojiko and Genzo watch nearby, smiling knowingly." << endl;
        pause();
        cout << "Nojiko (teasing softly): About time you two stood here together without trying to kill each other." << endl;
        pause();
        cout << "Keigan (smirking faintly at Nami): Some things take longer than expected." << endl;
        pause();
        cout << "Nami (rolling her eyes, a small smile forming): Just… don't make me regret trusting you, Jet." << endl;
        pause();
        cout << "There's no grand declaration, only quiet understanding — two children of the same home, finally free to breathe. They share a moment of warmth under the morning sun." << endl;
        pause();
        cout << "Keigan (thinking quietly): After all these years… finally, peace… finally, home." << endl;
        pause();
        cout << "Scene 3 — Nami's Farewell" << endl;
        pause();
        cout << "As the festival winds down, Nami prepares to leave with the Straw Hats. She visits Doctor Nako to have her tattoo tended and her wounds checked." << endl;
        pause();
        cout << "Doctor Nako (examining her arm): You're lucky… scars heal, but your spirit… that's what kept you alive." << endl;
        pause();
        cout << "Nami (smiling faintly): I hope so." << endl;
        pause();
        cout << "Meanwhile, Genzo and Keigan make a final visit to Bell-mère's grave." << endl;
        pause();
        cout << "Genzo (softly): She would be happy… seeing the village free." << endl;
        pause();
        cout << "Keigan (placing his hand on the grave): I promised her… I've kept my word. But I'll stay vigilant… always." << endl;
        pause();
        cout << "Luffy interrupts their reflection with his trademark volume — shouting, laughing, and reminding them the ship's about to sail." << endl;
        pause();
        cout << "Luffy: Oi! Keigan! Nami! Let's go! The sea isn't waiting!" << endl;
        pause();
        cout << "Keigan (half-laughing, half-sighing): Some things never change…" << endl;
        pause();
        cout << "Nami (grinning at Luffy, then at Keigan): Let's go." << endl;
        pause();
        cout << "The solemn moment turns cheerful as everyone joins in Luffy's energy. Genzo gives Nami his blessing; Keigan watches silently, proud but wistful." << endl;
        pause();
        cout << "Keigan (thinking quietly): This isn't a goodbye… it's a beginning." << endl;
        pause();
        cout << "Scene 4 — Luffy Recruits Keigan" << endl;
        pause();
        cout << "At the Cocoyashi Docks, the Going Merry prepares to depart. Luffy turns to Keigan with that usual reckless grin." << endl;
        pause();
        cout << "Luffy (excited, almost bouncing): Oi, Keigan! You're strong — come with us! You can fight, navigate, or whatever!" << endl;
        pause();
        cout << "Keigan (pausing, considering): Fight, navigate… or bookkeeping. I suppose I could do all three." << endl;
        pause();
        cout << "Nami (teasing, crossing her arms): Don't mess it up, Jet." << endl;
        pause();
        cout << "Keigan (smiling faintly, looking at the ship): Then I'll handle it… with you by my side." << endl;
        pause();
        cout << "The Straw Hats erupt in cheers. Nami smirks, already imagining her new navigator-partner and accountant in one. Together, they board the ship — two hearts bound by the same promise of freedom." << endl;
        pause();
        cout << "Keigan (glancing back at the village one last time): The sea feels lighter than ever… Cocoyashi is safe… and we'll protect it." << endl;
        pause();
        cout << "Scene 5 — Bounty Reveal" << endl;
        pause();
        cout << "Days later, aboard the Going Merry, Nami lounges on deck, reading the newspaper. As she flips a page, two sheets flutter loose — Keigan catches them before they hit the floor." << endl;
        pause();
        cout << "Keigan (eyes widening, reading the bounty): 5,000,000 Beli… huh." << endl;
        pause();
        cout << "Nami (smirking): Looks like someone's famous now." << endl;
        pause();
        cout << "Usopp (bursting with excitement): Jet? What's next, flying through the sky?" << endl;
        pause();
        cout << "Keigan (grinning, holding the papers): Maybe… but for now, let's enjoy the ride." << endl;
        pause();
        cout << "The crew bursts into laughter over Keigan's nickname. For the first time, his name carries weight across the seas." << endl;
        pause();
        cout << "Keigan (thinking, quietly, to himself): The world knows who I am… but more importantly, I know who I fight for." << endl;
    }
}

// Main
int main() {
    title();
    menu();
    InitPlayer(keigan);
    InitBossAndSkills();

    cout << "AND THE STORY BEGINS NOW...\n"; pause();
    act1();
    act2();
    gameplay();
    trainingLoop(keigan);
    act3();
    battleloop();
    ending();
    
    return 0;
}
