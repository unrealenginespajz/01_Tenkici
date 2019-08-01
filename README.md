Procitaj ako hoces.
---
##  TANK

*	Pravimo BP_TENK - PAWN dodajemo StaticMash komponente 

*	Da bi to bila komaktna Celina dodajemo sockete…na telo stavljamo sockete levu I desnu gusenicu I barrel, na barel cevku

*	Kad smo napravili BP_Tenk kad u nasem gamemodu promenimo da je DefaultPawnClass taj BP onda se tenk spona kao glavi igrac

*	Dodajemo Scene, SpringArm I Kameru . Da ne bi doslo do pomeranja osa kad pomeramo kameru (sto se desava ako su samo kamer I springarm) dodajemo I scenu. 
	U BP smo napravili novi event graph gde smo inpute za misa po x I y osi prosledili jedan na scenu drugi na arms I onda se kamera ponasa normalno.

*	Uz pomoc UI BP pravimo nisan. Posto zelimo da se vidi kad neko vozi tenk znaci da ce za njegovo prikazivanje biti zaduzen PlayerControler.

*	Pravimo BP_TenkPlayerCOntroler I tamo dodajemo taj UI kroz event graph (create widget pa add to viewport)

*	Pravimo glavni meni UI. Da bi bilo transparentije pravimo ga u posebnom lvl-u. Dodajemo event na dugme i da playercontroler game mode bude ui only a kad louduje glavnu mapu vracamo na game mode.

*  	Pravimo c++ clasu TanPlayerControlera i postavimo je kao parent postojeceg BP koji smo napravili. PlayerControler i AiPlayerControler moraju kog tenka kontrolisi i prvo to pravimo.
	Posto tu koristimo return Cast<AtENK>(GetPawn()); moramo napraviti c++ klasu tipa Pawn aTenk i reperentujemo za postojeci BP_Tank

*       Za AI tenkove napravicemo c++ clasu tipa AIControler.Da bi Ai zaposednuo tenka MORAMO u BP_Tank podesavanju za Ai Control Class da postavimo ovu nasu klasu koju smo napravili

*	Ucimo AI kako da nadje naseg tenka GetWorld()->GetFirstPlayerController()->GetPawn();

*       Nalazimo gde nisan pogadja

*	Pravimo funkciju Nacijalj koja ima ulazni parametar Pawn tako da moze da ga koristi i player i ai tank

* 	Funkciju Naciljaj prebacimo u posenu komponentu. To je opcionu, verovato u praksi napravicemo u tenku a onda cemo odluciti da li treba posebna komponenta
	pogotovo ako se ona cesto koristi. Mi prebacujemo pogotovo sto ce mo to korisititi i za movment(ovo cu objasniti kad budemo radili)

*	1.1 Pravimo c++ Actor Component. deklarisemo ga u AtEnku pod protected, zato sto ne moze da bude private jer moramo da koristimo UPROPERTU kasine a za to ne moze private
	a public ne treba jer to je stvar teknak sta se koga tice ostalog to :).Prebacujemo logiku iz AtENK naciljaj u UNaciljajKompontu...POTPIS OSTAJE U AtEnku.
	
*	1.2.
	-Ovde je poenta kako da capimo StaticMash (Cevku) i da uzmemo njenu poziciju. Skraceno- preko tenka uzimamo iz BP cevku i prosledjuemo naciljaj komponenti
	Posto je za putanju projektila potrebno pored toga de pogadjamo sto vec imamo (hitlocation) potrebno da znamo i pocetak a to je pocetak barela u Actor Componenti UNaciljajKomponenti
	prvo pronalazimo barrel(cevku). Napravili smo metodu u komponenti ANaciljajKomponenta i istu taku u Atenku ali tamo stmo stavili 
	UFUNCTION(BlueprintCallable,Category = Setup) da bi mogli da preuzmemo tu varijabili cevku iz BP i onda smo delegirali iz Atenka u anaciljakompnen TenkuNaciljaj->SetBarrelReference(CevkaIzBP);


* 	1.3
	Ovde je dobra fora kako smo uzeli startnu poziciju odakle metak treba da krene a to je vrh cevke. U BP_Barrel dodali smo prazan zocket i onda smo u kogu uz pomoc njegovog imena
	uzeli njegovu lokaciju. 
	Posle toga pozvlai smo staticku funkciju UGameplayStatics::SuggestProjectileVelocity. OVO CU OBNOVITI NA KRAJU DA VIDIM STA JE FORA SA OVIM