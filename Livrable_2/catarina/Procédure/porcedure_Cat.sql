DELIMITER |
DROP PROCEDURE IF EXISTS ajout_Commande |
CREATE PROCEDURE ajout_Commande(IN `i_prix_ht` INT, IN `i_prix_tva` INT, IN `i_remise` INT, IN `date_liv` DATE, IN `date_emi` DATE, IN `date_paye` DATE, IN `date_sol` DATE, IN `i_id_adresse_de_livraison` INT, IN `i_id_adresse_facturation` INT, IN `i_id_cli` INT, IN `id_paye` INT)
BEGIN
  DECLARE adresseliv_cli INT;
  DECLARE adressefact_cli INT;
  DECLARE paiement_cli INT;
  DECLARE id_commande INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT ID_adresse_client INTO adresseliv_cli FROM Adresse_client WHERE adresse_client = i_id_adresse_de_livraison;
  SELECT ID_adresse_client INTO adressefact_cli FROM Adresse_client WHERE adresse_client = i_id_adresse_facturation;
  SELECT ID_paiement INTO paiement_cli FROM Paiement WHERE moyen_paiement = id_paye;

  INSERT INTO Commande(ID_commande, reference, prix_ht, prix_tva, remise, date_livraison_prevue, date_emission, date_paiement, date_solde, ID_adresse_livraison, ID_adresse_facturation, ID_client, ID_paiement)
  VALUES(NULL, "0", i_prix_ht, i_prix_tva, i_remise, date_liv, date_emi, date_paye, date_sol,adresseliv_cli, adressefact_cli, i_id_cli, paiement_cli);

  SELECT LAST_INSERT_ID() INTO id_commande;
  CALL generer_reference(i_id_cli, id_commande, @reference);

  UPDATE Commande
  SET reference = @reference
  WHERE Commande.ID_commande = id_commande;
END |

DELIMITER |
DROP PROCEDURE IF EXISTS ajoutUpdate_Adresse_client |
CREATE PROCEDURE ajoutUpdate_Adresse_client(IN i_id INT, IN i_adresse VARCHAR(50), IN i_ville INT(20), IN i_type INT(25))
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


DELIMITER |
DROP PROCEDURE IF EXISTS envoie_Commande |
CREATE PROCEDURE envoie_Commande (IN i_id_com INT)
BEGIN
  -- DECLARE EXIT HANDLER FOR SQLEXCEPTION
  -- BEGIN
  --   ROLLBACK;
  -- END;

  SELECT Commande.*, Client.nom, Client.prenom, Client.date_naissance, Paiement.moyen_paiement, j.quantite, j.nom
  FROM Commande
  JOIN Client ON Client.ID_client = Commande.ID_client
  JOIN Paiement ON Paiement.ID_paiement = Commande.ID_paiement
  JOIN (
    SELECT Fournir.ID_commande, Fournir.quantite, Catalogue.nom
    FROM Fournir
    JOIN Catalogue ON Catalogue.ID_article = Fournir.ID_article
  ) AS j ON j.ID_commande = Commande.ID_commande
  WHERE Commande.ID_commande = i_id_com;
END |
DELIMITER ;

Call envoie_Commande('41');
