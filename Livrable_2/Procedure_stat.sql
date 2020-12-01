USE projet;

DELIMITER |
DROP PROCEDURE IF EXISTS Stat_Plus_vendu |
CREATE PROCEDURE Stat_Plus_vendu ()
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

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
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Catalogue.nom, SUM(Fournir.quantite) AS quantite_total
  FROM Fournir
  INNER JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article
  GROUP BY Catalogue.nom
  ORDER BY quantite_total ASC
  LIMIT 10;
END |
DELIMITER ;
