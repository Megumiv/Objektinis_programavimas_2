# Objektinis-programavimas

- Sukurtas cmake 
- Pateikta Doxygen dokumentacija kartu su sugeneruotu PDF per Overleaf
- Realizuoti Unit Testai ("Rule of Five" ir įvesties, išvesties operatoriai; randama v2.0 test.cpp)

<br/> **Naudojimuisi naudingi** paths ir failai šiame branch'e:
<br/> - Dokumentacija/html/index.html  ---------- (Doxygen dokumentacija)
<br/> - Dokumentacija/documentation pdf.pdf  ---- (PDF dokumentacija)
<br/> - v2.0 cmake/CMake2.0.exe  ---------------- (v2.0 paleidimo cmake failas)
<br/> - v2.0 cmake/test.cpp  -------------------- (naujas failas Unit Testams)


<br/>Programa nuskaito vartotojų įvedamus duomenis, juos nuskaito iš failo arba sugeneruoja: studento vardą ir pavardę, namų darbų rezultatus ir egzamino rezultatus. 
<br/>Realizuota su klase, konstruktoriais ir destruktoriumi, įvesties ir išvesties operatoriais, "Rule of Five".<br/>

<br/> Sukurtos dvi klasės: Student (išvestinė) ir Zmogus (abstrakti).

**Meniu** skirtingos programos eigos pasirinkimui:  <br /> 1 - įrašyti ranka; <br /> 2 - generuoti tik pažymius; <br /> 3 - generuoti studentų vardus, pavardes ir pažymius; <br /> 4 - duomenis nuskaityti iš pasirinkto / įvesto ranka failo; <br /> 5 - baigti darbą ir išvesti rezultatus su pasirinktinu rūšiavimu; <br/> 6 - sugeneruoti duomenų failus testavimui; <br/> 7 - išvalo įvestus duomenis; <br/> 8 - "Rule of Five" ir įvesties/šsvesties operatorių testavimas.

<br />
Baigus duomenų įvedimą, suskaičiuoja galutinį balą pagal formulę:  Galutinis = 0.4 * vidurkis + 0.6 * egzaminas.  Arba vietoj vidurkio pasirenkant medianą.

<br/>Rezultatai išvedami lentelėje, pasirenkant duomenų eigą bei išvestį į ekraną arba failą. Papildomai išvedami failai: kietiakiai.txt (balas >= 5) ir vargsiukai.txt (balas < 5). <br/>

<br/>Duomenų nuskaitymo iš failo testavimas su norimu pakartojimų skaičiaus įvedimu (išvedamas vidurkis).
![Screenshot 2025-06-02 031428](https://github.com/user-attachments/assets/10901d79-c9e9-4a90-a99d-ed97b9d9d45b)

