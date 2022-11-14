#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;


vector <string> lunchOrder(const string& line) {

	vector <string> row;

	istringstream istm(line); //vailable line input stream
	string item;  //first line item

	if (getline(istm, item, ',')) {
		row.push_back(move(item));

		while (getline(istm, item, ',')) {
				row.push_back(move(item));
		}	
	}
		return row;
}

vector <vector <string>> csv_read(istream&& istm) {
	
	vector<vector<string>> table;
	string line;
	while (getline(istm, line)) {
		table.push_back(lunchOrder(line));
		}
	return table;
}
void invoice(vector <vector <string>>& table, int tax) {

	for (auto& cells : table) {
		if (!cells.empty()) {
				for (auto& cell:cells) {
					cell = to_string (tax * stoi(cell));
				}
		}

	}
}
void csv_write(ostream&& ostm, const vector <vector <string>>& table) {
	for (const auto& cells : table) {
		if (!cells.empty()) {
			ostm << cells[0];
			for (size_t i = 1; i < cells.size() ;++i){
				ostm << ',' << cells[i];
			}
		}
	}
}

int main() {

	auto table = csv_read(ifstream("lunchOrder.csv"));
	invoice(table,1.15);
	csv_write(ofstream("invoice.csv"),table);

	system("pause>0");
}
