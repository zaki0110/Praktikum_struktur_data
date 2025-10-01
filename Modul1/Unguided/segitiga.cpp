#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Masukan Tinggi : ";
    if (!(cin >> n) || n < 0)
    {
        cout << "Tinggi tidak valid\n";
        return 1;
    }
    for (int i = n; i >= 1; --i)
    {
        int spasiDepan = n -i;
        for (int s = 0; s < spasiDepan; ++s) cout << " ";
        for (int a = i; a >= 1; --a) cout << a;
        cout << "*";
        for (int b = 1; b <= i; ++b) cout << b;
        cout << "\n";
    }
    for (int s = 0; s < n; ++s) cout << " ";
    cout << "*" << "\n";
    return 0;
    
    
}