
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct data_ {

	string name;
	string date;
	string adress;
	int mark = 0;
};
const int mass = 3;
class Laba_2 {

private:
	data_ arr[mass];
public:
	void clear(int index) {
		if (arr[index].mark == 0) {
			cout << "Clear\n";

		}
		else {
			arr[index].adress = "";
			arr[index].name = "";
			arr[index].date = "";
			arr[index].mark = 0;

		}
	}
	void free_place() {
		for (int s = 0; s < mass; s++) {

			if (arr[s].mark == 0) {
				cout << "Free\n";
				break;
			}

		}

	}
	void getdata(int index, data_ d) {

		arr[index].mark = 1;
		arr[index].adress = d.adress;
		arr[index].name = d.name;
		arr[index].date = d.date;

	}
	void putdata(int index) {
		cout << arr[index].adress << endl << arr[index].name << endl << arr[index].date;

	}
	void mass_struct() {

		for (int s = 0; s < mass; s++) {
			if (arr[s].mark == 1) {
				cout << arr[s].adress << endl << arr[s].name << endl << arr[s].date;

			}
			else { break; }
		}
	}
	// ѕоиск в массиве структур элемента с заданным значением пол€ или с наиболее близким к нему по значению. ѕредусмотреть возможность задани€ одного числового значени€ и одного строкового.
	void dermo(int pole, string d) {
		int schet = 0;
		int max = 0;
		string mark;

		switch (pole) {
		case 1:
			for (int s = 0; s < mass; s++) { // for (int j = 0; j < (array[i].name).size(); j++) 
				for (int j = 0; j < (arr[s].adress).size(); j++) {
					if (d[j] == (arr[s].adress[j])) {
						schet++;

					}
				}
				if (schet > max) {
					max = schet;
					mark = arr[s].adress;
				}
				schet = 0;
			}
			break;
		case 2:
			for (int s = 0; s < mass; s++) {
				for (int j = 0; j < (arr[s].date).size(); j++) {
					if (d[j] == (arr[s].date[j])) {
						schet++;

					}
				}
				if (schet > max) {
					max = schet;
					mark = arr[s].date;
				}
				schet = 0;
			}
			break;
		case 3:
			for (int s = 0; s < mass; s++) {
				for (int j = 0; j < (arr[s].name).size(); j++) {
					if (d[j] == (arr[s].name[j])) {
						schet++;

					}
				}
				if (schet > max) {
					max = schet;
					mark = arr[s].name;
				}
				schet = 0;
			}
			break;


		}
		cout << mark;

	}
	// ѕоиск в массиве структуры с минимальным значением заданного пол€. ѕоле должно передаватьс€ в поле числом, обозначающим номер пол€ в структуре.
	void min_element(int pole) {

		string min;

		switch (pole) {
		case 1:
			min = arr[0].adress;
			for (int s = 0; s < mass - 1; s++) {
				if (min < arr[s + 1].adress) {
					min = arr[s + 1].adress;
				}
			}


			break;
		case 2:
			min = arr[0].date;
			for (int s = 0; s < mass - 1; s++) {
				if (min < arr[s + 1].date) {
					min = arr[s + 1].date;
				}
			}
			break;

		case 3:
			min = arr[0].name;
			for (int s = 0; s < mass - 1; s++) {
				if (min < arr[s + 1].name) {
					min = arr[s + 1].name;
				}
			}
			break;

		
		}
	}


			
	// —ортировка массива структур в пор€дке возрастани€ заданного пол€ (при сортировке можно использовать тот факт, что в —и++ разрешаетс€ присваивание структурированных переменных);

			void sortirovka_minmax(int pole) {
				data_ a;

				switch (pole) {
				case 1:
					for (int i = 0; i < mass; i++) {
						for (int j = 0; j < mass; j++) {
							if (arr[i].adress < arr[j].adress) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
								arr[i] = arr[j];
							}
						}
					}
					break;
				case 2:
					for (int i = 0; i < mass; i++) {
						for (int j = 0; j < mass; j++) {
							if (arr[i].date < arr[j].date) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
								arr[i] = arr[j];
							}
						}
					}
					break;
				case 3:
					for (int i = 0; i < mass; i++) {
						for (int j = 0; j < mass; j++) {
							if (arr[i].name < arr[j].name) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
								arr[i] = arr[j];
							}
						}
					}

					break;
				}

				mass_struct();
			}
	// —ортировка массива структур в пор€дке убывани€ заданного пол€(при сортировке можно использовать тот факт, что в —и++ разрешаетс€ присваивание структурированных переменных);
	void sortirovka_maxmin(int pole) {
		data_ a;

		switch (pole) {
		case 1:
			for (int i = 0; i < mass; i++) {
				for (int j = 0; j < mass; j++) {
					if (arr[i].adress > arr[j].adress) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
						arr[i] = arr[j];
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < mass; i++) {
				for (int j = 0; j < mass; j++) {
					if (arr[i].date > arr[j].date) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
						arr[i] = arr[j];
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < mass; i++) {
				for (int j = 0; j < mass; j++) {
					if (arr[i].name > arr[j].name) { // temp = array[i]; array[i] = array[j]; array[j] = temp;
						arr[i] = arr[j];
					}
				}
			}
			break;
		
		}
		mass_struct();
	}


	void write() {
		string d = "\n";
		ofstream file("C:\\ѕользователи\\BOBDAN\\–абочий стол\\test.txt");
		for (int i = 0; i < mass; i++) {
			file << arr[i].adress + d;
			file << arr[i].date + d;
			file << arr[i].name + d;
			file << endl;
		}
		file.close();
	}
	// ‘ункци€ чтени€ файла с содержимым базы данных(массива структурных элементов).
	void read() {
		string line;
		ifstream file("C:\\ѕользователи\\BOBDAN\\–абочий стол\\test.txt");
		while (getline(file, line)) {
			cout << line << endl;
		}
	}

};


int main() {
	setlocale(LC_ALL, "Rus");
	Laba_2 a;
	data_ b;
	int index = 0;
	a.clear(index);
	a.free_place();
	for (int i = 0; i < mass; i++) {
		
		cout << "¬ведите адресс : \n";
		cin >> b.adress;
		cout << "¬ведите им€ : \n";
		cin >> b.name;
		cout << "¬ведите дату : \n";
		cin >> b.date;
	}
	a.putdata(index);
	a.mass_struct();
	
	int pole;
	string sravn;
	cout << "¬ведите поле : 1-адресс, 2-дата, 3-им€" << endl;
	cin >> pole;
	cout << "¬ведите строку " << endl;
	cin >> sravn;
	a.dermo(pole,sravn);
	cout << "¬ведите поле : 1-адресс, 2-дата, 3-им€" << endl;
	cin >> pole;
	a.min_element(pole);
	cout << "¬ведите поле : 1-адресс, 2-дата, 3-им€" << endl;
	cin >> pole;
	a.sortirovka_maxmin(pole);
	a.sortirovka_minmax(pole);

	a.write();
	a.read();

}