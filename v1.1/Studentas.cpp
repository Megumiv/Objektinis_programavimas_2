#include "Studentas.h"
#include "Header.h"

// pilnas konstruktorius
Student::Student(const string& v, const string& p, const vector<int>& paz, int egz)
    : vardas(v), pavarde(p), pazymiai(paz), egzaminas(egz), galutinisVid(0.0), galutinisMed(0.0) {}


// Duomenu ivedimai ranka
void Student::ivestiRanka() {
    string v, p;
    vector<int> pazymiai;
    int nd, egz;
    pazymiai.clear();

    cout << "\nIveskite studento varda ir pavarde: ";
    cin >> v >> p;

    // namu darbu rezultatu ivedimas ranka
    cout << "Iveskite namu darbu tarpinius rezultatus (0-10), o jei norite pabaigti: -1: ";
    while (true) {
        cin >> nd;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Blogas ivesties formatas. Iveskite skaiciu nuo 0 iki 10. ";
            continue;
        }
        if (nd == -1) break;
        if (nd >= 0 && nd <= 10)
            pazymiai.push_back(nd);
        else {
            cout << "Blogas ivesties intervalas. Iveskite skaiciu nuo 0 iki 10.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    // egzamino rezultato ivedimas ranka
    cout << "Iveskite egzamino bala (0-10): ";
    while (true) {
        cin >> egz;
        if (!cin.fail() && egz >= 0 && egz <= 10) break;
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Blogas ivesties formatas. Iveskite skaiciu nuo 0 iki 10: ";
        }
    }
    *this = Student(v, p, pazymiai, egz);
}


// Nuskaitymas is failo
bool Student::nuskaitytiIsFailo(const string& filename, vector<Student>& grupe, bool naudotiVidurki) {
    ifstream file(filename);
    if (!file) {
        cout << "Klaida: Nepavyko atidaryti failo " << filename << ". Patikrinkite, ar failas egzistuoja.\n";
        return false;
    }

    // praleidziama pirma nuskaitomo failo eilute
    string line;
    std::getline(file, line);

    // nuskaitymas
    while (std::getline(file, line)) {

        if (line.empty()) continue; 

        std::istringstream ss(line);
        string v, p;
        ss >> v >> p; // nuskaitomas vardas ir pavarde

        if (ss.fail()) { 
            cout << "Ispejimas: Nepavyko nuskaityti vardo arba pavardes is eilutes:\n" << line << "\n";
            continue;
        }

        std::vector<int> paz_temp;
        int pazymys = 0;

        while (ss >> pazymys) {
            paz_temp.push_back(pazymys);
        }

        if (paz_temp.empty()) {
            cout << "Klaida: Studentas " << v << " neturi jokiu pazymiu.\n";
            continue;
        }

        int egz = paz_temp.back();
        paz_temp.pop_back();

        // Sukuriamas studentas su pilnu konstruktoriumi
        Student s(v, p, paz_temp, egz);

        // galutinis balas
        s.skaiciuokGalutinis(naudotiVidurki);
        grupe.push_back(s);
        
    }
    file.close();
    return true;
}


//  Galutinis balas
void Student::skaiciuokGalutinis(bool naudotiVidurki) {
    if (pazymiai.empty()) {
        galutinisVid = 0.0;
        galutinisMed = 0.0;
        return;
    }

    if (naudotiVidurki) {
        double vid = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
        galutinisVid = 0.4 * vid + 0.6 * egzaminas;
        galutinisMed = -1;
    }
    else {
        std::sort(pazymiai.begin(), pazymiai.end());
        double med;
        int n = pazymiai.size();
        if (n % 2 == 0)
            med = (pazymiai[n / 2 - 1] + pazymiai[n / 2]) / 2.0;
        else
            med = pazymiai[n / 2];

        galutinisMed = 0.4 * med + 0.6 * egzaminas;
        galutinisVid = -1;
    }
}

// Isvedimas
void Student::Isvedimas(const vector<Student>& grupe) {
    int isv;

    if (grupe.empty()) {
        cout << "\nNera studentu isvedimui.\n";
        return;
    }

    while (true) {
        cout << "\nIrasykite, i kur norite isvesti rezultatus (1 - ekrana, 2 - faila): ";
        cin >> isv;
        if (isv == 1 || isv == 2) break;
        else cout << "Netinkama verte. Iveskite skaiciu 1 arba 2.\n";
    }

    // isvestis i ekrana
    if (isv == 1) {

        cout << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
        cout << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "------------------------------------------------------------------\n";

        for (const auto& s : grupe) {
            cout << left << setw(15) << s.getPavarde() << setw(15) << s.getVardas();
            // galutinis pasirinktas pagal vidurki, o prie medianos - x
            if (s.getGalutinisVid() == -1) cout << setw(20) << "x.xx";
            else cout << setw(20) << fixed << setprecision(2) << s.getGalutinisVid();
            // galutinis pasirinktas pagal mediana, o prie vidurkio - x
            if (s.getGalutinisMed() == -1) cout << setw(20) << "x.xx" << endl;
            else cout << setw(20) << fixed << setprecision(2) << s.getGalutinisMed() << endl;
        }
    }


    // isvestis i faila
    else if (isv == 2) {
        string file = "Rezultatai.txt";
        ofstream failas(file);

        if (!failas) {
            cout << "Klaida atidarant faila!\n";
            //return;
        }

        failas << left << setw(15) << "\nPavarde" << setw(15) << "Vardas";
        failas << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        failas << "------------------------------------------------------------------\n";

        for (const auto& s : grupe) {
            failas << left << setw(15) << s.getPavarde() << setw(15) << s.getVardas();
            // galutinis pasirinktas pagal vidurki, o prie medianos - x
            if (s.getGalutinisVid() == -1) failas << setw(20) << "x.xx";
            else failas << fixed << setprecision(2) << setw(20) << s.getGalutinisVid();
            // galutinis pasirinktas pagal mediana, o prie vidurkio - x
            if (s.getGalutinisMed() == -1) failas << setw(20) << "x.xx" << endl;
            else failas << fixed << setprecision(2) << setw(20) << s.getGalutinisMed() << endl;
        }
        failas.close();
        cout << "\nRezultatai issaugoti faile: " << file << endl;
    }
}
