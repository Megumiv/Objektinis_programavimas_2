#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;

class Student {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;

public:
    // konstruktorius
    Student() : egzaminas(0), galutinisVid(0.0), galutinisMed(0.0) { }; // default
    Student(const string& v, const string& p, const vector<int>& paz, int egz); // pilnas

    // destruktorius 
    ~Student() { };
    //~Student() = default;
     
    // Ivedimas ranka
    void ivestiRanka();

    // Nuskaitymas is failo
    static bool nuskaitytiIsFailo(const string& filename, vector<Student>& grupe, bool naudotiVidurki);

    // Isvedimas
    static void Isvedimas(const vector<Student>& grupe);

    // Nustatymai
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzaminas(int e) { egzaminas = e; }
    void addNd(int nd) { pazymiai.push_back(nd); }

    // Get'ai
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    double getGalutinisVid() const { return galutinisVid; }
    double getGalutinisMed() const { return galutinisMed; }

    // Skaiciavimai
    void skaiciuokGalutinis(bool naudotiVidurki);
};