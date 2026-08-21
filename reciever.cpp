#include <iostream>
using namespace std;

int main()
{
    int h[12] = {0};
    
    // Data word = 1011001
    // Positions: 11 10 9 8 7 6 5 4 3 2 1
    //            D  D  D R D D D R D R R
    
    h[11] = 1;
    h[10] = 0;
    h[9] = 1;
    h[7] = 1;
    h[6] = 0;
    h[5] = 0;
    h[3] = 1;
    
    // Even parity calculations
    
    // R1 checks positions 1,3,5,7,9,11
    h[1] = h[3] ^ h[5] ^ h[7] ^ h[9] ^ h[11];
    
    // R2 checks positions 2,3,6,7,10,11
    h[2] = h[3] ^ h[6] ^ h[7] ^ h[10] ^ h[11];
    
    // R4 checks positions 4,5,6,7
    h[4] = h[5] ^ h[6] ^ h[7];
    
    // R8 checks positions 8,9,10,11
    h[8] = h[9] ^ h[10] ^ h[11];
    
    // Outputting the values of parity bits at 1, 2, 4, 8
    cout <<"Data word: 1011001" << endl;
    cout << "Value at position 1 (R1): " << h[1] << endl;
    cout << "Value at position 2 (R2): " << h[2] << endl;
    cout << "Value at position 4 (R4): " << h[4] << endl;
    cout << "Value at position 8 (R8): " << h[8] << endl;
    cout << "Hamming code :";
     //print from position 11 to 1 
     for (int i=11; i>=1;i--)
     {
        cout<< h[i];
     }
      cout<< endl;
      return 0;
}