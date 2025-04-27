// Created by Kilian
// C++ Übung 02 | Aufgabe 3
// Module mit ECTS Punkten, Noten berechnen und ausgeben!


#include <iostream>
#include <vector>
#include <string>

struct Module {
	std::string nameofmodule;
    int ects;
    double note;

};

Module read_module(int i) {
    Module m;
    std::cout << std::endl;
    std::cout << "Enter name of Module " << (i + 1) << ": ";
    std::cin >> m.nameofmodule;
    std::cout << "Enter ECTS and grade for module " << (i + 1) << ": ";
    std::cin >> m.ects >> m.note;
    return m;
}

std::string names(const std::vector<Module>& modules) {
    std::string result;
    bool first = true;
    for (const Module& m : modules) {
        if (m.note < 5.0) { // nur bestandene Module
            if (!first) {  // Beim erstmal nichtrein, danach schon wegen dann immer Komma setzen
                result += ", ";
            }
            result += m.nameofmodule;
            first = false;
        }
    }
    return result;
}


double gpa(const std::vector<Module>& modules) {
    double average = 0.0;
    int ectsall = 0;
    for (const Module& m : modules) {
        if (m.note < 5.0) { // nur bestandene Module zählen
            average += m.ects * m.note;
            ectsall += m.ects;
        }
    }
    if (ectsall > 0) {
        return average / ectsall;
    } else {
        return 0.0; // Verhindert Division durch 0
    }
}

void print_summary(const std::vector<Module>& modules) {
    std::cout << std::endl;
    std::string passed_module_names = names(modules);

    if (!passed_module_names.empty()) {
        std::cout << "Passed Modules: " << passed_module_names << std::endl;
    } else {
        std::cout << "No passed modules." << std::endl;
    }

    double average = gpa(modules);
    if (average > 0) {
        std::cout << "Grade point average: " << average << std::endl;
    } else {
        std::cout << "No passed modules, GPA cannot be calculated." << std::endl;
    }
}


int read_n_modules() {
    std::cout << "How many modules?" << std::endl;
	int n = 0;
	std::cin >> n;
    return n;
}



int main() {
	int n = read_n_modules();

    std::vector<Module> modules;
    for (int i = 0; i < n; i++) {
        modules.push_back(read_module(i));
    }
    print_summary(modules);

	return 0;
}
