#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

//Input:
//7 30 5
//6 50 8
//7 20 7
//12 40 9
//13 50 11
//23 10 7

//Output:
//80




struct car {
public:
    long long position = 0;
    long long time = 0;
    long long movement = 0;

    car(long long pos, long long tim, long long mov) {
        position = pos;
        time = tim;
        movement = mov;
    }

};



vector<car> cars;
map<long long,unsigned long long> hashcar;
long long R=0, N=0, E=0;

long long backtrack(long long reach, long long startPosition=0, long long remained=-1) {
    long long min = INT8_MAX;
    long long result = INT8_MAX;
    bool foundCar = false;


    //if we reached the end with the current energy return the current car
    if (remained!=-1 && cars[remained].movement + startPosition >= N) return cars[remained].time;

    

    for (unsigned long long i = remained+1; i < cars.size(); ++i) {
        
        //check only the car we can reach
        if (cars[i].position <= startPosition + reach) {
            foundCar = true;
            if (hashcar.find(cars[i].position) == hashcar.end()) {//not found
                result= backtrack(cars[i].movement, cars[i].position, i);
                if (result != INT8_MAX) {
                    //if there is a path to end add the current time + time it takes to get there
                    if (min > result) {
                        if(remained!=-1)
                        hashcar[cars[remained].position] = result + cars[remained].time;
                        min = result;
                    }
                }
                else {
                    //if there is no path to end
                    if (remained != -1 && hashcar.find(cars[remained].position) == hashcar.end())
                    hashcar[cars[remained].position] = INT8_MAX;

                    hashcar[cars[i].position] = INT8_MAX;
                }
                
            }
            else {//found,find if there is a path
                //if there is a path compare the current best time with the one from the new one.
                long long found = hashcar[cars[i].position];
                if (found == INT8_MAX && remained!=-1 && hashcar.find(cars[remained].position) == hashcar.end()) {
                    hashcar[cars[remained].position]=INT8_MAX;
                }else
                if (found<min ) {
                    if (remained != -1)
                    hashcar[cars[remained].position] = found+cars[remained].time;
                    min = found;
                }

            }
        
        }
        else 
            break;
    }

    //if there is no car => there is no path
    if (!foundCar)return INT8_MAX;

    //return current car time
    if (remained != -1)
        return hashcar[cars[remained].position];
    else
        return min;//if we are at begging just return the min
}

int main()
{
     ifstream in("ice.in");
     ofstream out("ice.out");
    
    in >> R >> N >> E;
    for (unsigned int i = 0; i < E; ++i) {
        long long d, t, r;
        in >> d >> t >> r;
        cars.push_back(car(d, t, r));
    }



    if(R>=N)
        out<<0;
    else {
        long long result= backtrack(R);
        if (result == INT8_MAX) 
            out << -1;
        else 
            out << result;
    }
        

    


    in.close();
    out.close();
    return 0;
}

