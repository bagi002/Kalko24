Kalkulator implementiran u Arduinu

Koriste se korisnicke biblioteke:
    -LCDdriver
    -matrixTastatura
i biblioteka otvorenog koda LiquidCrystal.h

Verzije:
 - v0.01 /omuguceno citanje karaktera sa tastature i baferovani sinhroni ispis na LCD za potrebe relizacije kreirane biblioteke LCDdriver i       matrixTastatura

 - v0.02 /Unapredjen ispis na LCD prevazilazenje ogranicenja duzine na 16 kroz pokretni prikaz i omogucen prikaz sift oznake, dodate optimizacije

 - v0.10
    - Kreirana klasa za obradu proracuna
    - Implementirana podrska za osnovne racunske operacije +-*/
    - Omogucena podrska za duze izraze sa vise operacija u izrazu
    - Optimizovana pretraga stringa putem rekruzivnih metoda
    - Implementirana pretraga na osnovu prioriteta racunskih operacija

 - v0.11
    - Omoguceno unosenje veceg broja izraza bez restartovanja ploce, unos novog karaktera poslje = rezultovace ciscenjem bafera
    - Dodata podrska Shift koja prosiruje mogucnosti tastature , kad je tastatura u dodatnom(shift) modu vidljiv karakter s na LCDu
    - Dodata podrska za tastere (decimalna tacka i delte)
    - Omoguceno brisanje karaktera tokom unosa

 - v0.12
    - Ispravljen bag odgovoran za gresku kod parsiranja negativnih brojeva na pocetku izraza
    - Onemoguceno updanje koda u beskonacnu petlju prilikom pogresnih izraza
- v0.20
    - Omogucen rad sa brojevima sa pokretnim zarezom
    - Dodata eksplicitna obrada greske prilikom dijeljenaja sa 0 vraca INF
    - Omoguceno parsiranje brojeva unesenih sa zarezom
- v0.21
    - Dodata opcija unosa zagrada
    - Dodata funkcija za obradu zagrada i prioritet operacija [BUG]
- v0.22
    - Ispravljeni dio BUGa ali kod idalje ne radi za zagrade(problem negdje kod poziva analizatora u metodi pretragaZ)