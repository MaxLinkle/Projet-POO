DELIMITER |
DROP PROCEDURE IF EXISTS remplissage_Client |
CREATE PROCEDURE remplissage_Client (IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), i_type_adresse VARCHAR(20))
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Client (ID_client, nom, prenom, date_naissance)
  VALUES (NULL, i_nom, i_prenom, i_date_naissance);

  INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
  SELECT i_adresse_client, ID_client, Ville.ID_ville, Type_adresse.ID_type_adresse
  FROM Client
  INNER JOIN Ville ON i_ville = Ville.ville
  INNER JOIN Type_adresse ON i_type_adresse = Type_adresse.type_adresse
  WHERE nom = i_nom AND prenom = i_prenom AND date_naissance = i_date_naissance;
END |


DROP PROCEDURE IF EXISTS verification_Client |
CREATE PROCEDURE verification_Client (IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), i_type_adresse VARCHAR(20))
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Client.nom, Client.prenom, Client.date_naissance, adresse_client, Type_adresse.type_adresse, Ville.ville
  FROM Adresse_client
  INNER JOIN Client ON Adresse_client.ID_client = Client.ID_client
  INNER JOIN Type_adresse ON Adresse_client.ID_type_adresse = Type_adresse.ID_type_adresse
  INNER JOIN Ville ON Adresse_client.ID_ville = Ville.ID_ville
  WHERE nom = i_nom AND prenom = i_prenom AND date_naissance = i_date_naissance;
END |
DELIMITER ;
