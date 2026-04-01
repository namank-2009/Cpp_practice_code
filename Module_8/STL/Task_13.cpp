#include<iostream>
#include<vector>
#include<chrono>
#include<map>
#include <bits/stdc++.h>
using namespace std;

const int NUM_WORDS = 100000; 
const int NUM_LOOKUP_TESTS = 10000; 
const int NUM_NONEXISTENT_WORDS = 10000;

using WordVector = std::vector<std::string>; 
using MilliSeconds = std::chrono::duration<double, std::milli>;

template <typename Func>
double measureTime(const string& description, Func func) {
    auto start = chrono::high_resolution_clock::now();

    func();

    auto end = chrono::high_resolution_clock::now();
    MilliSeconds duration = end - start;

    cout << fixed << setprecision(3);
    cout << " " << left << setw(35) << description + ":" 
         << duration.count() << " ms" << endl;

    return duration.count();
}

WordVector generateWords(int count, const string& prefix) {
    WordVector words;
    words.reserve(count);

    for (int i = 0; i < count; i++) {
        words.push_back(prefix + to_string(i));
    }

    return words;
}

template <typename MapType>
void conditionallyReserve(MapType& mp, size_t count) {
    if constexpr (is_same_v<MapType, unordered_map<string, int>>) {
        mp.reserve(count);
    }
}

template <typename MapType>
void benchmarkContainer(const string& name,
                        const WordVector& words,
                        const WordVector& non_exist) {

    cout << "\n===== " << name << " =====" << endl;

    MapType mp;

    // Reserve if unordered_map
    conditionallyReserve(mp, words.size());

    // 1. Insertion
    measureTime("Insertion", [&]() {
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }
    });

    // 2. Lookup Existing
    volatile int found = 0;

    measureTime("Lookup (Existing Keys)", [&]() {
        for (int i = 0; i < NUM_LOOKUP_TESTS; i++) {
            auto it = mp.find(words[i]);
            if (it != mp.end()) {
                found++;
            }
        }
    });

    // 3. Lookup Non-Existing
    volatile int not_found = 0;

    measureTime("Lookup (Non-Existing Keys)", [&]() {
        for (int i = 0; i < NUM_NONEXISTENT_WORDS; i++) {
            auto it = mp.find(non_exist[i]);
            if (it == mp.end()) {
                not_found++;
            }
        }
    });

    cout << " Final Size: " << mp.size() << endl;
}

int main(){
    cout << "===== Benchmark: std::map vs std::unordered_map =====\n" << endl;

    // --- Data Preparation ---
    cout << "Generating " << NUM_WORDS << " words..." << endl;
    WordVector words = generateWords(NUM_WORDS, "word_");

    cout << "Generating non-existing words..." << endl;
    WordVector non_exist = generateWords(NUM_NONEXISTENT_WORDS, "no_word_");

    cout << "Data ready.\n" << endl;

    // --- Benchmark ---
    benchmarkContainer<map<string, int>>(
        "std::map<string,int>", words, non_exist
    );

    benchmarkContainer<unordered_map<string, int>>(
        "std::unordered_map<string,int>", words, non_exist
    );

    cout << "\n===== Benchmark Complete =====" << endl;

}