Depot
=====

Enunt pe scurt:

Implementarea unui sistem de "parcare" a trenurilor intr-un depou feroviar

Implementare:

Clasa Vagon:

	Am folosit aceasta clasa pentru reprezentarea unui vagon, caracterizat prin id.

Clasa Train:

	Reprezentarea unui tren este o stiva de vagoane, acest lucru m-a ajutat atunci cand a trebuit sa 
inserez un tren in depou incepand de la spatele acestuia.

Clasa Stack:

	Reprezinta implementarea unei stive generice care isi dubleaza capacitatea atunci cand se ajunge
la limita capacitatii acesteia.

Clasa Depot:

	In cadrul acestei clase memorez marimea depoului in fiecare moment prin variabila "size" numarul
fiecarui tip de vagoane in fiecare moment prin vectorul "vagoane". Acest lucru ma ajuta in momentele in
care trebuie sa afisez mesaje de eroare.
	Am mai implementat functii pentru inserarea unui vagon, extragerea acestuia si afisarea configuratiei
depoului. Variabilele "ad" si "gt" ma ajuta la extragerea sau inserarea unui tren tinand cont de circularitatea ceruta in enunt
