#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of frames: ";
    cin >> n;

    srand(time(0));

    int frame = 1;

    while (frame <= n)
    {
        cout << "\n";
        cout << "----------------------------------------";
        cout << "\n           FRAME " << frame << " START";
        cout << "\n----------------------------------------\n";

        bool acknowledged = false;

        while (!acknowledged)
        {
            cout << "Sender   : Sending Frame " << frame << "...\n";

            this_thread::sleep_for(chrono::seconds(1));

            int lost = rand() % 3;   

            if (lost == 0)
            {
                cout << "Channel  : Frame " << frame << " LOST!\n";

                cout << "Sender   : Waiting for ACK...\n";

                this_thread::sleep_for(chrono::seconds(2));

                cout << "Sender   : TIMEOUT!\n";
                cout << "Sender   : No ACK received.\n";

                cout << "Sender   : Retransmitting Frame "
                     << frame << "...\n";

                this_thread::sleep_for(chrono::seconds(1));
            }
            else
            {
                cout << "Receiver : Frame " << frame
                     << " received successfully.\n";

                cout << "Receiver : Sending ACK "
                     << frame << "...\n";

                this_thread::sleep_for(chrono::seconds(1));

                cout << "Sender   : ACK " << frame
                     << " received.\n";

                acknowledged = true;
            }
        }

        cout << "\nFrame " << frame
             << " completed successfully.\n";

        frame++;
    }

    cout << "\n========================================";
    cout << "\n       ALL FRAMES TRANSMITTED";
    cout << "\n========================================\n";

    return 0;
}