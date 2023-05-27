# msm

Modular Server Manager este un software modular destinat serverelor fizice și are ca scop ușurarea rulării și managementului software-ului.

## Compilare
### Necesită: 
`Linux`
`make`
`gcc`
`git`
### Instrucțiuni:
`git clone https://github.com/Mircea1805/msm`
`cd msm`
`make`

## Crearea și utilizarea modulelor:
Pentru a crea module ce vor fi rulate de msm, este necesară crearea unei librării dinamice care să conțină o funcție cu aceeași denumire ca librăria. Pentru rulare, aceasta trebuie plasată în același folder cu executabilul msm și trebuie trecută denumirea fișierului în main.conf pe o nouă linie.

## Funcționare:
Când începe execuția, msm citește fișierul main.conf care conține modulele ce trebuie rulate, câte una pe o linie, și lansează în execuție, într-un nou thread, librăria dinamică corespunzătoare, apelând funcția cu același nume. Numele modulelor ce rulează sunt atunci trecute într-o listă liniară.
