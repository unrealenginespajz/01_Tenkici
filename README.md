Procitaj ako hoces.
---
##  TANK

*	Pravimo BP_TENK  dodajemo StaticMash komponente 

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

