#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string pre_process(string s) {
    string hash;
    for (int i = 0; i < s.size(); i++) {
        hash.append(std::bitset<8>(s[i]).to_string());
    }

    hash.push_back('1');

    int original_length = hash.size();
    while ((hash.size() + 64) % 512 != 0)
        hash.push_back('0');
    hash.append(std::bitset<64>(original_length).to_string());

    return hash;
}

void createMessageSchedule(string s, string *w) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        w[count].push_back(s[i]);
        if (i / 32 == count)
            count++;
    }

    count++;
    for (int i = count; i < 64; i++) {
        w[i] = "00000000000000000000000000000000";
    }
    for (int i = 0; i < 64; i++)
        cout << w[i] << endl;
}

int main() {
    string s;
    getline(cin, s);
    string hash = pre_process(s);
    cout << hash << endl;
    const string h0 = "0x6a09e667";
    const string h1 = "0xbb67ae85";
    const string h2 = "0x3c6ef372";
    const string h3 = "0xa54ff53a";
    const string h4 = "0x510e527f";
    const string h5 = "0x9b05688c";
    const string h6 = "0x1f83d9ab";
    const string h7 = "0x5be0cd19";

    cout << h0;

}
