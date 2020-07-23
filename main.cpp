#include <fstream>
#include <istream>
#include <iostream>
#include <math.h>
#include <time.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

const int kStudents = 25;
const int kProblemSets = 10;

// This function returns the highest grade in the Problem Set array.
int get_high_grade(int *a, int cols, int row, int col) {
  int i, j;
  int highgrade = *a;


  for (i = 0; i < row; i++){

    for (j = 0; j < col; j++){

        if (*(a + i * cols + j) > highgrade){// How does this line work?
         highgrade = *(a + i*cols + j);
      }

    }
  }

  return highgrade;
}

/*int main() {
 int grades[kStudents][kProblemSets] = {
   {75, 70, 85, 72, 84},
   {85, 92, 93, 96, 86},
   {95, 90, 83, 76, 97},
   {65, 62, 73, 84, 73}
 };
 int std_num = 4;
 int ps_num = 5;
 int highest;

 highest = get_high_grade((int *)grades, kProblemSets, std_num, ps_num);
 cout << "The highest problem set score in the class is " << highest << endl;

 return 0;
}*/

/*int main()
{
    // initializing the 3-dimensional array
    int first = 0;
    int second = 0;
    int third = 0;
    int result = 0;
    int x[2][3][2] =
    {
        { {0,1}, {2,3}, {4,5} },
        { {6,7}, {8,9}, {10,11} }
    };

    // output each element's value
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                cout << "Element at x[" << i << "][" << j
                     << "][" << k << "] = " << x[i][j][k]
                     << endl;
            cout<<"=============================="<<endl;
                     result = i + j +k;
                     x[i][j][k]= result;
                     cout << x[i][j][k]
                     << endl;

            }
        }
    }
    return 0;
}*/
/*
int main()
{

    int result = 0;
     int x[1][3][5] =
    {
        { {75, 70, 85, 72, 84}, {85, 205, 93, 96, 86}, {95, 90, 83, 76, 97}}
    };

    // output each element's value
    for (int i = 0; i < 1; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for(int k = 0; k<5;++k){
                if(x[i][j][k] > result){
                    result =(int) x[i][j][k];
                }
            }


        }
    }
    cout<<"Highest Mark: "<<result<<endl;
    return 0;
}

*/
bool binarySearch(vector<int>array, int numberToSearch, int low, int high) {

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == numberToSearch)
      return true;

    if (array[mid] < numberToSearch)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return true;
}


int main(){

  vector<int> sortedNumb;
  vector<int>primes;
  vector<int>allPrimes;
  set<int>removeDuplicate;

  int res ;
  int exhaust;
  int randNum;
  string file_name= "ttt.txt";
  ofstream People(file_name, ios::out);
  // Write the output to the stream.
  cout<<"How many Number you want to generate?"<<endl;
  cin>>exhaust;
  cout<<"Maximum Number For Random Number? Like 400,500"<<endl;
  cin>>randNum;
  srand (time(NULL));
  for(int i = 0;i<exhaust;i++){

    res = (int )rand() % randNum + 1;
    People  << res <<" ";
    if(i % 5 == 0){
        People<<endl;
    }

  }
  // Close the stream.
  People.close();

  int p = 0;
  ifstream People_in(file_name);
  int highNumber = 0;
  while(p < exhaust){

        People_in >> res;
        sortedNumb.push_back(res);
        //cout<<res<<" ";
        //if(i % 5 == 0){
        // cout<<endl;
        //}
        //if(res > highNumber){
        //    highNumber = res;
        //}
        p++;
  }
  People_in.close();

//sort func

  for(int i = 0;i<exhaust;i++){
    for(int j = i + 1; j<exhaust;j++){
        if(sortedNumb[i] < sortedNumb[j]){
            int temp = sortedNumb[j];
            sortedNumb[j] = sortedNumb[i];
            sortedNumb[i] = temp;
        }
    }
  }
   int counter = 1;
   for(auto i: sortedNumb){
    cout<<i<<" ";
    if(counter % 5 == 0){
        cout<<endl;
    }
    counter++;
   }

   for(auto i: sortedNumb){
     if(i > highNumber){
        highNumber = i;
     }
    }
    cout<<endl;
    cout<<"================================"<<endl;
    cout<<"Higest Number: "<<highNumber<<endl;
    cout<<"================================"<<endl;

    int number;
    int foundNumber = false;
    cout<<"Enter Number to find"<<endl;
    cin>>number;

  //  for(int i = 0; i<sortedNumb.size(); i++){
   //         if(sortedNumb[i] == number){
   //             foundNumber = true;
   //         }

   // }


  int sizeOfsortedList = sortedNumb.size();
  foundNumber = binarySearch(sortedNumb, number, 0, sizeOfsortedList - 1);

    if(foundNumber){
        cout<<"Found It"<<endl;

    }else{
         cout<<"Sorry"<<endl;
    }


    cout<<"Showing All Prime Numbers "<<endl;

   int n = randNum;
    bool arr[n];
    for(int i = 0; i< n; i++){
        arr[i] = true;
    }

    for(int i = 2; i<n; i++){
        if(arr[i]){
            for(int c= i; i* c<n ;c++){
                arr[i * c] = false;
            }
        }
    }

    for(int i = 1; i<n; i++){
        if(arr[i]){
            primes.push_back(i);
        }
    }

    for(auto i: primes){
        for(auto j:sortedNumb){
            if(i == j){
             removeDuplicate.insert(i);
            }
        }
    }
    cout<<"+++++++++++++++++++++++++"<<endl;


    for(auto i: removeDuplicate){
       cout<<i<<" ";
    }



}
