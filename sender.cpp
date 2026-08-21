#include <iostream>
using namespace std;

int main()
{
    int h[12];

    cout << "Enter 11-bit received Hamming code: ";

    string code;
    cin >> code;

    // Store received code
    // Input is from position 11 to position 1

    for(int i = 0; i < 11; i++)
    {
        h[11 - i] = code[i] - '0';
    }

    // Calculate parity checks

    int R1 = h[1] ^ h[3] ^ h[5] ^ h[7] ^ h[9] ^ h[11];

    int R2 = h[2] ^ h[3] ^ h[6] ^ h[7] ^ h[10] ^ h[11];

    int R4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    int R8 = h[8] ^ h[9] ^ h[10] ^ h[11];

    cout << "\nR1 = " << R1;
    cout << "\nR2 = " << R2;
    cout << "\nR4 = " << R4;
    cout << "\nR8 = " << R8 << endl;

    // Calculate error position
    int errorPosition = R1 * 1 +
                        R2 * 2 +
                        R4 * 4 +
                        R8 * 8;

    if(errorPosition == 0)
    {
        cout << "\nNo error detected." << endl;
    }
    else
    {
        cout << "\nError detected at position: "
             << errorPosition << endl;

        // Correct the error
        h[errorPosition] = h[errorPosition] ^ 1;

        cout << "Corrected Hamming code: ";

        for(int i = 11; i >= 1; i--)
        {
            cout << h[i];
        }

        cout << endl;
    }

    return 0;
}