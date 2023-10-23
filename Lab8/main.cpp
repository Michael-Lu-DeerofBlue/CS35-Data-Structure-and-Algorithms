/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "keywordSearcher.h"

using namespace std;

/*
runs the keyword search function
argc: the number of arguments
argv: an array holding each argument as a string
*/
int main(int argc, char** argv) {
  if (argc > 2){
      cout<<"Invalid number of arguments"<<endl;
      cout<<"Correct usage: /keywordSearch file"<<endl;
      return 1;
    }
  if (argc < 2){
      cout<<"Invalid number of arguments"<<endl;
      cout<<"Correct usage: /keywordSearch file"<<endl;
      return 1;
    }
  ifstream my_file;
  string filename;
  filename = argv[1];
  my_file.open(filename);
  if(!my_file.is_open()) {
     cout<<"file " + filename + " failed to open "<<endl;
     return 1;
}
KeywordSearcher ks;
ks.loadWords(filename);
cout<<"File Loaded"<<endl;
string input;
cout<<endl;
cout<<"Please enter a search word or '!' to quit: ";
cin>>input;
while(input!="!"){
  vector<pair<int,int>> result;
  result = ks.search(input);
  if (result.size()==0){
    cout<<"The word "<<input<<" does not appear in the file."<<endl;
  }
  else{
    cout<<"The word "<<input<<" appears in the file."<<endl;
    for(int i=0;i<result.size();i++){
      cout<<" "<<"on page "<<result[i].first<<" ("<<result[i].second<<" occurrences)"<<endl;
    }
  }
  cout<<endl;
  cout<<"Please enter a search word or '!' to quit: ";
  cin>>input;
}
cout<<endl;
cout<<"Goodbye!"<<endl;
return 0;
}
  

