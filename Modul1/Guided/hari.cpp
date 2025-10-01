#include <iostream>
using namespace std;
int main()
{
    int hari;
    cout << "hari 1-7: ";
    cin >> hari;
    if (hari == 7)
    {
    cout << "hari minggu\n";
    }
    else{
    cout << "hari kerja\n";
    }
    switch (hari)
    {
    case 7:
        cout << "hari minggu\n";
        break;
    default: 
        cout << "hari kerja\n";
        break;
    }
}