 <h1>DOCUMENTATION</h1>

 <h1>SRB</h1>

 <h2>Napomena</h2>
 Pre pocetka dokumentacije, moram da napomenem da je ovaj projekat radjen koristeci biblioteku <a href="https://www.raylib.com/index.html">Raylib</a>. 
 Raylib je biblioteka koja sluzi za crtanje po ekranu i to je ono za sta sam je ja koristio. Pored renderovanja sam je koristio i za input. Da bi projekat radio, treba da se reinstalira preko nunuget package menadzera u Visual studiu.

 <h2>Player.cpp</h2>>
 Ova klasa sluzi za hadleovanja inputa igraca, njegovo pomeranje i rotiranje.

 <h2>Map.cpp</h2>
 Ova klasa sluzi za sve vezano za mapu. Ima dve glavne funkcije koje su: <strong>void Map::SetupMap(string name)</strong> i <strong>void Map::SaveMap()</strong> od kojih jedna cita mapu, a druga je cuva.

 <h2>Renderer.cpp</h2>
 Ova igrica se sastoji od dva renderera, a ovo je abstraktna klasa koju oba nasledjuju. Sadrzi samo jednu virtualnu funkciju <strong>virtual void RenderGame()</strong> koja se koristi da se igrica renderuje.

 <h3>MinimapRenderer.cpp</h3>
 Renderer koji sam prvi napisao, predstavlja mapu iz top-down perspektive i pokazuje igraca kao crveni kvadrat sa vidljivim poljem koje nam pokazuje sta ce da vidi u drugom rendereru.

 <h3>RaycastRenderer.cpp</h3>
 Renderer oko kog se sve vrti u ovom projektu. On funkcionise tako sto iz igracevih "ociju" ispaljujemo gomilu zraka koji idu kroz mapu sve dok ne udare u zid. Kada udare u zid, vracaju informaciju o udaljenosti od pocetne tacke.
 Sa tom udaljenoscu mozemo da izracunamo visinu linije koja ce da predstavlja taj deo zida zajedno sa njenom bojom. Postoji efikasniji nacina da se raycastuje, ali ja sam iskoristio najlaksi moguci za ovaj projekat zato sto je matematika malo komplikovanija.

 <h2>LevelEditor.cpp</h2>
 Nasa poslednja ali i najduza klasa koja sluzi kao main meni i editor za nivo u kome se nalazimo. Sastoji se od funkcija za: renderovanje celog UI-a <strong>void RenderUI()</strong>, vise funkcija za hendleovanje klikova misa, te funkcije 
 sluze da simuliraju dugmice uglavnom. I takodje dve funkcije za cuvanje i ucitavanje mogucih boja za koriscenje iz fajla.
