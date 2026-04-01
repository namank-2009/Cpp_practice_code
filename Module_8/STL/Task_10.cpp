#include<iostream>
#include<string>
#include<map>
#include<string>

struct PlayerStats{
    std::string playerId;
    std::string playerName;
    int score;
    
    PlayerStats(std::string id, std::string name, int sc)
        : playerId(id), playerName(name), score(sc) {}
};

struct PlayerRankComparator{
    bool operator()(const PlayerStats& p1, const PlayerStats& p2){
        if(p1.score != p2.score){
            return p1.score>p2.score;
        }
        if(p1.playerName != p2.playerName){
            return p1.playerName<p2.playerName;
        }
        return p1.playerId < p2.playerId;
    }
};

int main(){
    std::map<PlayerStats, bool, PlayerRankComparator> leaderboard;
    leaderboard[{ "P001", "Alice", 1500 }] = true;
    leaderboard[{ "P003", "Charlie", 1200 }] = true;
    leaderboard[{ "P002", "Bob", 1500 }] = true;
    leaderboard[{ "P005", "David", 1800 }] = true;
    leaderboard[{ "P004", "Alice", 1000 }] = true;
    leaderboard[{ "P007", "Emily", 1200 }] = true;
    leaderboard[{ "P006", "Bob", 1500 }] = true;

    std::cout << "\n===== Leaderboard =====\n";
    int rank = 1;
    for (const auto& entry : leaderboard) {
        const PlayerStats& p = entry.first;

        std::cout << "Rank " << rank++ << " -> "
             << "ID: " << p.playerId
             << ", Name: " << p.playerName
             << ", Score: " << p.score << std::endl;
    }
}