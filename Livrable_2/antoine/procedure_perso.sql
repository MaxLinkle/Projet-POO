USE projet;

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

  -- DELETE FROM Adresse_client
  -- WHERE ID_adresse_client = i_id;
  UPDATE Adresse_client
  SET Adresse_client.ID_client = NULL
  WHERE Adresse_client.ID_adresse_client = i_id;
END |


-- DROP PROCEDURE IF EXISTS update_Adresse_client |
-- CREATE PROCEDURE update_Adresse_client (IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
-- BEGIN
--   DECLARE ville_cli INT;
--   DECLARE type_cli INT;
--
--   DECLARE EXIT HANDLER FOR SQLEXCEPTION
--   BEGIN
--     ROLLBACK;
--   END;
--
--   SELECT Ville.ID_ville INTO ville_cli FROM Ville WHERE Ville.ville = i_ville;
--   SELECT Type_adresse.ID_type_adresse INTO type_cli FROM Type_adresse WHERE Type_adresse.type_adresse = i_type;
--
--   UPDATE Adresse_client
--   SET
--     Adresse_client.adresse_client = i_adresse,
--     Adresse_client.ID_ville = ville_cli,
--     Adresse_client.ID_type_adresse = type_cli
--   WHERE Adresse_client.ID_adresse_client = i_id_adresse;
-- END |

-- DELIMITER |
-- DROP PROCEDURE IF EXISTS update_Adresse_client |
-- CREATE PROCEDURE update_Adresse_client (IN i_id INT, IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN ancienne_adr VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
-- BEGIN
--   DECLARE a_livr INT DEFAULT NULL;
--   DECLARE a_fact INT DEFAULT NULL;
--
--   DECLARE ville_cli INT;
--   DECLARE type_cli INT;
--
--   -- DECLARE EXIT HANDLER FOR SQLEXCEPTION
--   -- BEGIN
--   --   ROLLBACK;
-- --  END;
--
--   SELECT Commande.ID_adresse_livraison INTO a_livr
--   FROM Commande
--   INNER JOIN Adresse_client
--   ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
--   WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id
--   LIMIT 1;
--
--   SELECT Commande.ID_adresse_facturation INTO a_fact
--   FROM Commande
--   INNER JOIN Adresse_client
--   ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
--   WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id
--   LIMIT 1;
--
--   SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
--   SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type;
--
--   IF a_livr IS NULL AND a_fact IS NULL THEN
--     UPDATE Adresse_client
--     SET
--       Adresse_client.adresse_client = i_adresse,
--       Adresse_client.ID_ville = ville_cli,
--       Adresse_client.ID_type_adresse = type_cli
--     WHERE Adresse_client.ID_adresse_client = i_id_adresse;
--   ELSE
--     CALL delete_Adresse_client(i_id_adresse);
--
--     INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
--     VALUES (i_adresse, i_id, ville_cli, type_cli);
--
--   END IF;
-- END |

-- DELIMITER |
-- DROP PROCEDURE IF EXISTS update_Adresse_client |
-- CREATE PROCEDURE update_Adresse_client (IN i_id INT, IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN ancienne_adr VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
-- BEGIN
--   DECLARE a_livr INT DEFAULT NULL;
--   DECLARE a_fact INT DEFAULT NULL;
--
--   DECLARE ville_cli INT;
--   DECLARE type_cli INT;
--
--   -- DECLARE EXIT HANDLER FOR SQLEXCEPTION
--   -- BEGIN
--   --   ROLLBACK;
-- --  END;
--
--   SELECT Commande.ID_adresse_livraison INTO a_livr
--   FROM Commande
--   INNER JOIN Adresse_client
--   ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
--   WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id
--   LIMIT 1;
--
--   SELECT Commande.ID_adresse_facturation INTO a_fact
--   FROM Commande
--   INNER JOIN Adresse_client
--   ON Adresse_client.ID_adresse_client = Commande.ID_adresse_livraison
--   WHERE Adresse_client.adresse_client = ancienne_adr AND Adresse_client.ID_client = i_id
--   LIMIT 1;
--
--   SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
--   SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type;
--
--   IF a_livr IS NULL AND a_fact IS NULL THEN
--     UPDATE Adresse_client
--     SET
--       Adresse_client.adresse_client = i_adresse,
--       Adresse_client.ID_ville = ville_cli,
--       Adresse_client.ID_type_adresse = type_cli
--     WHERE Adresse_client.ID_adresse_client = i_id_adresse;
--   ELSE
--     CALL delete_Adresse_client(i_id_adresse);
--
--     INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
--     VALUES (i_adresse, i_id, ville_cli, type_cli);
--
--   END IF;
-- END |

DROP PROCEDURE IF EXISTS update_Adresse_client |
CREATE PROCEDURE update_Adresse_client (IN i_id INT, IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN ancienne_adr VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
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


-- DELIMITER |
-- DROP PROCEDURE IF EXISTS update_Adresse_client |
-- CREATE PROCEDURE update_Adresse_client (IN i_id INT, IN i_id_adresse INT, IN i_adresse VARCHAR(50), IN i_ville VARCHAR(20), IN i_type VARCHAR(25))
-- BEGIN
--   DECLARE ville_cli INT;
--   DECLARE type_cli INT;
--
--   -- DECLARE EXIT HANDLER FOR SQLEXCEPTION
--   -- BEGIN
--   --   ROLLBACK;
--   -- END;
--
--   SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
--   SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type;
--
--   CALL delete_Adresse_client(i_id_adresse);
--
--   INSERT INTO Adresse_client (adresse_client, ID_client, ID_ville, ID_type_adresse)
--   VALUES (i_adresse, i_id, ville_cli, type_cli);
-- END |


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
CREATE PROCEDURE verification_Catalogue_perso (IN i_id INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT Catalogue.nom, Catalogue.reference, Catalogue.prix_ht, Catalogue.taux_tva, Catalogue.coefficient_economie, Catalogue.stock, Catalogue.seuil_reapprovisionnement, Catalogue.actif
  FROM Catalogue
  WHERE Catalogue.ID_article = i_id;
END |


DROP PROCEDURE IF EXISTS ajout_Catalogue_perso |
CREATE PROCEDURE ajout_Catalogue_perso (IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Catalogue (nom, reference, prix_ht, taux_tva, coefficient_economie, stock, seuil_reapprovisionnement, actif)
  VALUES (i_nom, i_ref, i_prix_ht, i_tva, i_coef, i_stock, i_seuil, i_actif);
END |

DROP PROCEDURE IF EXISTS verification_ajout_Catalogue_perso |
CREATE PROCEDURE verification_ajout_Catalogue_perso (IN i_nom VARCHAR(50), IN i_ref VARCHAR(50), IN i_prix_ht INT, IN i_tva INT, IN i_coef INT, IN i_stock INT, IN i_seuil INT, IN i_actif BOOLEAN)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT *
  FROM Catalogue
  WHERE Catalogue.nom = i_nom AND Catalogue.reference = i_ref AND Catalogue.prix_ht = i_prix_ht AND Catalogue.taux_tva = i_tva AND Catalogue.coefficient_economie = i_coef AND Catalogue.stock = i_stock AND Catalogue.seuil_reapprovisionnement = i_seuil AND Catalogue.actif = i_actif;
END |

-- DELIMITER |
DROP PROCEDURE IF EXISTS update_Catalogue_stock |
CREATE PROCEDURE update_Catalogue_stock (IN i_id_art INT, IN i_dif INT)
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


-- DELIMITER |
DROP PROCEDURE IF EXISTS ajout_Commande |
CREATE PROCEDURE ajout_Commande(IN i_prix_ht INT, IN i_prix_tva INT, IN i_remise INT, IN date_liv DATE, IN date_emi DATE, IN date_paye DATE, IN date_sol DATE, IN i_id_adresse_de_livraison VARCHAR(50), IN i_id_adresse_facturation VARCHAR(50), IN i_id_cli INT, IN id_paye VARCHAR(50))
BEGIN
  DECLARE adresseliv_cli INT;
  DECLARE adressefact_cli INT;
  DECLARE paiement_cli INT;
  DECLARE id_commande INT;

  -- DECLARE last INT;

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

  SELECT id_commande;
  -- SELECT LAST_INSERT_ID() INTO last;
  -- SELECT last;
END |


DROP PROCEDURE IF EXISTS ajout_Fournir |
CREATE PROCEDURE ajout_Fournir (IN i_quant INT, IN i_id_art INT, IN i_id_com INT)
BEGIN
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  INSERT INTO Fournir (ID_fournir, quantite, ID_article, ID_commande)
  VALUES (NULL, i_quant, i_id_art, i_id_com);
END |


-- DELIMITER |
DROP PROCEDURE IF EXISTS delete_Commande |
CREATE PROCEDURE delete_Commande ()
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


DROP PROCEDURE IF EXISTS delete_Adresse_client_deref |
CREATE PROCEDURE delete_Commande_deref ()
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


-- DELIMITER |
DROP PROCEDURE IF EXISTS ajout_Date_achat |
CREATE PROCEDURE ajout_Date_achat (IN i_id_client INT)
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
