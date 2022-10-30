#include "my_include.h"

// test case "(a(b){10}){3}";
//   abbbbbbbbbbabbbbbb......

void solution(string s) {
  stack<char> allchars; // stack read each characters

  string cur_string = ""; // stroed the current inner string

  for (auto c : s) {
    // cout << c << endl;

    /////////////////////////////////
    ////////Process sub string //////
    // if meet '}' we need process the progress: cur_string * times
    if (c == '}') {
      char pop_char = allchars.top();
      /////////////////////////////
      ////////GET THE NUMBER //////
      string val_string = "";
      int val = 0;
      while (pop_char != '{') {
        // pop the value-char for # of time duplicate the string
        val_string = pop_char + val_string;
        allchars.pop();
        pop_char = allchars.top();
      }
      // change value from string to int
      val = stoi(val_string);
      // cout << "VALUE IS: " << val << endl;
      // pop the '{'
      allchars.pop();

      /////////////////////////////////////
      ////////GET THE STRING TO COPY //////
      string temp_string = cur_string;
      allchars.pop(); // pop the ')'
      pop_char = allchars.top();
      temp_string = cur_string;
      // cout << "Temp string start with: " << temp_string << endl;
      while (pop_char != '(') {
        temp_string = pop_char + temp_string;
        allchars.pop();
        pop_char = allchars.top();
      }
      // pop the '('
      allchars.pop();
      /////////////////////////////////////////////////
      ////////process duplicated (string) * time //////
      string t = temp_string;
      for (int i = 1; i < val; i++) {
        temp_string += t;
      }

      //////////////////////////////////////////
      ////////CHECKING ANY CHAR BEFOR () //////
      // checking next char in string if it is '('
      // before '(', ther can be character, '(', or nothing

      if (!allchars.empty() && allchars.top() != '(') {
        // need checking if previous charact is '(' or not
        pop_char = allchars.top();
        while (pop_char != '(') {
          temp_string = pop_char + temp_string;
          allchars.pop();
          pop_char = allchars.top();
        }
      }
      // cout << "AFTER PROCESS, THE TOP STACK IS: " << allchars.top() <<
      // endl;;
      cur_string = temp_string;
    }

    else {
      allchars.push(c);
    }
  }

  cout << cur_string << endl;
}

int main()
{
  string s = "(a(b){10}){3}";

  solution(s);
}


