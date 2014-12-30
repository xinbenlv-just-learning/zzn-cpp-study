// my first program in C++
#include <iostream>
#include <array>
#include <typeinfo>
using namespace std;

void addAndPrint(int a, int b) {
  cout << "Compute " << a << " + " << b << " = " << a + b << endl;
}

void basicDataTypesPrint() {

	char d_char = 1<<8 - 1;
	cout << "char " << d_char << "\n";
	// Requires --std=c++0x to pick up c++11 syntax
	char16_t d_char16_t = 1<<16 -1;
	cout << "char16_t " << d_char16_t << "\n";
	char32_t d_char32_t = 1<<32 -1;
	cout << "char32_t " << d_char32_t << "\n";
	wchar_t d_wchar_t = 1<<32 -1;
	cout << "wchar_t " << d_wchar_t << "\n";

	signed char d_signed_char_t = 1<<8 -1;
	cout << "signed char " << d_signed_char_t << "\n";

	signed short int d_signed_short_int_t = 1<<16 -1;
	cout << "signed short int " << d_signed_short_int_t << "\n";

	signed int d_signed_int_t = 1<<32 -1;
	cout << "signed int " << d_signed_int_t << "\n";

	signed long int d_signed_long_int_t = 1<<32 -1;
	cout << "signed long int " << d_signed_long_int_t << "\n";

	signed long long int d_signed_long_long_int_t = 1<<32 -1;
	cout << "signed long long int " << d_signed_long_long_int_t << "\n";

	float d_float = 1.234567890;
	cout << "float " << d_float << "\n";

	double d_double = 1.234567890;
	cout << "double " << d_double << "\n";

	long double d_long_double = 1.234567890;
	cout << "long double " << d_long_double << "\n";

	bool d_bool = true;
	cout << "bool " << d_bool << "\n";
}

void initialization() {
	int x {12345};  // uniform initialization, introduced in C++11;
	cout << "int x{12345} = " << x << endl;
	auto y  = 12345;
	cout << "y = " << y << endl;
	auto a = "hello ";
	auto b = "world ";
	cout << "ab = " << a << b << endl;
}

void statements() {
  int a = 1;
  if (a == 1) {
  	cout << "a == 1" << endl;
  }
  for (int i = 0; i < 3; i++) {
  	cout << i << endl;
  }
  while(a == 1) {
  	cout << "a = " << a << endl;
  	a ++;
  }
  do  {
  	cout << "a = " << a << endl;
  	a ++;
  } while(a == 2);
  string str {"Hello!"};
  for (char c : str)
  {
    cout << "[" << c << "]";
  }
}

void duplicate (int& a, int& b, int& c) {
  a*=2;
  b*=2;
  c*=2;
}

void defaultValue(int a, int b = 20) {
	cout << a + b << endl; 
}

template <class T>
T sum(T a, T b) {
	return a + b;
}

void arrayPrint() {
	int foo [5] = { 16, 2, 77, 40, 12071 }; 
	for (int i : foo) {
		cout << i << " ";
	}
	cout << endl;
}

void arrayLibary() {
 array<int,3> myarray {10,20,30};
 for (int i=0; i<myarray.size(); ++i)
    ++myarray[i];

 for (int elem : myarray)
    cout << elem << '\n';
}

void stringLibary() {
  string a {"hello "}, b {"world"};
  cout << "concatenate: " << a + b << endl;
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}
void functionPointers ()
{
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n << endl;
  // TODO(zzn): why the values of pointer are 1? 
  cout << "value of pointer minus:" << minus << endl;
  cout << "value of pointer addition:" << addition << endl; 
  cout << "value of pointer operation:" << operation << endl;
}

void pointers() {
	int myvar = 25;
	int* myvar_type = &myvar;
	cout << " type of myvar_type = "<< typeid(myvar_type).name() << endl; 
	cout << " value of myvar_type = " << myvar_type << endl; 
	cout << " *myvar_type = " << *myvar_type << endl;

	int my_int_array[3] = {100000, 200000, 300000};

	cout << " addr of my_int_array[0] = "<< long(&(my_int_array[0])) << endl; 
	cout << " addr of my_int_array[1] = "<< long(&(my_int_array[1])) << endl; 

	char my_char_array[3] = {1, 2, 3};
	cout << " addr of my_char_array[0] = "<< long(&(my_char_array[0])) << endl; 
	cout << " addr of my_char_array[1] = "<< long(&(my_char_array[1])) << endl; 

	bool my_bool_array[3] = {1, 1, 1};
	cout << " addr of my_bool_array[0] = "<< long(&(my_bool_array[0])) << endl; 
	cout << " addr of my_bool_array[1] = "<< long(&(my_bool_array[1])) << endl; 
}

void unionPrint() {
	union mytypes_t {
	  char c;
	  int i;
	  float f;
	} mytypes;
	mytypes.f = 12.12312;
	cout << "mytypes.f " << mytypes.f << endl;
	cout << "mytypes.i " << mytypes.i << endl;
	cout << "mytypes.c " << mytypes.c << endl;
	mytypes.c = 1;
	cout << "mytypes.f " << mytypes.f << endl;
	cout << "mytypes.i " << mytypes.i << endl;
	cout << "mytypes.c " << mytypes.c << endl;
}


void dataStruct() {
	struct product {
	  int weight;
	  double price;
	} apple;
	apple.weight = 1;
	apple.price = 1.1;
	cout << apple.weight << " " << apple.price << endl;
	product* p_apple = &apple;
	cout << p_apple->weight << " " << p_apple->price << endl;
	typedef product Product_Redef;
	Product_Redef banana;
	banana.weight = 2;
	banana.price = 2.2;
	cout << banana.weight << " " << banana.price << endl;
	using Product_Redef2 = product;
	Product_Redef2 melon;
	melon.weight = 3;
	melon.price = 3.3;
	cout << melon.weight << " " << melon.price << endl;	
}

void constMemberFunctions() {
	class MyClass {
	  public:
	    int x;
	    MyClass(int val) : x(val) {}
	    int get() {return x;}
	    int constGet() const {return x;}
	};
	const MyClass foo(10);
	// foo.x = 20; // not valid: x cannot be modified
	cout << foo.x << endl;  // ok: data member x can be read
	// cout << foo.get()<< endl;  // not valid: function member get() can not be called
	cout << foo.constGet()<< endl;  // ok: function member constGet() can be called
	
}

void  compilerInfo() {
  cout << "This is the line number " << __LINE__;
  cout << " of file " << __FILE__ << ".\n";
  cout << "Its compilation began " << __DATE__;
  cout << " at " << __TIME__ << ".\n";
  cout << "The compiler gives a __cplusplus value of " << __cplusplus;
}

int main()
{
  cout << "Variables\n";
  cout << "Start\n";
  addAndPrint(4, 5);
  basicDataTypesPrint();
  initialization();
  statements();
  cout << "End\n";
  int x=1, y=3, z=7;
  duplicate (x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  defaultValue(2);
  cout << sum<int>(1, 2) << endl;
  arrayPrint();
  arrayLibary();
  stringLibary();
  pointers();
  functionPointers();
  dataStruct();
  unionPrint();
  constMemberFunctions();
  compilerInfo();
  return 0;
}


