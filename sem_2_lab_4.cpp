#include <iostream>
#include <string>
#include <map>

using namespace std;

enum State {
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
};

bool belongsToLanguage(const string& word) {
    State state = Q0;
    
    map<State, map<char, State>> transitions = {
        {Q0, {{'a', Q2}, {'b', Q1}, {'c', Q1}, {'d', Q1}, {'e', Q0}}},
        {Q1, {{'a', Q3}, {'b', Q0}, {'c', Q0}, {'d', Q0}, {'e', Q1}}},
        {Q2, {{'a', Q2}, {'b', Q5}, {'c', Q1}, {'d', Q1}, {'e', Q0}}},
        {Q3, {{'a', Q3}, {'b', Q4}, {'c', Q0}, {'d', Q0}, {'e', Q1}}},
        {Q4, {{'a', Q2}, {'b', Q1}, {'c', Q6}, {'d', Q1}, {'e', Q0}}},
        {Q5, {{'a', Q3}, {'b', Q0}, {'c', Q7}, {'d', Q0}, {'e', Q1}}}
    };
    for (char ch : word) {
        state = transitions[state][ch];
        if (state == Q6 || state == Q7) return false;
    }
    return (state == Q0 || state == Q2 || state == Q4);
}

int main() {
    string test_words[] = {
        "", "a", "e", "aa", "ae",          // 0 согласных
        "bb", "abd", "abec", "abde", "aabb", "abdb", "cac", "dd", "cba",
        "b", "c", "d",                     // 1 согласная
        "abc", "abcd", "abca", "abcc", "aabc", "abcb", "dabc", "abcde"
    };
    
    int num_tests = sizeof(test_words) / sizeof(test_words[0]);
    
    cout << "Результаты тестирования:\n";
    cout << "Слово -> Принадлежит языку?\n";
    cout << "----------------------------\n";
    
    for (int i = 0; i < num_tests; i++) {
        string w = test_words[i];
        bool result = belongsToLanguage(w);
        cout << "\"" << (w.empty() ? "λ" : w) << "\" -> " 
             << (result ? "ДА" : "НЕТ") << endl;
    }
    
    return 0;
}
