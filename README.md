# Zadanie4

## Uloha 6.5.18:

Naprogramujte konštruktor, ktorý vygeneruje náhodný bimodálny
cyklický zoznam. Pripomeňme, že bimodálna je taká funkcia, ktorá má
práve dve lokálne maximá. Rovnaká definícia platí aj pre zoznam s tým, že v
zozname číselných hodnôt je lokálne maximum taký jeho uzol, že ani v jednom
z jeho susedov nie je uložená väčšia hodnota. Funkcia bude mať prototyp:

`CTWL *ctwl_create_random_bimodal(unsigned int size);`

pričom cez argument size sa funkcia dozvie, koľko uzlov má zoznam mať. Ak
funkcia uspeje, cez návratovú hodnotu oznámi adresu reprezentácie vygenerovaného
zoznamu. V prípade neúspechu vráti hodnotu NULL. Algoritmus navrhnite
tak, aby potenciálnym výstupom funkcie mohol byť akýkoľvek bimodálny zoznam
zadanej dĺžky.

compile `gcc -Wall -o zadanie4.exe src/zadanie4.c`
