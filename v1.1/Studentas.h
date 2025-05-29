#pragma once
#include <vector>
#include <string>
#include <utility> // std::move

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


    // Rule of five
    ~Student();                                    // destruktorius 
    //~Student() = default;
    Student(const Student& other);                  // kopijavimo konstruktorius
    Student& operator=(const Student& other);       // kopijavimo priskyrimo operatorius
    Student(Student&& other) noexcept;              // perkelimo konstruktorius
    Student& operator=(Student&& other) noexcept;   // perkelimo priskyrimo operatorius
    
    // Ivesties / Isvesties operatoriai
    friend std::ostream& operator<<(std::ostream& out, const Student& s);   // isvesties
    friend std::istream& operator>>(std::istream& in, Student& s);          // ivesties
     
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
    int getEgzaminas() const { return egzaminas; }
    const vector<int>& getPazymiai() const { return pazymiai; }

    // Skaiciavimai
    void skaiciuokGalutinis(bool naudotiVidurki);
};