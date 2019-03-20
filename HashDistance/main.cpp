//Method 3

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int arraySize =  4000037;
long long arrayMain[arraySize];
long long dataSet=1000000;

long checkNum(long num){
    
    num = abs(num % arraySize);
    
    return num;
}

long distanceK (long num){
    
    num = abs((checkNum(num)%dataSet)-num) % dataSet;
    
    return num;
}

long distanceD (long num){
    num = abs((checkNum(num)%dataSet)-num) % dataSet;
    
    return num;
}

void distanceCalculation(long long pos,long long val){
    if(pos==arraySize-1) {
        pos=0;}
    else {
        pos++;
    }
    if(arrayMain[pos]==0)
    {
        arrayMain[pos]=val;
    }
    else if (distanceD(val) <= distanceK(arrayMain[pos])) {
        long long temp;
        temp=arrayMain[pos];
        arrayMain[pos] = distanceD(val);
        distanceCalculation(pos, temp);
    }
    else if(distanceK(arrayMain[pos])<=distanceD(val)){
        distanceCalculation(pos, val);
    }
}


int main() {
    long long temporary = 0;
    long long position;
    int counter = 0;
    ifstream in;
    
    in.open("progr3-data-set.txt");
    
    clock_t begin = clock();
    for (int i=0; i<arraySize; i++) {
        arrayMain[i] = 0;
    }
    
    for (int i = 0; i < 1000000; i++) {
        in >> temporary;
        
        position = checkNum(temporary);
        
        distanceCalculation(position, temporary);
    }
    for (int i=0; i<arraySize; i++) {
        if (arrayMain[i] != 0)
        {
            //cout<<arrayMain[i]<<endl;
            counter ++;
        }
    }
      clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout <<"Time Taken: " << elapsed_secs << " Seconds" <<endl;
    cout << counter << " values stored" << endl;
    
    in.close();
     return 0;
}
