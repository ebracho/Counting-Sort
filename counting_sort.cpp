#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int MAX = 50;

bool counting_sort(const int min, const int max, vector<int>& numbers) {

    vector<int> number_index(max - min);

    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] < min || numbers[i] > max) return false;
        number_index[numbers[i]]++;
    }

    numbers.clear();

    for(int i = 0; i < number_index.size(); i++) {
        for(int j = 0; j < number_index[i]; j++) {
            numbers.push_back(min + i);
        }
    }
}

int main() {
    
    ofstream unsorted("unsorted.txt");
    ofstream sorted("sorted.txt");
    srand(time(NULL));
    vector<int> numbers(0);

    for(int i = 0; i < MAX; i++) {
        numbers.push_back(rand()%100);
        unsorted << numbers[i] << endl;
    }

    counting_sort(0, 100, numbers);

    for(int i = 0; i < MAX; i++) {
        sorted << numbers[i] <<  endl;
    }
    
    return 0;
}
