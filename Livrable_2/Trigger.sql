DELIMITER |
DROP TRIGGER IF EXISTS delete_Personnel |
CREATE TRIGGER delete_Personnel BEFORE DELETE
ON Personnel FOR EACH ROW
BEGIN
  DELETE FROM Adresse_personnel WHERE (ID_personnel = OLD.ID_personnel);

  UPDATE Personnel
  SET ID_superieur = NULL
  WHERE ID_superieur = OLD.ID_personnel;
END |


DROP TRIGGER IF EXISTS delete_Client |
CREATE TRIGGER delete_Client BEFORE DELETE
ON Client FOR EACH ROW
BEGIN
  DELETE FROM Adresse_client WHERE (ID_client = OLD.ID_client);
END |


DROP TRIGGER IF EXISTS delete_Commande |
CREATE TRIGGER delete_Commande BEFORE DELETE
ON Commande FOR EACH ROW
BEGIN
  DELETE FROM Fournir WHERE (ID_commande = OLD.ID_commande);
END |

DELIMITER ;

-- DROP TRIGGER IF EXISTS update_Catalogue |
-- CREATE TRIGGER update_Catalogue AFTER UPDATE
-- ON Catalogue FOR EACH ROW
-- BEGIN
--   DROP VIEW IF EXISTS Catalogue_actif;
--
--   CREATE VIEW Catalogue_actif (ID_catalogue_actif, nom, reference, prix_ht, taux_tva, stock, seuil_reapprovisionnement) AS
--   SELECT ID_catalogue_actif, nom, reference, prix_ht, taux_tva, stock, seuil_reapprovisionnement
--   FROM Catalogue
--   WHERE actif = true;
-- END |
