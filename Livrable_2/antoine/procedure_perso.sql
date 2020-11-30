DELIMITER |
DROP PROCEDURE IF EXISTS remplissage_Client |
CREATE PROCEDURE remplissage_Client (IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), IN i_type_adresse VARCHAR(25))
BEGIN
  DECLARE id_cli INT;
  DECLARE type_cli INT;
  DECLARE ville_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Client (ID_client, nom, prenom, date_naissance)
  VALUES (NULL, i_nom, i_prenom, i_date_naissance);

  SELECT LAST_INSERT_ID() INTO id_cli;
  SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type_adresse;
  SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;

  INSERT INTO Adresse_client (ID_adresse_client, adresse_client, ID_client, ID_type_adresse, ID_ville)
  VALUES (NULL, i_adresse_client, id_cli, type_cli, ville_cli);
END |


DROP PROCEDURE IF EXISTS verification_Client |
CREATE PROCEDURE verification_Client (IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), i_type_adresse VARCHAR(25))
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


DROP PROCEDURE IF EXISTS ajout_Adresse_client |
CREATE PROCEDURE ajout_Adresse_client (IN i_id_client INT, IN i_adresse VARCHAR(50), IN i_ville VARCHAR(20), IN i_type_adresse VARCHAR(25))
BEGIN
  DECLARE ville_cli INT;
  DECLARE type_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
  SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type_adresse;

  INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
  VALUES (i_adresse, i_id_client, ville_cli, type_cli);
END |


DROP PROCEDURE IF EXISTS delete_Adresse_client |
CREATE PROCEDURE delete_Adresse_client (IN i_id INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  DELETE FROM Adresse_client
  WHERE ID_adresse_client = i_id;
END |


DROP PROCEDURE IF EXISTS update_Adresse_client |
CREATE PROCEDURE update_Adresse_client (IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
BEGIN
  DECLARE ville_cli INT;
  DECLARE type_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Ville.ID_ville INTO ville_cli FROM Ville WHERE Ville.ville = i_ville;
  SELECT Type_adresse.ID_type_adresse INTO type_cli FROM Type_adresse WHERE Type_adresse.type_adresse = i_type;

  UPDATE Adresse_client
  SET
    Adresse_client.adresse_client = i_adresse,
    Adresse_client.ID_ville = ville_cli,
    Adresse_client.ID_type_adresse = type_cli
  WHERE Adresse_client.ID_adresse_client = i_id_adresse;
END |


DROP PROCEDURE IF EXISTS verification_Adresse_client |
CREATE PROCEDURE verification_Adresse_client (IN i_id_client INT)
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
  WHERE Adresse_client.ID_client = i_id_client;
END |
                                                                                                                                 
                                                                                                                                 
DROP PROCEDURE IF EXISTS update_Catalogue_perso |
CREATE PROCEDURE update_Catalogue_perso (IN i_id_cat INT, IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  UPDATE Catalogue
  SET
    Catalogue.nom = i_nom,
    Catalogue.reference = i_ref,
    Catalogue.prix_ht = i_prix_ht,
    Catalogue.taux_tva = i_tva,
    Catalogue.coefficient_economie = i_coef,
    Catalogue.stock = i_stock,
    Catalogue.seuil_reapprovisionnement = i_seuil,
    Catalogue.actif = i_actif
  WHERE Catalogue.ID_article = i_id_cat;
END |


DROP PROCEDURE IF EXISTS verification_Catalogue_perso |
CREATE PROCEDURE verifiactin_Catalogue_perso (IN i_id INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Catalogue.nom, Catalogue.reference, Catalogue.prix_ht, Catalogue.taux_tva, Catalogue.coefficient_economie, Catalogue.stock, Catalogue.seuil_reapprovisionnement, Catalogue.actif
  FROM Catalogue
  WHERE Catalogue.ID_article = i_id;
END |
DELIMITER ;
