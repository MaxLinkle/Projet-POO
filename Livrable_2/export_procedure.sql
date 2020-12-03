USE projet;

DELIMITER  |
DROP PROCEDURE IF EXISTS `Ajouter_Adresse_Perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `Ajouter_Adresse_Perso`(IN IDPERSO INT, IN PVille VARCHAR(50),IN PAdresse VARCHAR(50))
BEGIN
  DECLARE IDVil INT;
  SELECT ID_Ville INTO IDVil FROM Ville WHERE PVille = ville;
  IF(SELECT COUNT(*) FROM Adresse_personnel WHERE ID_personnel = IDPerso) = 0 THEN

    INSERT INTO Adresse_personnel(ID_personnel,adresse_personnel,ID_ville) VALUES (IDPerso,PAdresse,IDvil);

  ELSEIF (SELECT COUNT(*) FROM Adresse_personnel WHERE ID_personnel = IDPerso) = 1 THEN

    UPDATE Adresse_personnel SET adresse_personnel = PAdresse , ID_ville = IDvil WHERE IDPerso = ID_personnel;

  END IF;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `Suppr_Perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `Suppr_Perso`(IN `ID_Perso` INT)
BEGIN

DELETE FROM Adresse_personnel WHERE ID_personnel = ID_Perso;
DELETE FROM Personnel WHERE ID_personnel = ID_Perso;

END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `VerifIndividus` |
CREATE DEFINER=`admin`@`%` PROCEDURE `VerifIndividus`(IN `CliPer` BOOLEAN, IN `PNom` VARCHAR(50), IN `PPrenom` VARCHAR(50), IN `PDate` DATE, IN `PSNom` VARCHAR(50), IN `PSPrenom` VARCHAR(50))
pr: BEGIN
    DECLARE Tab VARCHAR(50);
    DECLARE Sup INT;
	DECLARE retour INT;

    IF CliPer THEN

	IF ISNULL(PDate)
            THEN SET PDATE = NULL;
    END IF;

        SELECT * FROM `Client` WHERE  nom = PNom AND prenom = PPrenom AND PDate = date_naissance;

    ELSE


        IF ISNULL(PDate)
            THEN LEAVE pr ;
        END IF;


        IF (SELECT COUNT(*) FROM Personnel WHERE nom = PSNom AND prenom = PSPrenom) != 1 THEN
            SET Sup = NULL;
        ELSE
            SELECT ID_personnel INTO Sup FROM Personnel WHERE nom = PSNom AND prenom = PSPrenom;
        END IF;


		SELECT * FROM `Personnel` WHERE nom=PNom AND prenom=PPrenom AND date_embauche=PDate AND ID_superieur=Sup;



    END IF;

END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajoutUpdate_Adresse_client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajoutUpdate_Adresse_client`(IN `i_id` INT, IN `i_adresse` VARCHAR(50), IN `i_ville` INT(20), IN `i_type` INT(25))
BEGIN
  DECLARE id_var INT;
  DECLARE type_var INT;

  DECLARE ville_cli INT;
  DECLARE type_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Adresse_client.ID_client INTO id_var
  FROM Adresse_client
  INNER JOIN Ville ON Ville.ID_ville = Adresse_client.ID_ville
  WHERE Adresse_client.adresse_client = i_adresse AND Ville.ville = i_ville AND Adresse_client.ID_client = i_id;

  SELECT Ville.ID_ville INTO ville_cli FROM Ville WHERE Ville.ville = i_ville;
  SELECT Type_adresse.ID_type_adresse INTO type_cli FROM Type_adresse WHERE Type_adresse.type_adresse = i_type;

  IF id_var = NULL
  THEN
    INSERT INTO Adresse_client (adresse_client,ID_client, ID_ville, ID_type_adresse)
    VALUES (i_adresse, i_id_client, ville_cli, type_cli);

  ELSE
    SELECT ID_type_adresse INTO type_var
    FROM Adresse_client
    INNER JOIN Ville ON Ville.ID_ville = Adresse_client.ID_ville
    WHERE Adresse_client.adresse_client = i_adresse AND Ville.ville = i_ville AND Adresse_client.ID_client = i_id;

    IF (type_var = 2 AND type_cli = 1) OR (type_var = 1 AND type_cli = 2)
    THEN
      UPDATE Adresse_client
      SET ID_type_adresse = 3
      WHERE ID_client = i_id_client;

    END IF;

  END IF;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajout_Adresse_client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Adresse_client`(IN i_id_client INT, IN i_adresse VARCHAR(50), IN i_ville VARCHAR(20), IN i_type_adresse VARCHAR(25))
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
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajout_Catalogue_perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Catalogue_perso`(IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Catalogue (nom, reference, prix_ht, taux_tva, coefficient_economie, stock, seuil_reapprovisionnement, actif)
  VALUES (i_nom, i_ref, i_prix_ht, i_tva, i_coef, i_stock, i_seuil, i_actif);
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajout_Commande` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Commande`(IN `i_prix_ht` INT, IN `i_prix_tva` INT, IN `i_remise` INT, IN `date_liv` DATE, IN `date_emi` DATE, IN `date_paye` DATE, IN `date_sol` DATE, IN `i_id_adresse_de_livraison` VARCHAR(50), IN `i_id_adresse_facturation` VARCHAR(50), IN `i_id_cli` INT, IN `id_paye` VARCHAR(50))
BEGIN
  DECLARE adresseliv_cli INT;
  DECLARE adressefact_cli INT;
  DECLARE paiement_cli INT;
  DECLARE id_commande INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT ID_adresse_client INTO adresseliv_cli FROM Adresse_client WHERE Adresse_client.adresse_client = i_id_adresse_de_livraison;
  SELECT ID_adresse_client INTO adressefact_cli FROM Adresse_client WHERE Adresse_client.adresse_client = i_id_adresse_facturation;
  SELECT ID_paiement INTO paiement_cli FROM Paiement WHERE Paiement.moyen_paiement = id_paye;

  INSERT INTO Commande(ID_commande, reference, prix_ht, prix_tva, remise, date_livraison_prevue, date_emission, date_paiement, date_solde, ID_adresse_livraison, ID_adresse_facturation, ID_client, ID_paiement)
  VALUES(NULL, "0", i_prix_ht, i_prix_tva, i_remise, date_liv, date_emi, date_paye, date_sol,adresseliv_cli, adressefact_cli, i_id_cli, paiement_cli);

  SELECT LAST_INSERT_ID() INTO id_commande;
  CALL generer_reference(i_id_cli, id_commande, @reference);

  UPDATE Commande
  SET reference = @reference
  WHERE Commande.ID_commande = id_commande;

  SELECT id_commande;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajout_Date_achat` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Date_achat`(IN `i_id_client` INT)
BEGIN
  DECLARE date_prem DATE;
  DECLARE date_actuelle DATE;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Client.date_premier_achat INTO date_prem FROM Client WHERE Client.ID_client = i_id_client;

  IF date_prem IS NULL
  THEN
    SELECT CURRENT_DATE INTO date_actuelle;

    UPDATE Client
      SET Client.date_premier_achat = date_actuelle
    WHERE Client.ID_client = i_id_client;
  END IF;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `ajout_Fournir` |
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Fournir`(IN i_quant INT, IN i_id_art INT, IN i_id_com INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Fournir (ID_fournir, quantite, ID_article, ID_commande)
  VALUES (NULL, i_quant, i_id_art, i_id_com);
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `delete_Adresse_client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `delete_Adresse_client`(IN i_id INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  UPDATE Adresse_client
  SET Adresse_client.ID_client = NULL
  WHERE Adresse_client.ID_adresse_client = i_id;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `delete_Commande` |
CREATE DEFINER=`admin`@`%` PROCEDURE `delete_Commande`()
BEGIN
  DECLARE date_moins_10 DATE;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT CURRENT_DATE - INTERVAL 10 YEAR INTO date_moins_10;

  DELETE FROM COMMANDE
  WHERE date_paiement < date_moins_10;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `delete_Adresse_client_deref` |
CREATE DEFINER=`admin`@`%` PROCEDURE `delete_Adresse_client_deref` ()
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  DELETE FROM Adresse_client
  WHERE (
    ISNULL(Adresse_client.ID_client)
    AND (
      NOT (
        (ID_adresse_client IN (SELECT DISTINCT ID_adresse_livraison FROM Commande))
        OR (ID_adresse_client IN (SELECT DISTINCT ID_adresse_facturation FROM Commande))
      )
    )
  );
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `envoie_Commande` |
CREATE DEFINER=`admin`@`%` PROCEDURE `envoie_Commande`(IN i_id_com INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Client.nom, Client.prenom, Client.date_naissance, Paiement.moyen_paiement, j.quantite, j.nom
  FROM Commande
  INNER JOIN Client ON Client.ID_client = Commande.ID_client
  INNER JOIN Paiement ON Paiement.ID_paiement = Commande.ID_paiement
  INNER JOIN (
    SELECT Fournir.ID_commande, Fournir.quantite, Catalogue.nom
    FROM Fournir
    INNER JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article
  ) AS j ON j.ID_commande = Commande.ID_commande
  WHERE Commande.ID_commande = i_id_com;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `generer_reference` |
CREATE DEFINER=`admin`@`%` PROCEDURE `generer_reference`(IN `id_client` INT, IN `id_commande` INT, OUT `reference` VARCHAR(50))
BEGIN
   SELECT CONCAT(LEFT(T1.prenom, 2), LEFT(T1.nom, 2), YEAR(NOW()), LEFT(T2.ville, 3), id_commande) INTO reference
  FROM (SELECT Client.* , Commande.ID_adresse_livraison FROM Client
  NATURAL JOIN Commande WHERE Commande.ID_commande = id_commande) AS T1
  INNER JOIN (SELECT * FROM Adresse_client
  NATURAL JOIN Ville) AS T2
 ON T2.ID_adresse_client = T1.ID_adresse_livraison;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `remplissage_Client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `remplissage_Client`(IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), IN i_type_adresse VARCHAR(25))
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
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `update_Adresse_client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Adresse_client`(IN i_id INT, IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN ancienne_adr VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
BEGIN
  DECLARE a_livr INT DEFAULT 0;
  DECLARE a_fact INT DEFAULT 0;

  DECLARE ville_cli INT;
  DECLARE type_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT COUNT(Commande.ID_adresse_livraison) INTO a_livr
  FROM Commande
  INNER JOIN Adresse_client
  ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
  WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id;

  SELECT COUNT(Commande.ID_adresse_facturation) INTO a_fact
  FROM Commande
  INNER JOIN Adresse_client
  ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
  WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id;

  SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
  SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type;

  IF a_livr = 0 AND a_fact = 0
  THEN
    UPDATE Adresse_client
    SET
      Adresse_client.adresse_client = i_adresse,
      Adresse_client.ID_ville = ville_cli,
      Adresse_client.ID_type_adresse = type_cli
    WHERE Adresse_client.ID_adresse_client = i_id_adresse;
  ELSE
    CALL delete_Adresse_client(i_id_adresse);

    INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
    VALUES (i_adresse, i_id, ville_cli, type_cli);

  END IF;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `update_Catalogue` |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Catalogue`(IN `i_quantite` INT, IN `i_id_article` INT)
UPDATE Catalogue
Set stock = (stock - quantite)
WHERE ID_article = i_id_article |
DELIMITER ;

DELIMITER  |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Catalogue_perso`(IN i_id_cat INT, IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
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
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `update_Catalogue_stock` |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Catalogue_stock`(IN i_id_art INT, IN i_dif INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  UPDATE Catalogue
  SET
    Catalogue.stock = Catalogue.stock - i_dif
  WHERE Catalogue.ID_article = i_id_art;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `update_Client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Client`(IN i_nom VARCHAR(50), IN i_prenom VARCHAR(50), IN i_date_naissance DATE, IN i_date_premier_achat DATE, IN i_id_client INT)
BEGIN
  UPDATE Client
    SET Client.nom = i_nom, Client.prenom = i_prenom, Client.date_naissance = i_date_naissance, Client.date_premier_achat = i_date_premier_achat
  WHERE Client.ID_client = i_id_client;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `update_Perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `update_Perso`(IN i_id_personnel INT, IN i_nom VARCHAR(50), IN i_prenom VARCHAR(50), IN i_date_embauche DATE, IN i_id_perso INT, IN i_id_superieur INT)
BEGIN
  UPDATE Personnel
    SET Personnel.nom = i_nom, Personnel.prenom = i_prenom, Personnel.date_embauche = i_date_embauche, Personnel.ID_superieur = i_id_superieur
  WHERE Personnel.ID_personnel = i_id_personnel;
END |
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `verification_Adresse_client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `verification_Adresse_client`(IN i_id_client INT)
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
DELIMITER ;


DELIMITER  |
DROP PROCEDURE IF EXISTS `verification_Catalogue_perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `verification_Catalogue_perso`(IN i_id INT)
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


DELIMITER  |
DROP PROCEDURE IF EXISTS `verification_Client` |
CREATE DEFINER=`admin`@`%` PROCEDURE `verification_Client`(IN i_nom VARCHAR(20), IN i_prenom VARCHAR(20), IN i_date_naissance DATE, IN i_adresse_client VARCHAR(50), IN i_ville VARCHAR(20), i_type_adresse VARCHAR(25))
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


DELIMITER  |
DROP PROCEDURE IF EXISTS  `verification_ajout_Catalogue_perso` |
CREATE DEFINER=`admin`@`%` PROCEDURE `verification_ajout_Catalogue_perso`(IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT *
  FROM Catalogue
  WHERE Catalogue.nom = i_nom AND Catalogue.reference = i_ref AND Catalogue.prix_ht = i_prix_ht AND Catalogue.taux_tva = i_tva AND Catalogue.coefficient_economie = i_coef AND Catalogue.stock = i_stock AND Catalogue.seuil_reapprovisionnement = i_seuil AND Catalogue.actif = i_actif;
END |
DELIMITER ;
