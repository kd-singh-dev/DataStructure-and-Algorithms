/*
Most problems on CodeChef highlight chef's love for food and cooking but little is known about his love for racing sports. He is an avid Formula 1 fan. He went to watch this year's Indian Grand Prix at New Delhi. He noticed that one segment of the circuit was a long straight road. It was impossible for a car to overtake other cars on this segment. Therefore, a car had to lower down its speed if there was a slower car in front of it. While watching the race, Chef started to wonder how many cars were moving at their maximum speed.

Formally, you're given the maximum speed of N cars in the order they entered the long straight segment of the circuit. Each car prefers to move at its maximum speed. If that's not possible because of the front car being slow, it might have to lower its speed. It still moves at the fastest possible speed while avoiding any collisions. For the purpose of this problem, you can assume that the straight segment is infinitely long.

Count the number of cars which were moving at their maximum speed on the straight segment.

Input
The first line of the input contains a single integer T denoting the number of test cases to follow. Description of each test case contains 2 lines. The first of these lines contain a single integer N, the number of cars. The second line contains N space separated integers, denoting the maximum speed of the cars in the order they entered the long straight segment.

Output
For each test case, output a single line containing the number of cars which were moving at their maximum speed on the segment.

Example
Input:
3
1
10
3
8 3 6
5
4 5 1 2 3

Output:
1
2
2
Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 10,000
All speeds are distinct positive integers that fit in a 32 bit signed integer.
Each input file will not be larger than 4 MB (4,000,000,000 bytes) in size.

WARNING! The input files are very large. Use faster I/O.

All submissions for this problem are available.
Author: 4★yellow_agony
Tester: 1★gamabunta
Date Added: 2-09-2012
Time Limit: 2 secs
Source Limit:   50000 Bytes
Languages:  CPP14, C, JAVA, PYTH 3.6, PYTH, CS2, ADA, PYP3, TEXT, PAS fpc, RUBY, PHP, NODEJS, GO, TCL, HASK, PERL, SCALA, BASH, JS, PAS gpc, BF, LISP sbcl, CLOJ, LUA, D, CAML, ASM, FORT, FS, LISP clisp, SCM guile, PERL6, CLPS, WSPC, ERL, ICK, NICE, PRLG, ICON, PIKE, SCM qobi, ST, NEM
Submit
My SubmissionsAll Submissions
Successful Submissions

*/

#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    int t,n,max_speed_of_car,prev_car_speed,currrent_car_speed;
    cin>>t;
    
    while(t--){
    cin>>n;
    int counter=0;
    prev_car_speed=2147483647;
    for(int i=1;i<=n;i++){
        cin>>max_speed_of_car;
        // cout<<max_speed_of_car<<endl;
        currrent_car_speed=min(max_speed_of_car,prev_car_speed);
        prev_car_speed=currrent_car_speed;
        if(currrent_car_speed==max_speed_of_car){
            counter++;
        }
    }
    cout<<counter<<endl;
    }
    return 0;
}