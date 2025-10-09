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
    for (int i = 1; i <= n; ++i)
    {
        for (int b = 1; b <= i; ++b) cout << b << " ";
        cout << "\n";
    }
    
    
}