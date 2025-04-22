#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<" Enter your age :"<<endl;
    cin>>age;
    cout<<"Enter yout name : "<<endl;
    char name[5];
    cin.getline(name,3);
    cout<< name <<endl;

}


// jab 0/1 me de boolean type data hoga toh inputna padega true false kaarke nhi chalta.

// cin.get()	Reads a single character from the input stream, including whitespace.
// cin.getline()	Reads a line of text, including whitespace, and stops when it reaches a newline character.
// cin.ignore()	Ignores a specified number of characters or until a specified delimiter is encountered.
// cin.peek()	Returns the next character from the input stream without extracting it.
// cin.putback()	Puts a character back into the input stream.
// cin.eof()	Returns true if the end of the input stream has been reached.
// cin.fail()	Returns true if an input operation has failed (e.g., when input doesn’t match the expected type).
// cin.clear()	Clears the error flags on the input stream, allowing further operations.
// cin.sync()	Discards unread characters from the input buffer.
// cin.gcount()	Returns the number of characters extracted by the last unformatted input operation.
// cin.rdbuf()	Gets or sets the associated stream buffer object for std::cin.


// we can also use #inlude<cstdio> and use commands of c language on cpp
printf("%s", string); printf(string);


// You can also use cin and cout instead of scanf and printf; however, if you are taking a million numbers as input and printing a million lines, it is faster to use scanf and printf.
printf("`format_specifier`", val)

char ch = 'd';
double d = 234.432;
printf("%c %lf", ch, d);