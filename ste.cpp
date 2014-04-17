#include <ncurses.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class File {
private:
	vector<string> contents; // contents of file for editing
	bool valid; // object validity (read only)
public:
	bool isValid() {return valid;} // getter for file validity checking
	File() { // by default, have the object invalid
		valid = false;
	}
	bool loadFile(string fn) { // load a file into memory
		contents.clear();
		valid = false;
		ifstream ifile;
		ifile.open(fn.c_str());
		if (!ifile) {
			return false;
		}
		string line;
		while (!ifile.eof()) {
			getline(ifile, line);
			contents.push_back(line);
		}
		ifile.close();
		valid = true;
		return true;	
	}
	int getLineCount() {return contents.size();}
	string getViewport(int line) {
		if (line > getLineCount()) {
			return ""; // nothing to show
		}
		for (int y = line; y < LINES; y++) {
			if (y > getLineCount()) {
				
			}
		}
	}
	
}
