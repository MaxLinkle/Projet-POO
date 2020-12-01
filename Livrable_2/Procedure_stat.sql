USE projet;

DELIMITER |
DROP PROCEDURE IF EXISTS Stat_Plus_vendu |
CREATE PROCEDURE Stat_Plus_vendu ()
BEGIN
  SELECT Catalogue.nom, SUM(Fournir.quantite) AS quantite_total
  FROM Fournir
  INNER JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article
  GROUP BY Catalogue.nom
  ORDER BY quantite_total DESC
  LIMIT 10;
END |


DROP PROCEDURE IF EXISTS Stat_Moins_vendu |
CREATE PROCEDURE Stat_Moins_vendu ()
BEGIN
  SELECT Catalogue.nom, SUM(Fournir.quantite) AS quantite_total
  FROM Fournir
  INNER JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article
  GROUP BY Catalogue.nom
  ORDER BY quantite_total ASC
  LIMIT 10;
END |


DROP PROCEDURE IF EXISTS Stat_Achat_stock |
CREATE PROCEDURE Stat_Achat_stock ()
BEGIN
  SELECT Catalogue.nom, Catalogue.stock, Catalogue.stock * Catalogue.prix_ht * 0.5 AS Valeur_achat
  FROM Catalogue;
END |


DROP PROCEDURE IF EXISTS Stat_Valeur_stock |
CREATE PROCEDURE Stat_Valeur_stock ()
BEGIN
  SELECT Catalogue.nom, Catalogue.stock, Catalogue.stock * Catalogue.prix_ht AS Valeur_Commercial
  FROM Catalogue;
END |


DROP PROCEDURE IF EXISTS `Stat_Panier_moy` |
CREATE PROCEDURE `Stat_Panier_moy` (IN `PNom` VARCHAR(50),IN `PPrenom` VARCHAR(50))
BEGIN
  SELECT AVG(prix_ht+prix_tva - remise)
  FROM Client NATURAL JOIN Commande
  WHERE nom = PNom AND prenom = PPrenom;
END |


DROP PROCEDURE IF EXISTS `Stat_Total_achat_client` |
CREATE PROCEDURE `Stat_Total_achat_client` (IN `PNom` VARCHAR(50),IN `PPrenom` VARCHAR(50))
BEGIN
  SELECT SUM(prix_ht+prix_tva - remise)
  FROM Client NATURAL JOIN Commande
  WHERE nom = PNom AND prenom = PPrenom;
END |
DELIMITER ;
