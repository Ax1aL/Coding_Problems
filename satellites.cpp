#include <iostream>
#include<vector>
#include<fstream>

using namespace std;

vector<long long> weight;


//Input:
//5 3
//1 2 2 1 2

//Output:
//3


int main()
{
    ifstream in("satellites.in");
    ofstream out("satellites.out");


    long long n = 0, k = 1;
    in >> n >> k;
    //CASE k==n(highest) and k==1(sum)

    if (k == n) {
        long long max = 0;
        for (int i = 0; i < n; ++i) {
            long long temp = 0;
            in >> temp;
            if (temp > max)max = temp;
        }
        out << max;

        in.close();
        out.close();
        return 0;
    }
    if (k == 1) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long temp = 0;
            in >> temp;
            sum += temp;
        }
        out << sum;

        in.close();
        out.close();
        return 0;
    }

    unsigned long long max = 0;
    unsigned long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long temp;
        in >> temp;
        if (max < temp)max = temp;
        sum += temp;
        weight.push_back(temp);
    }

    bool found = false;

    for (unsigned long long i = max; i <= sum; ++i) {
        long long tempK = k;
        unsigned long long tempSum = 0;
        for (int j = 0; j < n; ++j) {

            if (tempSum + weight[j] > i) {
                tempSum = weight[j];
                --tempK;
            }
            else {
                tempSum += weight[j];
            }
            if (tempK == 0)break;
            if (j == n - 1 && tempSum <= i)
                found = true;
        }
        if (found)
        {
            out << i;
            break;
        }

    }




    in.close();
    out.close();
    return 0;
}

