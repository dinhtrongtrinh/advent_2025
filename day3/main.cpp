#include <bits/stdc++.h>
using namespace std;

int highest_2_digits(string line){
    char first = 0;
    char second = 0;
    for(int i = 0; i < line.length() - 1 ; i++){
        if(line[i] > first){
            first = line[i];
            second = 0;
        }
        else if(line[i] > second){
            second = line[i];
        }
    }
    if(line[line.length() - 1] > second){
        second = line[line.length() - 1];
    }
    return (first - '0') * 10 + (second - '0');
}
long long heighest_12_digit(string line){
    char digits[12] = {0};
    int u = 0; 
    int start = 0;
    while (u < 12){
        for (int i = start; i < line.length() - (11 - u); i++){
            if(line[i] > digits[u]){
                digits[u] = line[i];
                start = i + 1;
            }
        }
        cout<<start<<" ";
        u++;
    }
    long long number = 0;
    for (int i = 0; i < 12; i++){
        number = number * 10 + (digits[i] - '0');
    }
    return number;
}



int main(int argc, char *argv[]){
    ifstream infile("input.txt");
    string line;
    int number;
    long long number2;
    int answer1 = 0;
    long long answer2 = 0;
    while (getline (infile, line)) {
        // Output the text from the file
        number = highest_2_digits(line);
        cout << number << endl;
        answer1 += number;
        number2 = heighest_12_digit(line);
        cout << number2 << endl;
        answer2 += number2;
      }
    cout << "Answer 1: " << answer1 << endl;
    cout << "Answer 2: " << answer2 << endl;
    infile.close();
    return 0;
}

