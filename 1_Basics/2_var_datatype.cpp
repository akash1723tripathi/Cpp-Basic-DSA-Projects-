// variable : named stored memory location 
// datatype : specifies the type of data and its size 
// data_type variable_name = value ;

#include <iostream>
using namespace std;

int main(){
    int age = 20;
    cout << age <<endl;
    cout<< sizeof(age);
    return 0;
}


//  decleration  int age 
//  definition   int age=20 

//input of different input variables
int a;
long b;
char c;
float d;
double e;
scanf("%d %ld %c %f %lf",&a,&b,&c,&d,&e);
printf("%d\n%ld\n%c\n%0.3f\n%0.9lf",a,b,c,d,e);



// for float type values and their precisions 
// 1. floor() Method  : Floor rounds off the given value to the closest integer which is less than the given value. It is defined in the <cmath> header file.
cout << floor(x) << endl;

// 2. ceil() Method : Ceil rounds off the given value to the closest integer which is more than the given value. It is defined in the <cmath> header file.
cout << ceil(x) << endl;

// 3. trunc() Method : Trunc rounds remove digits after the decimal point. It is defined in the <cmath> header file.
cout << trunc(x) << endl;

//4. round() : Rounds gave numbers to the closest integer. It is defined in the header files: <cmath> and <ctgmath>
cout << round(x) << endl;

//5. setprecision() : Setprecision when used along with ‘fixed’ provides precision to floating-point numbers correct to decimal numbers mentioned in the brackets of the setprecision. It is defined in header file <iomanip>.
double pi = 3.14159, npi = -3.14159;
cout << setprecision(3) << pi << " " << npi;