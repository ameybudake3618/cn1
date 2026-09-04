#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Check if IPv4 address is valid and extract octets
bool isValid(string ip, int octet[])
{
    stringstream ss(ip);
    string part;
    int count = 0;

    while (getline(ss, part, '.'))
    {
        // More than 4 octets
        if (count >= 4 || part.empty())
            return false;

        // Check all characters are digits
        for (char ch : part)
        {
            if (!isdigit(ch))
                return false;
        }

        int num;

        try
        {
            num = stoi(part);
        }
        catch (...)
        {
            return false;
        }
        
        if (num < 0 || num > 255)
            return false;

        octet[count] = num;
        count++;
    }

    // IPv4 must have exactly 4 octets
    return count == 4;
}

// Convert decimal number to 8-bit binary
string decimalToBinary(int num)
{
    string binary = "";

    for (int i = 7; i >= 0; i--)
    {
        binary += ((num >> i) & 1) ? '1' : '0';
    }

    return binary;
}

// Convert complete decimal IP to binary
string ipToBinary(int octet[])
{
    string result = "";

    for (int i = 0; i < 4; i++)
    {
        result += decimalToBinary(octet[i]);

        if (i != 3)
            result += ".";
    }

    return result;
}

// Convert integer array to dotted decimal string
string toDottedDecimal(int arr[])
{
    return to_string(arr[0]) + "." +
           to_string(arr[1]) + "." +
           to_string(arr[2]) + "." +
           to_string(arr[3]);
}

int main()
{
    string ip;
    int octet[4];

    cout << "Enter IPv4 address in decimal form: ";
    cin >> ip;

    // Validate IP address
    if (!isValid(ip, octet))
    {
        cout << "\nInvalid IPv4 Address!" << endl;
        return 0;
    }

    cout << "\nValid IPv4 Address!" << endl;

    int firstOctet = octet[0];

    string ipClass;
    string defaultMask;
    int networkBits;

    if (firstOctet >= 1 && firstOctet <= 126)
    {
        ipClass = "Class A";
        defaultMask = "255.0.0.0";
        networkBits = 8;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        ipClass = "Class B";
        defaultMask = "255.255.0.0";
        networkBits = 16;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        ipClass = "Class C";
        defaultMask = "255.255.255.0";
        networkBits = 24;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "Class: Class D" << endl;
        cout << "Used for Multicast." << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }
    else
    {
        cout << "Class: Class E" << endl;
        cout << "Reserved for Experimental Use." << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }

   
    int netID[4] = {0, 0, 0, 0};
    int hostID[4] = {0, 0, 0, 0};


    if (networkBits == 8)        
    {
        netID[0] = octet[0];

        hostID[1] = octet[1];
        hostID[2] = octet[2];
        hostID[3] = octet[3];
    }
    else if (networkBits == 16)    
    {
        netID[0] = octet[0];
        netID[1] = octet[1];

        hostID[2] = octet[2];
        hostID[3] = octet[3];
    }
    else if (networkBits == 24)   
    {
        netID[0] = octet[0];
        netID[1] = octet[1];
        netID[2] = octet[2];

        hostID[3] = octet[3];
    }

    cout << "\n========== OUTPUT ==========" << endl;

    cout << "\nIPv4 Address (Decimal): "
         << ip << endl;

    cout << "IPv4 Address (Binary):  "
         << ipToBinary(octet) << endl;

    cout << "\nIP Class: "
         << ipClass << endl;

    cout << "Default Subnet Mask: "
         << defaultMask << endl;

    cout << "\nNetwork ID:" << endl;

    cout << toDottedDecimal(netID) << endl;

    cout << "\nHost ID:" << endl;

    cout << toDottedDecimal(hostID) << endl;


    return 0;
}
