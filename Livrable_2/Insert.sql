USE projet;

INSERT INTO Catalogue (ID_article, nom, reference, prix_ht, taux_tva, coefficient_economie, stock, seuil_reapprovisionnement, actif)
VALUES (NULL, 'Choipeau magique', '795842', '15,90', '20', '0', '120', '100', '1'),
(NULL, 'Baguette de sureau', '496532', '25', '20', '0', '200', '50', '1'),
(NULL, 'Figurine Harry Potter', '624853', '10', '20', '0', '500', '20', '0'),
(NULL, 'Figurine Hermione Granger', '762137', '10', '20', '0', '528', '15', '0'),
(NULL, 'Figurine Ron Weasley', '449652', '10', '20', '0', '590', '15', '1'),
(NULL, 'Trivial Pursuit Harry Potter', '968751', '30', '20', '0', '100', '20', '0');

INSERT INTO Paiement(moyen_paiement)
VALUES ('Par carte'),
('4x sans frais');

INSERT INTO Type_adresse (ID_type_adresse, type_adresse)
VALUES (NULL, 'livraison'),
(NULL, 'facturation'),
(NULL,'livraison et facturation');


INSERT INTO Pays(ID_pays, pays)
VALUES (NULL, 'France');

INSERT INTO Ville (ID_ville, ville, ID_pays)
VALUES (NULL, 'Nice', 1);


INSERT INTO Personnel (ID_personnel, nom, prenom, date_embauche, ID_superieur)
VALUES (NULL, 'Sarcerdote', 'Dorian', '2015/10/10', NULL),
(NULL, 'Silva Roriz', 'Catarina', '2001/06/08', NULL),
(NULL, 'Tain', 'Dylan', '2011/12/01', NULL),
(NULL, 'Gomez', 'Alexis', '2018/10/10', NULL),
(NULL, 'Malhas', 'Valentin', '2013/11/10', NULL),
(NULL, 'Bruno', 'Jean-Vincent', '2001/10/15', NULL),
(NULL, 'Bourgain', 'Alexandre', '2001/10/10', NULL),
(NULL, 'Di Menza', 'Antonin', '2001/08/10', NULL),
(NULL, 'Massoudi', 'Ray-hann', '2001/07/30', NULL),
(NULL, 'Bores', 'Maxime', '2001/03/15', NULL),
(NULL, 'Brieulle', 'Ludovic', '2010/12/10', NULL),
(NULL, 'Gandre', 'Quentin', '2009/06/08', NULL),
(NULL, 'Pruvot', 'Tom', '2001/10/10', NULL),
(NULL, 'Labonde', 'Gabriel', '2006/10/25', NULL),
(NULL, 'Tarte', 'Antoine', '2001/11/05', NULL),
(NULL, 'Maillochaud', 'Laurianne', '2001/01/30', NULL),
(NULL, 'Barnouin', 'Joris', '2000/11/18', NULL),
(NULL, 'Do', 'Charlie', '2017/10/07', NULL),
(NULL, 'Dellamonica', 'Arnaud', '2020/03/16', NULL),
(NULL, 'Wendt', 'Djan', '2016/09/10', NULL),
(NULL, 'Menhaj', 'Lamyae', '2015/09/10', NULL),
(NULL, 'Bruno', 'Tom', '2015/10/10', NULL);


INSERT INTO Adresse_personnel (adresse_personnel,ID_personnel,ID_ville)
VALUES ('102 Chemin Saint Bernard', '16','1'),
('23 Boulevard de la république', '4','1'),
('67 Chemin entre deux maisons', '2','1'),
('84 Rue dans un coin paummé', '9','1'),
('1 Avenue quelque part', '18','1'),
('102 Avenue Pierre-Hubert', '17','1');

INSERT INTO Client (ID_client, nom, prenom, date_naissance, date_premier_achat)
VALUES (NULL,'Dupont','Jean','1969/11/25','2011/10/16'),
(NULL,'Lacastagne','Bernadette','1955/07/16','2013/12/23'),
(NULL,'Darty','Geaorge','1998/03/13','2018/03/19'),
(NULL,'Martir','Claudette','1955/11/25','2013/09/16'),
(NULL,'Montanelli','Bernard','1970/04/08','2018/06/08'),
(NULL,'Dupont','Arthur','1994/09/25','2010/05/10');

INSERT INTO Adresse_client(adresse_client,ID_client,ID_ville,ID_type_adresse)
VALUES ('8 Avenue Notre Dame de Vie', '1','1','2'),
('54 Chemin des traverse', '2','1','3'),
('36 Rue de Poudlard', '3','1','2'),
('35 Voie neuf trois quart', '4','1','1'),
('42 Rue elfe Dobby', '5','1','1'),
('3 Avenue Lili Potter', '6','1','3');
