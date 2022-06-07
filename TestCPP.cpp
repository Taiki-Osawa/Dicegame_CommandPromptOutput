#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

typedef struct class1{
  string name;
  int number;
  vector<int> vec;
} Class1;

Class1 one = {"one", 1};
Class1 two = {"two", 2};
Class1 three = {"three", 3};

vector<Class1> onetwothree = {one, two, three};

void alpha(int a){
  a = 0;
}

void beta(int *b){
  *b = 0;
}

int MAX(int a, int b){
  if(a < b) return b;
  else return a;
}

int MIN(int a, int b){
  if(a < b) return a;
  else return b;
}

static random_device rnd;

int Random(int a){
  int max_value = random_device::max();
  int pool = max_value - max_value % (a + 1);
  cout << pool << endl;
  cout << max_value << endl;
  int result;
  while(1){
    result = rnd();
    if(result < pool) break;
  }
  return result % (a + 1);
}
int Time_Random(){
  srand(time(NULL));
  return rand();
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
  for(int i = 0; i < (a * Time_Random()) % 10000; i++){
    int k = rnd();
  }
  return a;
}

int Dice(){
  string s;
  cout << "Please choose number and enter that." << endl;
  cout << "1 : [normal dice]///you can get a number for 1 ~ 6." << endl;
  cout << "2 : [range dice]///you enter two number(a, b). you can get a number for [a, b] or [b, a]." << endl;
  cout << "3 : [appoint dice]///you enter some number(a[n]). you can get a number from a[n]." << endl;
  cout << "any : [normal dice]" << endl;
  cin >> s;
  if(s == "2"){
    int a, b;
    cin >> a >> b;
    srand(time(NULL));
    return rand() % (MAX(a, b) - MIN(a, b) + 1) + MIN(a, b);
  }
  else if(s == "3"){
    vector<int> vi;
    string str = "0";
    while(str == "0"){
      cout << "Please enter the number [x] you will enter numbers." << endl;
      int x;
      cin >> x;
      cout << "Please enter [x] numbers." << endl;
      for(int y = 0; y < x; y++){
        int z;
        cin >> z;
        vi.push_back(z);
      }
      cout << "if you continue to enter numbers, you enter [0] or you don't do enter any." << endl;
      cin >> str;
    }
    srand(time(NULL));
    if(vi.size() == 0){
      cout << "no data return 0;" << endl;
      return 0;
    }
    else{
      return vi[rand() % vi.size()];
    }
  }
  else{
    srand(time(NULL));
    return rand() % 6 + 1;
  }
}

void test_a(Class1 *a){
  for(auto itr = a->vec.begin(); itr != a->vec.end(); itr++){
  *itr = *itr - 1;
  }
}

void spone_number(){
  srand(time(NULL));
  cout << rand() << endl;
}

void add_combination(vector<vector<int>> *combinations, vector<int> combination, vector<int> names, int counter){
  if(counter >= names.size()) combinations->push_back(combination);
  else{
    add_combination(combinations, combination, names, counter + 1);
    combination.push_back(names[counter]);
    add_combination(combinations, combination, names, counter + 1);    
  }
}

int main(){
  int a = 1;
  int b = 2;
  alpha(a);
  beta(&b);
  cout << a << ", " << b << endl;
  for(int i = 0; i < 100; i++){
    cout <<endl;
  }
  vector<int> vec(1, 1);
  //vec.push_back();
  cout << vec.size() << endl;
  for(int i = 0; i < 100; i++){
    vec.push_back(i);
  }
  for(int i = 0; i < vec.size(); i++){
    cout << i << ", " <<  vec[i] << endl;
  }
  vector<string> str{"one", "two", "three", "four"};
  for(auto itr = str.begin(); itr != str.end(); itr++){
    cout << "start " << *itr << endl;
    for(auto itr2 = onetwothree.begin(); itr2 != onetwothree.end(); itr2++){
      if((*itr2).name == *itr) cout << "hit " << (*itr2).number << endl;
    }
  }
  if(0) cout << "ha?" << endl;
  else cout << "yosi!" << endl;
  if(0) cout << "ha?" << endl;
  else cout << "yosi!" << endl;
  int dice_number = Dice();
  cout << dice_number << endl;
  vector<int> vvv;
  for(int sasa = 0; sasa < 10; sasa++){
    vvv.push_back(sasa);
  }
  for(auto itr = vvv.begin(); itr != vvv.end(); itr++){
    if(*itr == 3) vvv.erase(itr);
  }
  for(auto itr = vvv.begin(); itr != vvv.end(); itr++){
    cout << *itr << endl;
  }
  Class1 f = {"f", 1, {0, 1, 2, 3, 4, 5, 6}};
  test_a(&f);
  for(auto itr = f.vec.begin(); itr != f.vec.end(); itr++){
    cout << *itr << endl;
  }
  Class1 data1, data2;
  data1.name = "1";
  data2.name = "2";
  if(data1.number == data2.number) cout << "clear" << endl;
  if(data1.vec == data2.vec) cout << "clear2" << endl;
/*
  int input;
  while(1){
    cin >> input;
    if(!cin.fail()){
      if(input <= upper && input > 0){
        break;
      }
    }
    cout << "Error!" << endl;
    cin.clear();
    cin.ignore(1024, '\n');
  }
  cout << "input = " << input << endl;
*/
/*
random_device rnd;
mt19937_64 mt(rnd());
uniform_int_distribution<> randN(1, 100);
*/
  int cc = 0;
  while(cc != 100){
    unsigned int result = rnd();
    //cout << randN(mt) << endl;
    cout << result << endl;
    cc = input_int(1000);
  }
  cc = 0;
  while(cc != 100){
    srand(time(NULL));
    cout << rand() << endl;
    cc = input_int(1000);
  }
  cout << "ok" << endl;
  cout << Random(100) << endl;
  cout << "test break" << endl;
  vector<int> test_break = {1, 2, 3, 1, 3, 2, 1, 2};
  auto itra = test_break.begin();
  int test_break_int = 0;
  while(itra != test_break.end()){
    itra = test_break.begin();
    test_break_int = 0;
    while(itra != test_break.end()){
      if(*itra != 1){
        test_break.erase(itra);
        cout << "loop" << endl;
        break;
      }
      itra++;
      cout << test_break_int << endl;
      test_break_int++;
    }
  }
  for(auto itr = test_break.begin(); itr != test_break.end(); itr++){
    cout << "[" << *itr << "]" << endl;
  }
  cout << "test[combination]" << endl;
  vector<vector<int>> vvi;
  vector<int> vi = {1, 3, 5, 7, 9};
  add_combination(&vvi, {}, vi, 0);
  for(auto itr = vvi.begin(); itr != vvi.end(); itr++){
    cout << "{";
    for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
      cout << *itr2 << ", ";
    }
    cout << "}" << endl;
  }
  cout << "All Completed!" << endl;
  return 0;
}
