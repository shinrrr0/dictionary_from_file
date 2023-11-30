#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void clear(string& tmp, vector<string>& forbbiden)
{
    int sub_string_pos;
    for (int i = 0; i < tmp.size(); ++i) {
        tmp[i] = tolower(tmp[i]);
    }
    for (auto& elem : forbbiden) {
        
        sub_string_pos = tmp.rfind(elem);
        if (sub_string_pos >= 0)
        {
            tmp.erase(tmp.begin() + sub_string_pos, tmp.begin() + sub_string_pos + elem.size());
        }
    }
}

bool is_in_vector(string& tmp, vector<string>& vector) {
    for (auto& elem : vector) {
        if (elem == tmp) {
            return true;
        }
    }
    return false;
}


int main()
{
    vector<string> forbbiden{
        string{'"'}, "...", ".", ",", ";", "!", "?", "'m", "(", ")", ":", "\\", "'t", "'ve", "'s",  "'d", "'re", "'ll", "--", "'", "'", "-", string{'"'},
    };
    set<string> s_dictionary;
    vector<string> v_dictionary;

    clock_t start_time = clock();
    ifstream f1("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");
    string tmp;
    while (!f1.eof())
    {
        f1 >> tmp;
        clear(tmp, forbbiden);
        if (!tmp.empty())
        {
            s_dictionary.insert(tmp);
        }
    }
    f1.close();

    clock_t first_stop = clock();

    ifstream f2("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");
    while (!f2.eof())
    {
        f2 >> tmp;
        clear(tmp, forbbiden);
        if (!tmp.empty())
        {
            if (!is_in_vector(tmp, v_dictionary)) {
                v_dictionary.push_back(tmp);
            }
        }
    }
    f2.close();
    std::sort(v_dictionary.begin(), v_dictionary.end());

    clock_t second_stop = clock();

    cout << "set dictionary: " << float(first_stop - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "vector dictionary: " << float(second_stop - first_stop) / CLOCKS_PER_SEC << " seconds" << endl;

    //for (auto& elem : s_dictionary) {
    //    cout << elem << endl;
    //}

    //for (auto& elem : v_dictionary) {
    //    cout << elem << endl;
    //}

}
