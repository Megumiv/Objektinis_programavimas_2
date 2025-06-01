#include <gtest/gtest.h>
#include "Studentas.h"
#include <vector>
#include <utility> // for std::move
#include <sstream>

TEST(StudentTest, RuleOfFive) {
    std::cout << "\n--- Tikrinamas Rule of Five ---\n";

    // Originalus objektas
    Student s1("Vardas", "Pavarde", { 10, 9, 8 }, 9);
    s1.skaiciuokGalutinis(true);

    // Kopijavimo konstruktorius
    Student s2(s1);
    EXPECT_EQ(s2.getVardas(), s1.getVardas()) << "Kopijavimo konstruktorius: vardas nesutampa";
    EXPECT_EQ(s2.getPavarde(), s1.getPavarde()) << "Kopijavimo konstruktorius: pavarde nesutampa";
    EXPECT_EQ(s2.getEgzaminas(), s1.getEgzaminas()) << "Kopijavimo konstruktorius: egzaminas nesutampa";
    EXPECT_EQ(s2.getPazymiai(), s1.getPazymiai()) << "Kopijavimo konstruktorius: pazymiai nesutampa";
    EXPECT_EQ(s2.getGalutinisVid(), s1.getGalutinisVid()) << "Kopijavimo konstruktorius: galutinisVid nesutampa";
    EXPECT_EQ(s2.getGalutinisMed(), s1.getGalutinisMed()) << "Kopijavimo konstruktorius: galutinisMed nesutampa";

    // Kopijavimo priskyrimo operatorius
    Student s3;
    s3 = s1;
    EXPECT_EQ(s3.getVardas(), s1.getVardas()) << "Kopijavimo priskyrimo operatorius: vardas nesutampa";
    EXPECT_EQ(s3.getPavarde(), s1.getPavarde()) << "Kopijavimo priskyrimo operatorius: pavarde nesutampa";
    EXPECT_EQ(s3.getEgzaminas(), s1.getEgzaminas()) << "Kopijavimo priskyrimo operatorius: egzaminas nesutampa";
    EXPECT_EQ(s3.getPazymiai(), s1.getPazymiai()) << "Kopijavimo priskyrimo operatorius: pazymiai nesutampa";
    EXPECT_EQ(s3.getGalutinisVid(), s1.getGalutinisVid()) << "Kopijavimo priskyrimo operatorius: galutinisVid nesutampa";
    EXPECT_EQ(s3.getGalutinisMed(), s1.getGalutinisMed()) << "Kopijavimo priskyrimo operatorius: galutinisMed nesutampa";

    // Perkelimo konstruktorius
    Student s4(std::move(s1));
    EXPECT_EQ(s4.getVardas(), "Vardas") << "Perkelimo konstruktorius: vardas neteisingas po move";
    EXPECT_EQ(s4.getPavarde(), "Pavarde") << "Perkelimo konstruktorius: pavarde nesutampa";
    EXPECT_EQ(s4.getEgzaminas(), 9) << "Perkelimo konstruktorius: egzaminas nesutampa";
    EXPECT_EQ(s4.getPazymiai(), std::vector<int>({ 10, 9, 8 })) << "Perkelimo konstruktorius: pazymiai nesutampa";
    EXPECT_GT(s4.getGalutinisVid(), 0.0) << "Perkelimo konstruktorius: galutinisVid neapskaiciuotas";

    // Perkelimo priskyrimo operatorius
    Student s5;
    s5 = std::move(s2);
    EXPECT_EQ(s5.getVardas(), "Vardas") << "Perkelimo priskyrimo operatorius: vardas nesutampa";
    EXPECT_EQ(s5.getPavarde(), "Pavarde") << "Perkelimo priskyrimo operatorius: pavarde neteisinga po move";
    EXPECT_EQ(s5.getEgzaminas(), 9) << "Perkelimo priskyrimo operatorius: egzaminas nesutampa";
    EXPECT_EQ(s5.getPazymiai(), std::vector<int>({ 10, 9, 8 })) << "Perkelimo priskyrimo operatorius: pazymiai nesutampa";
    EXPECT_GT(s5.getGalutinisVid(), 0.0) << "Perkelimo priskyrimo operatorius: galutinisVid neapskaiciuotas";

    std::cout << "\nRULE OF FIVE TESTAS SEKMINGAI BAIGTAS:\n";
}

// Ivesties / isvesties operatoriu testas
TEST(StudentTest, IOOperators) {

    std::cout << "\n--- Tikrinami ivesties ir isvesties operatoriai ---\n";

    std::istringstream input("Vardas\nPavarde\n3\n8 9 10\n9\n");

    Student s;
    input >> s;
    ASSERT_FALSE(input.fail()) << "Klaida: nepavyko nuskaityti studento duomenu.";

    EXPECT_EQ(s.getVardas(), "Vardas");
    EXPECT_EQ(s.getPavarde(), "Pavarde");
    EXPECT_EQ(s.getEgzaminas(), 9);
    EXPECT_EQ(s.getPazymiai(), std::vector<int>({ 8, 9, 10 }));

    std::ostringstream output;
    output << s;

    ASSERT_FALSE(output.str().empty()) << "Isvesties srautas tuscias.";

    // Optionally print output in test log
    std::cout << "\n\nIVESTIES / ISVESTIES OPERATORIU TESTAS SEKMINGAS (su nustatytais duomenimis):\n\n" << output.str() << std::endl;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
