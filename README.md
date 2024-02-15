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
