#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;

//typedef struct

int _pow(int x, int y){
  if(y <= 0){return 1;}
  int i = 1;
  while(y > 0){
    i = i * x;
    y--;
  }
  return i;
}

int input_int(int upper){
  int a;
  while(1){
    cin >> a;
    if(!cin.fail()){
      if(a <= upper && a > 0){
        break;
      }
    }
    cout << "Error!" << endl;
    cin.clear();
    cin.ignore(1024, '\n');
  }
  /*
  for(int i = 0; i < (a * Time_Random()) % 10000; i++){
    int trash = rnd();
  }
  */
  //cout << "////////////////////////////////////////////////////////////////////////////" << endl;
  return a;
}

vector<vector<bool>> make_all_number2(vector<vector<bool>> numbers){
  vector<vector<bool>> _numbers;
  for(auto itr = numbers.begin(); itr != numbers.end(); itr++){
    auto a = *itr;
    a.push_back(true);
    itr->push_back(false);
    _numbers.push_back(*itr);
    _numbers.push_back(a);
  }
  return _numbers;
}

vector<vector<bool>> make_all_number(int length){
  vector<vector<bool>> numbers = {{0}, {1}};
  while(length > 1){
    numbers = make_all_number2(numbers);
    length -= 1;
  }
  return numbers;
}

void viewinnumber(vector<bool> number){
  cout << "::/";
  for(auto itr = number.begin(); itr != number.end(); itr++){
    if(*itr){cout << "1";}else{cout << "0";};
  }
  cout << endl;
}

void viewinnumbers(vector<vector<bool>> numbers){
  for(auto itr = numbers.begin(); itr != numbers.end(); itr++){
    viewinnumber(*itr);
  }
}

////////////////
int distance(vector<bool> number_a, vector<bool> number_b){
  assert(number_a.size() == number_b.size());
  int counter = 0;
  for(int i = 0; i < number_a.size(); i++){
    if(number_a[i] != number_b[i]){counter++;}
  }
  return counter;
}

bool isstock(vector<bool> number, vector<vector<bool>> *stock){
  for(auto itr = stock->begin(); itr != stock->end(); itr++){
    if(distance(number, *itr) == 0) return 1;
  }
  return 0;
}

int kind_number(vector<vector<bool>> numbers){
  vector<vector<bool>> stock;
  for(auto itr = numbers.begin(); itr != numbers.end(); itr++){
    if(!isstock(*itr, &stock)) stock.push_back(*itr);
  }
  return stock.size();
}

vector<vector<vector<bool>>> make_numbers(vector<vector<bool>> numbers){
  vector<vector<vector<bool>>> _numbers;
  int size = numbers.size();
  for(int i = 0; i < _pow(2, size); i++){
    vector<vector<bool>> numbers_alt;
    for(int j = 0; j < size; j++){
      auto number = numbers[j];
      if(i % _pow(2, j + 1) < _pow(2, j)){
        number.push_back(0);
      }else{
        number.push_back(1);
      }
      numbers_alt.push_back(number);
    }
    _numbers.push_back(numbers_alt);
  }
  return _numbers;
}

vector<int> distance_sum(vector<vector<bool>> numbers){
  int counter = 0;
  int minimum_distance = 10000;
  for(auto itr = numbers.begin(); itr != numbers.end(); itr++){
    for(auto itr2 = itr + 1; itr2 != numbers.end(); itr2++){
      int k = distance(*itr, *itr2);
      if(k < minimum_distance) minimum_distance = k;
      counter += k;
    }
  }
  return {counter, minimum_distance, kind_number(numbers)};
}

vector<vector<bool>> minimum_numbers(vector<vector<vector<bool>>> _numbers){
  int max_0 = 0;
  int min_1 = 0;
  int kind = 0;
  vector<vector<bool>> numbers;
  for(auto itr = _numbers.begin(); itr != _numbers.end(); itr++){
    vector<int> v = distance_sum(*itr);
    if(v[1] > min_1 || (v[1] == min_1 && v[2] > kind) || (v[1] == min_1 && v[2] == kind && v[0] > max_0)){
      numbers = *itr;
      max_0 = v[0];
      min_1 = v[1];
      kind = v[2];
    }
  }
  return numbers;
}

vector<vector<bool>> well_numbers(int number, int length){
  //step:0
  if(number >  _pow(2, length)){cout << "dual number is borned..." << endl;}
  vector<vector<bool>> numbers;
  //step:1
  for(int i = 0; i < number / 2; i++){
    numbers.push_back({0});
  }
  for(int i = 0; i < number - number / 2; i++){
    numbers.push_back({1});
  }
  //step:2..
  while(length > 1){
    numbers = minimum_numbers(make_numbers(numbers));
    viewinnumbers(numbers);
    length--;
  }
  return numbers;
}

//////////////////
int main(){
  cout << "DIGITAL_NUMBER://" << endl;
  int digitalnumber = input_int(99);
  cout << "LENGTH://" << endl;
  int length = input_int(512);
  viewinnumbers(well_numbers(digitalnumber, length));
  /*
  cout << "TEST://" << endl;
  cout << "  distance_sum" << endl;
  auto _ds = distance_sum({{0, 1, 1, 1}, {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}});
  cout << "(" << _ds[0] << ", " << _ds[1] << ")" << endl;

  //cout << "  make_numbers" << endl;

  vector<vector<vector<bool>>> vvv;
  vvv = make_numbers({{0, 0, 1}, {0, 1, 0}, {1, 0, 0}});
  for(auto itr = vvv.begin(); itr != vvv.end(); itr++){
    viewinnumbers(*itr);
    cout << "distance_sum = (";
    vector<int> ds = distance_sum(*itr);
    cout << ds[0] << ", " << ds[1] << ")";
    cout << endl;
    cout << "//" << endl;
  }
//  cout << "  minimum_numbers" << endl;
//  viewinnumbers(minimum_numbers(vvv));

/*
  cout << "  _pow" << endl;
  for(int i = 0; i < 10; i++){
    cout << _pow(2, i) << endl;
  }
*/
cout << "TEST.END://" << endl;
  return 0;
}
