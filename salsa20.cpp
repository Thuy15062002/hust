// salsa20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

void Quarterround_Function(long long int a[], long long int result[]) {
    long long int x = pow(2, 32);
    long long int y;
    for (int i = 0; i < 4; i ++ ) {
        if (i == 0)
        {
            y = (a[1] ^ ((a[0] + a[3]) % x));
            result[1] = y << 7;
        }
        if (i == 1)
        {
            y = (a[2] ^ ((result[1] + a[0]) % x));
            result[2] = y << 9;
        }
        if (i == 2)
        {
            y = (a[3] ^ ((result[2] + result[1]) % x));
            result[3] = y << 13;
        }
        if (i == 3)
        {
            y = (a[0] ^ ((result[3] + result[2]) % x));
            result[0] = y << 18;
        }
    }

}


void Rowround_Function(long long int a[], long long int result[]) {
    long long int x[4];
    long long int y[4];
    for (int i = 0; i < 4; i++) {
        if (i == 0)
        {
            for (int j = 0; j < 4; j++) {
                x[j] = a[j];
                Quarterround_Function(x, y);
                result[j] = y[j];
            }
        }
        if (i == 1)
        {
            x[0] = a[5];
            x[1] = a[6];
            x[2] = a[7];
            x[3] = a[4];
            Quarterround_Function(x, y);
            result[5] = y[0];
            result[6] = y[1];
            result[7] = y[2];
            result[4] = y[3];
        }
        if (i == 2)
        {
            x[0] = a[10];
            x[1] = a[11];
            x[2] = a[8];
            x[3] = a[9];
            Quarterround_Function(x, y);
            result[10] = y[0];
            result[11] = y[1];
            result[8] = y[2];
            result[9] = y[3];
        }
        if (i == 3)
        {
            x[0] = a[15];
            x[1] = a[12];
            x[2] = a[13];
            x[3] = a[14];
            Quarterround_Function(x, y);
            result[15] = y[0];
            result[12] = y[1];
            result[13] = y[2];
            result[14] = y[3];
        }
    }
}

void Columnround_Function(long long int a[], long long int result[]) {
    long long int x[4];
    long long int y[4];
    for (int i = 0; i < 4; i++) {
        if (i == 0)
        {
            for (int j = 0; j < 4; j++) {
                x[j] = a[j*4];
                Quarterround_Function(x, y);
                result[j*4] = y[j];
            }
        }
        if (i == 1)
        {
            x[0] = a[5];
            x[1] = a[9];
            x[2] = a[13];
            x[3] = a[1];
            Quarterround_Function(x, y);
            result[5] = y[0];
            result[9] = y[1];
            result[13] = y[2];
            result[1] = y[3];
        }
        if (i == 2)
        {
            x[0] = a[10];
            x[1] = a[14];
            x[2] = a[2];
            x[3] = a[6];
            Quarterround_Function(x, y);
            result[10] = y[0];
            result[14] = y[1];
            result[2] = y[2];
            result[6] = y[3];
        }
        if (i == 3)
        {
            x[0] = a[15];
            x[1] = a[3];
            x[2] = a[7];
            x[3] = a[11];
            Quarterround_Function(x, y);
            result[15] = y[0];
            result[3] = y[1];
            result[7] = y[2];
            result[11] = y[3];
        }
    }
}

void Doubleround_Function(long long int a[], long long int result[]) {
    long long int x[16];
    Columnround_Function(a, x);
    Rowround_Function(x, result);
}

void Littleendian_Function(long long int a[])
{
    long long int result = a[0] + a[1] * pow(2, 8) + a[2] * pow(2, 16) + a[3] * pow(2, 24);
}
int main() {
    long long int a[64];
    long long int w[15];

}

