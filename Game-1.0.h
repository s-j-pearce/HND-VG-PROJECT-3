#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std; 

vector<string> split(string value, char token);
string Anagram(unsigned maxLength);
void Solution(string anagram, string word);
bool ContainsAll(string anagram, string word);

string solution;

int main(){
  string anagram = Anagram(3);
  
  ifstream infile("dictionary.txt");
  string line;
  
  while(infile >> line){
    string word = split(line, ',').at(0);
    if(word.length() > anagram.length()) continue; 
    Solution(anagram, word); 
  }
  if(solution == ""){
  	cout << "Word not found!" << endl;
  	
  } else {
  	cout << "Best solution: " << solution << endl;
  }
  
  return 0;
}

void Solution(string anagram, string word) {
	bool valid = true;
	map<unsigned, bool> slots;
    for(unsigned a = 0; a < word.length(); a++){ 
	  bool found = false;
      
      for(unsigned b = 0; b < anagram.length(); b++){

  	 	
  	 	if(slots[b] == true) { 
	 	} else if(anagram[b] == word[a]) {
           slots[b] = true;
           found = true;
    	} else {
    		slots[b] = false;
    	}
      }
      
      if(found == false) {
      	valid = false;
      	break;
      }
    }
    
	if(valid) {
		if(solution.length() > word.length()) return;
		solution = word;
	}

}



string Anagram(unsigned maxLength) {
  string c;
  do {
  cout << "Enter 3 Letters: ";
  cin >> c;
  cout << endl;
  if(c.length() > maxLength){
  }
  } while(c.length() > maxLength);
  
  return c;
}



vector<string> split(string value, char token){
    stringstream ss(value);
    vector<string> vect;
    
    while(ss.good()){
      string substr;
      getline(ss, substr, ',');
      vect.push_back(substr);
    }
    
    return vect;
