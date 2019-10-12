# ai-showdown

Hoplite 2.0 es aj pokażdowna

1. Gra odbywa się na symetrycznej planszy dowolnej wielkości pomiędzy dwomagraczami. Składa się z 2 meczy. Pierwszy mecz zaczyna gracz 1szy, drugi mecz zaczyna gracz 2gi
2. Drużyna gracza składa się z 6 jednostek - po 2 jednostki każdej klasy.
3. Klasy w grze:
    każda jednostka w grze ma 3 punkty życia, poza rycerzem który ma 5 punktów życia
    a) rycerz
    może się poruszać na dowolne pole wokół niego <również po skosie> . Może również zaatakować te pola bez cooldownu.
    b) łucznik
    może się poruszać tylko na najbliższe pola <nie może ruszać się po skosie>. Może zaatakować bez cooldownu pola w odległości 2 od niego.
    c) bombiarz
    może się poruszać tylko na najbliższe 4 pola. Może rzucić bombę na pola w odległości 2 od niego. Bomba wybucha w następnej turze gracza. Bomba odnawia się po następnej turze gracza Bomba zadaje 3 obrażenia w centrum i 1 na najbliższych 4 polach. (Efektywnie może rzucić bombą - wybuchnie - rzucić - wybuchnie). Bomby również niszczą ściany.
4. Tura
Tura składa się z poruszania każdąjednostką należącą do gracza. ZAMIAST poruszania się, każda jednostka może zaatakować zgodnie z zasadami powyżej.
Gracze wykonują swoje tury na przemian.

5.  Po każdych 4 turach mapa pomniejsza się o 1 pole z góry i z dołu. Jednostki które znajdują się poza obszarem gry otrzymują obrażenia.

6. Struktura wymienianych danych:
tura
id_drużyny_aktualnego_gracza
liczba pól (wysokość) które zadają obrażenia (pomniejszająca się plansza)
rozmiar planszy x
rozmiar planszy y
pola {
     typ[podloga/sciana/???]
     x
     y
}
jednostki_druzyny_jeden {
     typ
     x
     y
     zycie
     czy_ma_cooldown   
}
jednostki_druzyny_dwa {
    to samo co wyzej
}

ewentualne_pozycje_bom_przeciwnikow i sojusznikow etc

7. flow gry
program host, nazwijmy go EAP ładuje programy boty i odpala je naprzemiennie
zapewniony jest plik state.eaps, który przechowuje informacje na temat stanu gry
każdy bot ładuje ten plik i sobie na jego podstawie wyznacza akcje
decyzje co do kazdej jednostki zapisuje do pliku result.eapr
i tak do usranej śmierci

8. mapa
mapa składa się z tilesów
każdy tile jest jednym z trzech typów:
- ściana, nieprzekraczalna, nie przepuszcza pocisków, niszczona przez bomby
- wodicznka, nieprzekraczalna, przepuszcza pociski, jak bomba na nią spadnie to znika
- podłoga, przekraczalna, przepuszcza pociski

